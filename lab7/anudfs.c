#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct vertex{
    char data;
    bool visited;
}typedef vertex;
int vertexCount = 0;
int top = -1;

void push(int a,int stack[]) { 
   stack[++top] = a; 
} 

int pop(int stack[]) { 
   return stack[top--]; 
} 

int peek(int stack[]) {
   return stack[top];
}

bool isStackEmpty() {
   return top == -1;
}

void addVertex(char data,vertex* vertices[]){
    vertex* vertex = (struct vertex*) malloc(sizeof(vertex));
    vertex->data = data;
    vertex->visited = false;
    vertices[vertexCount++] = vertex;
}

void addEdge(int max,char edge[],vertex* vertices[],int adjMatrix[max][max]){
    int i,start,end;
    for(i=0;i<max;i++){
        if(vertices[i]->data==edge[0])
            start = i;
        if(vertices[i]->data==edge[2])
            end = i;
    }
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void display(int index,vertex* vertices[]){
    printf("%c ",vertices[index]->data);
}

int adjUnvisitedVertex(int max,int index,vertex* vertices[],int adjMatrix[max][max]){
    int i;
    for(i=0;i<vertexCount;i++){
        if(adjMatrix[index][i]==1 && vertices[i]->visited==false)
            return i;
    }
    return -1;
}

void depthFirstSearch(int max,vertex* vertices[],int adjMatrix[max][max],int stack[]){
    int i,unvisitedVertex;
    vertices[0]->visited = true;
    display(0,vertices);
    push(0,stack);
    while(!isStackEmpty()){
        unvisitedVertex = adjUnvisitedVertex(max,peek(stack),vertices,adjMatrix);
        if(unvisitedVertex==-1)
            pop(stack);
        else{
            vertices[unvisitedVertex]->visited = true;
            display(unvisitedVertex,vertices);
            push(unvisitedVertex,stack);
        }
    }
    printf("\n");
    for(i=0;i<vertexCount;i++){
        vertices[i]->visited = false;
    }
}

void displayAdjMatrix(int max,vertex* vertices[],int adjMatrix[max][max]){
    int i,j;
    printf("The adjacency matrix : \n  |");
    for(i=0;i<vertexCount;i++){
        printf("%c ",vertices[i]->data);
    }
    printf("\n");
    for(i=0;i<vertexCount;i++){
        printf("---");
    }
    printf("\n");
    for(i=0;i<vertexCount;i++){
        printf("%c |",vertices[i]->data);
        for(j=0;j<vertexCount;j++){
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int i,j,edges,max;
    char data;
    printf("Enter the number of vertices : ");
    scanf("%d",&max);
    getchar();
    int stack[max];
    int adjMatrix[max][max];
    vertex* vertices[max];
    for(i=0;i<max;i++){
        for(j=0;j<max;j++)
            adjMatrix[i][j] = 0;
    }
    printf("Enter the vertices:\n");
    fflush(stdin);
    for(i=0;i<max;i++){
        data = getchar();
        getchar();
        addVertex(data,vertices);
    }
    printf("Enter the number of edges:\n");
    scanf("%d",&edges);
    getchar();
    printf("Enter the edges:\n");
    for(i=0;i<edges;i++){
        char edge[4];
        fgets(edge,4,stdin);
        getchar();
        addEdge(max,edge,vertices,adjMatrix);
    }
    displayAdjMatrix(max,vertices,adjMatrix);
    printf("\nDepth First Search from vertex %c : ",vertices[0]->data);
    depthFirstSearch(max,vertices,adjMatrix,stack);
    printf("\n");
}