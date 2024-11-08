#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // Initialise a string and prompt the user for their current ranked candidate choice
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if the user-given name matches the current candidate name
        if (!strcmp(name, candidates[i]))
        {
            // Set the value of the current rank to that candidate's index and return true
            ranks[rank] = i;
            return true;
        }
    }
    // If the user-given name doesn't match any of the candidate names, return false
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Loop through each subsequently ranked candidate
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Increment the preference count for ranks[i] over ranks[j]
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Loop through each subsequent candidate
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Check if candidate i is preferred over candidate j
            if (preferences[i][j] > preferences[j][i])
            {
                // Set winner and loser and increment pair counter
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            // Else check if candidate j is preferred over candidate i
            else if (preferences[i][j] < preferences[j][i])
            {
                // Set winner and loser and increment pair counter
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Loop through each pair except the first
    for (int i = 0; i < pair_count - 1; i++)
    {
        // Loop through each pair except the last
        for (int j = 1; j < pair_count; j++)
        {
            // Check if pair j is preferred over pair j - 1
            if (preferences[pairs[j].winner][pairs[j].loser] >
                preferences[pairs[j - 1].winner][pairs[j - 1].loser])
            {
                // Switch adjacent pairs
                pair n = pairs[j];
                pairs[j] = pairs[j - 1];
                pairs[j - 1] = n;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Loop through each pair
    for (int i = 0; i < pair_count; i++)
    {
        // If locking the  current pair does not create a cycle that leads to the winner of a previously locked pair
        if (!creates_cycle(pairs[i].winner, pairs[i].loser))
        {
            // Lock the current pair
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Check that locking a pair is not the winner of a previously locked pair
bool creates_cycle(int winner, int loser)
{
    // TODO
    if (winner == loser)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (creates_cycle(winner, i))
            {
                return true;
            }
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                is_source = false;
            }
        }
        if (is_source)
        {
            printf("%s\n", candidates[i]);
        }
    }
}
