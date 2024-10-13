#include <stdlib.h>
#include <stdio.h>
int main(){
int N,M,S=0,P=1,i;
float m;
printf("\n Entrez N : ");
scanf("%d", &N);
i=1;
while(i<=N){ printf("Entrez nombre %d: ", i); scanf("%d", &M);
S += M;
P *= M;
i++;
}
m=(float)S/N;
printf("\n S = %d \n", S);
printf("\n P = %d \n", P);
printf("\n m = %.2f\n", m);
return 0;
}