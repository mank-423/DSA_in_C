#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * createNode(int data){
    
    struct node *n; //Creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); //Allocating the memory in the heap
    n->left = NULL; //Setting the left and right children to NULL
    n->right = NULL;//Setting the left and right children to NULL
    n->data = data; //Setting the data 
    return n;
}

void preOrder(struct node *root){
    if (root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main()
{
   // 4<-- 2 --> 1
   //Constructing the root node - Using functions
   struct node *p = createNode(2);
   struct node *p1 = createNode(1);
   struct node *p2 = createNode(4);
   struct node *p3 = createNode(5);
   struct node *p4 = createNode(6);

   //Linking the root node with left and right children
   p->left = p1;
   p->right = p2;
   p1->left = p3;
   p1->right = p4;

    /*
                 2
                / \
                1  4
                /\
                5 6
    */  
    //Using the function
    preOrder(p);
    return 0;
}