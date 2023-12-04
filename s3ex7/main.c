#include <stdio.h>

double epsilon = 0.0001;

double abso(double x);
double Racine_carre(double x);
double Racine_n(double x, int n);

int main()
{
    double n;
    printf("Entrer un nombre : ");
    scanf("%lf", &n);

    printf("%lf\n", Racine_carre(n));
}

double abso(double x)
{
    if (x < 0)
    {
        return -x;
    }

    return x;
}

double Racine_carre(double x)
{
    double sqr = 1;
    while (abso(sqr*sqr - x) >= epsilon)
    {
        sqr = (sqr + x/sqr)/2;
    }

    return sqr;
}

double Racine_n(double x, int n)
{
    if (n == 0)
    {
        return x;
    }

    return Racine_n(Racine_carre(x), n - 1);
}