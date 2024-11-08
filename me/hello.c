#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts the user for their name and then says hello
    string answer = get_string("what's your name? \n");
    printf("hello, %s\n", answer);
}
