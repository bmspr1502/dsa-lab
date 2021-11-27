#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
}typedef node;
node *root = NULL;

int max(node *ptr){

    while(ptr!=NULL && ptr->rightChild!=NULL){
        ptr = ptr->rightChild;
    }
    return ptr->data;

}

int min(node *ptr){

    while(ptr!=NULL && ptr->leftChild!=NULL){
        ptr = ptr->leftChild;
    }
    return ptr->data;
}

node *newNode(int dat){
    node* new = (node*) malloc(sizeof(node));
    new->data = dat;
    new->leftChild=NULL;
    new->rightChild=NULL;
    return new;
}

void insertwhile(int dat){
    node* new = (node*) malloc(sizeof(node));
    new->data = dat;
    new->leftChild=NULL;
    new->rightChild=NULL;

    if(root==NULL){
        root=new;
        printf("Inserted as root.\n");
    }else{
        node *ptr = root;

        while(1){
            if((ptr->leftChild!=NULL)&&(ptr->rightChild!=NULL)){
                if(dat < max(ptr->leftChild)){
                    ptr = ptr->leftChild;
                    continue;
                }else if(dat > min(ptr->rightChild)){
                    ptr = ptr->rightChild;
                    continue;
                }
            }else {
                if (dat<ptr->data){
                    ptr->leftChild = new;
                    printf("Inserted as leftchild of %d", ptr->data);
                    break;
                }else if(dat>ptr->data){
                    ptr->rightChild = new;
                    printf("Inserted as rightchild of %d", ptr->data);
                    break;
                }else if( dat == ptr->data){
                    printf("\nDuplicate values not allowed.");
                }
            }

            
        }
    }
}

void insert(node *ptr,int dat){

    if(root==NULL){
        root=newNode(dat);
        return;
    }

    if(ptr==NULL){
        ptr=newNode(dat);
    }else{
        
        if(dat < ptr->data){
            insert(ptr->leftChild, dat);
        }else if(dat > ptr->data){
            insert(ptr->rightChild, dat);
        }else{
            printf("\nDuplicate values not enterable.");
        }   
    }
}
void inorderDisplay(node *ptr){
    if(ptr!=NULL){
        inorderDisplay(ptr->leftChild);
        printf(" %d", ptr->data);
        inorderDisplay(ptr->rightChild);
    }
}

int main(){

    int temp,ch;
    do{
        printf("\n1.Insert\n2.Display\n0.Exit\nEnter(0-2): ");
        scanf("%d", &ch);
        if(ch==0){
            break;        
        }
        switch (ch)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &temp);
            insert(root,temp);
            
            break;
        
        case 2:
            printf("\nThe inorder display of the tree: ");
            inorderDisplay(root);
            break;

        default:
            break;
        }

    }while(1);

    return 0;
}