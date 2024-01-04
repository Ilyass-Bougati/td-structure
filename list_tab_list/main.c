#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct insert_Note str;
struct insert_Note
{
    str *Next;
    float N;
    str *Last;
};

typedef struct Liste liste;
struct Liste
{
    str *Deb;
    str *p;
    str *Fin;
};

typedef struct Table_de_Liste tablist;
struct Table_de_Liste
{
    liste **table;
    tablist *Next, *Last;
};


typedef struct insert_tablist strtablist;
struct insert_tablist
{
    strtablist *Next;
    tablist *TL;
    strtablist *Last;
};

typedef struct ListeTableListe listtablist;
struct ListeTableListe
{
    strtablist *Deb;
    strtablist *p;
    strtablist *Fin;
};


liste *inialiser()
{
    liste *l;
    l = (liste *) malloc(sizeof(liste));
    l->Deb = NULL;
    l->Fin = NULL;
    l->p   = NULL;

    return l;
}

void Affiche(liste *L)
{
    L->p = L->Deb;
    while (L->p != NULL)
    {
        printf("%.3f   ", L->p->N);
        L->p = L->p->Next;
    }
    printf("\n");
}

str *creat_new(float n)
{
    str *s;

    s = (str *) malloc(sizeof(str));

    s->Last = NULL;
    s->Next = NULL;
    s->N    = n;

    return s;
}

void insertnew(liste* L, str* New)
{
    
    // if the list is empty
    if (L->Deb == NULL)
    {
        L->Deb = New;
        L->Fin = New;
        L->p   = New;
    } else {
        // New->Next = NULL;
        New->Last = L->Fin;
        L->Fin->Next = New;
        L->Fin = New;
    }
}

tablist *creertablist(int t) 
{
    tablist *T;
    int i, j, n;
    str *temp_str;
    float temp_f;

    // initialising the list of lists
    T = (tablist *) malloc(sizeof(tablist));
    T->table = (liste **) malloc(t * sizeof(liste *));

    // getting the size of the lists
    printf("Le taille des lists : ");
    scanf("%d", &n);

    // getting the elements of the matrix
    printf("Saisir les elements de tableau\n");    
    for (i = 0; i < t; i++)
    {
        // initializing the list
        T->table[i] = inialiser();
        printf("liste %d\n", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("L[%d] = ", j);
            scanf("%f", &temp_f);
            temp_str = creat_new(temp_f);
            insertnew(T->table[i], temp_str);
        }
    }

    return T;
}


listtablist* initlisttablist()
{
    listtablist *l;
    l = (listtablist *) malloc(sizeof(listtablist));
    l->Deb = NULL;
    l->Fin = NULL;
    l->p   = NULL;

    return l;
}

void insertnewTL(listtablist* L, strtablist* New)
{
    if (L->Deb == NULL)
    {
        L->Deb = New;
        L->Fin = New;
        L->p   = New;
    } else {
        L->Fin->Next = New;
        New->Last    = L->Fin;
        L->Fin       = New;
    }
}


listtablist *creerlisttablist(int m, int *T)
{
    listtablist * lt;
    strtablist * temp_str;
    int i;

    lt = initlisttablist();
    
    for (i = 0; i < m; i++)
    {
        temp_str = (strtablist *) malloc(sizeof(temp_str));
        temp_str->Next = NULL;
        temp_str->Last = NULL;
        temp_str->TL   = creertablist(T[i]);

        insertnewTL(lt, temp_str);
    }

    return lt;
     
}


 void affichelistetablist(listtablist* L, int *T)
 {
    int i, j;
    liste **table;
    L->p = L->Deb;
    i = 0;
    while (L->p != NULL)
    {
        table = L->p->TL->table;
        for (j = 0; j < T[i]; j++)
        {
            Affiche(table[j]);
        }
        printf("\n");
        L->p = L->p->Next;
        i++;
    }
 }


int main()
{
    return 0;
}
