#include <stdio.h>
int chercheTab(int A[], int T[], int n, int m)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i] == T[j])
            {
                count++;
                printf("%d |",A[i]);
                break;
            }
        }
    }
    return count;
}


int main()
{
    int A[] = {1, 3, 7};
    int T[] = {1, 2, 3, 7, 5};
    printf("\nLe nombre d'element est : %d\n", chercheTab(A, T, 3, 5));

    return 0;
}