/*
 * A program which removes lines with only the new line character 
 */

#include <stdio.h>

int removeLine()
{
    int c;
    int lastchar;
    
    while ((c = getchar()) != EOF)
    {
        if (c == 0x0A && lastchar == 0x0A)
        {
        }
        else
        {
            putchar(c);
        }
        lastchar = c;
    }
}

int main()
{
    removeLine();
    return 0;
}