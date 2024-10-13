#include <stdlib.h>
#include <stdio.h>
int main(){
int A,B,C ;
printf("Introduisez trois nombres entiers :\n"); scanf("%d %d %d", &A, &B, &C);
if (A>B && A>C)
printf("Max=%d\n",A);
else if (B>C)
printf("Max=%d\n",B);
else
printf("Max=%d\n",C);
return 0;
}
