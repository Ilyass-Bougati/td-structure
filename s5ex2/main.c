#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    struct node *next;
    struct node *prev;
} node;

typedef struct liste {
    node *deb;
    node *fin;
    node *p;
} liste;

char *saisir_chaine();
liste *init_liste();
node *init_node();
void print_liste(liste *L);
void print_node(node *n);
void empiler(liste *L, char c);
char *check(char *input);
void depiler(liste *L);

int main()
{

    // getting the input
    printf("Entrer une chaine de charactere : ");
    char * str = saisir_chaine();
    char * msg = check(str);
    puts(msg);
}

char *check(char *input)
{
    liste *L = init_liste();
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        switch (input[i])
        {
            case '(':
                empiler(L, input[i]);
                break;
            case ')':
                if (L->deb != NULL || L->deb->ch != '(')
                {
                    return "incorrect";
                } else {
                    depiler(L);
                }
                break;
        }
    }

    

    if (L->deb != NULL)
    {
        return "incorrect";
    } else {
        return "correct";
    }
}

void depiler(liste *L)
{
    printf("%p\n", L->deb);
    if (L->deb == NULL)
    {
        return;
    }

    if (L->deb->next == NULL)
    {
        L->deb = NULL;
        L->fin = NULL;
        return;
    }

    node *n = L->deb->next;
    free(L->deb);
    n->prev = NULL;
    L->deb  = n; 
}

char *saisir_chaine()
{
    int i = 0;
    char *ch, c;

    ch = (char *) malloc(sizeof(char));
    while ((c = getchar()) != '\n')
    {
        ch[i++] = c;
        ch = (char *) realloc(ch, (i + 1) * sizeof(char));
    }
    ch[i] = '\0';

    return ch;
}

liste *init_liste()
{
    liste *l = (liste *) malloc(sizeof(liste));
    l->deb = NULL;
    l->fin = NULL;
    l->p   = '\0';
}

node *init_node()
{
    node *n = (node *) malloc(sizeof(node));
    n->ch   = '\0';
    n->next = NULL;
    n->prev = NULL;

    return n;
}

void empiler(liste *L, char c)
{
    // create a new node
    node *n = init_node();
    n->ch   = c;

    // adding the node to the liste
    if (L->fin == NULL)
    {
        L->deb = n;
        L->fin = n;
    } else {
        n->prev = L->fin;
        L->fin->next  = n;
        L->fin = n;
    }
}

void print_node(node *n)
{
    if (n == NULL)
    {
        return;
    }
    printf("%c   ", n->ch);
    print_node(n->next);
}

void print_liste(liste *L)
{
    if (L->deb == NULL)
    {
        return;
    }

    print_node(L->deb);
}