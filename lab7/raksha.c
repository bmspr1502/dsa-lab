#include<stdio.h>
#define n 7
int adj[n][n],node[n],res[n],c=0;
int a[n],top = -1;
void push(int x){
    a[++top] = x;
}
int pop(){
    return a[top--];
}
int isempty(){
    if(top == -1)
        return 1;
    return 0;
}
int ispresentstack(int x){
	int i;
	for(i=0;i<=top;i++){
		if(a[i] == x)
			return 1;
	}
	return 0;
}
int isvisited(int x){
	int i;
	for(i=0;i<c;i++){
		if(res[i] == x)
			return 1;
	}
	return 0;
}
void dfs(){
	int i = 0,j = 0;
	push(node[j]);
	res[c++] = node[j];
	while(i < n){
		while(j < n){
			if(adj[i][j] == 1 && !ispresentstack(node[j]) && !isvisited(node[j])){
				push(node[j]);
				res[c++] = node[j];
			}
			j++;
		}
		i++;
	}
}
int main(){
	int i,j;
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&adj[i][j]);
	}
	printf("Enter the nodes: ");
	for(i=0;i<n;i++)
		scanf("%d",&node[i]);
	dfs();
	printf("DFS search result: ");
	for(i=0;i<c;i++)
		printf("%d ",res[i]);
	return 0;
}