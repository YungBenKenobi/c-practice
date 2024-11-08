#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Text: "); // Take a string from the user and store as a variable
    // Initialise several variables to store needed values
    int words = 1;  // Starts at 1 to count first word
    int sentences = 0;
    int chars = 0;
    int letters = 0;
    while (text[chars] != '\0') // Loop through every char until the reaching the input strings terminating NUL byte
    {
        if (isalpha(text[chars]))   // Check if char is alphabetical
        {
            letters++; // Count each char that is alphabetical
        }
        if (isblank(text[chars]))   // Check if char is blank
        {
            words++; // Count space and add to words counter
        }
        if (text[chars] == '.' | text[chars] == '!' | text[chars] == '?')   // Check if char is sentence ending punctuation
        {
            sentences++; // Count each sentence
        }
        chars++; // Increment byte counter
    }
    float L = ((float) letters / (float) words) * 100;   // Calculate L
    float S = ((float) sentences / (float) words) * 100; // Calculate S
    float index = 0.0588 * L - 0.296 * S - 15.8;         // Calculate Coleman-Liau Index
    if (index < 1)  // Check if index value is below 1
    {
        printf("Before Grade 1\n"); // Print result
    }
    else if (index > 16)    // Otherwise, check if index value is above 16
    {
        printf("Grade 16+\n");  // Print Result
    }
    else    // In all other cases
    {
        printf("Grade %i\n", (int) round(index));   // Round index value to nearest whole number, cast to an integer and print result
    }
}
