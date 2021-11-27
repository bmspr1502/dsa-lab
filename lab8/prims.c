#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//GRAPH DEFINITIONS
struct adjlistnode{
    int dest;
    int weight;
    struct adjlistnode *next;
}typedef adjlistnode;

struct adjlist{
    adjlistnode *head;
}typedef adjlist;

struct graph{
    int vert;
    int *key;
    int *parent;
    bool *mstset;
    adjlist *array;
}typedef graph;

//Minimum Key of the graph, that has not been visited yet will be returned
int minkey(graph *a){
    int min = INT_MAX, min_index, v;
 
    for (v = 0; v < a->vert; v++)
        if (a->mstset[v] == false && a->key[v] < min){
            min = a->key[v];
            min_index = v;
        }
 
    return min_index;
}

//Function to print the minimum spanning tree of the Graph
void printMST(graph *a){
    printf("\nEdge \tWeight\n");
    int i;

    for(i=1; i<a->vert; i++){
        printf("%d - %d \t%d \n", a->parent[i], i, a->key[i]);
    }
    
}

//Function to find the minimum cost edges for the spanning tree
void primMST(graph *a){
    int i,count;
    for(i=0; i<a->vert; i++){
        a->key[i] = INT_MAX;
        a->mstset[i] = false;
    }

    a->key[0] = 0;
    a->parent[0] = -1;

    for(count = 0; count< a->vert -1;count++){
        int u=minkey(a);
        a->mstset[u] = true;

        adjlistnode *temp = a->array[u].head;
        while(temp){
            if(a->mstset[temp->dest]==false && temp->weight < a->key[temp->dest]){
                a->parent[temp->dest] = u;
                a->key[temp->dest] = temp->weight;
            }
            temp = temp->next;
        }

        printf("\nCurrent vertex: %d", u);
        printf("\n Shortest DistanceS : ");
        for(i=0; i<a->vert; i++){
            if(a->key[i] == INT_MAX)
                printf("\tINF");
            else
                printf("\t%d", a->key[i]);

        }
    }

    printMST(a);
}

//Function to create a dynamically allocated graph
graph *creategraph(int vert){
    graph *new = (graph *) malloc(sizeof(graph));

    new->vert = vert;
    new->array = (adjlist *) malloc(new->vert * sizeof(adjlist));
    int i;
    for(i=0; i<new->vert; i++){
        new->array[i].head = NULL;
    }
    new->key = (int *) malloc(vert * sizeof(int));
    new->parent = (int *) malloc(vert * sizeof(int));
    new->mstset = (bool *) malloc(vert * sizeof(bool));

    for(i=0; i<new->vert; i++){
        new->key[i] = 0;
        new->parent[i] = -1;
        new->mstset[i] = false;
    }

    return new;
}

//function to add the edge in the graph
void addedge(graph *x, int source, int dest, int weight){
    adjlistnode *new = (adjlistnode *) malloc(sizeof(adjlistnode));

    new->dest = dest;
    new->weight = weight;
    new->next = x->array[source].head;
    x->array[source].head = new;

    new = (adjlistnode *) malloc(sizeof(adjlistnode));
    new->dest = source;
    new->weight = weight;
    new->next = x->array[dest].head;
    x->array[dest].head = new;
}

//function to print the adjacency list
void printlists(graph *a){
    int i;
    for(i=0; i<a->vert; i++){
        printf("\n For vertex %d ", i);
        adjlistnode *temp = a->array[i].head;
        while(temp){
            printf(" -> %d (%d) ", temp->dest, temp->weight);
            temp = temp->next;
        }
    }
}

//Driver function
int main(){
    int x,y,i,v,e,w;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &v);

    printf("\nEnter the number of Edges: ");
    scanf("%d", &e);
    getchar();
    graph *a = creategraph(v);
    printf("\nEnter the edges in the format:- V1<space>V2<space>Weight\n");
    
    for(i=0; i<e; i++){
        scanf("%d %d %d", &x, &y, &w);
        if(x<a->vert && y<a->vert){
            addedge(a,x,y,w);
        }else{
            printf("\nVertex value incorrect, aborting\n");
            break;
        }
    }

    
    printf("\nThe Adjacency List for the graph: ");
    printlists(a);
    printf("\n");
    primMST(a);
    

    return 0;
}
