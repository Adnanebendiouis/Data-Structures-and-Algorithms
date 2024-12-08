#include <stdio.h>
#include <stdlib.h>
typedef struct ElementListe
{
    int val;
    struct ElementListe *prec;
    struct ElementListe *suiv;
} Element;
typedef struct DList
{
    struct ElementListe *debut;
    struct ElementListe *fin;
} liste;
liste *initialiser_Liste(liste *L)
{
    L = malloc(sizeof(liste));
    L->debut = NULL;
    L->fin = NULL;
    return L;
}
int estVide(liste *L)
{
    if (L->debut == NULL)
        return 1;
    else
        return 0;
}
liste *ajout_en_tete(liste *L, int X)
{
    Element *newElement = malloc(sizeof(Element));
    newElement->val = X;
    newElement->prec = NULL;
    if (estVide(L))
    {
        newElement->suiv = NULL;
        L->debut = newElement;
        L->fin = newElement;
    }
    else
    {
        newElement->suiv = L->debut;
        L->debut->prec = newElement;
        L->debut = newElement;
    }
    return L;
}

void Afficher_Liste(liste *L)
{
    if (estVide(L))
    {
        printf("Liste Vide\n");
        return;
    }
    Element *tmp = L->debut;
    while (tmp != NULL)
    {
        printf("%d <-> ", tmp->val);
        tmp = tmp->suiv;
    }
    printf("NULL\n");
}
liste *ajout_Fin(liste *L, int X)
{
    Element *newElement = malloc(sizeof(Element));
    newElement->val = X;
    newElement->suiv = NULL;
    if (estVide(L))
    {
        newElement->prec = NULL;
        L->debut = newElement;
        L->fin = newElement;
    }
    else
    {
        newElement->prec = L->fin;
        L->fin->suiv = newElement;
        L->fin = newElement;
    }
    return L;
}
liste *supprimer_en_tete(liste *L)
{
    if (!estVide(L))
    {
        if (L->debut == L->fin)
        {
            free(L);
            return initialiser_Liste(L);
        }
        else
        {
            Element *suppElement = L->debut;
            suppElement->suiv->prec = NULL;
            L->debut = suppElement->suiv;
            free(suppElement);
        }
    }
    return L;
}
liste *supprimer_Fin(liste *L)
{
    if (!estVide(L))
    {
        if (L->debut == L->fin)
        {
            free(L);
            return initialiser_Liste(L);
        }
        else
        {
            Element *suppElement = L->fin;
            suppElement->prec->suiv = NULL;
            L->fin = suppElement->prec;
            free(suppElement);
        }
    }
    return L;
}
void Afficher_Liste_Avant(liste *L)
{
    if (estVide(L))
        printf("Liste Vide\n");
    else
    {
        Element *tmp = L->debut;
        while (tmp != NULL)
        {
            printf(" %d ", tmp->val);
            tmp = tmp->suiv;
        }
        printf("\n");
    }
}
void Afficher_Liste_Arriere(liste *L)
{
    if (estVide(L))
        printf("Liste Vide\n");
    else
    {
        Element *tmp = L->fin;
        while (tmp != NULL)
        {
            printf(" %d ", tmp->val);
            tmp = tmp->prec;
        }
        printf("\n");
    }
}