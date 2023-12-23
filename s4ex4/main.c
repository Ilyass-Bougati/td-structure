#include <stdio.h>
#include <stdlib.h>

char *saisirchaine(char * aff);
void enMajuscules(char *CH);

int main()
{
    char * input = saisirchaine("Saisir une chaine : ");
    enMajuscules(input);
    puts(input);
}

char *saisirchaine(char * aff)
{
    printf("%s", aff);

    char *ch;
    char temp;
    int i = 0;
    ch = (char *) malloc(30 * sizeof(char));

    while ((temp = getchar()) != '\n')
    {
        ch[i++] = temp;
    }

    ch[i] = '\0';
    return ch;
}

void enMajuscules(char *CH)
{
    int i;
    for (i = 0; CH[i] != '\0'; i++)
    {
        if (CH[i] <= 'z' && CH[i] >= 'a')
        {
            CH[i] += 'A' - 'a';
        }
    }
}