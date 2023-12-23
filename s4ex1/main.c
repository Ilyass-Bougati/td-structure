#include <stdio.h>
#include <stdlib.h>

char *saisirchaine();
void AfficheV(char *T, int n);

int main()
{
    printf("Entrer chaine : ");
    char * ch = saisirchaine();
    AfficheV(ch, 0);
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

void AfficheV(char *T, int n)
{
    if (T[n] == '\0')
    {
        return;
    }

    printf("%c", T[n]);
    AfficheV(T, n + 1);
}