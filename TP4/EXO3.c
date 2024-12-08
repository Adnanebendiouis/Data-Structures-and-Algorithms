#include <stdio.h>
#include <stdlib.h>

typedef struct cellule cellule;
typedef cellule *Liste;

struct cellule {
    int val;
    struct cellule *suivant;
};
Liste Ajouter_Fin_Liste(Liste liste, int valeur) {
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

void Afficher_Liste(Liste liste) {
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
// int estIncluse(int A[], int tailleA, int B[], int tailleB) {
//     for (int i = 0; i < tailleA; i++) {
//         int trouve = 0;
//         for (int j = 0; j < tailleB; j++) {
//             if (A[i] == B[j]) {
//                 trouve = 1;
//                 break;
//             }
//         }
//         if (!trouve) {
//             return 0;
//         }
//     }
//     return 1;
// }
int estIncluse(Liste A, Liste B) {
    while (A != NULL) {
        Liste tempB = B;
        while (tempB != NULL && tempB->val != A->val) {
            tempB = tempB->suivant;
        }
        if (tempB == NULL) {
            return 0;
        }
        A = A->suivant;
    }
    return 1;
}
void purgee(Liste *liste){
    Liste current = *liste;
    while(current != NULL){
        Liste runner = current;
        while(runner->suivant != NULL){
            if(runner->suivant->val == current->val){
                cellule *temp = runner->suivant;
                runner->suivant = runner->suivant->suivant;
                free(temp);
            } else {
                runner = runner->suivant;
            }
        }
        current = current->suivant;
    }
}
Liste intersection(Liste A, Liste B) {
    Liste result = NULL;
    while (A != NULL) {
        Liste tempB = B;
        while (tempB != NULL) {
            if (A->val == tempB->val) {
                result = Ajouter_Fin_Liste(result, A->val);
                break;
            }
            tempB = tempB->suivant;
        }
        A = A->suivant;
    }
    return result;
}
int identique(Liste A,Liste B){
    while(A != NULL && B != NULL){
        if(A->val != B->val){
            return 0;
        }
        A = A->suivant;
        B = B->suivant;
    }
    return A == NULL && B == NULL;
}
int main() {
    int choix, val;
    Liste listeA = NULL;
    Liste listeB = NULL;
    Liste listeResult = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un element a la fin de la liste A\n");
        printf("2. Ajouter un element a la fin de la liste B\n");
        printf("3. Afficher la liste A\n");
        printf("4. Afficher la liste B\n");
        printf("5. Dupliquer les elements pairs de la liste A\n");
        printf("6. Verifier si la liste A est incluse dans la liste B\n");
        printf("7. Verifier si les listes A et B sont identiques\n");
        printf("8. Trouver l'intersection des listes A et B\n");
        printf("9. Supprimer les doublons de la liste A\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez une valeur pour la liste A: ");
                scanf("%d", &val);
                listeA = Ajouter_Fin_Liste(listeA, val);
                break;
            case 2:
                printf("Entrez une valeur pour la liste B: ");
                scanf("%d", &val);
                listeB = Ajouter_Fin_Liste(listeB, val);
                break;
            case 3:
                printf("Liste A: ");
                Afficher_Liste(listeA);
                break;
            case 4:
                printf("Liste B: ");
                Afficher_Liste(listeB);
                break;
            case 5:
                dupliquer_elements_pairs(&listeA);
                printf("Liste A apres duplication des elements pairs: ");
                Afficher_Liste(listeA);
                break;
            case 6:
                if (estIncluse(listeA, listeB)) {
                    printf("La liste A est incluse dans la liste B.\n");
                } else {
                    printf("La liste A n'est pas incluse dans la liste B.\n");
                }
                break;
            case 7:
                if (identique(listeA, listeB)) {
                    printf("Les listes A et B sont identiques.\n");
                } else {
                    printf("Les listes A et B ne sont pas identiques.\n");
                }
                break;
            case 8:
                listeResult = intersection(listeA, listeB);
                printf("Intersection des listes A et B: ");
                Afficher_Liste(listeResult);
                break;
            case 9:
                purgee(&listeA);
                printf("Liste A apres suppression des doublons: ");
                Afficher_Liste(listeA);
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