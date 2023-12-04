#include <stdio.h>
#include <stdlib.h>

int * tableau(int n);
int partition(int *T, int deb, int fin);
void tri_rapide(int *T, int deb, int fin);
void permut(int *a, int *b);
void printt(int *T, int n);

int main()
{
    int *T, n;

    do {
        printf("Entrer la valeur de n : ");
        scanf("%d", &n);
    } while (n <= 1);

    T = tableau(n);
    tri_rapide(T, 0, n);
    printt(T, n);

}

int * tableau(int n)
{
    int i;
    int *T = (int *) malloc(n * sizeof(n));

    for (i = 0; i < n; i++)
    {
        printf("T[%d] = ", i);
        scanf("%d", T + i);
    }

    return T;
}

int partition(int *T, int deb, int fin)
{
    int j = deb, i;
    
    for (i = deb + 1; i < fin; i++)
    {
        if (T[i] < T[deb])
        {
            j++;
            permut(T + i, T + j);
        }
    }

    permut(T + j, T + deb);
    return j;
}

void permut(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tri_rapide(int *T, int deb, int fin)
{
    int pv;
    if (deb < fin)
    {
        pv = partition(T, deb, fin);
        tri_rapide(T, deb, pv - 1);
        tri_rapide(T, pv + 1, fin);
    }
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