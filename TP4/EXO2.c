#include <stdio.h>
#include <stdlib.h>

typedef struct cellule cellule;
typedef cellule *Liste;

struct cellule {
    int val;
    struct cellule *suivant;
};

cellule *initialiser_Liste(cellule *liste) {
    liste = NULL;
    return liste;
}

Liste Ajouter_Debut_Liste(cellule *liste, int valeur) {
    Liste newcellule = malloc(sizeof(cellule));
    newcellule->val = valeur;
    newcellule->suivant = liste;
    return newcellule;
}

cellule *Ajouter_Fin_Liste(cellule *liste, int valeur) {
    cellule *newcellule = malloc(sizeof(cellule));
    newcellule->val = valeur;
    newcellule->suivant = NULL;
    if (liste == NULL)
        return newcellule;
    else {
        cellule *temp = liste;
        while (temp->suivant != NULL)
            temp = temp->suivant;
        temp->suivant = newcellule;
        return liste;
    }
}

cellule *Supprimer_Fin_Liste(cellule *liste) {
    if (liste == NULL)
        return NULL;
    if (liste->suivant == NULL) {
        free(liste);
        return NULL;
    }
    cellule *tmp = liste;
    cellule *ptmp = liste;
    while (tmp->suivant != NULL) {
        ptmp = tmp;
        tmp = tmp->suivant;
    }
    ptmp->suivant = NULL;
    free(tmp);
    return liste;
}

cellule *Supprimer_Debut_Liste(cellule *liste) {
    if (liste != NULL) {
        cellule *NouveauEntete = liste->suivant;
        free(liste);
        return NouveauEntete;
    } else
        return NULL;
}

void Afficher_Liste(cellule *liste) {
    if (liste == NULL)
        printf(" La Liste est Vide.\n");
    else {
        cellule *tmp = liste;
        while (tmp != NULL) {
            printf(" %d ->", tmp->val);
            tmp = tmp->suivant;
        }
        printf(" NULL\n");
    }
}

void afficher_croissant(Liste liste) {
    if (liste == NULL) {
        return;
    }
    printf("%d -> ", liste->val);
    afficher_croissant(liste->suivant);
}

void afficher_decroissant(Liste liste) {
    if (liste == NULL) {
        return;
    }
    afficher_decroissant(liste->suivant);
    printf("%d -> ", liste->val);
}

Liste inser_tri(Liste liste, int val, Liste cell) {
    cellule *tmp = liste;
    cellule *ptmp = liste;
    while (liste->suivant > val) {
        ptmp = tmp;
        tmp = tmp->suivant;
        liste = liste->suivant;
    }
    ptmp->suivant = cell;
    cell->suivant = tmp;
}

int estTrieeIteratif(Liste liste) {
    if (liste == NULL || liste->suivant == NULL) {
        return 1;
    }
    cellule *current = liste;
    while (current->suivant != NULL) {
        if (current->val > current->suivant->val) {
            return 0;
        }
        current = current->suivant;
    }
    return 1;
}

int estTrieeRecursif(Liste liste) {
    if (liste == NULL || liste->suivant == NULL) {
        return 1;
    }
    if (liste->val > liste->suivant->val) {
        return 0;
    }
    return estTrieeRecursif(liste->suivant);
}

Liste inverserListe(Liste liste) {
    cellule *prev = NULL;
    cellule *current = liste;
    cellule *next = NULL;
    while (current != NULL) {
        next = current->suivant;
        current->suivant = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Liste fusioner(Liste liste1, Liste liste2) {
    if (liste1 == NULL) return liste2;
    if (liste2 == NULL) return liste1;
    cellule *temp = liste1;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = liste2;
    return liste1;
}

int main() {
    int choix, val, pos;
    Liste liste = NULL;
    Liste liste2 = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Initialiser une Liste\n");
        printf("2. Ajouter un element au debut d'une liste\n");
        printf("3. Ajouter un element a la fin d'une liste\n");
        printf("4. Supprimer un element a la fin d'une liste\n");
        printf("5. Supprimer un element au debut d'une liste\n");
        printf("6. Afficher la liste\n");
        printf("7. Afficher la liste en ordre croissant\n");
        printf("8. Afficher la liste en ordre decroissant\n");
        printf("9. Verifier si la liste est triee (iteratif)\n");
        printf("10. Verifier si la liste est triee (recursif)\n");
        printf("11. Inverser la liste\n");
        printf("12. Fusionner deux listes\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                liste = initialiser_Liste(liste);
                printf("Liste initialisee.\n");
                break;
            case 2:
                printf("Entrez une valeur: ");
                scanf("%d", &val);
                liste = Ajouter_Debut_Liste(liste, val);
                Afficher_Liste(liste);
                break;
            case 3:
                printf("Entrez une valeur: ");
                scanf("%d", &val);
                liste = Ajouter_Fin_Liste(liste, val);
                Afficher_Liste(liste);
                break;
            case 4:
                liste = Supprimer_Fin_Liste(liste);
                Afficher_Liste(liste);
                break;
            case 5:
                liste = Supprimer_Debut_Liste(liste);
                Afficher_Liste(liste);
                break;
            case 6:
                Afficher_Liste(liste);
                break;
            case 7:
                printf("Liste en ordre croissant: ");
                afficher_croissant(liste);
                printf("NULL\n");
                break;
            case 8:
                printf("Liste en ordre decroissant: ");
                afficher_decroissant(liste);
                printf("NULL\n");
                break;
            case 9:
                if (estTrieeIteratif(liste)) {
                    printf("La liste est triee (iteratif).\n");
                } else {
                    printf("La liste n'est pas triee (iteratif).\n");
                }
                break;
            case 10:
                if (estTrieeRecursif(liste)) {
                    printf("La liste est triee (recursif).\n");
                } else {
                    printf("La liste n'est pas triee (recursif).\n");
                }
                break;
            case 11:
                liste = inverserListe(liste);
                printf("Liste apres inversion: ");
                Afficher_Liste(liste);
                break;
            case 12:
                printf("Entrez les elements de la deuxieme liste (entrez -1 pour terminer):\n");
                while (1) {
                    scanf("%d", &val);
                    if (val == -1) break;
                    liste2 = Ajouter_Fin_Liste(liste2, val);
                }
                liste = fusioner(liste, liste2);
                printf("Liste apres fusion: ");
                Afficher_Liste(liste);
                break;
            case 0:
                printf("Quitter...\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}

