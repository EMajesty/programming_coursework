// callback-example.c

#include <stdio.h>

// limit count to
#define LIMIT 1000000000

void LenghtyTask(void (*pInform)(int))
{
    int i;
    int last_percentage = 0;
    for (i = 0; i < LIMIT; i++)
    {
        int percentage = i / (LIMIT / 100);

        if (last_percentage != percentage &&
            (percentage % 5) == 0)
        {
            // inform should be called
            (*pInform)(percentage);
            last_percentage = percentage;
        }
    }
}

void Inform(int percentage)
{
    printf("Progress: %d\n", percentage);
}

int main(int argc, char *argv[])
{
    printf("Starting LenghtyTask...");
    LenghtyTask(Inform);
    printf("Done\n");
}