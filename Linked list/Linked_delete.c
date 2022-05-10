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
struct Node *deleteAtFirst(struct Node *head){
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
};

//Case 2
struct Node *deleteAtEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q;
    q = p->next;
    
    while(q->next != NULL){
        q = q->next;
        p = p->next;
    }

    p->next=NULL;
    free(q);
    return head;
}

//Case 3
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q;
    int i = 0;

    while(i!=index-1){
        p = p->next;
        i++;
    }

    q = p->next;
    p->next = q->next;
    free(q);

    return head;
}

//Case 4
//This case isn't working check it once
struct Node *deleteAtNode(struct Node *head,int value){
    struct Node *p = head;
    struct Node *q = head->next;
    
    //int i = 0;

    while(q->data != value || q->next!=NULL){
        p = p->next;
        q = q->next;
    }

    //When only the second condition of while loop is satisfied
    if (q->data == value){
       p->next = q->next;
       free(q);
    }
    return head;
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
    head->data = 4;
    head->next = second;
    
    //Link second and third data
    second->data = 3;
    second->next = third;
    //head->next->next = third;

    //Link third and the fourth
    third->data = 8;
    third->next = fourth;

    //Last node NULL
    fourth->data = 1;
    fourth->next = NULL;

    //Calling the traversal function
    printf("The original linked list: \n");
    Linked_traverse(head);

    //Deleting the first element
    // printf("The changed linked list:");
    // head = deleteAtfirst(head);
    // Linked_traverse(head);

    //Deleting the last element
    // printf("The changed linked list: \n");
    // head = deleteAtEnd(head);
    // Linked_traverse(head);

    //Deleting at a index
    // printf("The changed linked list: \n");
    // head = deleteAtIndex(head,2);
    // Linked_traverse(head);

    //Deleting a node = this isn't working right!!
    printf("The changed linked list: \n");
    head = deleteAtNode(head,3);
    Linked_traverse(head);


    return 0;
}