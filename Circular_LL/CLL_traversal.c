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

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    //struct node *first;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    
    //Linking head to second
    head->data = 4;
    head->next = second;

    //Linking second to third
    second->data = 6;
    second->next = third;

    //Linking third to head again
    third->data = 8;
    third->next = head;

    Circular_traversal(head);
  
    return 0;
}