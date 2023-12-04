#include <stdio.h>
#include <stdlib.h>

void printt(int *T, int n);
void InsertTab(int *T, int n, int x, int e);

int main()
{
    int *T, n, i;

    do {
        printf("Entrer la taille de tableau : ");
        scanf("%d", &n);
    } while (n <= 1);

    T = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("T[%d] = ", i + 1);
        scanf("%d", T + i);
    }

    InsertTab(T, n, 12, 2);
    printt(T, n + 1);

}


void printt(int *T, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%6d", T[i]);
    }
    printf("\n");
}



// the worst code I've ever written
void InsertTab(int *T, int n, int x, int e)
{

    int i, j = 0;
    int *G = (int *) malloc((n + 1) * sizeof(int));

    for (i = 0; i <= n; i++)
    {
        if (i == e)
        {
            G[i] = x;
        } else {
            G[i] = T[j++];
        }
    }

    for (i = 0; i <= n; i++)
    {
        T[i] = G[i];
    }

}