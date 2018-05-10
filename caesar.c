#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // argc must be 2, key must be given as main argument
    if (argc != 2)
    {
        printf("Error: key must be passed.\n");
        return true;
    }
    // key string to int
    int key = atoi(argv[1]);

    // get plaintext
    string ptext = get_string("Text to encode: ");
    // encode plaintext
    // equation: encoded_char = (text_char + key) % 26
    // note: this equation will only work for alphabetical indeces --> convert ascii to alphabetical
    for (int i = 0; i < strlen(ptext); i++)
    {
        // only change alphabetical characters
        if (isalpha(ptext[i]))
        {
            if (isupper(ptext[i]))
            {
                //code for uppercase
                int upper_index = ptext[i] - 65;
                ptext[i] = (upper_index + key) % 26;
                ptext[i] += 65;
            }
            else if (islower(ptext[i]))
            {
                //code for lowercase
                int lower_index = ptext[i] - 97;
                ptext[i] = (lower_index + key) % 26;
                ptext[i] += 97;
            }
        }

    }
    // print ciphertext
    printf("encoded text: %s\n", ptext);
}
