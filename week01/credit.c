#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Enter your card number: ");

    int digitsCount = 0;
    long numCopy1 = num;
    while (numCopy1 >= 1)
    {
        numCopy1 = numCopy1 / 10;
        digitsCount++;
    }

    int sum = 0;
    int odd;
    int even;
    int r1;
    int r2;
    long numCopy2 = num;

    do
    {
        odd = numCopy2 % 10;
        numCopy2 = numCopy2 / 10;
        sum += odd;

        even = (numCopy2 % 10) * 2;
        numCopy2 = numCopy2 / 10;

        if (even > 9)
        {
            r1 = even % 10;
            r2 = 1;
            sum = sum + r1 + r2;
        }
        else
        {
            sum = sum + even;
        }
    }
    while (numCopy2 != 0);

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    if (digitsCount == 15)
    {
        long firstDigits = num / 10000000000000;
        if (firstDigits == 34 || firstDigits == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digitsCount == 13)
    {
        long firstDigit = num / 1000000000000;
        if (firstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        long firstDigits = num / 100000000000000;
        if (firstDigits == 51 || firstDigits == 52 || firstDigits == 53 || firstDigits == 54 || firstDigits == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (firstDigits / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}