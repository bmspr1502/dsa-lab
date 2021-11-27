#include<stdio.h>
#include<stdlib.h>
#define n 6
int front = -1, rear = -1, q[n],node[n],res[n],co=0;
struct graph{
	int data;
	struct graph *next;
	struct graph *link;
}*head = NULL;
void enqueue(int x){
    if(front == -1)
        front = 0;
    q[++rear] = x;
}
int dequeue(){
	return q[front++];
}
int isempty(){
	if(front == -1 || front >  rear)
        return 1;
	return 0;
}
struct graph * adjlist1(int x){
	struct graph* newnode = (struct graph*)malloc(sizeof(struct graph));
	struct graph* temp = head;
	newnode->data = x;
	newnode->next = NULL;
	newnode->link = NULL;
	if(head == NULL)
		head = newnode;
	else{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
	return newnode;
}
struct graph* adjlist2(struct graph* temp,int x){
	struct graph* newnode = (struct graph*)malloc(sizeof(struct graph));
	newnode->data = x;
	newnode->next = NULL;
	newnode->link = NULL;
	return newnode;
}
void display(){
	struct graph* temp1 = head;
	struct graph* temp2 = NULL;
	while(temp1 != NULL){
		printf("\nNode\n");
		printf("%d\n",temp1->data);
		if(temp1->link == NULL)
			printf("No links\n");
		else{
			printf("Links\n");
			temp2 = temp1->link;
			while(temp2 != NULL){
				printf("%d ",temp2->data);
				temp2 = temp2->link;
			}
		}
		temp1 = temp1->next;
	}
}
void display1(){
	struct graph *temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int ispresentqueue(int x){
	int i;
	for(i=front;i<=rear;i++){
		if(q[i] == x)
			return 1;
	}
	return 0;
}
int isvisited(int x){
	int i;
	for(i=0;i<co;i++){
		if(res[i] == x)
			return 1;
	}
	return 0;
}
void bfs(){
	struct graph* temp1 = head;
	struct graph* temp2 = NULL;
	enqueue(temp1->data);
	while(1){
		res[co++] = dequeue();
		if(temp1->link == NULL)
			;
		else{
			temp2 = temp1->link;
			while(1){
				if(temp2 != NULL && !ispresentqueue(temp2->data) && !isvisited(temp2->data))
					enqueue(temp2->data);
				else if(temp2 == NULL)
					break;
				temp2 = temp2->link;
			}
		}
		while(1){
			if(temp1 == NULL)
				temp1 = head;
			else if(temp1->data == q[front])
				break;
			else if(co >= n)
				break;
			else
				temp1 = temp1->next;
		}
		if(co >= n)
			break;
	}
}
int main(){
	int i,c;
	struct graph *temp1,*temp2;
	for(i=0;i<n;i++){
		printf("Enter the node: ");
		scanf("%d",&node[i]);
		temp1 = adjlist1(node[i]);
		printf("Enter the adjacent nodes of %d(-1 to stop): ",node[i]);
		temp2 = temp1;
		while(1){
			scanf("%d",&c);
			if(c == -1)
				break;
			temp2->link = adjlist2(temp2, c);
			temp2 = temp2->link;
		}
	}
	//display1();
	//display();
	bfs();
	printf("\nBFS search result: ");
	for(i=0;i<co;i++)
		printf("%d ",res[i]);
	return 0;
}   