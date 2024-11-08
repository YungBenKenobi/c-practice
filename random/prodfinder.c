// Product finder function testbed for credit.c project - week 1 CS50x
#include <cs50.h>
#include <stdio.h>

int prodfinder(int x);

int main(void)
{
    int target = get_int("Int: ");
    // Find product of target * 2, and if its over 9 separate the integers and sum them together
    target = prodfinder(target);
    printf("%i\n", target);
}

int prodfinder(int x)
{
    x = x * 2;
    if (x > 9)
    {
        // Modulo 10 to find ones place integer (could also just subtract 10 but is less robust)
        x = x % 10;
        // Add one to simulate the tens place integer (lazy but products will never be more than 18)
        x++;
    }
    return x;
}

// Seems to work as intended
