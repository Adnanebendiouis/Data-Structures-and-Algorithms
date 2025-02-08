#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct File {
    Node* front;
    Node* rear;
} File;

void Initialiser_File(File* F) {
    F->front = F->rear = NULL;
}

void Enfiler(File* F, int X) {
    Node* nouveauNoeud = (Node*)malloc(sizeof(Node));
    if (!nouveauNoeud) return;
    nouveauNoeud->data = X;
    nouveauNoeud->next = NULL;
    if (F->rear == NULL) {
        F->front = F->rear = nouveauNoeud;
        return;
    }
    F->rear->next = nouveauNoeud;
    F->rear = nouveauNoeud;
}

void Defiler(File* F) {
    if (F->front == NULL) {
        printf("La file est vide.\n");
        return;
    }
    Node* temp = F->front;
    F->front = F->front->next;
    if (F->front == NULL) F->rear = NULL;
    free(temp);
}

int Tete(File* F) {
    if (F->front == NULL) return -1;
    return F->front->data;
}

int Queue_Element(File* F) {
    if (F->rear == NULL) return -1;
    return F->rear->data;
}

int File_Vide(File* F) {
    return F->front == NULL;
}

void Afficher_File(File* F) {
    Node* actuel = F->front;
    if (actuel == NULL) {
        printf("La file est vide.\n");
        return;
    }
    printf("Éléments de la file : ");
    while (actuel) {
        printf("%d ", actuel->data);
        actuel = actuel->next;
    }
    printf("\n");
}

int main() {
    File F;
    int choix, valeur;
    
    Initialiser_File(&F);

    do {
        printf("\nMenu de la File :\n");
        printf("1. Enfiler un élément\n");
        printf("2. Défiler un élément\n");
        printf("3. Afficher la file\n");
        printf("4. Voir la tête de la file\n");
        printf("5. Voir la fin de la file\n");
        printf("6. Vérifier si la file est vide\n");
        printf("7. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à enfiler : ");
                scanf("%d", &valeur);
                Enfiler(&F, valeur);
                break;
            case 2:
                Defiler(&F);
                break;
            case 3:
                Afficher_File(&F);
                break;
            case 4:
                if (!File_Vide(&F))
                    printf("Tête de la file : %d\n", Tete(&F));
                else
                    printf("La file est vide.\n");
                break;
            case 5:
                if (!File_Vide(&F))
                    printf("Fin de la file : %d\n", Queue_Element(&F));
                else
                    printf("La file est vide.\n");
                break;
            case 6:
                if (File_Vide(&F))
                    printf("La file est vide.\n");
                else
                    printf("La file n'est pas vide.\n");
                break;
            case 7:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Réessayez.\n");
        }
    } while (choix != 7);

    return 0;
}
