#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f_ind;
    int b_ind;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->b_ind==q->f_ind){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->b_ind==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->b_ind++;
        q->arr[q->b_ind] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f_ind++;
        a = q->arr[q->f_ind]; 
    }
    return a;
}
 
int main(){
    struct queue q;
    q.size = 10;
    q.f_ind = q.b_ind = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));

    //Checing isEmpty before insertion
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    printf("Dequeuing element %d\n", dequeue(&q));
    
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }

    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}
