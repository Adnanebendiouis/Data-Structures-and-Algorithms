#include<stdio.h>
#include<string.h>

int Incorrectement_parenthesee(char *arg){
    int i = 0;
    int count = 0;
    while(arg[i] != '\0'){
        if(arg[i] == '('){
            count++;
        }
        else if(arg[i] == ')'){
            count--;
        }
        if(count<0){
        return -i-1;
    }
        i++;
    }
    if(count == 0){
        return 0;
    }
    else{
        return count;
    }
     if(count == 0){
        return 0;
    }
}



int main(){
    char *chaine="(int))(double((bool)))))))";
    // printf("%d\n",strlen(chaine));
    printf("%d\n",Incorrectement_parenthesee(chaine));
    
    
    
    return 0;
}