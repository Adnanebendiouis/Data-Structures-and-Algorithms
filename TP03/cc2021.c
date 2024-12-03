#include <stdio.h>
int fct1(int *);
void fct2(int);
float pi = 3.14;
int val = 10;
int ingtersection_iter(int A[], int n, int T[], int m)
{
    int j = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (A[i] > T[j])
            {
                continue;
            }
            if (A[i] == T[j])
            {
                printf("%d | %d\n", A[i], T[j]);
                return 0;
            }
        }
        if (A[i] < T[j])
        {
            continue;
        }
    }
    return 1;
}
int intersection_rec(int A[], int n, int T[], int m, int i, int j)
{
    if (i < 0 || j < 0)
    {
        return 1;
    }
    else if (A[i] == T[j])
    {
        return 0;
    }
    else if (A[i] < T[j])
    {
        return intersection_rec(A, n, T, m, i, j - 1);
    }
    else
    {
        return intersection_rec(A, n, T, m, i - 1, j);
    }
}
int verif_id_rec(int T1[], int N, int T2[], int M)
{
    if (M < 0 || N < 0)
        return 1;
    if (T1[N] == T2[M])
        return 0;
    if (T1[N] < T2[M])
        return verif_id_rec(T1, N, T2, M - 1);
    else
        return verif_id_rec(T1, N - 1, T2, M);
}
int ver_iter(double A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 10)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return (count > 0) ? 1 : 0;
}
int ver_rec(double A[], int n, int count, int i)
{
    if (i >= n)
    {
        return (count > n / 2) ? 1 : 0;
    }
    if (A[i] > 10)
    {
        return ver_rec(A, n, count + 1, i + 1);
    }
    else
    {
        return ver_rec(A, n, count, i + 1);
    }
}
void insererDansTableauTrie(int A[], int n, int V, int i) {
    if (i >= n || A[i] > V) {
        if (i < n) {
            insererDansTableauTrie(A, n, A[n - 1], i + 1);
            A[i] = V;
        } else {
            A[n] = V;
        }
        return;
    }
    insererDansTableauTrie(A, n, V, i + 1);
}
void printTab(int T[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d |", T[i]);
    }
}
int est_pair(int n){
    return (n%2==0)?1:0;
}
int separe(int A[],int n,int i,int j){
    if(i==n){
        return 1;
    }
    if(est_pair(A[i])){
        j=i;
        separe(A,n,i+1,j);
}
    else{
        int temp = A[i];
        A[i]=A[j];
        A[j]=temp;
        separe(A,n,i,j+1);
}
}
int main(){
    // int val = 5, *ptr;
    // char c = '\x31';
    // ptr = &val;
    // printf("debut main: c=%d val=%d *ptr =%d \n", c, val, *ptr);
    // fct2(val);
    // c = (int)pi;
    // printf("fin main : c = %d val =%d *ptr=%d \n", c, val, *ptr);
    // int A[] = {1, 2, 3, 4, 5};
    int B[100] = {5,6, 8, 9, 10};
    separe(B, 5,0,0);
    printTab(B, 5);
    // printf("%d", intersection_rec(A, 5, B, 5,5,5));
    // return 0;
    // double A[]={9, 7, 0.5, 4, 1.75, 15, 10, 3, 9.5, 8};
    // printf("%d",ver_rec(A,5,0,0));
}
int fct1(int *n)
{
    printf("debut fct1 : n= %d\n", *n);
    if (*n < 6)
    {
        *n = *n + 3;
        return fct1(n);
    }
    else
    {
        printf("fin fct1 : n= %d \n", *n);
        return 1;
    }
}
void fct2(int x)
{
    if (x)
    {
        int val = fct1(&x) + 1;
        printf("debut fct2: x = %d val = %d \n", x, val);
    }
    x = x + 1;
    printf("fin fct2: x =%d val= %d \n", x, val);
}