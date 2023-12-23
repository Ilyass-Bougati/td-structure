#include <stdio.h>
#include <stdlib.h>


void printt(int *T, int n);
int suppTab(int *V, int n, int x);

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

    suppTab(T, n, 2);
    printt(T, n);


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

int suppTab(int *V, int n, int x)
{
    int i, j = 0, temp;

    for (i = 0; i < n; i++)
    {
        V[j] = V[i];
        if (V[i] != x)
        {
            j++;
        }
    }

    // give a segmentation fault
    // for (i = j; i < n; i++)
    // {
    //     free(V + i);
    // }
}