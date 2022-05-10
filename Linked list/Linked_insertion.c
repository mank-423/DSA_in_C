#include<stdio.h>
#include<stdlib.h>


//Creation of Linked List
struct Node
{
    int data;
    struct Node *next;
    
};

void Linked_traverse(struct Node *ptr){

    while (ptr != NULL){    
    printf("Element: %d \n",ptr->data);
    ptr = ptr->next;
    }

}

//Case 1
//As it will return the head pointer of struct Node type so,,
struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    
    //Returning head of the linked list
    return ptr;

};

//Case 4
//Insert at the begining of the list, manipulating the head
struct Node * insertAtEnd(struct Node *head,int data){
    struct Node *ptr = head;
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
    while (ptr->next!=NULL){
        ptr = ptr->next;
    }
    link->data = data;
    ptr->next = link; 
    link->next = NULL;
    return head;
};

//Case 2
//Insert at and index , Willn't work for index = 0
struct Node * insertAtIndex(struct Node *head,int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while (i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
};

//Case 3
//Insert after a node
struct Node * insertAfter(struct Node *head,struct Node *prvs_node,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prvs_node->next;
    prvs_node->next = ptr;

    return head;
};


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    

    //Allocated memory in the Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    //Link first and second data
    head->data = 7;
    head->next = second;
    
    //Link second and third data
    second->data = 55;
    second->next = third;
    //head->next->next = third;

    //Link third and the fourth
    third->data = 6;
    third->next = fourth;

    //Last node NULL
    fourth->data = 45;
    fourth->next = NULL;

    //Calling the traversal function
    printf("Original Linked list: \n");
    Linked_traverse(head);

    //Insert at the head position
    // head = insertAtFirst(head,89);//Updating the head of the linked list
    // printf("New Linked list: \n");  // Printing the new Liked list
    // Linked_traverse(head);

    //Insert in between
    // head = insertAtIndex(head,58,2);
    // printf("After inserting in between \n");
    // Linked_traverse(head);

    //Insert at the end
    // head = insertAtEnd(head,90);
    // printf("Inserting at the end \n");
    // Linked_traverse(head);
    
    //Insert after previous node
    head = insertAfter(head,second,70);
    printf("Inserting after a node \n");
    Linked_traverse(head);
    
    return 0;
}

/*
1. first
ptr->next = head;
return ptr

2. index
traverse krenge with a *p = head till the index-1 - kyunki index pe element
ptr->next  = p->next;
p->next = ptr;

3. At place of a index given or ndoe given
4.
while loop for ptr->next!=NULL - it will reach the last node
p->next = ptr;
ptr->next = NULL

*/