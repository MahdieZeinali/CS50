#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("h: ");
    }
    while (h < 1 || h > 8);

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
