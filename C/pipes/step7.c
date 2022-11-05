/*
 * This program removes C-style block comments
 */

#include <stdio.h>

int main()
{
    int c;
    int fComment = 0;
    int lastChar = 0;
    int printBuf = 0;
    int endCounter = 0;

    while ((c = getchar()) != EOF)
    {
        if (endCounter > 0)
        {
            endCounter--;
        }

        if (c == '/')
        {
            if (lastChar == '*')
            {
                fComment--;
                endCounter = 3;
            }
        }

        if (c == '*')
        {
            if (lastChar == '/')
            {
                fComment++;
            }
        }

        if (fComment == 0 && endCounter == 0)
        {
            putchar(printBuf);
        }
        printBuf = lastChar; // Use a buffer to delay the print by one character
        lastChar = c;
    }
    return 0;
}