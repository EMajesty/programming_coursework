/*
 * A program which removes one line comments starting with '//'
 */

#include <stdio.h>
#include <string.h>

#define MAX_STR 1000

int main()
{
    char str[MAX_STR]; // The array to hold a line of input

    while (fgets(str, MAX_STR, stdin) != NULL)
    {
        int slash = 0; // How many slashes in a row

        for (size_t i = 0; i < strlen(str); i++)
        {
            if (str[i] == '/')
            {
                slash++;
            }
            if (slash == 2)
            {
                str[i - 1] = 0x0A; // Newline at first '/'
                str[i] = 0x00;     // Null at second '/'
            }
        }
        printf("%s", str);
    }
    return 0;
}