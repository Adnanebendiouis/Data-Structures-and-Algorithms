#include<stdio.h>
int numrepeat(int A[],int n,int num){
    int count = 0;
    for(int i = 0;i<n;i++){
        if(A[i] == num){
            count++;
        }
    }
    return count>1?count:0;
}





int main(){
    int A[]={1,2,3,4,5,6,7};
    printf("%d\n",numrepeat(A,9,4));
    return 0;

}