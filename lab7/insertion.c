#include<stdio.h>
#include<stdlib.h>

struct node{
    int lbit;
    struct node* left;
    int val;
    struct node* right;
    int rbit;
};

void insert(struct node* root, struct node* temp);
void inorder(struct node* head);

void main(){
    int n = 0;
    struct node *temp,*root,*head;
    root = NULL;
    printf("enter the data to be inserted enter -1 to quit:\n");
    do{
        scanf("%d",&n);
        temp = (struct node*)malloc(sizeof(struct node));
        temp->val = n;
        temp->left = NULL;
        temp->right = NULL;
        temp->lbit = 0;
        temp->rbit = 0;

        if(root == NULL)
        {
            root = temp;
            head = (struct node*)malloc(sizeof(struct node));
            head->val = 999;
            head->right = head;
            head->rbit = 1;
            head->left = root;
            head->lbit = 1;
            root->left = head;
        }
        else{
            insert(root,temp);
        }
    }while(n != -1);
    inorder(head);
}

void insert(struct node* root,struct node* temp)
{
   if(temp->val < root->val)
   {
       if(root->left == NULL)
       {
            temp->left = root->left;
            temp->right = root;
            root->left = temp;
            root->lbit = 1;
       }
       else
       {
            insert(root->left, temp);
       }
   }
   if(temp->val > root->val)
   {
       if(root->right == NULL)
       {
            temp->right = root->right;
            temp->left = root;
            root->right = temp;
            root->rbit = 1;
       }
       else
       {
            insert(root->right, temp);
       }
   }
}

void inorder(struct node* head)
{
    struct node *t;
    do{
        while(t->lbit != 0)
        {
            t = t->left;
        }
        printf("%d ",t->val);
        while(t->right == 0)
        {
            t = t->right;
            if(t == head)
                return;
            printf("%d ",t->val);
        }
        t = t->right;
    }while(t != head);
}
