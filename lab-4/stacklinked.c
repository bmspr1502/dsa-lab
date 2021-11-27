#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}typedef Node;
Node *head = NULL;

void push(int data){

    Node *new = (Node*) malloc(sizeof(Node));
    if(!new){
        printf("\n Overflow\n");
        return;
    }

    new->data = data;
    new->next = NULL;

    if(head==NULL){
        head = new;
    }else{
        new->next = head;
        head = new;
    }
}

void pop(){
    if(head==NULL){
        printf("\nEmpty stack, Underflow");
        return;
    }

    Node *temp = head;
    head = head->next;
    printf("\n Deallocating %d", temp->data);
    free(temp);
}

void display(){
    if(head==NULL){
         printf("\nEmpty stack, Underflow");
        return;
    }
    Node *temp = head;
    printf("\nStack ");
    while(temp){
        printf("->%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int ch, temp;
    while (1)
    {
         printf("\n1. Insert at first (push) \n2.Delete at first (pop) \n3.Display the stack \n0.Exit\nEnter your choice(0-3):");
        scanf("%d", &ch);

        if(ch==0)
            break;

        switch (ch)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &temp);
            push(temp);
            break;
        
        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    }
    
}