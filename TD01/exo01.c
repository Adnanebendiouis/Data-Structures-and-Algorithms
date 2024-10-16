#include <stdio.h>

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

int main()
{
    int N;
    printf("Enter the number of Pythagorean triplets to display: ");
    scanf("%d", &N);
    findPythagoreanTriplets(N);
    return 0;
}