#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool digitChecker(string input);
char rotate(char c, int n);

int main(int argc,
         string argv[]) // Take a positive integer up to (2^31 - 26) as a command-line argument
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        bool test = digitChecker(argv[1]);
        if (test != true)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            int key = atoi(argv[1]);
            key = key % 26;
            string inputText = get_string("plaintext: ");
            printf("ciphertext: ");
            int i = 0;
            while (inputText[i] != '\0')
            {
                printf("%c", rotate(inputText[i], key));
                i++;
            }
            printf("\n");
        }
    }
}

char rotate(char c, int n) // Create a function that rotates a char by the given key
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = c - 'A';
            c = (c + (n % 26)); // Can I make just this part a separate function?
            if (c >= 26)
            {
                c = (c - 26);
            }                   //
            c = c + 'A';
        }
        else if (islower(c))
        {
            c = c - 'a';
            c = (c + (n % 26));
            if (c >= 26)
            {
                c = (c - 26);
            }
            c = c + 'a';
        }
    }
    return c;
}

bool digitChecker(string input) // Create a function that checks if the input string is only digits
{
    int c = strlen(input);
    for (int i = 0; i < c; i++) // Loop through each char in string
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}
