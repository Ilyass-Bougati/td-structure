#include <stdio.h>
#include <stdlib.h>

int **Matrice(int n, int m);
int **ProdMat(int **A, int **B, int n, int m);
void printm(int **M, int n, int m);

int main()
{
    int n, m, l;
    int **A, **B, **P;

    do {
        printf("Entrer les valeurs de n, m et l : ");
        scanf("%d%d%d", &n, &m, &l);
    } while (n <= 1 || m <= 1 || l <= 1);

    A = Matrice(n, m);
    B = Matrice(m, l);
    P = ProdMat(A, B, n, m);

    printm(P, n, l);

}


int **Matrice(int n, int m)
{
    int i, j;
    int **M = (int **) malloc(n * sizeof(int *));
    printf("Entrer les valeur de matrice\n");

    for (i = 0; i < n; i++)
    {
        M[i] = (int *) malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            printf("M[%d][%d] = ", i + 1, j + 1);
            scanf("%d", M[i] + j);
        }
    }

    return M;
}


int **ProdMat(int **A, int **B, int n, int m)
{
    int i, j, k;
    int **P = (int **) malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        P[i] = (int *) malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            P[i][j] = 0;
            for (k = 0; k < m; k++)
            {
                P[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return P;
}

void printm(int **M, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%6d", M[i][j]);
        }
        printf("\n");
    }
}