#include "cs50.h"
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");
    long leftover = num;
    int n_digits = 0;
    int sum = 0;
    while (leftover != 0)
    {
        leftover = leftover / 10;
        n_digits++;
    }
    leftover = num;
    for (int i = n_digits - 2; i > 0; i--)
    {
        leftover /= 10;
    }
    int first_digits = leftover;
    if (num < 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (first_digits / 10 == 4)
        {
            first_digits = 4;
        }
        int digit, digit_2;
        leftover = num;
        for (int i = 1; i <= n_digits; i++)
        {
            digit = leftover % 10;
            leftover /= 10;
            if (i % 2 == 0)
            {
                digit *= 2;
            }
            if (digit >= 10)
            {
                digit_2 = digit % 10;
                sum += digit_2 + 1;
            }
            else
            {
                sum += digit;
            }
        }
        if (sum % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {
            if ((first_digits == 34 || first_digits == 37) && n_digits == 15)
            {
                printf("AMEX\n");
            }
            else if (first_digits == 4 && (n_digits == 13 || n_digits == 16))
            {
                printf("VISA\n");
            }
            else if (n_digits == 16 &&
                     (first_digits == 51 || first_digits == 52 || first_digits == 53 ||
                      first_digits == 54 || first_digits == 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
