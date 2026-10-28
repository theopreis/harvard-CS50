#include "cs50.h"
#include <stdio.h>

int main(void)
{
    int h = get_int("Height: ");
    while (true)
    {
        if (!(h >= 1 && h <= 8))
        {
            h = get_int("Height: ");
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (j < h - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int k = 0; k < h; k++)
        {
            if (k > i)
            {
                break;
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
