#include <stdio.h>

#define INT_MAX 9999

//Function to print graph in matrix form
void printMatrix(int n, int *matrix){
    int i, j,k;
    
    for(i=0; i<n; i++){
        if(i==0){
            printf("\t");
            for(k=0; k<n; k++){
                printf("%d\t", k);
            }   
            printf("\n");
            printf("==|==========================================\n");
        }

        printf("%d |\t", i);
        for(j=0; j<n; j++){
            if(*((matrix + i*n) + j) == INT_MAX){
                printf("INF\t");
            }else{
                printf("%d \t", *((matrix + i*n) + j));
            }
        }
            
    printf("\n");
    }
    return;
}

//Function to find the sortest path, time complexity = O(V^3)
void shortPath( int n, int *costMatrix){
    int distance[n][n], i, j, k;
    for (i=0; i<n; i++)
        for(j=0; j<n; j++){
            distance[i][j] = *((costMatrix + i*n) +j);
        }

    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if((distance[i][k] + distance[k][j]) < distance[i][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    printMatrix(n,&distance[0][0]);
}

//Driver function
int main(){
    int n,i,j;
    printf("\nEnter the no. of vertex: ");
    scanf("%d", &n);

    printf("\nEnter the matrix:(for no edge, give input as -1)\n");
    int cost[n][n];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            printf("Enter cost[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);

            cost[i][j] = (cost[i][j] == -1)? INT_MAX : cost[i][j];
        }

    printf("\nInput Matrix: \n");
    printMatrix(n, (int *)&cost[0][0]);
    printf("\nThe All Pair Shortest Path - Distance Matrix :\n");
    shortPath(n, (int *)&cost[0][0]);

    return 0;
}