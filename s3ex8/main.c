#include <stdio.h>
#include <stdlib.h>

float puis(float x, int n);
float CalculPolynome(float x, float *A, int n);

int main()
{
    float *T, x;
    int n, i;

    do {
        printf("Entrer le degree de la polynome : ");
        scanf("%d", &n);
    } while (n <= 1);
    n++;

    T = (float *) malloc(n * sizeof(float));
    for (i = 0; i < n; i++)
    {
        printf("T[%d] = ", i);
        scanf("%f", T + i);
    }

    printf("Entrer le point : ");
    scanf("%f", &x);

    printf("P(%.2f) = %.2f\n", x, CalculPolynome(x, T, n));
}

float puis(float x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return x * puis(x, n - 1);
}

float CalculPolynome(float x, float *A, int n)
{
    float res = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        res += A[i]*puis(x, i);
    }

    return res;
}
