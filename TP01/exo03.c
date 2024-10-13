#include <stdio.h>
#include <math.h>
int nombreparfaitfor(int n){
    
    int sum=0;
    for(int i=1 ;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
        
    }
      if( n==sum){
        printf("%d est parfait\n",n);
    }
    else{
        printf("%d n'est pas parfait\n",n);
    }
}
int nombreparfaitwhile(int n){
    int sum=0;
    int i=1;
    while(i<n){
        if(n%i==0){
            sum+=i;
            }
            i++;
    }
        if( n==sum){
        printf("%d est parfait\n",n);
    }
    else{
        printf("%d n'est pas parfait\n",n);
    }
}
int nombreparfaitdowhile(int n){
    int sum=0;
    int i=1;
    do
    {
        if(n%i==0){
            sum+=i;
        }
        i++;
    } while (i<n);
    if( n==sum){
        printf("%d est parfait\n",n);
    }
    else{
        printf("%d n'est pas parfait\n",n);
    }
    
}
int tester(){
    for(int i=0;i<1000;i++){
        if (nombreparfaitfor(i))
        {
            printf("%d est parfait\n",i);

        }
        else{
            printf("%d n'est pas parfait\n",i);
        }
        
    }
}
int main(){
    int n=0;
  int choix ;
  do
  {
  printf("1)tester un nombre parfait for loop\n");
  printf("2)tester un nombre parfait for while loop\n");
  printf("3)tester un nombre parfait for do while loop\n");
  printf("4)pour affichier tout les nombres parfait entre 0 et 1000\n");
  printf("0)entrer 0 pour quitter\n");
  scanf("%d",&choix);
  printf("entrer votre nombre :\n");
  scanf("%d",&n);
switch(choix){
    case 1:nombreparfaitfor(n);
    break;
    case 2:nombreparfaitwhile(n);
    break;
    case 3:nombreparfaitdowhile(n);
    break;
    case 4:tester();
    break;
    default:printf("error");
    break;
}
 } while (choix!=0);
}