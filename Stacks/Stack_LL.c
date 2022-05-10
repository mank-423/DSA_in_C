#include<stdio.h>
#include<stdlib.h>
//Global scope declaration of top
// struct node *top = NULL;


//Linked list using structure
struct node{
    int data;
    struct node *next;
};

//Travesral of the stack
void Stack_traversal(struct node *top){
    struct node *ptr =  top;
    int i = 0;
    while (ptr != NULL){
        printf("The element %d: %d \n", i+1, ptr->data);
        ptr = ptr->next;
        i++;
    }   
}

//Operations to be performed for stack:
//1.push()
//2.pop()
//3.isFull()
//4.isEmpty()
//5.peek()
//6.StackTop() & StackBottom()

//In the linked list, the bottom element is the the one is next == NULL
//And the head is the top pointer of the stack

//isFull(): Check if the size is full
int isFull(struct node *top){
    //If ptr is able to allocate memroy then it's not full
    //Else if device space is full then ptr == NULL 
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr==NULL){
        return 1;
    }
    return 0;
}

//isEmpty(): Check if the stack is empty or not, top == NULL
int isEmpty(struct node *top){
    if (top == NULL){
        return 1;
    }
    return 0;
}

//Push operation : head is the top pointer 
struct node *push(struct node *top, int data){
    if (isFull(top)){
        printf("Stack Overflow\n");
    }

    else{
        struct node *n  = (struct node *)malloc(sizeof(struct node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}

//Pop operation: using the head as top pointer
//This works with the global variable of top
// int pop(struct node *tp){
//     struct node *ptr = tp;
//     if (isEmpty(tp)){
//         printf("Stack Underflow/n");
//     }
//     int x = tp->data;
//     tp = tp->next;
//     free(ptr);
//     return x;
// }

//This works with the given in main top declartion
int pop(struct node **top){
    struct node *ptr = *top;
    if (isEmpty(*top)){
        printf("Stack Underflow/n");
    }
    int x = (*top)->data;
    *top = (*top)->next;
    free(ptr);
    return x;
}


//peek(): Printing
void peek(struct node *top, int position){
    int i=1;
    struct node *ptr = top;
    for (i=0;(i<position-1 && ptr!=NULL);i++){
        ptr = ptr->next;
    }

    if (ptr!=NULL){
    printf("The element at position %d is %d \n",position, ptr->data);
    }
    else{
        printf("Index not applicable");
    }
}

//stackTop
void stackTop(struct node *top){
    struct node *ptr = top;
    if (isEmpty(ptr)){
        printf("Stack underflow");
    }
    printf("The top element is: %d \n",ptr->data);   
}

int stackBottom(struct node *top){
    struct node *ptr = top;
    if (isEmpty(ptr)){
        printf("Stack underflow");
    }
    else{
    while (ptr != NULL){
        ptr = ptr->next;
    }
    //printf("The data at bottom is: %d",ptr->data);
        return ptr->data;
    }
    
}


int main(){
    struct node *top = NULL;

    //Operations on the stack 
    top = push(top, 78);
    top = push(top, 8);
    top = push(top, 7);
    top = push(top, 1);
    Stack_traversal(top);
    //Used to pass as the pointer for the function pop above
    int element = pop(&top);
    printf("The popped element is: %d \n",element);
    Stack_traversal(top);
    peek(top,1);
    stackTop(top);
    //This below isn't working (- - _)
    int bottom = stackBottom(top);
    printf("The bottom element of stack is: %d \n",bottom);
}