#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Pile {
    Node* sommet;
} Pile;

void Initialiser_Pile(Pile* P) {
    P->sommet = NULL;
}

void Empiler(Pile* P, int X) {
    Node* nouveauNoeud = (Node*)malloc(sizeof(Node));
    if (!nouveauNoeud) return;
    nouveauNoeud->data = X;
    nouveauNoeud->next = P->sommet;
    P->sommet = nouveauNoeud;
}

void Depiler(Pile* P) {
    if (P->sommet == NULL) {
        printf("La pile est vide.\n");
        return;
    }
    Node* temp = P->sommet;
    P->sommet = P->sommet->next;
    free(temp);
}

int Sommet(Pile* P) {
    if (P->sommet == NULL) return -1;
    return P->sommet->data;
}

int Pile_Vide(Pile* P) {
    return P->sommet == NULL;
}

void Afficher_Pile(Pile* P) {
    Node* actuel = P->sommet;
    if (actuel == NULL) {
        printf("La pile est vide.\n");
        return;
    }
    printf("Éléments de la pile : ");
    while (actuel) {
        printf("%d ", actuel->data);
        actuel = actuel->next;
    }
    printf("\n");
}

int main() {
    Pile P;
    int choix, valeur;
    
    Initialiser_Pile(&P);

    do {
        printf("\nMenu de la Pile :\n");
        printf("1. Empiler un élément\n");
        printf("2. Dépiler un élément\n");
        printf("3. Afficher la pile\n");
        printf("4. Voir le sommet de la pile\n");
        printf("5. Vérifier si la pile est vide\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à empiler : ");
                scanf("%d", &valeur);
                Empiler(&P, valeur);
                break;
            case 2:
                Depiler(&P);
                break;
            case 3:
                Afficher_Pile(&P);
                break;
            case 4:
                if (!Pile_Vide(&P))
                    printf("Sommet de la pile : %d\n", Sommet(&P));
                else
                    printf("La pile est vide.\n");
                break;
            case 5:
                if (Pile_Vide(&P))
                    printf("La pile est vide.\n");
                else
                    printf("La pile n'est pas vide.\n");
                break;
            case 6:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Réessayez.\n");
        }
    } while (choix != 6);

    return 0;
}
