#include <stdio.h>
double pow_rec(int nb, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return nb * pow_rec(nb, --power);
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
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + sumnbrrec(n / 10);
}
int cherchetabiter(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == n)
            return 1;
    }
    return 0;
}
int cherchetabrec(int A[], int n, int size)
{
    if (size < 0)
    {
        return 0;
    }
    if (A[size] == n)
    {
        return 1;
    }
    return cherchetabrec(A, n, --size);
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
int main()
{
    // char chaine1[] = "(abc(defij)klmnop)";
    // char chaine2[] = "(abc(def)))ghijklmn()";
    // printf("Resultat pour chaine1  %d\n", incorrectement_parenthesee(chaine1, 0, 0));
    // printf("Resultat pour chaine2  %d\n", incorrectement_parenthesee(chaine2, 0, 0));
    // int A[] = {2, 6, 6, 3, 5, 7, 1, 3, 9};
    // int size = sizeof(A)/sizeof(A[0]);
    // printf("%d\n",cherchetabrec(A,1,size));
    // printf("%f\n", pow_rec(2, 10));
    // printf("%d\n", sumnbriter(429));
    // printf("%d\n", sumnbrrec(429));
    int T1[] = {1, 3, 7};
    int T2[] = {1, 2, 3, 4, 5, 6};
    // int n = sizeof(T1) / sizeof(T1[0]);
    int m = sizeof(T2) / sizeof(T2[0]);
    int A[]={2,5,2,8,9,8,2,5};
    int n = sizeof(A) / sizeof(A[0]);
    int count = recurec(A,n,0,2);
    if(count==0){
        printf("Element non trouve\n");
        }
        else if(count<2){
            printf("the element does not repeat\n");
        }
        else{
            printf("the element repeats %d times\n",count);
        }
    

    printf("Les elements communs sont : ");
    int count1 = chercheTabRec(T1, T2, n, m, 0, 0);
    printf("\nLe nombre d elements est : %d\n", count1);
}