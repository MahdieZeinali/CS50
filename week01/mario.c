#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int h;
    do
    {
        h = get_int("Enter a number between 1 and 8: ");
    }
    while(h < 1 || h > 8);

    for(int line = 1; line <= h; line++)
    {
        for(int space = 1; space <= h - line; space++)
        {
            printf(" ");
        }
        for(int block1 = 1; block1 <= line; block1++)
        {
            printf("#");
        }
        printf(" ");
        for(int block2 = 1; block2 <= line; block2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
