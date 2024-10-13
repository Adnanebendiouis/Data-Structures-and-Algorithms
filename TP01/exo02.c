#include <stdio.h>
#include <math.h>

int leurChiffres(int n){
    int a,b,c,d;
a=n/100;
b=n%100;
c=b/10;
d=b%10;
return(n==pow(a, 3) + pow(c, 3) + pow(d,3));
    }
void forloop(){
    int i=140;
    for(i=140;i<500;i++){
    if(leurChiffres(i)){
        printf("%d\n",i);
    }
    }
}
void whileloop(){
    int i=140;
    while(i<500){
        if(leurChiffres(i)){
            printf("%d\n",i);
        }
        i++;
    }
}
void dowhileloop(){
    int i=140;
    do{
        if(leurChiffres(i)){
            printf("%d\n",i);
        }
        i++;
    }while(i<(500));
}




int main(){

forloop();

whileloop();
dowhileloop();
    
return 0;
}
