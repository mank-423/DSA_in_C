#include<stdio.h>
#include<conio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d \n",arr[i]);
    }
}
//Finish making the sorting funtion
//Done
void sort(int a[],int size)
{
    int temp;
    for(int i=0;i<size;i++){
        for (int j=0;j<size-1;j++){
            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    display(a,size);
}

int lin_search(int element,int size,int arr[]){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element){
            return i;
        }
    }
    return -1;
}

int bin_search(int arr[], int size, int element){
    int low,mid,high; 
    low = 0;
    high = size-1;

    while (low<=high){
    //start searching
    mid = (high+low)/2;

    if (arr[mid]==element){
        return mid;
    }

    else if (arr[mid]<element){
        low = mid+1;
    }

    else{
        high  = mid-1;
    }
    }
    //Searching ends
    return -1;
}
int main()
{
    int search_Index;
    int element = 55;
    //All for linear search
    //int size = 6;
    int arr[100]={1,55,6,78,9,24};//Unsorted array for linear search
    // search_Index = lin_search(element,size,arr);
    // if (search_Index >= 0){
    //     printf("Element %d found at index %d",element, search_Index);
    // }

    // else{
    //     printf("Element %d not in array",element);
    // }

    
    int *ptr = arr;
    int size = 6;
    sort(ptr,size);
    search_Index = bin_search(arr,size,element);
    printf("Element %d found at index %d",element, search_Index);
    
    return 0;
}