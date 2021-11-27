#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}typedef Node;

Node *head=NULL, *rear=NULL;

void enqueue(int dat){

    Node *new = (Node*) malloc(sizeof(Node));
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

void dequeue(){

    if(head==NULL){
        printf("\nNo elements in the queue, underflow\n"); 
        return;
    }
    Node *temp = head;
    head = head->next;
    printf("\nDeallacating %d .",temp->data);
    free(temp);
    if(head==NULL){
        rear=NULL;
    }
}

void display(){

    Node *temp = head;
    if(head==NULL){
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue: ");
    while(temp){
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    int ch,temp;
    while(1){
        printf("\n1. Enqueue (Insert at last) \n2.Dequeue (Delete at first) \n3.Display the queue \n0.Exit\nEnter your choice(0-3):");
        scanf("%d", &ch);

        if(ch==0)
            break;

        switch (ch)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &temp);
            enqueue(temp);
            break;
        
        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    }
}