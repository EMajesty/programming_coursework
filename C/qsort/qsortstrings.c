#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpAlpha(const void *one, const void *two)
{
    const char **iOne = (const char **)one;
    const char **iTwo = (const char **)two;
    return strcmp(*iOne, *iTwo);
}

int cmpLength(const void *one, const void *two) {
    const char *iOne = *(const char * const *)one;
    const char *iTwo = *(const char * const *)two;
    size_t len1 = strlen(iOne);
    size_t len2 = strlen(iTwo);
    if (len1 > len2)
        return +1;
    if (len2 > len1)
        return -1;
    return strcmp(iOne, iTwo);
}

int main(void)
{
    FILE *us;
    FILE *qs;
    FILE *qsl;

    int count, number;
    char *randomWord[1000];

    us = fopen("unsorted.txt", "w");
    qs = fopen("sorted.txt", "w");
    qsl = fopen("sortedL.txt", "w");

    // Print 1000 strings 5..30 chars in length
    for (count = 0; count < 1000; count++)
    {
        int wordLength = (rand() % (30 - 5 + 1)) + 5; // Get random length between 5..30
        randomWord[count] = malloc(wordLength + 1);

        for (number = 0; number < wordLength; number++)
        {
            randomWord[count][number] = 'A' + rand() % 26;
        }

        randomWord[count][number] = '\0';
        fprintf(us, "%s\n", randomWord[count]);
    }

    qsort(randomWord, 1000, sizeof(char *), cmpAlpha); // Sort alphabetically

    for (count = 0; count < 1000; count++)
    {
        fprintf(qs, "%s\n", randomWord[count]);
    }



    qsort(randomWord, 1000, sizeof(char *), cmpLength); // Sort by length

    for (count = 0; count < 1000; count++)
    {
        fprintf(qsl, "%s\n", randomWord[count]);
    }

    fclose(us);
    fclose(qs);
    fclose(qsl);
    return 0;
}