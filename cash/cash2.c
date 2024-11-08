// Calculate minimum number of U.S. coins required for a given amount of change
#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int total;
    do
    {
        total = get_int("Change Owed (in cents): ");
    }
    while (total < 0);

    // Calculate how many quarters you should give the customer
    int quarters = calculate_quarters(total);
    // Subtract the value of those quarters from cents
    total = total - (quarters * 25);

    // Calculate how many dimes you should give the customer
    int dimes = calculate_dimes(total);
    // Subtract the value of those dimes from remaining cents
    total = total - (dimes * 10);

    // Calculate how many nickels you should give the customer
    int nickels = calculate_nickels(total);
    // Subtract the value of those nickels from remaining cents
    total = total - (nickels * 5);

    // Calculate how many pennies you should give the customer
    int pennies = calculate_pennies(total);
    // Subtract the value of those pennies from remaining cents
    total = total - pennies;

    // Sum the number of quarters, dimes, nickels and pennies used
    int sum = (quarters + dimes + nickels + pennies);

    // Print that sum
    printf("%i\n", sum);
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give the customer
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give the customer
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculate how many nickels you should give the customer
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculate how many pennies you should give the customer
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
