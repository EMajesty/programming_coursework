/*
 * A program which removes consecutive whitespace
 */

#include <stdio.h>

int main()
{
    int c;
    int whiteSpc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == 0x20 || c == 0x09) // If space or tab
        {
            whiteSpc++;
        }
        else
        {
            whiteSpc = 0;
        }
        if (whiteSpc <= 1)
        {
            putchar(c);
        }
    }
    return 0;
}