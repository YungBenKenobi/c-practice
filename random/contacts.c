// Stores and prints out a user's contact information (name, age, phone number)
#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("\n\n*Enter Contact Information*\n");
    string firstname = get_string("First Name?\n");
    string lastname = get_string("Last Name?\n");
    int age = get_int("Age?\n");
    string phonenumber = get_string("Phone Number?\n");
    printf("Name: %s %s\nAge: %i\nNumber: %s\n", firstname, lastname, age, phonenumber);
}

