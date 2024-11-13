#include <stdio.h>
double pow_rec(double nb, int power)
{
    if (power == 0)
    {
        return 1;
    }
    if(power<0){
        return 1/pow_rec(nb, -power);
    }
    else{
        return nb * pow_rec(nb, power-1);
    }
}
int sumnbriter(int n)
{
    int somme = 0;
    while (n > 0)
    {
        somme += n % 10;
        n /= 10;
    }
    return somme;
}
int sumnbrrec(int n)
{
    return n < 10 ? n  : n%10 + sumnbrrec(n/10);
}
void rechrchedichotomique(int T[],int val,int size){
    if(size == 0){
        return 0;
    }
    
}
int cherchetabrec(int A[], int n, int size)
{
    if (size<0)
    {
        return 0;
    }
    if (A[size] == n)
    {
        return 1;
    }
    return cherchetabrec(A, n, size-1);
}
int incorrectement_parenthesee(char chaine[], int i, int count) {
    if (chaine[i] == '\0') {
        return count;
    }
    if (chaine[i] == '(') {
        return incorrectement_parenthesee(chaine, i+1, count+1);
    }
    if (chaine[i] == ')') {
        if(count == 0){
            return -i-1; 
        } else {
            return incorrectement_parenthesee(chaine, i+1, count-1);
        }
    }
    return incorrectement_parenthesee(chaine, i+1, count);
}
int chercheTabRec(int A[],int T[],int n,int m,int i,int j){
   if(i>=n){
         return 0;
   }
    if(j>=m){
            return chercheTabRec(A,T,n,m,i+1,0);
    }   
    if(A[i]==T[j]){
        printf("%d |",A[i]);
        return 1+chercheTabRec(A,T,n,m,i+1,0);
    }
    return chercheTabRec(A,T,n,m,i,j+1);
}
int recurec(int A[],int n,int i,int element){
    if(n==i){
        return 0;
    }
    if(A[i]==element){
        return 1+recurec(A,n,i+1,element);
    }
    return recurec(A,n,i+1,element);
 
}
int numrepeat(int A[], int n, int num, int i, int count) {
    if (i >= n) {
        return count;
    }
    if (A[i] == num) {
        count++;
    }
    return numrepeat(A, n, num, i + 1, count);
}
int rechelem(int A[], int n, int i) {
    if (i >= n) {
        return 1;
    }
    if (numrepeat(A, n, A[i], 0, 0) < 2) {
        return 0;
    }
    return rechelem(A, n, i + 1);
}
int main()
{
    char chaine1[] = "(abc(defij)klmnop)";
    char chaine2[] = "(abc(def)))ghijklmn()";
    // printf("Resultat pour chaine1  %d\n", incorrectement_parenthesee(chaine1, 0, 0));
    printf("Resultat pour chaine2  %d\n", incorrectement_parenthesee(chaine2, 0, 0));
    // int A[] = {2, 6, 6, 3, 5, 7, 1, 3, 9};
    // int size = sizeof(A)/sizeof(A[0]);
    // printf("%d\n",cherchetabrec(A,1,size));
    // printf("%f\n", pow_rec(2, -2));
    // printf("%d",sumnbrrec(429));
    // printf("%d\n", sumnbriter(429));
    // printf("%d\n", sumnbrrec(429));
    // int T1[] = {1, 3, 7};
    // int T2[] = {1, 2, 3, 4, 5, 6};
    // int n1 = sizeof(T1) / sizeof(T1[0]);
    // int m = sizeof(T2) / sizeof(T2[0]);
    // int A[]={2,5,2,8,9,8,2,5};
    // int n = sizeof(A) / sizeof(A[0]);
    // int count = recurec(A,n,0,2);
    // if(count==0){
    //     printf("Element non trouve\n");
    //     }
    //     else if(count<2){
    //         printf("the element does not repeat\n");
    //     }
    //     else{
    //         printf("the element repeats %d times\n",count);
    //     }
    

    // printf("Les elements communs sont : ");
    // int count1 = chercheTabRec(T1, T2, n, m, 0, 0);
    // printf("\nLe nombre d elements est : %d\n", count1);
    int A[] = {1, 2, 3,  3, 1, 4, 4};
    int n = sizeof(A) / sizeof(A[0]);

    if (rechelem(A, n, 0)) {
        printf("Tous les elements apparaissent au moins deux fois.\n");
    } else {
        printf("Tous les elements n'apparaissent pas au moins deux fois.\n");
    }
}