#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void printArray(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int maximum(int *a, int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
    
}

void countSort(int *a, int n){
    //Find the maximum element in a
    int max = maximum(a,n);
    int i,j;
    
    //Create the count array
    int *count = (int *)malloc(max+1 * sizeof(int));
    
    //Initialize the array elements to 0
    for (i = 0; i < max+1 ; i++)
    {
        count[i] = 0;    
    }

    //Increment the correspondning index in the count array
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]]+1;
    }
    
    i=0; //Counter for count array
    j=0; //Counter for the final array
    while (i < max){
        if (count[i] > 0){
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int arr[] = {10,2,3,4,55,90};
    int n = 6;
    printArray(arr, n);
    countSort(arr,n);
    printArray(arr, n);
    return 0;
}