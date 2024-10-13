#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int convertireTemps(int t,int *heures,int *minutes,int *secondes){
     *heures = t / 3600;
     *minutes = (t % 3600) / 60;
     *secondes = t % 60;

}
int main(){
    int t,heures,minutes,secondes;
    printf("entree un temps en seconde: \n");
    scanf("%d",&t);
    convertireTemps(t,&heures,&minutes,&secondes);
    printf("%d:%d:%d",heures,minutes,secondes);
}