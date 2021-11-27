#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int lthread ;
    int rthread ;
}typedef node;

node *createNode(int data){
    node *new= (node *) malloc(sizeof(node));

    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->lthread =0;
    new->rthread = 0;

    return new;
}

node* insert(node *root, int data){
    if(root==NULL){
        return createNode(data);
    }

    node *ptr= root;
    node *parent = NULL;

    while(ptr!=NULL){
        parent = ptr;

        if(data == ptr->data){
            printf("\nDuplicate data");
            return root;
        }else if(data < ptr->data){
            if(ptr->lthread == 0)
                ptr = ptr->left;
            else 
                break;
        }else if(data > ptr->data){
            if(ptr->rthread == 0)
                ptr = ptr->right;
            else 
                break;
        }
    }

    node *tmp = createNode(data);
    tmp->lthread = 1;
    tmp->rthread = 1;
    if(data<parent->data){
        tmp->left = parent->left;
        tmp->right = parent;

        parent->lthread = 0;
        parent->left = tmp;
    }else{
        tmp->right = parent->right;
        tmp->left = parent;

        parent->rthread = 0;
        parent->right = tmp;
    }

    return root;
}

node *inorderSuccessor(node *ptr){
    if(ptr->rthread == 1)
        return ptr->right;

    ptr = ptr->right;
    while(ptr->lthread == 0)
        ptr= ptr->left;

    return ptr;
}

void inorder(node *root){
    if(root==NULL){
        printf("Tree is empty\n");
    }
    
    node *ptr = root;
    while(ptr->lthread == 0)
        ptr = ptr->left;
    printf("\nTree: ");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
}

int main(){
    int ch, temp;
    node *root = NULL;
    while(1){
        printf("\n1. INSERT \n2. DISPLAY\n0. EXIT");
        printf("\nEnter your choice(0-2): ");
        scanf("%d", &ch);

        if(ch==0){
            break;
        }

        switch (ch)
        {
        case 1:
            printf("Data: ");
            scanf("%d", &temp);
            root = insert(root, temp);
            break;

        case 2:
            inorder(root);
            break;
        
        default:
            break;
        }
    }

    return 0;
}