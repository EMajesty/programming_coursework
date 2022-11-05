/*
 * A program which removes tab and space chars from a file
 */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c != 0x20 && c != 0x09) // If not space
        {
            putchar(c);
        }
    }
    return 0;
}