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

//Delete at the first node
struct node *deleteAtFirst(struct node *head){
    struct node *p = head;
    head = head->next;
    head->prvs = NULL;
    free(p);

    return head;
};

//Delete at end node
struct node *deleteAtEnd(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next != NULL){
        q = q->next;
        p = p->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
};


//Delete at index node
struct node *deleteAtIndex(struct node *head,int index){
    struct node *p = head;
    struct node *q = head->next;
    int i = 0;
    while(i != index-1){
        q = q->next;
        p = p->next;
        i++;
    }
    p->next = q->next;
    q->next->prvs = p;
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
    printf("The original Circular Linked List is: \n");
    Double_LLtraverse(head);

    //Deletion at the first node
    // printf("The new Circular Linked List is: \n");
    // head = deleteAtFirst(head);
    // Double_LLtraverse(head);

    //Deletion at end node
    // printf("The new Circular Linked List is: \n");
    // head = deleteAtEnd(head);
    // Double_LLtraverse(head);

    //Deletion at index node
    printf("The new Circular Linked List is: \n");
    head = deleteAtIndex(head,2);
    Double_LLtraverse(head);
    return 0;
}