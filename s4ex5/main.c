#include <stdio.h>
#include <stdlib.h>

char * saisirchar();

int main()
{
    char * ch = saisirchar();
    puts(ch);
}

char * saisirchar()
{
    char *CH, c;
    int i = 0;

    CH = (char *) malloc(sizeof(char));

    while ((c = getchar()) != '\n')
    {
        CH[i++] = c;
        CH = (char *) realloc(CH, (i + 1) * sizeof(char));
    }
    CH[i] = '\0';

    return CH;
}