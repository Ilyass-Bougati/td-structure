#include <stdio.h>
#include <stdlib.h>

void sommat(double **M1, double **M2, double **S, int n, int m);
double **sommat2(double **M1, double **M2, int n, int m);
double **Matrix(int n, int m);
void printm(double **M, int n, int m);

int main()
{
    int n, m;
    double **M1, **M2, **S;

    do {
        printf("Entrer les valeurs de n et m : ");
        scanf("%d%d", &n, &m);
    } while (n <= 1 || m <= 1);

    // allocating memory to S
    int i, j;
    S = (double **) malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
    {
        S[i] = (double *) malloc(m * sizeof(double));
    }

    M1 = Matrix(n, m);
    M2 = Matrix(n, m);
    sommat(M1, M2, S, n, m);
    printm(S, n, m);
}

void sommat(double **M1, double **M2, double **S, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            S[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

double **sommat2(double **M1, double **M2, int n, int m)
{
    double ** S = Matrix(n, m);
    sommat(M1, M2, S, n, m);
    return S;
}

double **Matrix(int n, int m)
{
    int i, j;
    double **M = (double **) malloc(n * sizeof(double *));
    printf("Entrer les valeur de matrice\n");

    for (i = 0; i < n; i++)
    {
        M[i] = (double *) malloc(m * sizeof(double));
        for (j = 0; j < m; j++)
        {
            printf("M[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", M[i] + j);
        }
    }

    return M;
}

void printm(double **M, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%6.2lf", M[i][j]);
        }
        printf("\n");
    }
}