// Print a right-ascending pyramid of #s with height based on user input, while also printing
// a left-ascending pyramid of the same height 2 spaces to the left.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variables
    int size = 0;
    int x = 1;
    // Get size of pyramid
    while (size < 1 || size > 8)
    {
        size = get_int("Size: ");
    }
    // Do the rest of the shit
    for (int a = size; a > 0; a--)
    {
        for (int b = size; b > x; b--)
        {
            printf(" ");
        }
        for (int c = x; c > 0; c--)
        {
            printf("#");
        }
        printf("  ");
        for (int d = x; d > 0; d--)
        {
            printf("#");
        }

        x++;
        printf("\n");
    }
}
