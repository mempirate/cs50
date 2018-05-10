#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramid_height;
    do
    {
        pyramid_height = get_int("Height: ");
    } while (pyramid_height <= 0 || pyramid_height > 23);

    // Outer loop handles count of rows
    for (int i = 0; i < pyramid_height; i++)
    {
        // inner loops handle the columns (spaces and pounds)
        // Print spaces
        for (int j = 0; j < pyramid_height - i - 1; j++)
        {
            printf("%s", " ");
        }
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
