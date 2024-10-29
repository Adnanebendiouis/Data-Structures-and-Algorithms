#include <stdio.h>
double pow_rec(int nb,int power){
    if(power==0){
        return 1;
    }
    return nb*pow_rec(nb,--power);
}
int sumnbriter(int n){
    int somme=0;
    while(n>0){
        somme+=n%10;
        n/=10;
    }
    return somme;
}
int sumnbrrec(int n){
    if(n==0){
        return 0;
    }
    return n%10+sumnbrrec(n/10);

}

int main(){
  printf("%f\n",pow_rec(2,10));
  printf("%d\n",sumnbriter(429));
  printf("%d\n",sumnbrrec(429));
}