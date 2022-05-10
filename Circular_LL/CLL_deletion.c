#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


void Circular_traversal(struct node *head){
    struct node *ptr;
    ptr = head;
    do
    {
        printf("Element: %d \n",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

//Deletion at head node
struct node *delAtFirst(struct node *head){
    struct node *p = head;
    struct node *r = head->next;
    struct node *q = head;

    while(q->next!=head){
        q = q->next;
    }

    q->next = r;
    free(p);
    head = r;
    return head;
};

//Deletion from index
struct node *delAtIndex(struct node *head,int index){
    int i = 0;
    struct node *p = head;
    struct node *q = head->next;
    while (i != index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
};

//Deletion at the end
struct node *delAtEnd(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next != head){
        q = q->next;
        p = p->next;
    }
    p->next = head;
    free(q);
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

    printf("Original Circular Linked List: \n");
    Circular_traversal(head);

    //Moving on to the operations

    //Deletion at the first
    // printf("New Circular Linked List: \n");
    // head = delAtFirst(head);
    // Circular_traversal(head);

    //Deletion at the index
    // printf("New Circular Linked List: \n");
    // head = delAtIndex(head,2);
    // Circular_traversal(head);

    //Deletion at the end
    printf("New Circular Linked List: \n");
    head = delAtEnd(head);
    Circular_traversal(head);
    
  
    return 0;
}