#include <stdio.h>
int chercheTab(int A[], int T[], int n, int m)
{
    if (n > m)
    {
        n = m;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (A[i] == T[i])
        {
            printf("%d  |", A[i]);
            count++;
        }
    }
    return count;
}

int main()
{
    int A[] = {1, 2, 3};
    int T[] = {1, 2, 3, 4, 5};
    printf("Le nombre d'element est : %d", chercheTab(A, T, 4, 2));

    return 0;
}