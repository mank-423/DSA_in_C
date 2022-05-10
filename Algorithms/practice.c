#include<stdio.h>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int a[], int n){
    int i;
    printf("The elements are: \n");
    for (i=0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n){
    int i,j;
    for (i=0; i < n-1; i++)   //Loop for each pass
    {
        for (j = 0; j < n-1 - i; j++)//Loop for comparison
        {
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }    
        }
    }
}


void insertionSort(int *a, int n){
    int i,j;
    int key;
    for (i = 1; i < n-1; i++){
        key = a[i];
        j = i-1;
        while (j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


void selectionSort(int *a, int n){
    int i,j,minIndex = 0;
    for (i = 0; i < n-1; i++){
        minIndex = i;
        for (j = i+1; j < n-1; j++){
            if (a[j] > a[minIndex]){
                minIndex = j;
            }
        }
        swap( &a[j], &a[minIndex]);
    }
}


int main(){
    int arr[] = {55,6,7,1};
    int n = 4, y = 5;
    printArray(arr, n);
    //bubbleSort(arr,n);
    //insertionSort(arr,n);
    selectionSort(arr,n);
    printArray(arr, n);
    
}