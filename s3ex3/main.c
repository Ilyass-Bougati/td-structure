#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b);
int Fmax(int *V, int deb, int fin);

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

    int max = Fmax(T, 0, n);
    printf("max = %d\n", max);
}

int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

int Fmax(int *V, int deb, int fin)
{
    int mid;
    
    if (deb == fin)
    {
        return V[deb];
    }
    
    mid = (deb + fin) - 1;

    return Max(Fmax(V, deb, mid), Fmax(V, mid + 1, fin));
    
}