#include<stdio.h>
#include<conio.h>

void printArray(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insertionSort(int a[],  int n){
    int i,j,key; 
    //Loop for each pass;
    for (i = 1; i <= n-1; i++)
    {
        //Loop for each pass
        key = a[i];
        j = i-1;
        // > - for ascsending, < - for descending
        while ( j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    
}

int main()
{
    int A[] = {10,1,4,78,2};
    int n = 5;
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);

    return 0;
}