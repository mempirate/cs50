#include <stdio.h>
#include <cs50.h>

// coins available: 25, 10, 5, 1

int main(void)
{
    float owed;
    int n = 0;
    do
    {
    owed = get_float("Change: ");
    }
    while (owed < 0);
    owed *= 100;

    while (owed >= 25)
    {
        owed -= 25;
        n++;
    }
    while (owed >= 10)
    {
        owed -= 10;
        n++;
    }
    while (owed >= 5)
    {
        owed -= 5;
        n++;
    }
    while (owed >= 1)
    {
        owed -= 1;
        n++;
    }
    printf("Amount of coins used: %i\n", n);
}
