#include <stdlib.h>
#include <stdio.h>
int main(){
int A, B;
printf("\n\tIntroduisez deux nombres entiers :\n");
scanf("%d %d", &A, &B);
if ((A>0 && B>0) || (A<0 && B<0))
printf(" produit positif\n ");
else if ((A<0 && B>0) || (A>0 && B<0))
printf(" produit négatif\n ");
else
printf(" produit nul \n ");
return 0;
}