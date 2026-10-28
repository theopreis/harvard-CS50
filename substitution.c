#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string alpha = "abcdefghijklmnopqrstuvwxyz";

string cipher(string original, string key);

int main(int argc, string argv[])
{
    // check validity of key and return 1 if not valid
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    int char_counter = 0;
    for (int i = 0; i < 26; i++)
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("Key should be alphabetic.");
            return 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (alpha[i] == tolower(argv[1][j]))
            {
                char_counter++;
            }
        }
        if (char_counter != 1)
        {
            printf("Key must contain each letter exactly once.");
            return 1;
        }
        char_counter = 0;
    }

    // ask user for text and cipher it (maybe a ciper function?) and return 0
    string text = get_string("plaintext:  ");
    printf("ciphertext: %s\n", cipher(text, argv[1]));
    return 0;
}

string cipher(string original, string key)
{
    for (int i = 0; i < strlen(original); i++)
    {
        if (isalpha(original[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (tolower(original[i]) == alpha[j])
                {
                    if (islower(original[i]))
                    {
                        original[i] = tolower(key[j]);
                        break;
                    }
                    else
                    {
                        original[i] = toupper(key[j]);
                        break;
                    }
                }
            }
        }
    }
    return original;
}
