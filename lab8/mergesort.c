#include <stdio.h>
#define size 100

//This is the combining function, and it has a time complexity of Theta(n)
void MergeArray(int arr[], int low, int mid, int high){
    int s1 = mid-low +1;
    int s2 = high - mid;
    int i,j,k;
    int leftArr[s1], rightArr[s2];

    for(i=0; i<s1; i++){
        leftArr[i] = arr[low+i];
    }
    for(j=0; j<s2; j++){
        rightArr[j] = arr[mid+1+j];
    }

    i=0;
    j=0;
    k=low;

    while(i<s1 && j<s2){
        if(leftArr[i]<=rightArr[j]){
            arr[k++]=leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while(i<s1){
        arr[k++] = leftArr[i++];
    }
    
    while(j<s2){
        arr[k++] = rightArr[j++];
    }
}

//This is the recursive call function, it has a recurrence relation
//T(n) = 2T(n/2) + Theta(n)
void MergeSort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        MergeArray(arr, low, mid, high);
    }
}

//driver function, complexity = Theta(n)
int main(){
    int arr[size], i=0,temp;
    printf("\nEnter the elements of the array (enter -1 to stop): \n");
    while(1){
        scanf("%d", &temp);
        if(temp==-1)
            break;
        arr[i++] = temp;
    }
    int n = i;
    
    printf("\n Unsorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    MergeSort(arr,0,n-1);

    printf("\n Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

/*

    * TIME COMPLEXITY ANALYSIS
    * ========================
    * 
    * The MergeSort algorithm always divides the array into 2 equal halves
    * unlike quicksort, which can happen in any way.
    * 
    * T(n) = 2T(n/2) + Theta(n)
    * 
    * On solving using master's theorem, 
    * we get the function to be Theta(n*log(n)) for all cases(best,worst,average)
*/