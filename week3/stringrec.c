#include <stdio.h>

#define size 100

//The analysis are written as comments

char string[size], string2[size];   //2 strings of n size, size=2n
int ind=0,length;                   //2 variables, size = 2

int lenstr(char *A){                //helping functions
    int i;
    for(i=0; A[i]!='\0'; i++);
    return i;
}

int isUpper(char X){                //helping functions
    if(X>=65 && X<=90)
        return 1;

    return 0;
}

void capsfirst(int pos,int caps){       //function call, size = 2 var
    if(pos==length){                    //time = 1
        if(caps==1){                    
            capsfirst(0, 0);            
            return;                     
        }else {                         
            string2[ind] = '\0';        
            return;                     
        }                       //if caps==1, time taken is 3
                                //else time taken is 4
    }
    
    if(caps==1){
        if(isUpper(string[pos]))
            string2[ind++] = string[pos];
    }else if(caps==0){
        if(!isUpper(string[pos]))
            string2[ind++] = string[pos];
    }                           //if caps==1, time taken is 3
                                //else time taken is 4
    capsfirst(++pos, caps);     //time = 1        
}

int main(){
    scanf("%s", string);
    length = lenstr(string);
    capsfirst(0,1);
    printf("\nThe arranged string is: %s\n", string2);
}

/*
        Time and Spatial Analysis

        * On analysing the number of times the recursive function capsfirst is being called:-
        * capsfirst with caps = 1 is called n times
        * capsfirst with caps = 0 is called n times
        
        * The time taken when caps = 1 is: 8
        * The time taken when caps = 0 is: 10
        * Therefore the total time taken by capsfirst() function is 8n+10n = 18n
        * Therefore the time complexity = O(n)

        * The space taken during each function call = 2
        * Total space taken = 2*(2n) (function calls) + 2n (arrays) + 2
        * = 6n +2
        * Here we can see that the absolute space taken is higher than iterative version
        * The space complexity though, it still is an Order(n)
*/