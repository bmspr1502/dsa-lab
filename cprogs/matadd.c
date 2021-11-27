#include<stdio.h>    
#include<stdlib.h>  
int main(){  
    int a[10][10],b[10][10],c[10][10],p,q,i,j,k;  
    printf("Enter the number of rows\n");    
    scanf("%d",&p);    
    printf("Enter the number of columns\n");    
    scanf("%d",&q);    
    printf("Enter the First matrix:\n");   
    for(i=0;i<p;i++)    
    {    
        for(j=0;j<q;j++)
        {     
            scanf("%d",*(a+i+j));    
        }
    }   
    printf("Enter the Second matrix:\n");    
    for(i=0;i<p;i++)    
    {    
        for(j=0;j<q;j++)    
        {    
            scanf("%d",*(b+i+j));    
        }    
    }   
    for(i=0;i<p;i++)    
    {    
        for(j=0;j<q;j++)    
        {        
            **(c+i+j) = **(a+i+j) + **(b+i+j);    
        }    
    }
    printf("Sum of the two matrices using pointers is:\n");
    for(i=0;i<p;i++)    
    {    
        for(j=0;j<q;j++)    
        {    
            printf("%d\t",**(c+i+j));    
        }    
        printf("\n");    
    }    
    return 0;  
}        