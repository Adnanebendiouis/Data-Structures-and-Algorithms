#include <stdio.h>
#include <time.h>
void lireTab(int T[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        printf("Entrer le nombre %d : ", i + 1);
        scanf("%d", &T[i]);
    }
}
void affichierTab(int T[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d |", T[i]);
    }
    printf("end \n");
}
void triaBulle(int T[], int n)
{
    int i, j, temp = 0;
    for (i = n - 1; i > 1; i--)
    {
        for (j = 0; j < i - 1; j++)
        {
            if (T[j] > T[j + 1])
            {
                temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
        affichierTab(T, n);
    }
}
void Tri_Insertion(int tab[], int n)
{
    int i, j, val;
    for (i = 1; i < n - 1; i++)
    {
        val = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > val)
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = val;
        affichierTab(tab, n);
    }
}
void Tri_Selection(int tab[], int n)
{
    int i, j, temp, pg;
    i = n - 1;
    while (i > 0)
    {
        pg = 0;
        for (j = 0; j <= i; j++)
        {
            if (tab[j] > tab[pg])
            {
                pg = j;
            }
        }
        temp = tab[pg];
        tab[pg] = tab[i];
        tab[i] = temp;
        i = i - 1;
        affichierTab(tab, n);
    }
}
int main()
{
    clock_t start_time, end_time;
    double total_time;
    start_time = clock();
    printf("Program Start Time: %ld\n", (long)start_time);
    int bubbleArray[] = {64, 34, 25, 12, 22, 11, 90};
    int insertionArray[] = {9, 2, 3, 4, 18, 5, 7};
    int selectionArray[] = {29, 10, 14, 37, 13};
    int longArray[] = {
    78, 12, 34, 56, 89, 23, 67, 45, 90, 32, 10, 11, 25, 62, 77, 98, 100, 1, 29, 87, 
    43, 68, 55, 76, 14, 9, 6, 53, 72, 88, 19, 41, 13, 37, 60, 3, 44, 74, 91, 21, 
    15, 40, 52, 80, 49, 85, 5, 31, 8, 24, 66, 28, 50, 2, 81, 20, 99, 16, 36, 47,
    7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
    75, 42, 86, 39, 69, 57, 30, 73, 46, 82, 94, 22, 58, 65, 97, 71, 93, 85, 51, 96
};
int nLong = sizeof(longArray) / sizeof(longArray[0]);
    int n1 = sizeof(bubbleArray) / sizeof(bubbleArray[0]);
    int n2 = sizeof(insertionArray) / sizeof(insertionArray[0]);
    int n3 = sizeof(selectionArray) / sizeof(selectionArray[0]);
    printf("\nOriginal Bubble Sort Array: \n");
    affichierTab(bubbleArray, n1);
    triaBulle(bubbleArray, n1);
    printf("\nSorted Bubble Sort Array: \n");
    affichierTab(bubbleArray, n1);
    printf("\nOriginal Insertion Sort Array: \n");
    affichierTab(insertionArray, n2);
    Tri_Insertion(insertionArray, n2);
    printf("\nSorted Insertion Sort Array: \n");
    affichierTab(insertionArray, n2);
    printf("\nOriginal Selection Sort Array: \n");
    affichierTab(selectionArray, n3);
    Tri_Selection(selectionArray, n3);
    printf("\nSorted Selection Sort Array: \n");
    affichierTab(selectionArray, n3);

    //long array test
    printf("\nOriginal Bubble Sort Array: \n");
    affichierTab(longArray, nLong);
    triaBulle(longArray, nLong);
    printf("\nSorted Bubble Sort Array: \n");
    affichierTab(longArray, nLong);
    printf("\nOriginal Insertion Sort Array: \n");
    affichierTab(longArray, nLong);
    Tri_Insertion(longArray, nLong);
    printf("\nSorted Insertion Sort Array: \n");
    affichierTab(longArray, nLong);
    printf("\nOriginal Selection Sort Array: \n");
    affichierTab(longArray, nLong);
    Tri_Selection(longArray, nLong);
    printf("\nSorted Selection Sort Array: \n");
    affichierTab(longArray, nLong);
    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Total execution time: %f seconds\n", total_time);
    printf("Program End Time: %ld\n", (long)end_time);
    return 0;
}