#include<stdio.h>
#include<stdlib.h>

//Declaring global variable for easy usage otherwise returning the head of linekd list
struct Node *f = NULL;
struct Node *r = NULL;

//Declaration of linked list
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    printf("Printing the elements of the Linked List: \n");
    struct Node *p = ptr;
    while (p != NULL){
        printf("The element: %d \n",p->data);
        p = p->next;
    }
}

//For the insertion if we don't use the global scope of f,r pointer
//void enqueue(struct Node *f, struct Node *r, int val), then we need to use this

void enqueue(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n==NULL){
        printf("Queue is full");
    }

    n->data = val;
    n->next = NULL;

    if (f==NULL){
        f = r = n;
    }
    else{
        r->next = n;
        r = n;
    }
}

int dequeue(){
    int val = -1;
    struct Node *ptr;
    ptr = f;
    if (f==NULL){
        printf("Queue is empty");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}


int main()
{
    linkedListTraversal(f);
    enqueue(10);
    enqueue(20);
    enqueue(8);
    enqueue(2);
    linkedListTraversal(f);
    printf("Dequeuing element: %d \n", dequeue());
    printf("Dequeuing element: %d \n", dequeue());
    
    return 0;
}