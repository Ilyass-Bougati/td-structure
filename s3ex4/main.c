#include <stdio.h>
#include <stdlib.h>

int somme_t(int *T, int n, int pre);
int somme(int *T, int n);


int main()
{
    // creating a table
    int *T, n, i;
    do {
        printf("Entrer la dimension : ");
        scanf("%d", &n);
    } while (n <= 1);

    T = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("T[%d] = ", i + 1);
        scanf("%d", T + i);
    }

    int sum = somme_t(T, n, 0);
    printf("S = %d\n", sum);
}

int somme(int *T, int n)
{
    if (n == 2)
    {
        return T[0] + T[1];
    }

    return T[n - 1] + somme(T, n -1);
}


int somme_t(int *T, int n, int pre)
{

    if (n == 0)
    {
        return pre;
    }

    return somme_t(T, n - 1, pre + T[n - 1]);
}