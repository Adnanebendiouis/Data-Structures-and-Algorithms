#include<stdio.h>
#include<string.h>

int Incorrectement_parenthesee(char arg[]){
    int i = 0;
    int count = 0;
    while(arg[i] != '\0'){
        if(arg[i] == '('){
            count++;
        }
        else if(arg[i] == ')'){
            count--;
        }
        i++;
    }
    if(count == 0){
        return 0;
    }
    else{
        return count;
    }
}



int main(){
    char chaine[]="(int(double((bool))))";
    printf("%d",Incorrectement_parenthesee(chaine));
    
    
    
    return 0;
}