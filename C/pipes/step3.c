/*
 * A program which removes trailing whitespace
 */

#include <stdio.h>
#include <string.h>

#define MAX_STR 1000

int main()
{
    char str[MAX_STR]; // The array to hold a line of input

    int i;

    while (fgets(str, MAX_STR, stdin) != NULL)
    {
        i = strlen(str) - 1; // Start index from the end of the string

        while (i > -1)
        {
            if (str[i] == 0x09 || str[i] == 0x20 || str[i] == 0x0A) // If tab, space or newline is encountered
            {
                i--;
            }
            else
            {
                break;
            }
        }

        str[i + 1] = 0x00; // Null after

        printf("%s\n", str);
    }

    return 0;
}