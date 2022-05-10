#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

//Traversing the list
void Circular_traversal(struct node *head){
    struct node *ptr;
    ptr = head;
    // printf("Element: %d \n",ptr->data);
    // ptr = ptr->next;
    // while(ptr != head){
    //     printf("Element: %d \n",ptr->data);
    //     ptr = ptr->next;
    // }
    do
    {
        printf("Element: %d \n",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

//Insertion at the first node
//4->5>6
struct node * insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while(p->next != head){
        p = p->next;
    }
    //At this point p is at last node
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    //Returning head of the linked list
    return head;
};

//Inserting at the end
//4->6>8>10----ptr--->4
struct node *insertAtEnd(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    while (p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    
    return head;
};

//Insert at one index

struct node *insertAtIndex(struct node *head, int data, int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    
    return head;
};

//Insert at given node ni krna!!!!!!

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    //Linking head to second
    head->data = 4;
    head->next = second;

    //Linking second to third
    second->data = 6;
    second->next = third;

    //Linking third to head again
    third->data = 8;
    third->next = fourth;

    //Linking third to head again
    fourth->data = 10;
    fourth->next = head;

    //Moving to the operations
    
    printf("Original Circular Linked list: \n");
    Circular_traversal(head);
    
    //Inserting at the begining
    // printf("New Circular Linked list: \n");
    // head = insertAtFirst(head,2);
    // Circular_traversal(head);

    //Inserting at the end
    // printf("New Circular Linked list: \n");
    // head = insertAtEnd(head,2);
    // Circular_traversal(head);
    
    //Inserting at the index
    printf("New Circular Linked list: \n");
    head = insertAtIndex(head,2,2);
    Circular_traversal(head);


    return 0;
}