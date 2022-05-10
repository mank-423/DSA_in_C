#include<stdio.h>
#include<stdlib.h>

//Initialize the DE queue
struct DE_queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct DE_queue *ptr){
    if (ptr->front == ptr->rear){
        return 1;
    }
    return 0;
}

int isFull(struct DE_queue *ptr){
    if (ptr->rear == ptr->size){
        return 1;
    }
    return 0;
}

void enqueue(struct DE_queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
        printf("Enqued element: %d\n", val);
    }
}

void enqueue_front(struct DE_queue *ptr, int value){
    if ((ptr->front) > 0){
        ptr->front--;
        ptr->arr[ptr->front] = value;
        printf("Enqued element: %d \n",value);
    }
    else if (ptr->front == 0){
        ptr->arr[0]==value;
        ptr->front--;
    }

    else{
        printf("No space at front to insert. \n");
    }
}

void enqueue_end(struct DE_queue *ptr, int value){
    if ((ptr->rear + 1) <= ptr->size-1){
        ptr->rear++;
        ptr->arr[ptr->rear] = value;
        printf("Enqued element: %d\n", value);
    }
    else{
        printf("No space at the rear \n");
    }
}

int dequeue(struct DE_queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->front++;
        a = q->arr[q->front];
        //printf("%d \n",q->front);
    }
    return a;
}

int dequeue_end(struct DE_queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        a = q->arr[q->rear];
        q->rear--;
    }
    return a;
}

int dequeue_front(struct DE_queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        a = q->arr[q->front];
        q->front++;
    }
    return a;
}

//Not working that properly : LOGIC NEEDS TO BE CHANGED
void display(struct DE_queue *ptr){
    int i = 0;
    printf("The elements: \n");
    for ( i = ptr->front+1; i <= ptr->rear; i++)
    {
        printf("%d \n",ptr->arr[i]);
    }
}

int main()
{
    //Instance of DE queue
    struct DE_queue dq;
    dq.size = 10;
    dq.front = dq.rear = -1;
    dq.arr = (int *)malloc(dq.size * sizeof(int));
    
    enqueue(&dq,11);
    enqueue(&dq,9);
    enqueue(&dq,20);
    printf("Dequeued element: %d \n", dequeue(&dq));
    printf("Dequeued element: %d \n", dequeue(&dq));
    enqueue_front(&dq,2);
    enqueue_end(&dq, 5);
    

    return 0;
}