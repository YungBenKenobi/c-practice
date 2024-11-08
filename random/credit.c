#include <cs50.h>
#include <stdio.h>

int placefinder(long x)
{
    x = cc % 10;
    return x;
}


if (cc > 9)
    {

    }


int prodfinder(int x);

int main(void)
{
    // Take card number (cc) from user
    long cc = get_long("Card Number: ");

    // Initialise counter = 0
    int counter = 0;

    // Find digit values and places
    int a = cc % 10; // cc % 10 to find last digit and save to int
    cc = cc / 10;    // cc / 10 to reduce by order of magnitude
    counter++;       // Digit counter ++
    int b = cc % 10;
    cc = cc / 10;
    counter++;
    int c = cc % 10;
    cc = cc / 10;
    counter++;
    int d = cc % 10;
    cc = cc / 10;
    counter++;
    int e = cc % 10;
    cc = cc / 10;
    counter++;
    int f = cc % 10;
    cc = cc / 10;
    counter++;
    int g = cc % 10;
    cc = cc / 10;
    counter++;
    int h = cc % 10;
    cc = cc / 10;
    counter++;
    int i = cc % 10;
    cc = cc / 10;
    counter++;
    int j = cc % 10;
    cc = cc / 10;
    counter++;
    int k = cc % 10;
    cc = cc / 10;
    counter++;
    int l = cc % 10;
    cc = cc / 10;
    counter++;
    int m = cc % 10;
    cc = cc / 10;
    counter++;
    int n = 0;
    int o = 0;
    int p = 0;
    if (cc > 9)
    {
        n = cc % 10;
        cc = cc / 10;
        counter++;
        if (cc > 9)
        {
            o = cc % 10;
            cc = cc / 10;
            counter++;
            if (cc > 0)
            {
                p = cc;
                counter++;
                cc = 0;
            }
        }
        else if (cc < 10 && cc > 0)
        {
            o = cc;
            counter++;
            cc = 0;
        }
    }
    else if (cc > 0)
    {
        n = cc;
        counter++;
        cc = 0;
    }
    // Multiply each second digit by 2. Split product integers and add together if necessary
    int prodb = prodfinder(b);
    int prodd = prodfinder(d);
    int prodf = prodfinder(f);
    int prodh = prodfinder(h);
    int prodj = prodfinder(j);
    int prodl = prodfinder(l);
    int prodn = prodfinder(n);
    int prodp = prodfinder(p);
    int sum = a + prodb + c + prodd + e + prodf + g + prodh + i + prodj + k + prodl + m + prodn +
              o + prodp;    // Sum all results together
    int modulus = sum % 10; // Find modulo 10
    if (modulus == 0)
    {
        if (counter == 13 && m == 4)
        {
            printf("VISA\n");
        }
        else if (counter == 16 && p == 4)
        {
            printf("VISA\n");
        }
        else if (counter == 15 && o == 3)
        {
            if (n == 4 || n == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (counter == 16 && p == 5)
        {
            if (o == 1 || o == 2 || o == 3 || o == 4 || o == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int prodfinder(int x)
{
    x = x * 2;
    if (x > 9)
    {
        // Modulo 10 to find ones place integer (could also just subtract 10 but that's lazy)
        x = x % 10;
        // Add one to simulate the tens place integer (lazy but products will never be more than 18)
        x++;
    }
    return x;
}


