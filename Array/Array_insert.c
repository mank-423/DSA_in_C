#include<stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d \n",arr[i]);
    }
}

//Problem - If the insertion is successful then , print otherwise not  - done
//1. How to insert the element as the array as it is keeps itself sorted
//1 2 3 44 67 889 - want to insert an element 20 then lookup for the index
//2. How to insert if we don't care about the order - done
//Swapping the values by last and the idnex element

//1.At index insertion 
int ins_atindex(int arr[],int size,int element,int capacity){

    if (size>=capacity){
        return -1;
    }

    else{
        int i,index = 0;
        for (i=0;i<size;i++){
            if (arr[i]<element){
                index++;
            }
            else{
                break;
            }
        }
        //index found
        //reverse
        for (i = size-1;i >= index; i--){
            arr[i+1]=arr[i];
        }
        arr[index] = element; 
        printf("Insertion successful /n");
    }
    return 0;
}

//2.
//Order not important
int Ins_noorder(int arr[],int size,int element,int capacity,int index){
    int temp;
    if (size>=capacity){
        return -1;
    }
    //Code for insertion with swap
    else{
    temp = arr[index];
    arr[index] = element;
    arr[size] = temp;
    }
    printf("Insertion successful \n");
    return 0;
}
    

int Indinsertion(int arr[],int size,int element, int capacity,int index){
    if (size>=capacity){
        return -1;
    }
    //Moving elements from last
    for (int i = size-1;i >= index; i--){
        arr[i+1]=arr[i];
    }
    arr[index] = element; 
    printf("Insertion successful /n");
    return 1;
}

int main()
{
    int  arr[100] =  {1,2,40,60,72};
    int size = 5, element = 45;
    int index = 1;
    printf("Before the insertion: \n");
    display(arr,size);
    //Indinsertion (arr,size,element,100,index);
    //Ins_noorder(arr,size,element,100,index);
    ins_atindex(arr,size,element,100);
    size++; //As the size of array will increase
    printf("After the insertion: \n");
    display(arr,size);



    return 0;
}