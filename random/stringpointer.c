#include<stdio.h>

int main()
{
    char str[6] = "Hello";
    int i;

    //printing each char value
    for(i = 0; str[i]; i++)
         printf("str[%d] = %p\n",i,(str+i)); //str[i] == *(str+i)

    return 0;
}
