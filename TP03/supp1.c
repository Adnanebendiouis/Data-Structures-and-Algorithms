#include <stdio.h>
#include <string.h>
int anag(char ch1[], char ch2[], int i, int j, int n, int m) {
    if (i >= n) {
        return 1;
    }
    if (j >= m) {
        return 0;
    }

    if (ch1[i] == ch2[j]) {
        
        return anag(ch1, ch2, i + 1, 0, n, m);
    }
    if(ch2[j]=='\0' ){
        return 0;
    }
    return anag(ch1, ch2, i, j + 1, n, m);
}
int estPalindrome(char ch[], int i, int j) {
    if (i >= j) {
        return 1; 
    }
    if (ch[i] != ch[j]) {
        return 0; 
    }
    return estPalindrome(ch, i + 1, j - 1); 
}
int main() {
    int choice;
    char ch1[100], ch2[100];

    do {
        printf("\nMenu:\n");
        printf("1. Vérifier si deux chaînes sont des anagrammes\n");
        printf("2. Vérifier si une chaîne est un palindrome\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez la première chaîne: ");
                scanf("%s", ch1);
                printf("Entrez la deuxième chaîne: ");
                scanf("%s", ch2);
                if (anag(ch1, ch2, 0, 0, strlen(ch1), strlen(ch2))) {
                    printf("Les chaînes sont des anagrammes.\n");
                } else {
                    printf("Les chaînes ne sont pas des anagrammes.\n");
                }
                break;
            case 2:
                printf("Entrez la chaîne: ");
                scanf("%s", ch1);
                if (estPalindrome(ch1, 0, strlen(ch1) - 1)) {
                    printf("La chaîne est un palindrome.\n");
                } else {
                    printf("La chaîne n'est pas un palindrome.\n");
                }
                break;
            case 0:
                printf("Quitter...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 0);

    return 0;
}