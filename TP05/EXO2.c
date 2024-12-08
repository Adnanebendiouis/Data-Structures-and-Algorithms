#include <stdio.h>
#include <stdlib.h>
typedef struct Element {
    int valeur;
    struct Element *suivant;
    struct Element *precedent;
} Element;
typedef struct Liste {
    Element *tete;
} Liste;
Liste *initialiser_liste() {
    Liste *liste = (Liste *)malloc(sizeof(Liste));
    liste->tete = NULL;
    return liste;
}
Element *creer_element(int valeur) {
    Element *nouvel_element = (Element *)malloc(sizeof(Element));
    nouvel_element->valeur = valeur;
    nouvel_element->suivant = NULL;
    nouvel_element->precedent = NULL;
    return nouvel_element;
}
void ajout_debut(Liste *liste, int valeur) {
    Element *nouvel_element = creer_element(valeur);
    if (liste->tete == NULL) {
        nouvel_element->suivant = nouvel_element;
        nouvel_element->precedent = nouvel_element;
        liste->tete = nouvel_element;
    } else {
        Element *dernier = liste->tete->precedent;

        nouvel_element->suivant = liste->tete;
        nouvel_element->precedent = dernier;
        dernier->suivant = nouvel_element;
        liste->tete->precedent = nouvel_element;

        liste->tete = nouvel_element;
    }
}
void ajout_fin(Liste *liste, int valeur) {
    Element *nouvel_element = creer_element(valeur);
    if (liste->tete == NULL) {
        nouvel_element->suivant = nouvel_element;
        nouvel_element->precedent = nouvel_element;
        liste->tete = nouvel_element;
    } else {
        Element *dernier = liste->tete->precedent;

        nouvel_element->suivant = liste->tete;
        nouvel_element->precedent = dernier;
        dernier->suivant = nouvel_element;
        liste->tete->precedent = nouvel_element;
    }
}
void supprimer_debut(Liste *liste) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }

    Element *a_supprimer = liste->tete;
    if (a_supprimer->suivant == a_supprimer) {
        liste->tete = NULL;
    } else {
        Element *dernier = liste->tete->precedent;

        liste->tete = liste->tete->suivant;
        liste->tete->precedent = dernier;
        dernier->suivant = liste->tete;
    }
    free(a_supprimer);
}
void supprimer_fin(Liste *liste) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }

    Element *dernier = liste->tete->precedent;
    if (dernier->suivant == dernier) {
        free(dernier);
        liste->tete = NULL;
    } else {
        Element *avant_dernier = dernier->precedent;

        avant_dernier->suivant = liste->tete;
        liste->tete->precedent = avant_dernier;
        free(dernier);
    }
}
void afficher_liste(Liste *liste) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }

    Element *actuel = liste->tete;
    do {
        printf("%d ", actuel->valeur);
        actuel = actuel->suivant;
    } while (actuel != liste->tete);
    printf("\n");
}
int main() {
    Liste *liste = initialiser_liste();
    int choix=0,val=0;
    do{
        printf("\nMenu:\n");
    printf("1. Ajouter un element en debut\n");
    printf("2. Ajouter un element en fin \n");
    printf("3. Supprimer un element en tete de la liste\n");
    printf("4. Supprimer un element en fin de la liste\n");
    printf("5. Afficher la liste \n");
    printf("6. Afficher la liste en ordre arriere\n");
    switch (choix !=0)
    {
    case 1:
    printf("entrer une valeur \n");
    scanf("%d",&val);
        liste = ajout_debut(liste, val);
        break;
    
    default:
        break;
    }
    }while(choix != 0);

    printf("Ajout en début :\n");
    ajout_debut(ma_liste, 10);
    ajout_debut(ma_liste, 20);
    afficher_liste(ma_liste);

    printf("Ajout en fin :\n");
    ajout_fin(ma_liste, 30);
    afficher_liste(ma_liste);

    printf("Suppression du début :\n");
    supprimer_debut(ma_liste);
    afficher_liste(ma_liste);

    printf("Suppression de la fin :\n");
    supprimer_fin(ma_liste);
    afficher_liste(ma_liste);

    return 0;
}
