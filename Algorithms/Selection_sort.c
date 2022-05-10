#include<stdio.h>

void printArray(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selectionsort(int *a, int n){
    int i,j;
    int minInd = 0;
    printf("Runing Selection Sort..... \n");
    for (i = 0; i < n-1; i++)
    {
        minInd = i;
        for (j = i+1;j < n-1; j++){
            if (a[j] < a[minInd]){
                minInd = j;
            }
        }
        //Swapping the elements
        swap(&a[i], &a[minInd]);
    }
    
}

int main()
{
    int arr[] = {10,2,3,4,55,90};
    int n = 6;
    printArray(arr, n);
    selectionsort(arr, n);
    printArray(arr, n);
    return 0;
}