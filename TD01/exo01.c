#include <stdio.h>

void findPythagoreanTriplets(int N) {
    int count = 0;
    for (int c = 1; count < N; c++) {
        for (int b = 1; b < c; b++) {
            for (int a = 1; a < b; a++) {
                if (a * a + b * b == c * c) {
                    count++;
                    printf("%d: %d^2 + %d^2 = %d^2 (= %d)\n", count, a, b, c, c * c);
                    if (count == N) {
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    int N;
    printf("Enter the number of Pythagorean triplets to display: ");
    scanf("%d", &N);
    findPythagoreanTriplets(N);
    return 0;
}