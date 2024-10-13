#include <stdlib.h>
#include <stdio.h>
int main(){
int N,M,S,P,i; float m;
printf("\n Entrez N : "); scanf("%d", &N);
for (S=0, P=1, i=1 ; i<=N ; i++){ printf("Entrez nombre %d: ", i); scanf("%d", &M);
S += M; //S=S+M;
P *= M; //P=P*M;
}
m=(float)S/N;
printf("\n S = %d \n", S);
printf("\n P = %d \n", P);
printf("\n m = %.2f\n", m);
return 0;
}