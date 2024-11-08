// Accept only one command line argument: a case-insensitive, 26-character, non-repeating,
// alphabetic-only cipher key. Otherwise print an error message and return 1 from main. Print
// "plaintext: " with no newline and prompt the user for a string. Print "ciphertext: " with no
// newline and then print the plaintext's corresponding ciphertext. Non-alpha characters remain
// unchanged. Case must be preserved. Print a newline when finished and return 0 from main.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_discrete_alpha(string s);  //Checks if a given string has any repeated chars and returns a boolean value
char rotate(char c, string s);
int user_error(void);

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26) // Return user_error if command-line input is incorrect
    {

        return user_error();
    }
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            return user_error();
        }
    }
    if (!is_discrete_alpha(argv[1]))
    {
        return user_error();
    }
    string text = get_string("plaintext: ");
    // Create a loop to cycle through each char in the text string and convert it to the corresponding value from the key string
    for (int j = 0; text[j] != '\0'; j++)
    {
        text[j] = rotate(text[j], argv[1]);
    }
    printf("ciphertext: %s\n", text);
    return 0;
}

// Create a function to test if a string contains any repeated chars
bool is_discrete_alpha(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalpha(s[i]))
        {
            for (int j = (i + 1); s[j] != '\0'; j++)
            {
                char c = tolower(s[i]);
                char d = tolower(s[j]);
                if (c == d)
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Create a function that rotates a char by the given key
char rotate(char c, string s)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            int index = c - 'A';
            c = toupper(s[index]);
        }
        else if (islower(c))
        {
            int index = c - 'a';
            c = tolower(s[index]);
        }
    }
    return c;
}

// Error message function
int user_error(void)
{
    printf("Usage: ./substitution key\n");
    return 1;
}
