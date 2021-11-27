#include <stdio.h>

int gcd(int a, int b){
    if(b==0)
        return a;

    else 
        return gcd(b, a%b);
}

int gcdgoto(int a, int b){
    start:
    if(b==0)
        return a;
    
    else
    {
        int temp = b;
        b = a%b;
        a = temp;
        goto start;
    }
    
}

int gcdwhile(int a, int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    if(b==0)
        return a;
}

int main(){
    int a,b;
    scanf("%d%d", &a, &b);
    printf("The gcd of %d, %d using \n1. Recursion = %d \n2.Goto = %d \n3.While = %d\n", a,b, gcd(a,b), gcdgoto(a,b), gcdwhile(a,b));
    return 0;
}