#include <cs50.h>
#include <stdio.h>

int counter(int i);

int main(void)
{
    int i = 0;
    do
    {

    }
    while(i < 100);
    counter(i);
}

void counter(int n)
{
    for (i = n, i > 0, i--)
    {
        printf("%i\n", i);
    }
}
