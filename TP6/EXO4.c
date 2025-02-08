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

typedef struct Pile {
    Node* top;
} Pile;

void Initialiser_File(File* Q) {
    Q->front = Q->rear = NULL;
}

void Initialiser_Pile(Pile* P) {
    P->top = NULL;
}

void Enfiler(File* Q, int X) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = X;
    newNode->next = NULL;
    if (Q->rear == NULL) {
        Q->front = Q->rear = newNode;
        return;
    }
    Q->rear->next = newNode;
    Q->rear = newNode;
}

int Defiler(File* Q) {
    if (Q->front == NULL) return -1;
    Node* temp = Q->front;
    int value = temp->data;
    Q->front = Q->front->next;
    if (Q->front == NULL) Q->rear = NULL;
    free(temp);
    return value;
}

void Empiler(Pile* P, int X) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = X;
    newNode->next = P->top;
    P->top = newNode;
}

int Depiler(Pile* P) {
    if (P->top == NULL) return -1;
    Node* temp = P->top;
    int value = temp->data;
    P->top = P->top->next;
    free(temp);
    return value;
}

int Pile_Vide(Pile* P) {
    return P->top == NULL;
}

void Afficher_File(File* Q) {
    Node* current = Q->front;
    if (current == NULL) {
        printf("La file est vide.\n");
        return;
    }
    printf("Éléments de la file : ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void Afficher_Pile(Pile* P) {
    Node* current = P->top;
    if (current == NULL) {
        printf("La pile est vide.\n");
        return;
    }
    printf("Éléments de la pile : ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void Deplacer_File(File* F1, File* F2) {
    File temp;
    Initialiser_File(&temp);

    while (F1->front != NULL) {
        int value = Defiler(F1);
        if (value % 2 == 0) {
            Enfiler(&temp, value);
        } else {
            Enfiler(F2, value);
        }
    }

    while (temp.front != NULL) {
        Enfiler(F1, Defiler(&temp));
    }
}

void Fusionner_Files(File* F1, File* F2, File* F) {
    while (F1->front != NULL && F2->front != NULL) {
        if (F1->front->data <= F2->front->data) {
            Enfiler(F, Defiler(F1));
        } else {
            Enfiler(F, Defiler(F2));
        }
    }

    while (F1->front != NULL) {
        Enfiler(F, Defiler(F1));
    }

    while (F2->front != NULL) {
        Enfiler(F, Defiler(F2));
    }
}

void Rotation_Pile(Pile* P1, Pile* P2, File* F, int N) {
    for (int i = 0; i < N && !Pile_Vide(P1); i++) {
        Enfiler(F, Depiler(P1));
    }

    while (!Pile_Vide(P1)) {
        Empiler(P2, Depiler(P1));
    }

    while (F->front != NULL) {
        Empiler(P1, Defiler(F));
    }

    while (!Pile_Vide(P2)) {
        Empiler(P1, Depiler(P2));
    }
}

int main() {
    File F1, F2, F;
    Pile P1, P2;
    int choix, valeur, N;

    Initialiser_File(&F1);
    Initialiser_File(&F2);
    Initialiser_File(&F);
    Initialiser_Pile(&P1);
    Initialiser_Pile(&P2);

    do {
        printf("\n--- Menu Gestion des Files et Piles ---\n");
        printf("1. Ajouter un élément à F1\n");
        printf("2. Déplacer les éléments de F1 (impairs vers F2, pairs restent dans F1)\n");
        printf("3. Fusionner F1 et F2 dans F\n");
        printf("4. Ajouter un élément à P1\n");
        printf("5. Effectuer une rotation de N éléments de P1\n");
        printf("6. Afficher F1\n");
        printf("7. Afficher F2\n");
        printf("8. Afficher F\n");
        printf("9. Afficher P1\n");
        printf("10. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à ajouter à F1 : ");
                scanf("%d", &valeur);
                Enfiler(&F1, valeur);
                break;
            case 2:
                Deplacer_File(&F1, &F2);
                printf("Déplacement effectué.\n");
                break;
            case 3:
                Fusionner_Files(&F1, &F2, &F);
                printf("Fusion effectuée.\n");
                break;
            case 4:
                printf("Entrez la valeur à ajouter à P1 : ");
                scanf("%d", &valeur);
                Empiler(&P1, valeur);
                break;
            case 5:
                printf("Entrez le nombre N pour la rotation de P1 : ");
                scanf("%d", &N);
                Rotation_Pile(&P1, &P2, &F, N);
                printf("Rotation effectuée.\n");
                break;
            case 6:
                printf("F1 : ");
                Afficher_File(&F1);
                break;
            case 7:
                printf("F2 : ");
                Afficher_File(&F2);
                break;
            case 8:
                printf("F : ");
                Afficher_File(&F);
                break;
            case 9:
                printf("P1 : ");
                Afficher_Pile(&P1);
                break;
            case 10:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Réessayez.\n");
        }
    } while (choix != 10);

    return 0;
}
