#include <cs50.h>
#include <stdio.h>

// int main(void)
// {
//     int a;
//     do
//     {
//         a = get_int("Enter a number: ");
//     }
//     while(a < 0);

//     if(a == 0)
//     {
//         printf("0!=1/n");
//     }
//     else
//     {
//         int final = 1;
//         for(int i = 1; i <= a; i++)
//         {
//             final = final * i;
//         }
//         printf("%i! = %i\n", a, final);
//     }
// }

int factorial(int p);

int main(void)
{
    int a;
    do
    {
        a = get_int("Enter a number: ");
    }
    while(a < 0);

    int x = factorial(a);
    printf("%i! = %i\n", a, x);
}

int factorial(int p)
{
    int final = 1;
    if(p == 0)
    {
        return 1;
    }
    else
    {
        for(int i = 1; i <= p; i++)
        {
            final = final * i;
        }
    }
    return final;
}
