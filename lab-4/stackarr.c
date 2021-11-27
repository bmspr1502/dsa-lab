#include<stdio.h>
#include<string.h>

#define size 100
int stack[size];
int* head = NULL;

int push(int x){
    if(head==(stack+size-1)){
        printf("\n Unable to push. Stack Overflow\n");
        return 1;
    }else if(head==NULL){
        head = stack;
        *head = x;
    }else
    {
        head++;
        *head = x;
    }
    return 0;
}

int pop(){
    if(head<stack){
        printf("\nNo Element found, underflow.");
    }else{
        int temp = *head;
        head--;
        return temp;
    }
}

void display(){
    printf("The current status of the stack ");
    int *a;
    for(a=head; a>=stack; a--)
        printf("-> %d,",*a);

    printf("\n");
}


int main(){
    int ch, temp;

    while (1)
    {
         printf("\n1. Push (insert at first) \n2.Pop (delete at first) \n3.Display the stack \n0.Exit\nEnter your choice(0-3):");
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
            printf("\n The element %d was deleted.",pop());
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    }
    return 0;
}