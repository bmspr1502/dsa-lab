#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define num 30

struct node{
    char name[num];
    int jerseyno;
    struct node* next;
}*head = NULL,*temp = NULL;

void create(char *nam, int n){
    struct node*p = (struct node*)malloc(sizeof(struct node));
    int l = strlen(nam);
    int i;
    for(i=0;i<l;i++)
        p->name[i] = nam[i];
    p->name[i] = '\0';
    p->jerseyno = n;
    p->next = NULL;
    if(head == NULL){
        head = p;
        temp = p;
    }
    else{
        temp->next = p;
        temp = p;
    }
}
void display(){
    printf("\nYour Entered Players Details are: \n");
    struct node*p = head;
    while(p != NULL){
        printf("Name: %s",p->name);
        printf("Jersey no: %d\n",p->jerseyno);
        p = p->next;
    }
}
int main(){
    int jerseyno;
    char name[20];
    printf("Press 0 in jersey number to quit\n");
    while(1){
        printf("Enter jersey no: ");
        scanf("%d",&jerseyno);
        if(jerseyno == 0)
            break;
        getchar();
        printf("Enter the player's name: ");
        fgets(name, num, stdin);
        if(jerseyno == 0)
            break;
        create(name, jerseyno);
    }
    display();
    return 0;
}