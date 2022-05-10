#include<stdio.h>
#include<stdlib.h>

//Declaring the ADT stack with structure
struct stack
{
    int top;
    int size;
    int *arr;
};

//Empty check on stack
int isEmpty(struct stack *ptr){
    if (ptr->top==-1){
        return 1;
    }

    return 0;
}

//Full check on stack
int isFull(struct stack *ptr){
    if (ptr->top==ptr->size-1){
        return 1;
    }

    return 0;
}

//Push the elements in stack
void push(struct stack *ptr, int value){
    if (isFull(ptr)){
        printf("Stack overflow \n");
        printf("Cannot push the element: %d \n",value);
    }

    ptr->top++;
    ptr->arr[ptr->top] = value;

}

//Pop the elements of the stack
int pop(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("Stack underflow");
        return -1;
    }

    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

//Function stackBottom : Bottom element of the stack
//O(1) Time complexity
int stackBottom(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("No element at bottom\n");
    }
    return ptr->arr[0];
}

//Function stackBottom : Bottom element of the stack
//o(n) Time Complexity
int stackTop(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("No element in stack\n");
    }
    return ptr->arr[ptr->top];
}

int main(){
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->top = -1;
    s1->size = 5;
    s1->arr = (int *)malloc(s1->size * sizeof(int));

    push(s1,4);
    push(s1,3);
    push(s1,6);
    push(s1,8);
    push(s1,10);

    printf("The value at bottom is: %d \n", stackBottom(s1));
    printf("The value at bottom is: %d \n", stackTop(s1));
}