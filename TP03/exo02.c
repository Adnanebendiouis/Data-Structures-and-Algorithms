#include <stdio.h>
void lireTableau(int A[], int n, int i) {
    if (i >= n) {
        return;
    }
    printf("Entrez l element %d: ", i + 1);
    scanf("%d", &A[i]);
    lireTableau(A, n, i + 1);
}
void afficherTableau(int A[], int n, int i) {
    if (i >= n) {
        return;
    }
    printf("%d ", A[i]);
    afficherTableau(A, n, i + 1);
}
int sommeTableau(int A[], int n, int i) {
    if (i >= n) {
        return 0;
    }
    return A[i] + sommeTableau(A, n, i + 1);
}
int occurrences(int A[], int n, int i, int V) {
    if (i >= n) {
        return 0;
    }
    return (A[i] == V) + occurrences(A, n, i + 1, V);
}
int rechercheDichotomique(int T[], int val, int low, int high) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2; 

    if (T[mid] == val) {
        return mid;
    } else if (T[mid] < val) {
        return rechercheDichotomique(T, val, mid + 1, high); 
    } else {
        return rechercheDichotomique(T, val, low, mid - 1); 
    }
}
void insererDansTableauTrie(int A[], int n, int V, int i) {
    if (i >= n || A[i] > V) {
        if (i < n) {
            insererDansTableauTrie(A, n, A[n - 1], i + 1);
            A[i] = V;
        } else {
            A[n] = V;
        }
        return;
    }
    insererDansTableauTrie(A, n, V, i + 1);
}
void afficherElementsCommuns(int T1[], int N, int i, int T2[], int M, int j) {
    if (i >= N || j >= M) {
        return;
    }
    if (T1[i] == T2[j]) {
        printf("%d ", T1[i]);
        afficherElementsCommuns(T1, N, i + 1, T2, M, j + 1);
    } else if (T1[i] < T2[j]) {
        afficherElementsCommuns(T1, N, i + 1, T2, M, j);
    } else {
        afficherElementsCommuns(T1, N, i, T2, M, j + 1);
    }
}
int main() {
    int choice, n, m, V, X;
    int T2[100];
    int A[100];
    do {
        printf("\nMenu:\n");
        printf("1. Lire le tableau\n");
        printf("2. Afficher le tableau\n");
        printf("3. Calculer la somme des éléments\n");
        printf("4. Compter les occurrences d une valeur\n");
        printf("5. Recherche dichotomique\n");
        printf("6. Inserer une valeur dans un tableau trie\n");
        printf("7. Afficher les elements communs entre deux tableaux tries\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez la taille du tableau: ");
                scanf("%d", &n);
                
                lireTableau(A, n, 0);
                break;
            case 2:
                printf("Les elements du tableau sont: ");
                afficherTableau(A, n, 0);
                printf("\n");
                break;
            case 3:
                printf("La somme des elements du tableau est: %d\n", sommeTableau(A, n, 0));
                break;
            case 4:
                printf("Entrez la valeur a rechercher: ");
                scanf("%d", &V);
                printf("Le nombre d occurrences de %d est: %d\n", V, occurrences(A, n, 0, V));
                break;
            case 5:
                printf("Entrez la valeur a chercher par dichotomie: ");
                scanf("%d", &X);
                int index = rechercheDichotomique(A, 0, n - 1, X);
                if (index != -1) {
                    printf("L element %d a ete trouve a l index %d\n", X, index);
                } else {
                    printf("L element %d n a pas ete trouve\n", X);
                }
                break;
            case 6:
                printf("Entrez la nouvelle valeur à insérer: ");
                scanf("%d", &V);
                insererDansTableauTrie(A, n, V, 0);
                n++; 
                printf("Les éléments du tableau après insertion sont: ");
                afficherTableau(A, n, 0);
                printf("\n");
                break;
            case 7:
                printf("Entrez la taille du tableau T2: ");
                scanf("%d", &m);
                int T2[100];
                lireTableau(T2, m, 0);
                printf("Les elements communs entre T1 et T2 sont: ");
                afficherElementsCommuns(A, n, 0, T2, m, 0);
                printf("\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choice != 0);

    return 0;
}