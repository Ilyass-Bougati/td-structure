#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    int val;
    struct noeud *gauche;
    struct noeud *droit;
} noeud;
typedef noeud* arbre;

arbre nouvelArbre(int val, arbre fd, arbre fg);
arbre insertionABR(int v, arbre A);
arbre insertiontab(int *T, arbre A, int n);
void ParcoursArb(arbre A);
void rechercheArbre(arbre A, int x);

int main()
{
    int T[11] = {30,14,8,15,16,18,17,32,40,34,42};
    arbre a = insertiontab(T, NULL, 11);
    rechercheArbre(a, 17);
}

arbre nouvelArbre(int val, arbre fd, arbre fg)
{
    arbre a = (arbre) malloc(sizeof(noeud));
    a->droit  = fd;
    a->gauche = fg;
    a->val    = val;

    return a;
}

arbre insertionABR(int v, arbre A)
{
    if (A == NULL)
    {
        A = nouvelArbre(v, NULL, NULL);
    } else if (v < A->val)
    {
        A->gauche = insertionABR(v, A->gauche);
    } else {
        A->droit  = insertionABR(v, A->droit);
    }

    return A;
}

arbre insertiontab(int *T, arbre A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        A = insertionABR(T[i], A);
    }

    return A;
}

void ParcoursArb(arbre A)
{
    if (A != NULL)
    {
        ParcoursArb(A->gauche);
        printf("%d  ", A->val);
        ParcoursArb(A->droit);
    }
}

void rechercheArbre(arbre A, int x)
{
    if (A->val == x)
    {
        printf("%d", x);
    } else if (x < A->val)
    {
        printf("%d->", A->val);
        rechercheArbre(A->gauche, x);
    } else
    {
        printf("%d->", A->val);
        rechercheArbre(A->droit, x);
    }
}