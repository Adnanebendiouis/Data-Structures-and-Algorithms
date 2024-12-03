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
            printf(" %d ", tmp->val);
            tmp = tmp->suivant;
        }
        printf("\n");
    }
}

int nbr_ele_itr(Liste liste) {
    int count = 0;
    while (liste != NULL) {
        count++;
        liste = liste->suivant;
    }
    return count;
}

int nbr_ele_rec(Liste liste, int count) {
    if (liste == NULL) {
        return count;
    }
    return nbr_ele_rec(liste->suivant, count + 1);
}

int nbr_occ_itr(Liste liste, int val) {
    int occ = 0;
    while (liste != NULL) {
        if (val == liste->val) {
            occ++;
        }
        liste = liste->suivant;
    }
    return occ;
}

int nbr_occ_rec(Liste liste, int val, int occ) {
    if (liste == NULL) {
        return occ;
    }
    if (val == liste->val) {
        return nbr_occ_rec(liste->suivant, val, occ + 1);
    }
    return nbr_occ_rec(liste->suivant, val, occ);
}

int cherch_pos_itr(Liste liste, int pos) {
    for (int i = 1; i < pos; i++) {
        if (liste == NULL) {
            return -1; // Position out of bounds
        }
        liste = liste->suivant;
    }
    return liste != NULL ? liste->val : -1; // Return -1 if position is out of bounds
}

int cherch_pos_rec(Liste liste, int pos, int i) {
    if (liste == NULL) {
        return -1; // Position out of bounds
    }
    if (pos == i) {
        return liste->val;
    }
    return cherch_pos_rec(liste->suivant, pos, i + 1);
}

int recherche_element_itr(Liste liste, int val) {
    while (liste != NULL) {
        if (val == liste->val) {
            return 1;
        }
        liste = liste->suivant;
    }
    return 0;
}

int recherche_element_rec(Liste liste, int val) {
    if (liste == NULL) {
        return 0;
    }
    if (liste->val == val) {
        return 1;
    }
    return recherche_element_rec(liste->suivant, val);
}

void ajou_apos(Liste liste, int pos, cellule *cell) {
    cellule *tmp = liste;
    cellule *ptmp = liste;
    int i = 1;
    while (i < pos) {
        ptmp = tmp;
        tmp = tmp->suivant;
        i++;
    }
    ptmp->suivant = cell;
    cell->suivant = tmp;
}

void sup_apos(Liste *liste, int pos) {
    cellule *tmp = *liste;
    cellule *ptmp = NULL;
    int i = 1;
    if (pos == 1) {
        *liste = tmp->suivant;
        free(tmp);
        return;
    }
    while (tmp != NULL && i < pos) {
        ptmp = tmp;
        tmp = tmp->suivant;
        i++;
    }
    if (tmp != NULL) {
        ptmp->suivant = tmp->suivant;
        free(tmp);
    }
}
void copie(Liste liste){
    Liste copie = liste;
    return NULL;
}

int main() {
    int choix, val = 0, pos;
    Liste liste = NULL;
    Ajouter_Debut_Liste(liste,23);
    Ajouter_Debut_Liste(liste,3);
    Ajouter_Debut_Liste(liste,2);
    Ajouter_Debut_Liste(liste,13);
    Ajouter_Debut_Liste(liste,53);
    Liste cop = copie(liste);
    // Afficher_Liste(copie);
    do {
        printf("1. Initialiser une Liste\n ");
        printf("2. Ajouter un element au debut d une liste\n ");
        printf("3. Ajouter un element au fin d une liste\n ");
        printf("4. Supprimer un element au fin d une liste\n ");
        printf("5. Supprimer un element au debut d une liste\n ");
        printf("6. Affichier une liste\n ");
        printf("7. Compter le nombre d'elements (iteratif)\n ");
        printf("8. Compter le nombre d'elements (recursif)\n ");
        printf("9. Compter le nombre d'occurrences d'une valeur (iteratif)\n ");
        printf("10. Compter le nombre d'occurrences d'une valeur (recursif)\n ");
        printf("11. Chercher la valeur a une position (iteratif)\n ");
        printf("12. Chercher la valeur a une position (recursif)\n ");
        printf("13. Rechercher un element (iteratif)\n ");
        printf("14. Rechercher un element (recursif)\n ");
        printf("15. Ajouter un element a une position\n ");
        printf("16. Supprimer un element a une position\n ");
        printf("0. Quitter\n ");
        printf("entrer votre choix :");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                liste = initialiser_Liste(liste);
                break;
            case 2:
                printf("entrer une valeur :\n");
                scanf("%d", &val);
                liste = Ajouter_Debut_Liste(liste, val);
                Afficher_Liste(liste);
                break;
            case 3:
                printf("entrer une valeur :\n");
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
                printf("Nombre d'elements (iteratif): %d\n", nbr_ele_itr(liste));
                break;
            case 8:
                printf("Nombre d'elements (recursif): %d\n", nbr_ele_rec(liste, 0));
                break;
            case 9:
                printf("entrer une valeur :\n");
                scanf("%d", &val);
                printf("Nombre d'occurrences (iteratif): %d\n", nbr_occ_itr(liste, val));
                break;
            case 10:
                printf("entrer une valeur :\n");
                scanf("%d", &val);
                printf("Nombre d'occurrences (recursif): %d\n", nbr_occ_rec(liste, val, 0));
                break;
            case 11:
                printf("entrer une position :\n");
                scanf("%d", &pos);
                printf("Valeur a la position (iteratif): %d\n", cherch_pos_itr(liste, pos));
                break;
            case 12:
                printf("entrer une position :\n");
                scanf("%d", &pos);
                printf("Valeur a la position (recursif): %d\n", cherch_pos_rec(liste, pos, 1));
                break;
            case 13:
                printf("entrer une valeur :\n");
                scanf("%d", &val);
                printf("Element trouve (iteratif): %d\n", recherche_element_itr(liste, val));
                break;
            case 14:
                printf("entrer une valeur :\n");
                scanf("%d", &val);
                printf("Element trouve (recursif): %d\n", recherche_element_rec(liste, val));
                break;
            case 15:
                printf("entrer une position :\n");
                scanf("%d", &pos);
                printf("entrer une valeur :\n");
                scanf("%d", &val);
                cellule *newcell = malloc(sizeof(cellule));
                newcell->val = val;
                newcell->suivant = NULL;
                ajou_apos(liste, pos, newcell);
                Afficher_Liste(liste);
                break;
            case 16:
                printf("entrer une position :\n");
                scanf("%d", &pos);
                sup_apos(&liste, pos);
                Afficher_Liste(liste);
                break;
            case 0:
                break;
            default:
                printf("choix invalide\n");
                break;
        }
    } while (choix != 0);
    return 0;
}

