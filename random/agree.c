#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for input
    char c = get_char("Do you agree? Y/N: ");

    // Print response
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed\n");
    }
}
