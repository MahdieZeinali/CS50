#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int first = get_int("Enter first number: ");
    int second = get_int("Enter second number: ");
    if (first > second)
    {
        printf("%i is larger than %i.\n", first, second);
    }
    else if (second > first)
    {
        printf("%i is larger than %i.\n", second, first);
    }
    else
    {
        printf("Equal!\n");
    }
}