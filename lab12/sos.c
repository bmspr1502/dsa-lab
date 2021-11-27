#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n,m, nodes=0;
int *arr;
bool *incl;

//Function to print the subsets
void write(int x){
    int i;
    for(i=0; i<=x; i++){
        if(incl[i]==true)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

//Function to calculate the sum of subsets (Backtracking algorithm)
void SumOfSubs(int s, int k, int r){
    nodes++;
    
    //Seeing the possiblities of left child (current element included)
    incl[k] = true;
    
    //If cuurent element included gives the required sum, print it
    if(s + arr[k] == m)
        write(k);

    //If the value is less than the sum, include the current element and go to the next element
    else if(s + arr[k] + arr[k+1] <= m)
        SumOfSubs(s + arr[k], k+1, r - arr[k]);

    //For the possiblities of right child (when current element is not included)
    if ( (s + r - arr[k] >= m) && (s+arr[k+1] <= m) ){
        incl[k] = false;
        SumOfSubs(s, k+1, r - arr[k]);
    }
}

//Comparing function (for quicksort)
int cmpfn (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int main(){
    int sum=0;
    printf("\nEnter the number of integers: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));
    incl = (bool *)  malloc(n * sizeof(bool));

    printf("Enter the set of %d integers: ", n);
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        sum+=arr[i];
        incl[i] = false;
    }

    //sorting the inputs
    qsort(arr, n, sizeof(int), cmpfn);
    
    printf("Enter the value of sum, you want subsets for: ");
    scanf("%d", &m);

    printf("\n The subsets whose sum is equal to %d is: \n", m);
    
    SumOfSubs(0,0,sum);

    printf("The number of nodes searched in is %d. \n", nodes);
    return 0;
}