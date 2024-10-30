#include<stdio.h>
int numrepeat(int A[],int n,int num){
    int count = 0;
    for(int i = 0;i<n;i++){
        if(A[i] == num){
            count++;
        }
    }
    return count>1?1:0;
}
int elerepeat(int A[],int n){
   for(int i=0;i<n;i++){
        if (!numrepeat(A,n,A[i]))
        {
            return 0;
        }
    }
    return 1;
}
int main(){
    int A[]={1,1,1,2,3,3,3,4,4,4};
    int n = sizeof(A)/sizeof(A[0]);
    printf("%d\n",elerepeat(A,n));
    return 0;

}