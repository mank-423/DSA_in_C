#include <stdio.h>
#include <stdlib.h>

//Stack formulation using structure, making it ADT 
struct stack
{
    int size;
    int top;
    int * arr;
};

//Check empty or not 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
 
//Checking if full or not
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
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

//Peek funtion takes the position
// which is index = pos-1, Eg: pos:1 == index(0)
// This will take its position starting from the bottom
int peek_simple(struct stack *ptr, int pos){
    if (isEmpty(ptr)){
        printf("Stack Underflow \n");
    }

    else if (pos<0){
        printf("Wrong Entry");
    }

    return ptr->arr[pos-1];
}


//This peek function will take value of position from top and index starts from bottom of array
//Then the position , ind = top - pos - 1
int peek(struct stack *ptr,int pos){
    if (isEmpty(ptr)){
        printf("Stack Underflow \n");
    }

    else if (ptr->top - pos + 1 < 0){
        printf("Not a valid position");
    }

    return ptr->arr[ptr->top-pos];
}

//Display the stack
void display(struct stack *ptr){
    for (int i = 0; i < ptr->top+1; i++){
        printf("The element %d: %d \n",i+1,ptr->arr[i]);
    }
}


int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
 

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully! \n");

    // Checking the functions created for stack
    printf("Before pushing, Full:%d \n",isFull(s));
    printf("Before pushing, Empty:%d \n",isEmpty(s));

    push(s,24);
    push(s,56);
    push(s,45);
    push(s,4);
    push(s,5);
    display(s);
    printf("Popped element is: %d \n", pop(s));
    // printf("Element at position: %d \n", peek_simple(s,2));
    printf("Element at position: %d \n", peek(s,2));
    printf("After pushing, Full:%d \n",isFull(s));
    printf("After pushing, Empty:%d \n",isEmpty(s));

    return 0;
}
