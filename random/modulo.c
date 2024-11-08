#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long target;
    int modulo;
    do
    {
        target = get_long("Target: ");
        modulo = get_int("Modulo: ");
    }
    while (target < 1 && modulo > 1);

    int result = target % modulo;
    printf("Result: %i\n", result);
}
