#include <stdio.h>

#define size 20

int Queue[size];
int head = -1, rear = -1;

void enqueue(int dat){
    if(head==-1 && rear==-1){
        head++;
        rear++;
    }else{
        rear++;
    }
    Queue[rear] = dat;
}

void dequeue(){
    if(head<0){
        printf("\nNo elements in the queue, underflow\n"); 
        return ;
    }
    printf("Element %d deleted",Queue[head]);
    Queue[head]=0;
    if(head==rear){
        head = rear = -1;
    }else{
    head++;
    }
    
}

void display(){
    int i;
    if(head<0){
        printf("\nQueue is empty.\n");
        return;
    }
    printf("Queue: ");
    for(i=head; i<=rear; i++){
        printf("-> %d ", Queue[i]);
    }
    printf("\n");
}

int main(){
    int ch;
    int temp;
    while(1){
        printf("\n1. Insert \n2.Delete \n3.Display the queue \n0.Exit\nEnter your choice(0-3):");
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