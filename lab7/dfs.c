#include <stdio.h>
#include <stdlib.h>


//The time complexity analysis of each function is written in the comments

//Stack implementation
struct Node{
    int data;
    struct Node *next;
}typedef Node;
Node *head = NULL;

//all steps take constant time, so time complexity of push() = O(1)
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

//all steps take constant time, so time complexity of peek() = O(1)
int peek(){
    if(!head)
        return -1;

    return head->data;
}

//all steps take constant time, so time complexity of peek() = O(1)
void pop(){
    if(head==NULL){
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
}


//Graph implementation
struct Graph{
    int *visited;
    int vert;
    int edges;
    int **adj;
}typedef Graph;

//function to check if the all vertices are visited 
//time complexity = O(v)
int allvisit(Graph *a){
    int i=0,vis=1;
    for(i=0; i<a->vert; i++){
        if(a->visited[i]==0){
            vis = 0;
            break;
        }
    }
    return vis;
}

//To find the vertex of the next subgraph
//time complexity = O(v), v= no. of vertices
int subg(Graph *a){
    int i=0;
    for(i=0; i<a->vert; i++){
        if(a->visited[i]==0){
            break;
        }
    }
    return i;
}

//function to find the Depth First Search
//time complexity = O(v^2), v= no. of vertices
void DFS(Graph *a){
    int i= 0,j;

start:    
    printf("Graph : ");
    while(1){           //outer loop runs v times
        if(a->visited[i]==0){
            a->visited[i] = 1;
            printf("%d ",i);
            push(i);
        }

        int flag=0;
        for(j=0; j<a->vert; j++){       //inner loop, runs max of v times
            if(a->visited[j] == 0 && a->adj[i][j]==1){
                flag=1;
                i=j; 
                break;
            }
        }
        
        if(flag==0){
            pop();
            i=peek();
        }
        if(i==-1){
            break;
        }
    }
    
    printf("\n");
    //to ensure all disconnected subgraphs are also taken into account
    if(!allvisit(a)){       
        i = subg(a);
        goto start;
    }

}

//function to add edge into the adjaceny matrix, time complexity = O(1)
void addedge(Graph *a, int x, int y){
    a->adj[x][y]=1;
    a->adj[y][x]=1;
}


//function to print the adjacency matrix, time complexity = O(v^2)
void printmatrix(Graph *a){
    int i,j;
    printf("Matrix: \n");
    for(i = 0; i<a->vert; i++){
        if(i==0){
            printf("  ");
            for(j=0; j<a->vert; j++){
                printf("%d ", j);
            }
            printf("\n");
        }
        printf("%d ", i);
        for(j=0; j<a->vert; j++){
            printf("%d ", a->adj[i][j]);
        }
        printf("\n");
    }
}

/*
0 4
0 2
0 1
1 2
4 2
3 1
3 4
*/

int main(){
    int i,j,x,y;
    Graph a;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &a.vert);

    printf("\nEnter the number of Edges: ");
    scanf("%d", &a.edges);
    

    int *adj[a.vert];
    //initialization of adj matrix, time complexity = O(v^2)
    for(i=0; i<a.vert; i++){
        adj[i] = (int *) malloc(a.vert * sizeof(int));
        for(j=0; j<a.vert; j++){
            adj[i][j]=0;
        }
    }
    a.adj = adj;

    //initialization of visited matrix, time complexity = O(v)
    int *vis = (int *) malloc(a.vert * sizeof(int));
    for(i=0; i<a.vert;i++){
        vis[i] = 0;
    }
    a.visited = vis;

    printf("Enter the edges in the format:- V1<space>V2\n");

    getchar();
    //entering the edges, complexity = O(edges)
    for(i=0; i<a.edges; i++){
        scanf("%d %d", &x, &y);
        if(x<a.vert && y<a.vert){
            addedge(&a,x,y);
        }else{
            printf("\nVertex value incorrect, aborting\n");
            break;
        }
    }

    printf("\nThe Adjacency Matrix for the graph: ");
    printmatrix(&a);
    DFS(&a);
    return 0;

}

/*
    * TIME COMPLEXITY ANALYSIS:-
    * ========================
    * 
    * All the stack operations push, pop and peek take O(1) time
    * Graph creation and initialization of matrices have a time complexity of O(v^2) 
    * The Depth First Search algorithm using Adjacency matrix has a time complexity of O(v^2)
    * 
    * Hence the total program's time complexity is O(v^2)
*/