#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void to_character(int n) {
    int a, b, o, f;
    a = n / 100; 
    b = n % 100; 
    o = b / 10;  
    f = b % 10;  

    char *chaine1[9] = {
        "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"
    };
    char *chaine2[10] = {
        "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix", "quatre-vingt", "quatre-vingt-dix"
    };
    char *chaine3[10]={"enze","douze","treize","quatorze","quinze","seize","dix-sept","dix-huit","dix-neuf"};

    if (a > 0) {
        a==1 ? printf("cent ") : printf("%s cents ", chaine1[a - 1]);
    
    
        if (o > 0) {
        printf("%s ", chaine2[o - 1]);
        }

        if (f > 0) {
        printf("%s", chaine1[f - 1]);
        }

        printf("\n");
    }
    else { 
        if (o > 1) {
        printf("%s ", chaine2[o - 1]);
        }

        // if (f > 0) {
        //     if ((o==9 || o ==7)&&(f==1))
        //         printf("onze");
        //     else 
        //         printf("%s", chaine1[f - 1]);
        if(o==1&&f>0){
            printf("%s",chaine3[f-1]);
        }


        printf("\n");
    }
}


int main() {
    to_character(71);
    to_character(123);
    to_character(999);
    to_character(100);
    to_character(101);
    to_character(11);
    to_character(12);
    to_character(13);
    to_character(14);
    to_character(15);
    to_character(16);
    to_character(17);
    to_character(18);
    to_character(19);
    
    return 0;
}