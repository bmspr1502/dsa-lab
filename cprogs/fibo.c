#include<stdio.h>
int fib(int n){
    if(n <= 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}
int main(){
    int n,res;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    res = fib(n);
    printf("Value of %dth term is %d\n",n,res);
    return 0;
}
