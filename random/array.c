#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int letterScores[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    for (int i = 0; i < 26; i ++)
    {
        printf("%c = ", alphabet[i]);
        printf("%i, ", letterScores[i]);
    }
    printf("\n");
}
