#include <stdio.h>
#include<time.h>

void findPythagoreanTriplets(int N)
{
    int count = 0;
    for (int c = 3; count < N; c++)
    {
        for (int b = 2; b < c; b++)
        {
            for (int a = 1; a < b; a++)
            {
                if (a * a + b * b == c * c)
                {
                    count++;
                    printf("%d: %d^2 + %d^2 = %d^2 (= %d)\n", count, a, b, c, c * c);
                }
            }
        }
    }
}
void findPythagoreanTripletsBetter(int n)
{
    int count = 0;
    for (int c = 3; count < n; c++)
    {
        for (int b = c - 1; b >= 2; b--)
        {
            for (int a = b-1; a >= 1; a--)
            {
                if (a * a + b * b == c * c)
                {
                    count++;
                    printf("%d: %d^2 + %d^2 = %d^2 (= %d)\n", count, a, b, c, c * c);
                }
            }
        }
    }
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
void findPythagoreanTripletsOptimized(int n)
{
    int count = 0;
    for (int m = 2; count < n; m++)
    {
        for (int k = 1; k < m && count < n; k++)
        {
            if ((m - k) % 2 == 1 && gcd(m, k) == 1) 
            {
                int a = m * m - k * k;
                int b = 2 * m * k;
                int c = m * m + k * k;
                count++;
                printf("%d: %d^2 + %d^2 = %d^2 (= %d)\n", count, a, b, c, c * c);
            }
        }
    }
}





int main()
{
    int N;
    long t = time(NULL);
    printf("Enter the number of Pythagorean triplets to display: ");
    scanf("%d", &N);
    findPythagoreanTripletsOptimized(N);
    printf("%ld",time(NULL)-t);
    return 0;
}