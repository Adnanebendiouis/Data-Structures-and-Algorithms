#include <stdio.h>
#include <math.h>

int leurChiffres(int n){
    int a, b, c, d;
    a = n / 100;
    b = n % 100;
    c = b / 10;
    d = b % 10;
    return (n == pow(a, 3) + pow(c, 3) + pow(d, 3));
}

void forloop(){
    int i = 140;
    for(i = 140; i < 500; i++){
        if(leurChiffres(i)){
            printf("%d\n", i);
        }
    }
}

void whileloop(){
    int i = 140;
    while(i < 500){
        if(leurChiffres(i)){
            printf("%d\n", i);
        }
        i++;
    }
}

void dowhileloop(){
    int i = 140;
    do{
        if(leurChiffres(i)){
            printf("%d\n", i);
        }
        i++;
    } while(i < 500);
}

int main(){
    int choice;
    do {
        printf("Menu:\n");
        printf("1) For loop\n");
        printf("2) While loop\n");
        printf("3) Do-while loop\n");
        printf("0) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                forloop();
                break;
            case 2:
                whileloop();
                break;
            case 3:
                dowhileloop();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    return 0;
}
