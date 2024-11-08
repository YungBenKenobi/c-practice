


// Get rid of charChecker?


if (argc != 2 || strlen(argv[1]) != 26)
{
    return user_error();
}
for (int i = 0; argv[1][i] != '\0'; i++)
{
    if (!isalpha(argv[1][i]) || strchr(argv[1] + i + 1, argv[1][i]))
    {
        return user_error();
    }
}
