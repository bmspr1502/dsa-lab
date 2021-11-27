#include <stdio.h>
#define size 100

//Function to swap elements, O(1)
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
    Recursive algorthim, can go upto the second level from the bottom
    Therefore it has O(log n) time complexity
*/
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && arr[l]>arr[largest])
        largest = l;

    if(r<n && arr[r] > arr[largest])
        largest = r;

    if(largest !=i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/*
    The heapify function is called for 3n/2 times in this function,
    So overall time complexity or this function is:= O(n logn)
*/
void heapSort(int arr[], int n){
    int i;

    //(n/2) heapify calls
    for(i= n/2 -1; i>=0; i--){
        heapify(arr, n, i);
    }

    //n heapify calls
    for(i=n-1; i>0; i--){
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

//Function to print the array, O(n)
void printArray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

//driver function:
int main(){
    int arr[size], i=0, temp;
    printf("\n enter the elements: (enter -1 to stop insertion)\n");

    while(1){
        scanf("%d", &temp);
        if(temp==-1)
            break;
        
        arr[i] = temp;
        i++;
    }

    printf("\nThe unsorted array is: ");
    printArray(arr, i);
    heapSort(arr, i);
    printf("\nThe sorted array is: ");
    printArray(arr, i);

    return 0;
}

/*
    * TIME COMPLEXITY ANALYSIS
    * ========================
    * 
    * Heapification takes O(log n) time
    * Heapsort calls heapify for O(n) times
    * 
    * Therefore heapsort has a time complexity of O(n*log n)
*/