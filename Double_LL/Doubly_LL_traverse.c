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
    Double_LLtraverse(head);

    return 0;
}