#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// declare function
char encode(int n, string text, char key_char);

int main(int argc, string argv[])
{
    // make sure key is given
    if (argc != 2)
    {
        printf("Error: key must be passed.\n");
        return 1;
    }

    // get key
    string key = argv[1];

    // make sure key is alphabetical
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetical");
            return 1;
        }
    }

    //get plaintext
    string text = get_string("Text to encipher: ");

    // declare variables

    // position in plaintext
    int n = 0;
    // position in keytext
    int i = 0;
    // variable to track the current key value
    int key_char;

    // loop for encoding
    while (n < strlen(text))
    {

        int idx = i % strlen(key);

        if (isupper(key[idx]))
        {
            key_char = key[idx] - 65;
        }
        else if (islower(key[idx]))
        {
            key_char = key[idx] - 97;
        }

        if (isalpha(text[n]))
        {
            // call encode function
            encode(n, text, key_char);
            // only advance key index if text character was alphabetical
            i++;
        }
        // advance text index
        n++;

    }
    printf("encoded text: %s\n", text);
}

char encode(int n, string text, char key_char)
{

    if (isupper(text[n]))
    {
        //code for uppercase
        int upper_index = text[n] - 65;
        text[n] = (upper_index + key_char) % 26;
        text[n] += 65;
    }
    else if (islower(text[n]))
    {
        //code for lowercase
        int lower_index = text[n] - 97;
        text[n] = (lower_index + key_char) % 26;
        text[n] += 97;
    }

    return text[n];
}
