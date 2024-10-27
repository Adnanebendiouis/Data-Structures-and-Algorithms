#include <stdio.h>
#include <time.h>
void lireTab(int T[], int n)
{

    for (int i = 0; i < n ; i++)
    {
        printf("Entrer le nombre %d : ", i + 1);
        scanf("%d", &T[i]);
    }
}
void affichierTab(int T[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        printf("%d |", T[i]);
    }
    printf("\n");
}
void copyTab(int A[],int T[],int n){
    for(int i =0;i<n;i++){
        T[i]=A[i];
    }
}
void triaBulle(int A[],int T[], int n)
{
    long t = clock();
    copyTab(A,T,n);
    int i, j, temp = 0;

    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (T[j] > T[j + 1])
            {
                temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
            affichierTab(T, n);
        }
        
    }
    printf("Total execution time: %ld seconds\n",clock()-t );
}
void Tri_Insertion(int tab[],int T[], int n)
{

    long t = clock();
    copyTab(tab,T,n);
    int i, j, val;
    for (i = 1; i < n ; i++)
    {
        val = T[i];
        j = i;
        while (j > 0 && T[j - 1] > val)
        {
            T[j] = T[j - 1];
            j--;
        }
        T[j] = val;
        affichierTab(T, n);
    }

    printf("Total execution time: %ld seconds\n",clock()-t );

}
void Tri_Selection(int tab[], int T[], int n) {

    copyTab(tab, T, n);

  
    long start_time = clock();

    int i, j, temp, pg;
    
    for (i = n - 1; i > 0; i--) {
        pg = 0; 
        for (j = 1; j <= i; j++) {
            if (T[j] > T[pg]) {
                pg = j;
            }
        }
        if (pg != i) {
            temp = T[pg];
            T[pg] = T[i];
            T[i] = temp;
        }
        affichierTab(T, n);
    }
    long end_time = clock();
    printf("Total execution time: %ld seconds\n", end_time - start_time);
}
int main()
{
//     int longArray[] = {
//     78, 12, 34, 56, 89, 23, 67, 45, 90, 32, 10, 11, 25, 62, 77, 98, 100, 1, 29, 87, 
//     78, 12, 34, 56, 89, 23, 67, 45, 90, 32, 10, 11, 25, 62, 77, 98, 100, 1, 29, 87, 
//     78, 12, 34, 56, 89, 23, 67, 45, 90, 32, 10, 11, 25, 62, 77, 98, 100, 1, 29, 87, 
//     78, 12, 34, 56, 89, 23, 67, 45, 90, 32, 10, 11, 25, 62, 77, 98, 100, 1, 29, 87, 
//     43, 68, 55, 76, 14, 9, 6, 53, 72, 88, 19, 41, 13, 37, 60, 3, 44, 74, 91, 21, 
//     15, 40, 52, 80, 49, 85, 5, 31, 8, 24, 66, 28, 50, 2, 81, 20, 99, 16, 36, 47,
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     7, 18, 59, 61, 33, 83, 38, 17, 64, 92, 70, 35, 48, 27, 95, 4, 26, 63, 84, 54, 
//     75, 42, 86, 39, 69, 57, 30, 73, 46, 82, 94, 22, 58, 65, 97, 71, 93, 85, 51, 96,
//     75, 42, 86, 39, 69, 57, 30, 73, 46, 82, 94, 22, 58, 65, 97, 71, 93, 85, 51, 96,
//     75, 42, 86, 39, 69, 57, 30, 73, 46, 82, 94, 22, 58, 65, 97, 71, 93, 85, 51, 96,
//     75, 42, 86, 39, 69, 57, 30, 73, 46, 82, 94, 22, 58, 65, 97, 71, 93, 85, 51, 96,
//     75, 42, 86, 39, 69, 57, 30, 73, 46, 82, 94, 22, 58, 65, 97, 71, 93, 85, 51, 96
// };
// int nLong = sizeof(longArray) / sizeof(longArray[0]);
    // triaBulle(longArray, nLong);7
    // Tri_Insertion(longArray, nLong);8
    // Tri_Selection(longArray, nLong);8
    int choix ;

    int n=0;
    int A[500]={0};
    int T[500]={0};

    do{
    printf("comment vous voulez sorter votre tab\n");
    printf("1) lire un tableau\n");
    printf("2) affichier un tableau\n");
    printf("3) trie a bulle\n");
    printf("4) trie par insertion\n");
    printf("5) trie par selection\n");
    printf("6) Quitter\n");
    scanf("%d",&choix);
    switch(choix){
        case 1:
        printf("entrer la taille du tableau :");
        scanf("%d",&n);
        lireTab(A,n);
        break;
        case 2:
        affichierTab(A,n);
        break;
        case 3:
        triaBulle(A,T,n);
        break;
        case 4:
        Tri_Insertion(A,T,n);
        break;
        case 5:
        Tri_Selection(A,T,n);
        break;
        
    }
    }while(choix!=6);
//     start_time = clock();
//     printf("Program Start Time: %ld\n", (long)start_time);
//     int bubbleArray[] = {64, 34, 25, 12, 22, 11, 90};
//     int insertionArray[] = {9, 2, 3, 4, 18, 5, 7};
//     int selectionArray[] = {29, 10, 14, 37, 13};


//     int n1 = sizeof(bubbleArray) / sizeof(bubbleArray[0]);
//     int n2 = sizeof(insertionArray) / sizeof(insertionArray[0]);
//     int n3 = sizeof(selectionArray) / sizeof(selectionArray[0]);
//     printf("\nOriginal Bubble Sort Array: \n");
//     affichierTab(bubbleArray, n1);
//     triaBulle(bubbleArray, n1);
//     printf("\nSorted Bubble Sort Array: \n");
//     affichierTab(bubbleArray, n1);
//     printf("\nOriginal Insertion Sort Array: \n");
//     affichierTab(insertionArray, n2);
//     Tri_Insertion(insertionArray, n2);
//     printf("\nSorted Insertion Sort Array: \n");
//     affichierTab(insertionArray, n2);
//     printf("\nOriginal Selection Sort Array: \n");
//     affichierTab(selectionArray, n3);
//     Tri_Selection(selectionArray, n3);
//     printf("\nSorted Selection Sort Array: \n");
//     affichierTab(selectionArray, n3);

//     //long array test
//     printf("\nOriginal Bubble Sort Array: \n");
//     affichierTab(longArray, nLong);

//     printf("\nSorted Bubble Sort Array: \n");
//     affichierTab(longArray, nLong);
//     printf("\nOriginal Insertion Sort Array: \n");
//     affichierTab(longArray, nLong);

//     printf("\nSorted Insertion Sort Array: \n");
//     affichierTab(longArray, nLong);
//     printf("\nOriginal Selection Sort Array: \n");
//     affichierTab(longArray, nLong);

//     printf("\nSorted Selection Sort Array: \n");
//     affichierTab(longArray, nLong);

    return 0;
 }