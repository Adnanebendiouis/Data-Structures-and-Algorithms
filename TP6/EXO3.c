#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void Initialiser_Pile(Stack* P) {
    P->top = -1;
}

int Pile_Vide(Stack* P) {
    return P->top == -1;
}

void Empiler(Stack* P, char X) {
    if (P->top < MAX - 1) {
        P->data[++P->top] = X;
    }
}

void Depiler(Stack* P) {
    if (!Pile_Vide(P)) {
        P->top--;
    }
}

char Sommet(Stack* P) {
    if (!Pile_Vide(P)) {
        return P->data[P->top];
    }
    return '\0';
}

int Parentheses_Valides(char* texte) {
    Stack P;
    Initialiser_Pile(&P);
    for (int i = 0; texte[i] != '\0'; i++) {
        if (texte[i] == '(' || texte[i] == '{' || texte[i] == '[') {
            Empiler(&P, texte[i]);
        } else if (texte[i] == ')' || texte[i] == '}' || texte[i] == ']') {
            if (Pile_Vide(&P)) return 0;
            char sommet = Sommet(&P);
            if ((texte[i] == ')' && sommet == '(') || 
                (texte[i] == '}' && sommet == '{') || 
                (texte[i] == ']' && sommet == '[')) {
                Depiler(&P);
            } else {
                return 0;
            }
        }
    }
    return Pile_Vide(&P);
}

int main() {
    char texte[MAX];
    printf("Entrez une chaîne : ");
    scanf("%s", texte);
    if (Parentheses_Valides(texte)) {
        printf("La chaîne est correctement parenthésée.\n");
    } else {
        printf("La chaîne n'est pas correctement parenthésée.\n");
    }
    return 0;
}
