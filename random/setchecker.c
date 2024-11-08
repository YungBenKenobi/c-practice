#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool is_unique_chars(string s);

int main(void)
{
    string input = get_string("Input String: ");
    if (is_unique_chars(input))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


bool is_unique_chars(string s)
{
    for(int i = 0; input[i] != '\0'; i++)
    {
        for (int j = (i + 1); input[j] != '\0'; j++)
        {
            char c = tolower(s[i]);
            char d = tolower(s[j]);
            if (c == d)
            {
                return false;
            }
        }
    }
    return true;
}
