#include<stdio.h>    
#include<stdlib.h>  
int main(){  
    int a[10][10],b[10][10],c[10][10];
    int x,y,r,s,i,j,k;    
    printf("Enter the number of rows and columns for first matrix\n");    
    scanf("%d",&r);
    scanf("%d",&s);    
    printf("Enter the number of rows and columns for second matrix\n");    
    scanf("%d",&x);
    scanf("%d",&y);
    if(s == x){   
        printf("Enter the First matrix\n");    
        for(i=0;i<r;i++)    
        {    
            for(j=0;j<s;j++)
            {     
                scanf("%d",&a[i][j]);    
            }
        }    
        printf("Enter the Second matrix:-\n");    
        for(i=0;i<x;i++)    
        {    
            for(j=0;j<y;j++)    
            {    
                scanf("%d",&b[i][j]);    
            }    
        }    
            
        printf("Multiplication of the two matrices are\n");    
        for(i=0;i<r;i++)    
        {    
            for(j=0;j<s;j++)    
            {    
                c[i][j]=0;    
                for(k=0;k<y;k++)    
                {    
                    c[i][j] += a[i][k] * b[k][j];    
                }    
            }    
        }      
        for(i=0;i<r;i++)    
        {    
            for(j=0;j<y;j++)    
            {    
                printf("%d\t",c[i][j]);    
            }    
            printf("\n");    
        }
    }
    else{
        printf("Invalid matrix order, matrix multiplication can't happen that way");
    }    
    return 0;  
}  