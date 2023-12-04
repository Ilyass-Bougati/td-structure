#include <stdio.h>
#include <stdlib.h>

int * tableau(int n);
int partition(int *T, int deb, int fin);
void tri_rapide(int *T, int deb, int fin);
void permut(int *a, int *b);
void printt(int *T, int n);
void fusion(int *T, int deb, int fin);
void tri_fusion(int *T, int deb, int fin);

int main()
{
    int *T, n;

    do {
        printf("Entrer la valeur de n : ");
        scanf("%d", &n);
    } while (n <= 1);

    T = tableau(n);
    tri_fusion(T, 0, n - 1);
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


void fusion(int *T, int deb, int fin)
{
    int *G = (int *) malloc((fin - deb + 1) * sizeof(int));
    int mid = (fin + deb)/2;
    int i = deb;
    int j = mid + 1;
    int k;

    for (k = 0; k <= fin - deb; k++)
    {
        if ((T[i] < T[j] && i <= mid) || j > fin)
        {
            G[k] = T[i++];
        } else {
            G[k] = T[j++];
        }
    }

    for (k = 0; k <= fin - deb; k++)
    {
        T[deb + k] = G[k];
    }

    free(G);
}


void tri_fusion(int *T, int deb, int fin)
{
    int mid;
    if (deb < fin)
    {
        mid = (deb + fin)/2;
        tri_fusion(T, deb, mid);
        tri_fusion(T, mid + 1, fin);
        fusion(T, deb, fin);
    }
}
