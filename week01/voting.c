#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char answer = get_char("do you agree?\n");

    if(answer == 'y' || answer == 'Y')
    {
        printf("Agreed!\n");
    }
    else if(answer == 'n' || answer == 'N')
    {
        printf("Disagreed!\n");
    }
    else
    {
        printf("invalid input!\n");
    }
}