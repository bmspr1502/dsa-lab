#include<stdio.h>
#include<stdlib.h>

//Structure for tree nodes
struct node{
    int data;
    struct node* left;
    struct node* right;
    int lthread ;
    int rthread ;
}typedef node;

//Queue implementation (for level order insertion of data into Binary tree)
struct queueElem{
    struct node *data;
    struct queueElem* next;
}typedef queueElem;

queueElem *head=NULL, *rear=NULL;

//has constant no. of steps, time complexity = O(1)
void enqueue(node *dat){
    queueElem *new = (queueElem*) malloc(sizeof(queueElem));
    if(!new)
    {
        printf("\nNot inserted, overflow.\n");
        return;
    }
    new->data = dat;
    new->next = NULL;
    if(head==NULL && rear==NULL){
        head = new;
        rear = new;
    }else{
        rear->next= new;
        rear = new;
    }
}

//has constant no. of steps, time complexity = O(1)
node * dequeue(){
    if(head==NULL){ 
        return NULL;
    }
    queueElem *temp = head;
    head = head->next;
    node *del = temp->data;

    free(temp);
    if(head==NULL){
        rear=NULL;
    }
    return del;
}

//has constant no. of steps, time complexity = O(1)
int isEmpty(){
    if(head==NULL && rear==NULL )
        return 1;
    return 0;
}

//THREADED BINARY TREE IMPLEMENTATION

//function to create a node, time complexity = O(1)
node *createNode(int data){
    node *new= (node *) malloc(sizeof(node));

    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->lthread =0;
    new->rthread = 0;

    return new;
}

//function to insert the nodes in the LEVEL ORDER 
//the overall time complexity to insert the elements is O(h)
node* insert(node *root, int data){
    if(root==NULL){
        return createNode(data);
    }
    
    enqueue(root);
    int dir=0;
    node *ptr = NULL, *parent = NULL;
    
    //loop to find the postion to insert the element, will have O(h) time complexity, h = height of tree
    while(!isEmpty()){
        ptr = dequeue();
        parent = ptr;

        if(ptr->lthread == 0 && ptr->left!=NULL){
            enqueue(ptr->left);
        }else{
            dir=0;
            break;
        }
        
        if(ptr->rthread == 0 && ptr->right!=NULL){
            enqueue(ptr->right);
        }else{
            
            dir =1;
            break;
        }
    }

    //The threading logic, has constant no. of steps, so O(1) time complexity
    node *tmp = createNode(data);
    tmp->lthread = 1;
    tmp->rthread = 1;

    //when to be inserted as left child
    if(dir==0){
        tmp->left = parent->left;
        tmp->right = parent;

        parent->lthread = 0;
        parent->left = tmp;
    }
    //when inserted as the right child
    else if(dir==1){
        tmp->right = parent->right;
        tmp->left = parent;

        parent->rthread = 0;
        parent->right = tmp;
    }

    return root;
}


//function to find the inorder successor of the node, 
//at max, it can have a time complexity of O(h), h=height of tree
node *inorderSuccessor(node *ptr){
    if(ptr->rthread == 1)
        return ptr->right;

    ptr = ptr->right;
    while(ptr->lthread == 0)
        ptr= ptr->left;

    return ptr;
}

//function to print the inorder version of the tree, time complexity = O(n)
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

//driver function
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


/*
    * TIME COMPLEXITY ANALYSIS
    * ========================
    * 
    * The queue operations take constant time (O(1))
    * The creation of a tree node takes constant time O(1)
    * Insertion of a node to tree has a time complexity of O(h), h=height of tree
    * The printing of the inorder traversal of the threaded tree has a time complexity of O(n), n=no. of nodes
    * 
    * The overall complexity of the whole program is O(n)

*/