#include<stdio.h>
int a[20],n;
void maxheap(){
    int i,temp;
    for(i=0;i<n;i++){
        if(a[i] >= a[2*i+1] && a[i] >= a[2*i+2]);
        else if(a[i] < a[2*i+1] || a[i] < a[2*i+2]){
            if(a[i] < a[2*i+1]){
               temp = a[i];
               a[i] = a[2*i+1];
               a[2*i+1] = temp; 
            }
            else if(a[i] < a[2*i+2]){
               temp = a[i];
               a[i] = a[2*i+2];
               a[2*i+2] = temp; 
            }
        }
    }
}
int main(){
    int i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        maxheap();
    printf("Max heap: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}