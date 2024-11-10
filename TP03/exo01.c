#include <stdio.h>
int factorial(int n)
{
if (n <= 1)
return 1;
else 
return n * factorial(n - 1);
}
int pgcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    if(a>b)
     return pgcd(b, a - b);


}
int sumnbrrec(int n)
{
    return n < 10 ? n  : n%10 + sumnbrrec(n/10);
}
int countlong(int n){
    return n < 10 ? 1 : 1 + countlong(n/10);
}

int main() {
    int choice, n, a, b;

    do {
        printf("\nMenu:\n");
        printf("1. Factorielle\n");
        printf("2. PGCD\n");
        printf("3. Somme des chiffres\n");
        printf("4. Nombre de chiffres\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez un nombre: ");
                scanf("%d", &n);
                printf("La factorielle de %d est %d\n", n, factorial(n));
                break;
            case 2:
                printf("Entrez deux nombres: ");
                scanf("%d %d", &a, &b);
                printf("Le PGCD de %d et %d est %d\n", a, b, pgcd(a, b));
                break;
            case 3:
                printf("Entrez un nombre: ");
                scanf("%d", &n);
                printf("La somme des chiffres de %d est %d\n", n, sumnbrrec(n));
                break;
            case 4:
                printf("Entrez un nombre: ");
                scanf("%d", &n);
                printf("Le nombre de chiffres dans %d est %d\n", n, countlong(n));
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 0);

    return 0;
}