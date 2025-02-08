#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int valeur;
    struct Element *suivant;
    struct Element *precedent;
} Element;

typedef struct Liste
{
    Element *tete;
} Liste;

Liste *initialiser_liste()
{
    Liste *liste = (Liste *)malloc(sizeof(Liste));
    liste->tete = NULL;
    return liste;
}

Element *creer_element(int valeur)
{
    Element *nouvel_element = (Element *)malloc(sizeof(Element));
    nouvel_element->valeur = valeur;
    nouvel_element->suivant = NULL;
    nouvel_element->precedent = NULL;
    return nouvel_element;
}

void ajout_debut(Liste *liste, int valeur)
{
    Element *nouvel_element = creer_element(valeur);
    if (liste->tete == NULL)
    {
        nouvel_element->suivant = nouvel_element;
        nouvel_element->precedent = nouvel_element;
        liste->tete = nouvel_element;
    }
    else
    {
        Element *dernier = liste->tete->precedent;

        nouvel_element->suivant = liste->tete;
        nouvel_element->precedent = dernier;
        dernier->suivant = nouvel_element;
        liste->tete->precedent = nouvel_element;

        liste->tete = nouvel_element;
    }
}

void ajout_fin(Liste *liste, int valeur)
{
    Element *nouvel_element = creer_element(valeur);
    if (liste->tete == NULL)
    {
        nouvel_element->suivant = nouvel_element;
        nouvel_element->precedent = nouvel_element;
        liste->tete = nouvel_element;
    }
    else
    {
        Element *dernier = liste->tete->precedent;

        nouvel_element->suivant = liste->tete;
        nouvel_element->precedent = dernier;
        dernier->suivant = nouvel_element;
        liste->tete->precedent = nouvel_element;
    }
}

void supprimer_debut(Liste *liste)
{
    if (liste->tete == NULL)
    {
        printf("Liste vide.\n");
        return;
    }

    Element *a_supprimer = liste->tete;
    if (a_supprimer->suivant == a_supprimer)
    {
        liste->tete = NULL;
    }
    else
    {
        Element *dernier = liste->tete->precedent;

        liste->tete = liste->tete->suivant;
        liste->tete->precedent = dernier;
        dernier->suivant = liste->tete;
    }
    free(a_supprimer);
}

void supprimer_fin(Liste *liste)
{
    if (liste->tete == NULL)
    {
        printf("Liste vide.\n");
        return;
    }

    Element *dernier = liste->tete->precedent;
    if (dernier->suivant == dernier)
    {
        free(dernier);
        liste->tete = NULL;
    }
    else
    {
        Element *avant_dernier = dernier->precedent;

        avant_dernier->suivant = liste->tete;
        liste->tete->precedent = avant_dernier;
        free(dernier);
    }
}

void supprimer_au_position(Liste *liste, int pos)
{
    if (liste->tete == NULL)
    {
        printf("Liste vide.\n");
        return;
    }

    Element *actuel = liste->tete;
    int i;

    for (i = 1; i < pos && actuel->suivant != liste->tete; i++)
    {
        actuel = actuel->suivant;
    }

    if (i < pos)
    {
        printf("Position invalide.\n");
        return;
    }

    if (actuel->suivant == actuel) 
    {
        free(actuel);
        liste->tete = NULL;
    }
    else
    {
        actuel->precedent->suivant = actuel->suivant;
        actuel->suivant->precedent = actuel->precedent;

        if (actuel == liste->tete) 
        {
            liste->tete = actuel->suivant;
        }
        free(actuel);
    }
}

void inserer_au_position(Liste *liste, int val, int pos)
{
    Element *newElement = (Element *)malloc(sizeof(Element));
    newElement->valeur = val;
    newElement->suivant = NULL;
    newElement->precedent = NULL;

    if (pos == 1)
    {
        newElement->suivant = liste->tete;
        if (liste->tete != NULL)
        {
            liste->tete->precedent = newElement;
        }
        newElement->precedent = liste->tete->precedent; 
        if (liste->tete == NULL)
        {
            newElement->suivant = newElement;
            newElement->precedent = newElement;
            liste->tete = newElement;
        }
        else 
        {
            liste->tete->precedent = newElement; 
        }
        liste->tete = newElement; 
        return;
    }

    Element *tmp = liste->tete;
    for (int i = 1; i < pos - 1 && tmp != NULL; i++)
    {
        tmp = tmp->suivant;
    }

    if (tmp == NULL)
    {
        printf("Position invalide\n");
        free(newElement);
        return;
    }

    newElement->suivant = tmp->suivant;
    newElement->precedent = tmp;
    if (tmp->suivant != NULL)
    {
        tmp->suivant->precedent = newElement;
    }
    tmp->suivant = newElement;
    if (newElement->suivant == liste->tete)
    {
        liste->tete->precedent = newElement;
    }
}

void afficher_liste(Liste *liste)
{
    if (liste->tete == NULL)
    {
        printf("Liste vide.\n");
        return;
    }

    Element *actuel = liste->tete;
    do
    {
        printf("%d ", actuel->valeur);
        actuel = actuel->suivant;
    } while (actuel != liste->tete);
    printf("\n");
}

void afficher_liste_arriere(Liste *liste)
{
    if (liste->tete == NULL)
    {
        printf("Liste vide.\n");
        return;
    }
    Element *actuel = liste->tete->precedent;
    do
    {
        printf("%d ", actuel->valeur);
        actuel = actuel->precedent;
    } while (actuel != liste->tete->precedent);
    printf("\n");
}
liste suprimer(liste l, int val){
    if(l == null){
        printf("liste vide");
        return l;
        }
    cell previous = l;
    cell current = l;
    while(current !=)
}
int main()
{
    Liste *liste = initialiser_liste();
    int choix = 0, val = 0, pos = 0;
    do
    {
        printf("\nMenu:\n");
        printf("1. Ajouter un element en debut\n");
        printf("2. Ajouter un element en fin\n");
        printf("3. Supprimer un element en tete de la liste\n");
        printf("4. Supprimer un element en fin de la liste\n");
        printf("5. Supprimer un element a une position donnée\n");
        printf("6. Inserer un element a une position donnée\n");
        printf("7. Afficher la liste\n");
        printf("8. Afficher la liste en ordre arriere\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("Entrer une valeur: \n");
            scanf("%d", &val);
            ajout_debut(liste, val);
            afficher_liste(liste);
            break;
        case 2:
            printf("Entrer une valeur: \n");
            scanf("%d", &val);
            ajout_fin(liste, val);
            afficher_liste(liste);
            break;
        case 3:
            supprimer_debut(liste);
            afficher_liste(liste);
            break;
        case 4:
            supprimer_fin(liste);
            afficher_liste(liste);
            break;
        case 5:
            printf("Entrer la position: \n");
            scanf("%d", &pos);
            supprimer_au_position(liste, pos);
            afficher_liste(liste);
            break;
        case 6:
            printf("Entrer une valeur: \n");
            scanf("%d", &val);
            printf("Entrer la position: \n");
            scanf("%d", &pos);
            inserer_au_position(liste, val, pos);
            afficher_liste(liste);
            break;
        case 7:
            afficher_liste(liste);
            break;
        case 8:
            afficher_liste_arriere(liste);
            break;
        default:
            break;
        }
    } while (choix != 0);

    return 0;
}
