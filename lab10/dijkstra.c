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
    int *distance;
    int *parent;
    bool *mstset;
    adjlist *array;
}typedef graph;

//Minimum distance of the graph, that has not been visited yet will be returned
//O(V) time complexity
int mindistance(graph *a){
    int min = INT_MAX, min_index, v;
 
    for (v = 0; v < a->vert; v++)
        if (a->mstset[v] == false && a->distance[v] < min){
            min = a->distance[v];
            min_index = v;
        }
 
    return min_index;
}

void printPath(graph *a, int source, int dest){
    if(a->parent[dest]==-1&& dest!=source)
        return;
    else if(source==dest)
        printf("%d ", dest);
        
    else{
        printPath(a, source, a->parent[dest]);
        printf("-> %d", dest);
    }
}

//Function to print the shortest distance and path between source and each vertex
void printShortestDistance(graph *a, int source){
    printf("\tVertex \tDistance\t Path\n");
    int i;

    for(i=0; i<a->vert; i++){
        
        if(a->distance[i]==INT_MAX)
        printf("\t  %d \tINFINITY \t\t", i);
        else
        printf("\t  %d \t%d \t\t", i, a->distance[i]);
        printPath(a,source,i);
        printf("\n");
    }
    
}

//Function to find the single source shortest distance of all vertex
//This function has a loop that runs V times and calls mindistance, which is O(V)
//Therefore, timecomplexity = O(V^2)
void dijkstra(graph *a, int source, int edge){
    int i,count;
    for(i=0; i<a->vert; i++){
        a->distance[i] = INT_MAX;
        a->mstset[i] = false;
        a->parent[i]=-1;
    }

    a->distance[source] = 0;
    a->parent[source] = -1;

    for(count = 0; count< a->vert -1;count++){
        int u=mindistance(a);
        a->mstset[u] = true;

        adjlistnode *temp = a->array[u].head;
        while(temp){

            int v= temp->dest;
            if(a->mstset[v] == false && a->distance[u]!= INT_MAX && (a->distance[u] + temp->weight < a->distance[v])){
                a->parent[v] = u;
                a->distance[v] = a->distance[u] + temp->weight;
            }
            temp = temp->next;
        }
    }

    printShortestDistance(a, source);
}

//Function to create a dynamically allocated graph O(V)
graph *creategraph(int vert){
    graph *new = (graph *) malloc(sizeof(graph));

    new->vert = vert;
    new->array = (adjlist *) malloc(new->vert * sizeof(adjlist));
    int i;
    for(i=0; i<new->vert; i++){
        new->array[i].head = NULL;
    }
    new->distance = (int *) malloc(vert * sizeof(int));
    new->parent = (int *) malloc(vert * sizeof(int));
    new->mstset = (bool *) malloc(vert * sizeof(bool));

    for(i=0; i<new->vert; i++){
        new->distance[i] = 0;
        new->mstset[i] = false;
    }

    return new;
}

//function to add the edge in the graph, O(1)
void addedge(graph *x, int source, int dest, int weight){

    adjlistnode *new = (adjlistnode *) malloc(sizeof(adjlistnode));

    new->dest = dest;
    new->weight = weight;
    new->next = x->array[source].head;
    x->array[source].head = new;
    
/*
    new = (adjlistnode *) malloc(sizeof(adjlistnode));
    new->dest = source;
    new->weight = weight;
    new->next = x->array[dest].head;
    x->array[dest].head = new;
*/
}

//function to print the adjacency list, O(E)
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

    int source;
    printf("\n Enter the source from where you want to calculate the path: ");
    scanf("%d", &source);
    dijkstra(a, source, e);
    

    return 0;
}

/* 
9 element
=========

0 1 4
0 7 8
1 7 11
1 2 8
2 8 2
2 5 4
2 3 7
3 5 14
3 4 9
4 5 10
5 6 2
6 8 6
7 8 7
6 7 1

6 vertices
==========

0 1 5
0 2 2
1 2 6
1 4 3
1 3 6
3 2 7
2 4 8
3 4 10
3 5 8
4 5 2


0 1 8
1 2 3
1 5 2
3 5 6
5 6 5
2 6 7
6 2 8
6 7 9
0 4 8
4 7 7
*/