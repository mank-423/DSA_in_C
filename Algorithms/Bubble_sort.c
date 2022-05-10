#include<stdio.h>
#include<conio.h>

void printArray(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubblesort(int a[], int n){
    int i,j,temp;
    for ( i = 0; i < n-1; i++) //Number of passes
    {
        //printf("The pass %d \n", i+1); //Printing the passes
        for ( j = 0; j < n-1-i; j++) //For swapping in each pass
        {
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


void bubblesortAdaptive(int a[], int n){
    int i,j,temp;
    int isSorted = 0;
    for ( i = 0; i < n-1; i++) //Number of passes
    {
        printf("The pass %d \n", i+1);
        isSorted = 1; //If it doesn't goes in this condition
        for ( j = 0; j < n-1-i; j++) //For swapping in each pass
        {
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                isSorted = 0; //If condn is satisfied
            }
        }
        if (isSorted){
            return;
        }   
    }
}

int main()
{
    int a1[] = {10,2,3,66,78,1,24,55,12,11,67,69,100,6,14};
    int a2[] = {1,2,3,4,5,6};
    int n2 = 6, n1 = 15;
    printf("For the first array: \n");
    printArray(a1,n1); //Printing the array before sorting
    bubblesort(a1,n1); //performing the sort
    printArray(a1,n1); //Printing the array after sorting

    printf("For the second array: \n");
    printArray(a2,n2); //Printing the array before sorting
    bubblesortAdaptive(a2,n2); //performing the sort
    printArray(a2,n2); //Printing the array after sorting


    return 0;
}