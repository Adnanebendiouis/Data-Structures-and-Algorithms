#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkverbe(char verbe[30]){
    int i = strlen(verbe);
    char un = verbe[i-1];
    char deux = verbe[i-2];
    char fin[3];
    fin[0] = deux;
    fin[1] = un;
    fin[2] = '\0';
    char grp1[3] = "er";
    char grp2[3] = "ir";
    if(strcmp(fin, grp1) == 0 || strcmp(fin, grp2) == 0){
        return 1;
    }
    else{
        return 0;
    }
}
void conjugaisonfutur(char verbe[30]){
    int i = strlen(verbe);
    if(checkverbe(verbe)){
        char base[30];
        strncpy(base, verbe, i-2);
        base[i-2] = '\0';
        printf("Je %srai\n", base);
        printf("Tu %sras\n", base);
        printf("Il %sra\n", base);
        printf("Elle %sra\n", base);
        printf("Nous %srons\n", base);
        printf("Vous %srez\n", base);
        printf("Ils %sront\n", base);
        printf("Elles %sront\n", base);
    } else {
        printf("Le mot %s n'est pas un verbe à l'infinitif.\n", verbe);
    }
}

int main(){
    char verbe[30];
    printf("Entrez un verbe: ");
    scanf("%s", verbe);
    if(checkverbe(verbe)){
        printf("Le verbe %s est un verbe à l'infinitif.\n", verbe);
        conjugaisonfutur(verbe);
    }
    else{
        printf("Le mot %s n'est pas un verbe à l'infinitif.\n", verbe);
    }
    return 0;
}