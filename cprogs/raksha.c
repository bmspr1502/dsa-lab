#include<stdio.h>
#define n 100
int main(){
    char a[n],b[n],c,*p,*q;
    int i,l1=0,l2=0,t=0,s1=0,s2=0,x,y;
    printf("Enter the string\n");
    for(p=a; c = getchar() != '\n' && p<&a[n];p++){
        *p = c;
        l1++;
    }
    *p = '\0';
    printf("Enter the string\n");
    for(q = b; c = getchar() != '\n' && q<&b[n];q++){
        *q = c;
        l2++;
    }
    *q = '\0';
    if(l1 != l2){
        if(l1>l2){
            printf("1\n");
            return 0;
        }
        if(l2>l1){
            printf("-1\n");
            return 0;
        }
    }
    else{
        for(p=a,q=b;*p != '\0';p++,q++){
            if(*p == *q){
                t++;
               printf("%c, %c", *p, *q);
            }
        
            if(t == l1){
                printf("0");
                return 0;
            }
            else if((*p) > (*q)){
                printf("1\n");
                return 0;
            }
            else if((*p) < (*q)){
                printf("-1\n");
                return 0;
            }
        }
    }
}