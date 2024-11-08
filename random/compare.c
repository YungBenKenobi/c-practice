#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for two integers
    int x = get_int("what is x? ");
    int y = get_int("what is y? ");

    // Compare integers and print conclusion
    if (x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x < y)
    {
        printf("x is less than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
