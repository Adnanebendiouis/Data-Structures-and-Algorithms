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
int main()
{
    int A[] = {2, 6, 6, 3, 5, 7, 1, 3, 9};
    int size = sizeof(A)/sizeof(A[0]);
    printf("%d\n",cherchetabrec(A,1,size));
    printf("%f\n", pow_rec(2, 10));
    printf("%d\n", sumnbriter(429));
    printf("%d\n", sumnbrrec(429));
}