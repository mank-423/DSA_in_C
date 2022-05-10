#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prvs;
    int data;
    struct node *next;
};

void Double_LLtraverse(struct node *head){
    struct node *ptr = head;

    while (ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertAtFirst(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    
    //Change the head
    head->prvs = ptr;
    ptr->next = head;
    ptr->prvs = NULL;
    head = ptr;

    return head;
};

struct node *insertAtEnd(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    
    struct node *p = head;
    while (p->next != NULL){
        p = p->next;
    }

    ptr->prvs = p;
    ptr->next = NULL;

    p->next = ptr;

    return head;
};

struct node *insertAtIndex(struct node *head, int data, int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i = 0;
    struct node *p = head;

    while(i != index-1){
        p = p->next;
        i++;
    }

    ptr->next = p->next;

    p->next = ptr;
    ptr->prvs = ptr;
    
    return head;
};


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

    //Linking head to the second node
    head->prvs = NULL;
    head->data = 1;
    head->next = second;

    //Linking second to the third node
    second->prvs = head;
    second->data = 2;
    second->next = third;

    //Linking third to the fourth node
    third->prvs = second;
    third->data = 3;
    third->next = fourth;

    //Linking second to the third node
    fourth->prvs =third;
    fourth->data = 4;
    fourth->next = NULL;

    //Operations on Double Linked List
    //Traversal of List
    printf("The original Double Linked list is: \n");
    Double_LLtraverse(head);
    
    //Insert at the first node
    // printf("The new Double Linked list is: \n");
    // head = insertAtFirst(head,0);
    // Double_LLtraverse(head);

    //Insert at the end node
    // printf("The new Double Linked list is: \n");
    // head = insertAtEnd(head,5);
    // Double_LLtraverse(head);

    //Insert at the index
    printf("The new Double Linked list is: \n");
    head = insertAtIndex(head,5,2);
    Double_LLtraverse(head);

    return 0;
}