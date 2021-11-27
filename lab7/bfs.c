#include <stdio.h>
#include <stdlib.h>

//Queue implementation:-
struct Node{
    int data;
    struct Node* next;
}typedef Node;

Node *head=NULL, *rear=NULL;

//takes constant time, time compexity = O(1)
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

//takes constant time, time complexity = O(1)
int dequeue(){
    if(head==NULL){ 
        return -1;
    }
    Node *temp = head;
    head = head->next;
    int del = temp->data;

    free(temp);
    if(head==NULL){
        rear=NULL;
    }
    return del;
}

//takes constant time, time complexity = O(1)
int peek(){
    if(!head)
        return -1;

    return head->data;
}

//Graph implementation

//structure to hold the list of adjacent vertex
struct adjlistnode{
    int value;
    struct adjlistnode *next;
}typedef adjlistnode;

//structure to hold the address of the first adjlistnode
struct adjlist{
    adjlistnode* head;
}typedef adjlist;

//structure to hold the graph's details
struct Graph{
    int vert;
    int edge;
    int *visited;
    adjlist *array;
}typedef Graph;



//function to add edge into that vertex's list
//has constant number of steps, time complexity = O(1)
void addedge(Graph *x, int source, int value){
    adjlistnode *new = (adjlistnode *) malloc(sizeof(adjlistnode));

    new->value = value;
    new->next = x->array[source].head;
    x->array[source].head = new;

    new = (adjlistnode *) malloc(sizeof(adjlistnode));
    new->value = source;
    new->next = x->array[value].head;
    x->array[value].head = new;
}

//function to create and initialize graph
//has 2 inner loops that run 'v' (no. of vertices) times
//time complexity = O(v)
Graph* creategraph(int v, int e){
    Graph *new = (Graph *) malloc(sizeof(Graph));

    new->vert = v;
    new->edge = e;
    new->array = (adjlist *) malloc(new->vert * sizeof(adjlist));

    int i;
    for(i=0; i<new->vert; i++){
        new->array[i].head = NULL;
    }
    new->visited = (int *) malloc(new->vert * sizeof(int));

    for(i=0; i<new->vert; i++){
        new->visited[i] = 0;
    }

    return new;
}

//prints the list of all adjacent vertices
//the no. of times this function depends on the number of adjacent vertices
//to that particular vertex, worst case it can run v times, time complexity = O(v)
void printlists(Graph *a){
    int i;
    for(i=0; i<a->vert; i++){
        printf("\n For vertex %d ", i);
        adjlistnode *temp = a->array[i].head;
        while(temp){
            printf(" -> %d", temp->value);
            temp = temp->next;
        }
    }
}

//function to find the vertex of the subgraph
//time complexity = O(v)
int subg(Graph *a){
    int i=0;
    for(i=0; i<a->vert; i++){
        if(a->visited[i]==0){
            break;
        }
    }
    return i;
}

/*  Breath first searching using adjacency list
    in this case, the outer loop runs v (no. of vertices) times,
    but we cannot be sure of the inner loop, but we can say for sure that 
    the total number of times the inner loop would have run (over the whole function's 
    period) would be equal to 2*edges (2e)

    Therefore the time complexity of BFS = O(v+e)
*/
void BFS(Graph *a){
    int i=0,found,j;

start:
    printf("\nGraph: ");
    while(1){
        if(a->visited[i]==0){
            a->visited[i] = 1;
            printf("%d ",i);
        }
        adjlistnode *temp = a->array[i].head;
        found=0;
        while(temp){
            if(a->visited[temp->value]==0){
                found=1;
                enqueue(temp->value);
            }

            temp = temp->next;
        }
        
        i= dequeue();
        if(i==-1)
            break;
    }

    i=subg(a);
    if(i!=a->vert){
        goto start;
    }
    printf("\n");
}

//driver function, calls creategraph [O(v)] and also gets input for the edges (O(e))
//time complexity = O(v+e) 
int main(){
    int x,y,i;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &x);

    printf("\nEnter the number of Edges: ");
    scanf("%d", &y);
    printf("Enter the edges in the format:- V1<space>V2\n");

    Graph *a = creategraph(x,y);
    getchar();

    for(i=0; i<a->edge; i++){
        scanf("%d %d", &x, &y);
        if(x<a->vert && y<a->vert){
            addedge(a,x,y);
        }else{
            printf("\nVertex value incorrect, aborting\n");
            break;
        }
    }

    printf("\nThe Adjacency List for the graph: ");
    printlists(a);

    BFS(a);
}

/*
    * TIME COMPLEXITY ANALYSIS
    * ========================
    * 
    * All the queue operations take O(1) time
    * The initializaton of Graph has a time complexity of O(v+e)
    * The breadth first search using adjacency list algorithm has a time complexity of O(v+e)
    * 
    * Hence the total program has a time complexity of O(v+e)
*/