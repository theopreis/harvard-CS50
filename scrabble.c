#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores
    int points1 = compute_score(word1);
    int points2 = compute_score(word2);

    // Print the winner
    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points2 > points1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int points = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (islower(word[i]))
        {
            if (0 <= word[i] - 'a' && word[i] - 'a' <= 25)
            {
                points += POINTS[word[i] - 'a'];
            }
        }
        else if (isupper(word[i]))
        {
            if (0 <= word[i] - 'A' && word[i] - 'A' <= 25)
            {
                points += POINTS[word[i] - 'A'];
            }
        }
    }
    return points;
}
