#include <cs50.h>
#include <stdio.h>

int sum(int x, int y);
int dif(int x, int y);
int prod(int x, int y);
int quot(int x, int y);

int main(void)
{
    printf("\n\n**INTEGER CALCULATOR**\n\n");
    int a = get_int("First Integer: ");
    int b = get_int("Second Integer: ");
}

int sum(int x, int y)
{
    return x + y;
}

int dif(int x, int y)
{
    return x - y;
}

int prod(int x, int y)
{
    return x * y;
}

int quot(int x, int y)
{
    return x / y;
}
