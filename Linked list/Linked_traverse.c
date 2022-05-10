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
    Linked_traverse(head);

    return 0;
}