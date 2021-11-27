#include<stdio.h>
#include <limits.h> 
#include<stdbool.h>
int V,graph[20][20];
int minDistance(int dist[], bool sptSet[]){  
	int min = INT_MAX, min_index,v;
	for(v = 0; v < V; v++) 
		if(sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 
	return min_index; 
} 
void printPath(int parent[], int j){  
	if(parent[j] == - 1) 
		return; 
	printPath(parent, parent[j]); 
	printf("%d ", j); 
} 
int printSolution(int dist[], int n,int parent[]){ 
	int src = 1,i; 
	printf("Vertex\t Distance\tPath"); 
	for(i = 0; i < V; i++){ 
        if(dist[i]==INT_MAX)
        printf("\n%d -> %d\t\tINFINITY\t ",src, i); 
        else
		printf("\n%d -> %d\t\t%d\t%d ",src, i, dist[i], src); 
		printPath(parent, i); 
	} 
} 

void dijkstra(int src){ 
	int dist[V],i,count,v,u;
	bool sptSet[V]; 
	int parent[V];
	for(i = 0; i < V; i++){ 
		parent[i] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = false; 
	}
	dist[src] = 0; 
	for(count = 0; count < V - 1; count++){ 
		u = minDistance(dist, sptSet); 
		sptSet[u] = true; 
		for(v = 0; v < V; v++)
			if(!sptSet[v] && graph[u][v]!=INT_MAX && dist[u] + graph[u][v] < dist[v]){ 
				parent[v] = u; 
				dist[v] = dist[u] + graph[u][v]; 
			} 
	} 
	printSolution(dist, V, parent); 
} 
int main(){
    int i,j;
    printf("Enter the number of nodes: ");
    scanf("%d",&V); 
    printf("Enter the matrix:\n");                  
    for(i = 0;i < V;i++){
        for(j = 0;j < V;j++)
            scanf("%d",&graph[i][j]);
    }
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            if(graph[i][j]==-1){
                graph[i][j]= INT_MAX;
            }
        }
    }
	dijkstra(1); 
    printf("\n");
	return 0; 
}