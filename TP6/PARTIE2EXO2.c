#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* creerNoeud(int valeur) {
    Node* nouveauNoeud = (Node*)malloc(sizeof(Node));
    nouveauNoeud->data = valeur;
    nouveauNoeud->left = NULL;
    nouveauNoeud->right = NULL;
    return nouveauNoeud;
}

Node* insererNoeud(Node* racine, int valeur) {
    if (racine == NULL) {
        return creerNoeud(valeur);
    }
    if (valeur < racine->data) {
        racine->left = insererNoeud(racine->left, valeur);
    } else if (valeur > racine->data) {
        racine->right = insererNoeud(racine->right, valeur);
    }
    return racine;
}

bool estABRUtil(Node* racine, int min, int max) {
    if (racine == NULL) {
        return true;
    }
    if (racine->data <= min || racine->data >= max) {
        return false;
    }
    return estABRUtil(racine->left, min, racine->data) &&
           estABRUtil(racine->right, racine->data, max);
}

bool estABR(Node* racine) {
    return estABRUtil(racine, -__INT_MAX__, __INT_MAX__);
}

int compterNoeuds(Node* racine) {
    if (racine == NULL) {
        return 0;
    }
    return 1 + compterNoeuds(racine->left) + compterNoeuds(racine->right);
}

bool estCompletUtil(Node* racine, int index, int totalNoeuds) {
    if (racine == NULL) {
        return true;
    }
    if (index >= totalNoeuds) {
        return false;
    }
    return estCompletUtil(racine->left, 2 * index + 1, totalNoeuds) &&
           estCompletUtil(racine->right, 2 * index + 2, totalNoeuds);
}

bool estComplet(Node* racine) {
    int totalNoeuds = compterNoeuds(racine);
    return estCompletUtil(racine, 0, totalNoeuds);
}

void parcoursInOrder(Node* racine) {
    if (racine == NULL) {
        return;
    }
    parcoursInOrder(racine->left);
    printf("%d ", racine->data);
    parcoursInOrder(racine->right);
}

int main() {
    Node* racine = NULL;
    int choix, valeur;

    do {
        printf("\nMenu Arbre Binaire :\n");
        printf("1. Insérer un nœud\n");
        printf("2. Vérifier si l'arbre est un Arbre Binaire de Recherche (ABR)\n");
        printf("3. Vérifier si l'arbre est complet\n");
        printf("4. Afficher le parcours In-Order\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à insérer : ");
                scanf("%d", &valeur);
                racine = insererNoeud(racine, valeur);
                break;
            case 2:
                if (estABR(racine)) {
                    printf("L'arbre est un Arbre Binaire de Recherche (ABR).\n");
                } else {
                    printf("L'arbre n'est pas un ABR.\n");
                }
                break;
            case 3:
                if (estComplet(racine)) {
                    printf("L'arbre est complet.\n");
                } else {
                    printf("L'arbre n'est pas complet.\n");
                }
                break;
            case 4:
                printf("Parcours In-Order : ");
                parcoursInOrder(racine);
                printf("\n");
                break;
            case 5:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Réessayez.\n");
        }
    } while (choix != 5);

    return 0;
}
