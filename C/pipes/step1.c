/* 
 * A program which calculates the number of chars, white spaces, words and lines
 * from stdin.
 * 
 * Word: alphabetic characters separated by non-alphabetic characters.
 */

#include <stdio.h>

int calc()
{
    int c;
    int lastchar = 0;

    int words = 0;
    int chars = 0;
    int lines = 0;
    int space = 0;

    while ((c = getchar()) != EOF)
    {
        // Check if last character was alphabetic
        if (lastchar >= 0x41 && lastchar <= 0x5A || lastchar >= 0x61 && lastchar <= 0x7A)
        {
            // Check if current character is not alphabetic
            if (c >= 0x00 && c <= 0x40 || c >= 0x5B && c <= 0x60 || c >= 0x7B && c <= 0x7F)
            {
                words++;
            }
        }

        lastchar = c;

        if ((c >= 0x33 && c <= 0x7E)) // Chars
        {
            chars++;
        }
        else if (c == 0x20 || c == 0x09) // Whitespace
        {
            space++;
        }
        else if (c == 0x0A) // Rows
        {
            lines++;
        }
    }
    
    printf("Chars: %d\n", chars);
    printf("Whitespace: %d\n", space);
    printf("Lines: %d\n", lines + 1);
    printf("Words %d\n\n", words);
}

int main()
{
    calc();
    return 0;
}