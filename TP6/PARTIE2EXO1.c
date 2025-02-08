#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Ajouter_Noeud(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = Ajouter_Noeud(root->left, value);
    } else if (value > root->data) {
        root->right = Ajouter_Noeud(root->right, value);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* Supprimer_Noeud(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->data) {
        root->left = Supprimer_Noeud(root->left, value);
    } else if (value > root->data) {
        root->right = Supprimer_Noeud(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = Supprimer_Noeud(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void sortUsingBST(int arr[], int size) {
    Node* root = NULL;
    for (int i = 0; i < size; i++) {
        root = Ajouter_Noeud(root, arr[i]);
    }
    int index = 0;
    void collectSorted(Node* root) {
        if (root != NULL) {
            collectSorted(root->left);
            arr[index++] = root->data;
            collectSorted(root->right);
        }
    }
    collectSorted(root);
}

int main() {
    Node* root = NULL;
    int choice, value, size;
    int arrayToSort[100], toDelete[100], values[] = {5, 1, 11, 9, 3, 10, 2, 15, 6, 4, 20, 13};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = Ajouter_Noeud(root, values[i]);
    }

    do {
        printf("\nMenu :\n");
        printf("1. Afficher l'ABR (Parcours In-Order)\n");
        printf("2. Supprimer un nœud\n");
        printf("3. Trier un tableau d'entiers avec un ABR\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Parcours In-Order de l'ABR : ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Entrez la valeur à supprimer : ");
                scanf("%d", &value);
                root = Supprimer_Noeud(root, value);
                printf("Parcours après suppression : ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Entrez la taille du tableau : ");
                scanf("%d", &size);
                printf("Entrez les éléments du tableau : ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arrayToSort[i]);
                }
                sortUsingBST(arrayToSort, size);
                printf("Tableau trié : ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arrayToSort[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Réessayez.\n");
        }
    } while (choice != 4);

    return 0;
}
