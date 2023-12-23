#include <stdio.h>
#include <stdlib.h>

char *saisirchaine();
void supchar(char *CH, char c);

int main()
{
    printf("Entrer chaine : ");
    char * ch = saisirchaine();
    char c = getchar();
    supchar(ch, c);
    puts(ch);
}

char *saisirchaine()
{
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


void supchar(char *CH, char c)
{
    int i, j = 0;
    char temp;

    for (i = 0; CH[i] != '\0'; i++)
    {
        CH[j] = CH[i];
        if (CH[i] != c)
        {
            j++;
        }
    }
    CH[j] = '\0';

    for (i = j; CH[i] != '\0'; i++)
    {
        free(CH + i);
    }
}
