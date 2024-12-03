#include <stdio.h>
#include <stdlib.h>

typedef struct cellule cellule;
typedef cellule *Liste;

struct cellule {
    int val;
    struct cellule *suivant;
};
Liste Ajouter_Fin_Liste(cellule *liste, int valeur) {
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

void Afficher_Liste(cellule *liste) {
    if (liste == NULL)
        printf("La Liste est Vide.\n");
    else {
        cellule *tmp = liste;
        while (tmp != NULL) {
            printf("%d -> ", tmp->val);
            tmp = tmp->suivant;
        }
        printf("NULL\n");
    }
}
void dupliquer_elements_pairs(Liste *liste) {
    cellule *current = *liste;
    while (current != NULL) {
        if (current->val % 2 == 0) {
            cellule *newcellule = malloc(sizeof(cellule));
            newcellule->val = current->val;
            newcellule->suivant = current->suivant;
            current->suivant = newcellule;
            current = newcellule->suivant;
        } else {
            current = current->suivant;
        }
    }
}
int estIncluse(Liste A, Liste B) {
    if (A == NULL) {
        return 1; 
    }
    while (B != NULL) {
        if (B->val == A->val) {
            Liste tempA = A;
            Liste tempB = B;
            while (tempA != NULL && tempB != NULL && tempA->val == tempB->val) {
                tempA = tempA->suivant;
                tempB = tempB->suivant;
            }
            if (tempA == NULL) {
                return 1; 
            }
        }
        B = B->suivant;
    }
    return 0;
}
void purgee(Liste liste){
    Liste liste1 = liste;
    for (int i = 0; liste->suivant != NULL; liste=liste->suivant)
    {
        for(int j = 0;liste1->suivant != NULL;liste1=liste1->suivant)
    }
    
}
int main() {
    Liste liste = NULL;
    liste = Ajouter_Fin_Liste(liste, 1);
    liste = Ajouter_Fin_Liste(liste, 2);
    liste = Ajouter_Fin_Liste(liste, 3);
    liste = Ajouter_Fin_Liste(liste, 4);
    liste = Ajouter_Fin_Liste(liste, 5);

    printf("Liste avant duplication des elements pairs: ");
    Afficher_Liste(liste);

    dupliquer_elements_pairs(&liste);

    printf("Liste apres duplication des elements pairs: ");
    Afficher_Liste(liste);

    return 0;
}