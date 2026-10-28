#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int coleman(int l, int w, int s);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    int letters = 0, words = 1, sentences = 0;

    // Count the number of letters, words, and sentences in the text
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Compute the Coleman-Liau index
    int index = coleman(letters, words, sentences);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int coleman(int l, int w, int s)
{
    float L = (float) l / w * 100;
    float S = (float) s / w * 100;
    float coleman_index = 0.0588 * L - 0.296 * S - 15.8;
    return round(coleman_index);
}
