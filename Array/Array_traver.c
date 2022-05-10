#include<stdio.h>
#include<conio.h>

void traverse(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d \n",arr[i]);
    }
    
}
int main()
{
    int arr[100] = {1,2,3,4};
    int *ptr = arr;
    traverse(ptr,4);
    return 0;
}