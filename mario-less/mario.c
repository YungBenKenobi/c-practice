// Print a right-ascending pyramid of #s with height based on user input
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variables
    int size = 0;
    int i = 1;
    // Get size of pyramid
    while (size < 1 || size > 8)
    {
        size = get_int("Size: ");
    }
    // Do the rest of the shit
    for (int a = size; a > 0; a--) // Loop until full height is printed
    {
        //Print spaces
        for (int b = size; b > i; b--)
        {
            printf(" ");
        }
        // Print #s
        for (int c = i; c > 0; c--)
        {
            printf("#");
        }
        i++;
        printf("\n");
    }
}
