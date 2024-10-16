#include<stdio.h>

void trieParSelectionGrand(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}
int main(){
    int A[] = {9,2,3,4,18,5,7};
    trieParSelectionGrand(A,7);
    for(int i = 0;i<7;i++){
        printf("%d\n",A[i]);
    }
    return 0;
}