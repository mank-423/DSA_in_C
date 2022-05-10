#include <stdio.h>
#include <stdlib.h>

//Stack formulation using structure, making it ADT 
struct stack
{
    int size;
    int top;
    char * arr;
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
void push(struct stack *ptr, char value){
    if (isFull(ptr)){
        printf("Stack overflow \n");
        printf("Cannot push the element: %d \n",value);
    }

    ptr->top++;
    ptr->arr[ptr->top] = value;
}

//Pop the elements of the stack
char pop(struct stack *ptr){
    if (isEmpty (ptr)){
        printf("Stack underflow");
        return -1;
    }

    char val = ptr->arr[ptr->top];
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

int parenthesisMatch(char *exp){
    //create and initialize the stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i]!='\0' ; i++)
    {
        if (exp[i]=='('){
            push(sp,'(');
        }

        else if (exp[i]==')')
        {
            if (isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main()
{
    char *exp = "8*(9)";
    if (parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}
