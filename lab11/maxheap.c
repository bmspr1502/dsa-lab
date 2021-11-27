#include<stdio.h>

#define size 40

//Function to swap numbers, O(1)
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Function to heapify, can recursively call upto reaching it's height, so O(log n)
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i + 2;

    if(left<n && arr[largest] < arr[left])
        largest = left;

    if(right<n && arr[largest] < arr[right])
        largest = right;

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

//Function calls heapify n/2 times, so overall complexity is O(n * log n)
void maxheap(int arr[], int n){
    int i;
    for(i=n/2 -1; i>=0; i--)
        heapify(arr, n, i);
}

//function to print the array, O(n)
void printArray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[size], i = 0, temp;

    printf("\n enter the elements (-1 to stop)\n");
    while(1){
        scanf("%d", &temp);
        if(temp == -1)
            break;

        arr[i] = temp;
        i++;
    }

    printf("\nThe given array is: ");
    printArray(arr, i);
    maxheap(arr, i);
    printf("\nThe max heap's array representation is: ");
    printArray(arr, i);

    return 0;
}

/*
    * TIME COMPLEXITY ANALYSIS
    * ========================
    * 
    * The heapification (checking if the largest element is the parent in the group)
    * takes O(log n) complexity.
    * 
    * The maxheap converting function calls the heapify function n/2 times, O(n*log n)
*/