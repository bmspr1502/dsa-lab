#include <stdio.h>
#define size 100

//TIME COMPLEXITY IS WRITTEN IN COMMENTS

//this function has a time complexity of Theta(n)
int partition(int arr[], int low, int high){
    int i=low, j=high;
    int pivot = arr[low];

    while(i<j){
        while(arr[i]<=pivot)
            i++;

        while(arr[j]>pivot)
            j--;

        if(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

//This is a recursive call algorithm 
//Here the time function is given by T(n) = T(k) + T(n-k-1) + Theta(n)
void QuickSort(int arr[], int low, int high){
    if(low<high){
        int j=partition(arr,low,high);
        QuickSort(arr, low, j-1);
        QuickSort(arr, j+1, high);
    }
}

//driver function: Theta(n)
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

    QuickSort(arr,0,n-1);

    printf("\n Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

/*
    TIME COMPLEXITY ANALYSIS:
    ========================

    * The overall complexity depends on the case we take.
    * T(n) = T(k) + T(n-k-1) + Theta(n)
    * 
    * Worst case scenario:-
    * 
    * Here k=0, in which case we get T(n) = T(n-1) + Theta(n)
    * Which will lead to the complexity of Theta(n^2)
    * 
    * Best Case scenario:-
    * 
    * Here k = n/2, in which case we get T(n) = 2T(n/2) + Theta(n^2)
    * Which gives a complexity of Theta(n*log(n))
    * 
    * Average Case Scenario:-
    * 
    * Here let us take k=n/4, => T(n) = T(n/4) + T(3n/4) + Theta(n)
    * Solution of above recurrence relation is also Theta(n*log(n))

*/