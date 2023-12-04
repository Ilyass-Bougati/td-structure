#include <stdio.h>
#include <stdlib.h>

float *sommepoly(float *A, float *B, int n, int m);
float *produitpoly(float *A, float *B, int n, int m);
void printt(float *T, int n);
float min(float a, float b);
float max(float a, float b);


int main()
{
    float *A, *B;
    int n, m, i;

    do {
    printf("Entrer n, m : ");
    scanf("%d%d", &n, &m);
    } while (n < 1 || m < 1);
    n++;
    m++;

    A = (float *) malloc(n * sizeof(float));
    B = (float *) malloc(m * sizeof(float));

    printf("Entrer les coefficients de A\n");
    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%f", A + i);
    }

    printf("\nEntrer les coefficients de A\n");
    for (i = 0; i < m; i++)
    {
        printf("B[%d] = ", i);
        scanf("%f", B + i);
    }

    float *S = produitpoly(A, B, n, m);

    printt(S, n + m - 1);
}


float *sommepoly(float *A, float *B, int n, int m)
{
    float *S, l, k;
    int i;
    k = max(n, m);
    S = (float *) malloc(k * sizeof(float));

    for (i = 0; i < k; i++)
    {
        S[i] = 0;
        if (i < n)
        {
            S[i] += A[i];
        }

        if (i < m)
        {
            S[i] += B[i];
        }
    }

    return S;
}


float *produitpoly(float *A, float *B, int n, int m)
{
    float *P;
    int i, j;

    P = (float *) malloc((n + m - 1) * sizeof(float));

    for (i = 0; i < n + m; i++)
    {
        P[i] = 0;
        for (j = 0; j <= i; j++)
        {
            P[i] += A[j] * B[i - j];
        }
    }

    return P;

}


float min(float a, float b)
{
    if (a < b)
    {
        return a;
    }

    return b;
}

float max(float a, float b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

void printt(float *T, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%6.2f", T[i]);
    }
    printf("\n");
}