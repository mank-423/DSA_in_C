//Fixed size array creation
//Top element pointer is needed
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr; //Getting the size from the heap for the stack
};



int main(){
    //One way to initialize a stack
    // struct Stack s1;
    // s1.size = 10;
    // s1.top = -1;
    // s1.arr = (int *)malloc(s1.size*sizeof(int));

    //printf("Done Succesfully");
    //Using a pointer for the initialization purpose
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    //Using arrow operator to access the members of the stack
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    printf("Done Succesfully");
   
     
    return 0;
}