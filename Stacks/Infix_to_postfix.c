#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}


//Pop the elements of the stack
char pop(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("Stack underflow");
        return -1;
    }

    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int isOperator(char ch){
    if (ch=='+' ||ch=='-' ||ch=='/' || ch=='*' ){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char ch){
    if (ch=='*' || ch=='/' ){
        return 3;
    }

    else if (ch=='+' || ch=='-'){
        return 2;
    }

    else{
        return 0;
    }
}



char *infixToPostfix(char *infix){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char * postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if (precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp,infix[i]);
            }
            else{
                postfix[j] = pop(sp);
            }
        }
    }
    
    while (!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    return postfix;

}

//Display the stack
void display(struct stack *ptr){
    for (int i = 0; i < ptr->top+1; i++){
        printf("The element %d: %d \n",i+1,ptr->arr[i]);
    }
}




int main()
{
    char * infix = "a-b";
    printf("Postfix is %s", infixToPostfix(infix));
    return 0;
}
