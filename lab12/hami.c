
#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>

#define vertex 5 

void printCycle(int path[]); 


bool canBeAdded(int v, bool graph[vertex][vertex], int path[], int pos) 
{ 
	if (graph [path[pos-1]][v] == 0) 
		return false; 

	for (int i = 0; i < pos; i++) 
		if (path[i] == v) 
			return false; 

	return true; 
} 


bool hamiCycleGenerator(bool graph[vertex][vertex], int path[], int pos) 
{ 
	
	if (pos == vertex) 
	{
		if (graph[path[pos-1]][path[0]] == 1) 
		    return true; 
		else
		    return false; 
	} 

	
	for (int v = 1; v < vertex; v++) 
	{ 
		if (canBeAdded(v, graph, path, pos)) 
		{ 
			path[pos] = v; 

			if (hamiCycleGenerator (graph, path, pos+1) == true) 
				return true; 

			path[pos] = -1; 
		} 
	} 

	return false; 
} 


bool hamiCycleSolver(bool graph[vertex][vertex]) 
{ 
	int *path = (int *) malloc(vertex * sizeof(int)); 
	for (int i = 0; i < vertex; i++) 
		path[i] = -1; 


	path[0] = 0; 
	if ( hamiCycleGenerator(graph, path, 1) == false ) 
	{ 
		printf("\nSolution does not exist"); 
		return false; 
	} 

	printCycle(path); 
	return true; 
} 

void printCycle(int path[]) 
{ 
	printf ("Solution Exists: Following is one Hamiltonian Cycle \n"); 
	for (int i = 0; i < vertex; i++) 
		printf(" %d ", path[i]); 

	printf(" %d ", path[0]); 
	printf("\n"); 
} 


void addEdge(bool a[vertex][vertex], int x, int y){
    a[x][y]=true;
    a[y][x]=true;
}

void printMatrix(bool a[vertex][vertex]){
    int i,j;
    printf("Matrix: \n");
    for(i = 0; i<vertex; i++){
        if(i==0){
            printf("  ");
            for(j=0; j<vertex; j++){
                printf("%d ", j);
            }
            printf("\n");
        }
        printf("%d ", i);
        for(j=0; j<vertex; j++){
            if(a[i][j]==true)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}


int main() 
{ 
    int i,j,x,y,edge;
    printf("Enter the number of edges: ");
    scanf("%d", &edge);
    
    bool Matrix[vertex][vertex];
    getchar();

    for(i=0; i<edge; i++){
         scanf("%d %d", &x, &y);
        if(x<vertex && y<vertex){
            addEdge(Matrix,x,y);
        }else{
            printf("\nVertex value incorrect, aborting\n");
            break;
        }
    }

    printMatrix(Matrix);
    hamiCycleSolver(Matrix);
/* Let us create the following graph 
	(0)--(1)--(2) 
	| / \ | 
	| / \ | 
	| /	 \ | 
	(3)-------(4) 
bool graph1[vertex][vertex] = {{0, 1, 0, 1, 0}, 
					{1, 0, 1, 1, 1}, 
					{0, 1, 0, 0, 1}, 
					{1, 1, 0, 0, 1}, 
					{0, 1, 1, 1, 0}, 
					}; 

	// Print the solution 
	hamiCycleSolver(graph1); 

 Let us create the following graph 
	(0)--(1)--(2) 
	| / \ | 
	| / \ | 
	| /	 \ | 
	(3)	 (4) 
	bool graph2[vertex][vertex] = {{0, 1, 0, 1, 0}, 
					{1, 0, 1, 1, 1}, 
					{0, 1, 0, 0, 1}, 
					{1, 1, 0, 0, 0}, 
					{0, 1, 1, 0, 0}, 
					}; 

	// Print the solution 
	hamiCycleSolver(graph2); 

*/
	return 0; 
} 
