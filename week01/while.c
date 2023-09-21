#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    int yes = 0;
    int no = 0;
    while(i < 5)
    {
        char answer = get_char("Do you agree?\n");
        if(answer == 'y' || answer == 'Y')
        {
            yes = yes + 1;
            // yes += 1
            // yes++
        }
        else if(answer == 'n' || answer == 'N')
        {
            no = no + 1;
        }
        else
        {
            printf("invalid input!/n");
        }

        i = i + 1;
    }
    printf("Agreed: %i and Disagreed: %i.\n", yes, no);
}