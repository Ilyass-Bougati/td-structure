#include <stdio.h>
#include <stdlib.h>

int Max2(int a, int b);
int Maxn(int *V, int n);

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

    int max = Maxn(T, n);
    printf("Max = %d\n", max);
}

int Max2(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

int Maxn(int *V, int n)
{
    if (n == 2)
    {
        return Max2(V[0], V[1]);
    }

    return Max2(Maxn(V, n - 1), V[n - 1]);
}