// Determines the winner of a short Scrabble-like game.
// The program should prompt for input twice:
// once for “Player 1” to input their word and once for “Player 2” to input their word.
// Then, depending on which player scores the most points,
// the program should either print “Player 1 wins!”,
// “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int p = 2; // Number of players

int main(void)
{
    string words[p];            // Initialise an array of size p to store player input
    for (int n = 0; n < p; n++) // Prompt players for words
    {
        words[n] = get_string("Player %i Input: ", (n + 1));
    }
    int wordLength[p];
    wordLength[0] = strlen(words[0]);
    wordLength[1] = strlen(words[1]);
    int scoreTotals[p] = {0};
    for (int x = 0; x < p; x++)
    {
        for (int i = 0; i < wordLength[x]; i++)
        {
            char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            int letterScores[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                                    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
            char c = words[x][i];
            for (int a = 0; a < 26; a++)
            {
                if (tolower(c) == alphabet[a])
                {
                    c = letterScores[a];
                    scoreTotals[x] = (letterScores[a] + scoreTotals[x]);
                }
            }
        }
    }
    if (scoreTotals[0] > scoreTotals[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (scoreTotals[0] < scoreTotals[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
