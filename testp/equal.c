#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}typedef node;

node *createNode(int data){
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

int equalTree(node *t1, node *t2){    
    if (t1==NULL && t2==NULL) 
        return 1; 
    if (t1!=NULL && t2!=NULL) 
    { 
        return ( (t1->data == t2->data) && (equalTree(t1->left, t2->left)) && (equalTree(t1->right, t2->right) )); 
    }    
    return 0; 
}

void preorderDisplay(node *ptr){
    if(ptr!=NULL){
        printf(" %d", ptr->data);
        preorderDisplay(ptr->left);      
        preorderDisplay(ptr->right);
    }
}


int main(){

    node *t1 = createNode(5);
    t1->right = createNode(3);  
    t1->left = createNode(4);
    t1->left->left  = createNode(1); 
    t1->left->right = createNode(2);  
  
    node *t2 = createNode(5); 
    t2->left = createNode(4); 
    t2->right = createNode(3); 
    t2->left->right = createNode(2); 
    t2->left->left = createNode(1); 

    printf("\n preorder traversal of T1: ");
    preorderDisplay(t1);
    printf("\n preorder traversal of T2: ");
    preorderDisplay(t2);
  
    if(equalTree(t1, t2)) 
        printf("\nBoth trees T1 and T2 are identical."); 
    else
        printf("\nT1 and T2 are not identical."); 

    t1= createNode(10);
    t1->left = createNode(4); 
    t1->right = createNode(3); 
    t1->right->left  = createNode(0); 
    t1->right->right = createNode(20);  
  
    t2=createNode(5);
    t2->left = createNode(7); 
    t2->right = createNode(3); 
    t2->left->left = createNode(1); 
    t2->left->right = createNode(2); 

    printf("\n preorder traversal of T1: ");
    preorderDisplay(t1);
    printf("\n preorder traversal of T2: ");
    preorderDisplay(t2);
  
    if(equalTree(t1, t2)) 
        printf("\n Both trees T1 and T2 are identical.\n"); 
    else
        printf("\n T1 and T2 are not identical.\n"); 

    return 0;
}