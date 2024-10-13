#include <stdlib.h>
#include <stdio.h>
int main(){
int A,B,C,M ;
printf("Introduisez trois nombres entiers :\n"); scanf("%d %d %d", &A, &B, &C);
M = (A>B) ? A : B;
M = (M>C) ? M : C;
printf(" Max= %d ",M);
return 0;
}