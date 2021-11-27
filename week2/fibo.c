#include<stdio.h>

int fibo(int n){
    if(n<=1)
        return n;

    else
        return fibo(n-1) + fibo(n-2);
}
int fibtail(int n, int a, int b) { 
    if (n == 0) 
        return a; 
    if (n == 1) 
        return b; 
    return fibtail(n - 1, b, a + b); 
}
int fibogoto(int n){
   if(n<=1)
    return n;

    int current=1, prev=0,i=1;
    start:
    if(i>=n)
        return current;
    else
    {
        int next = current + prev;
        prev = current;
        current = next;
        i++;
        goto start;
    }
    
}
int fibowhile(int n){
    if(n<=1)
        return n;
    int current = 1;
    int prev = 0, i=1;
    while(i<n){
        int next = current + prev;
        prev = current;
        current = next;
        i++;
    }
    return current;
}
int main(){
    int x;
    scanf("%d", &x);
    printf("The %dth fibo no. is: \nUsing reursion %d \nUsing tail recursion %d \n Using goto: %d \n Using while: %d\n", x, fibtail(x,0,1), fibo(x), fibogoto(x), fibowhile(x));
    return 0;
}