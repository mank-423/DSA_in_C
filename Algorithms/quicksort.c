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

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do {
    while (a[i] <= pivot){
        i++;
    }
    while (a[j] > pivot){
        j--;
    }

    if (i < j){
        swap( &a[i], &a[j]);
    }
    }  while (i<j);

    swap(&a[low], &a[j]);
    return j;
}

void quicksort(int a[], int low, int high){
    int partitionIndex;
    if (low < high){
        partitionIndex = partition(a, low, high);
        quicksort(a, low, partitionIndex-1); //Sort left subarray
        quicksort(a, partitionIndex+1, high); //Sort right subarray
    }
}


int main()
{
    int arr[] = {10,2,3,4,55,90};
    int n = 6;
    printArray(arr, n);
    quicksort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}