#include<stdio.h>
#include<conio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d \n",arr[i]);
    }
}

//Order not important
int Del_noorder(int arr[],int size,int index,int capacity){
    //Try to use condition - index is greater than capacity then not posible 
    if (index>capacity){
        return -1;
    }
    //Code for deletion updation
    else{
    arr[index] = arr[size-1];
    }
    return 0;
}
    


//Maintaining the order
int Delinsertion(int arr[],int size,int index,int capacity){
    
    //Try to use condition - index is greater than capacity then not posible 
    if (index>capacity){
        return -1;
    }
    //Code for deletion updation
    else{
    for (int i = index;i < size; i++){
        arr[i]=arr[i+1];
    }
    }
    return 0;
}


int main()
{
    int  arr[100] =  {1,2,3,4};
    int size = 4;
    int index = 0;
    printf("Before the deletion: \n");
    display(arr,size);
    //int delete = Delinsertion (arr,size,index,100);
    int delete = Del_noorder(arr,size,index,100);

    if (delete == -1){
        printf("Not possible as index value is out of bound");
    }
    else{
        size--; //As the size of array will increase
        printf("After the deletion: \n");
        display(arr,size);
    }
    
    return 0;
}