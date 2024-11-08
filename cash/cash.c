// Calculate minimum number of U.S. coins required for a given amount of change
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;

    // Get amount owed from user
    do
    {
        cents = get_int("Change Owed (in cents): ");
    }
    while (cents < 0);

    // Calculate how many quarters you should give the customer
    if (cents >= 25)
    {
        quarters = cents / 25;
        // Recalculate cents total
        cents = cents % 25;
    }

    // Calculate how many dimes you should give the customer
    if (cents >= 10)
    {
        dimes = cents / 10;
        // Recalculate cents total
        cents = cents % 10;
    }

    // Calculate how many nickels you should give the customer
    if (cents >= 5)
    {
        nickels = cents / 5;
        // Recalculate cents total
        cents = cents % 5;
    }

    // Calculate total coins and print result
    int change = quarters + dimes + nickels + cents;
    printf("%i\n", change);
}
