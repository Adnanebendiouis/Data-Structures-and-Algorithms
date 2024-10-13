#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int ispythagore(int a, int b, int c){
    a = pow(a, 2);
    b = pow(b, 2);
    c = pow(c, 2);
    printf("%d\n", a);
    printf("%d\n", b);
    // a += b;
    printf("%d\n", c);
    if (c == a) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int a = 3;
    int b = 4;
    int c = 5;
    int result = ispythagore(a, b, c);
    printf("%d", result);
    return 0;
}   