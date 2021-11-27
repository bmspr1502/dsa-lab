#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 10
int G[size][size];
int path[size];

bool non_dup(int k){
    for(int i=1;i<k;i++){
        if(path[i]==path[k])
            return false;
    }
    return true;
}

bool isEdge(int i,int j){//to check if an Edge exists b/w i and j
    if(G[i][j]==1)
        return true;
    return false;
}

void print_cycle(int n){
    printf("Printing the cycle path...\n");
    for(int i=1;i<=n;i++){
        printf("%d..",path[i]);
    }
}

int next_vertex(int k,int n){
    
    if(k==1)
        return path[k];
    int count=n;
    while(count--){
        path[k]=(path[k]+1)%(n+1);
        printf("%d-%d\n",count,path[k]);
        if(!non_dup(k)){
            printf("dup case-%d\n",k);
            continue;
        }
        int u=path[k-1];
        int v=path[k];
        if(isEdge(u,v)){
            if(k<n || (k==n)&&(isEdge(n,1)))
                return path[k];
        }
        else{
            printf("no edge case %d-%d..\n",u,v);
            continue;
        }
    }
    return 0;
}
void Hamiltonian(int k,int n){

    path[k]=next_vertex(k,n);
    if(path[k]==0)
        return;
    if(k==n)
        print_cycle(n);
    else
        return Hamiltonian(k+1,n);
}


int main(){
    int n;
    scanf("%d",&n);
    printf("enter the Adj matrix of the Graph...(row wise)\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&G[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        path[i]=1;
    }
    Hamiltonian(1,n);
}
