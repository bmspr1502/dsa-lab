#include <stdio.h>

#define size 30

//the time analysis of each function is written in comments
//all numbers are in units

char stack[size];       //space used = n, (n=size of stack)
int top = -1;           

void push(char x){      //max time used =  2
    if(top>=size-1){
        printf("\nStack overflow");
        return;
    }
    stack[++top] = x;
}

char peek(){        //time taken = 2
    if(top==-1){
        return '\0';
    }
    return stack[top];
}

void pop(){         //time taken = 1
    stack[top--] = '#';
}

int isMatch(char x){    //max time taken = 3
    if(x==')' && peek()=='(')
        return 1;
    if(x=='}' && peek()=='{')
        return 1;
    if(x==']' && peek()=='[')
        return 1;

    return 0;
}

int main(){

    char string[size+1];    //space used = n+1
    fgets(string,size,stdin); //time taken = n
    int i;

    for(i=0; string[i]!='\0';i++){      //time = n
        switch (string[i])              
        {
        case '{':
        case '[':
        case '(':
                    push(string[i]);
                    break;
        case ')':
        case ']':
        case '}':    
                    if(isMatch(string[i])){
                        pop();
                    }else
                        push(string[i]);
                    break;   
        default:
            break;
        }
    }       //the total time taken for all the steps is some constant a*n
            //because it depends on the string's configuration

    if(top==-1){
        printf("\nThe given expression is balanced\n");
    }else{
        printf("\nNOT BALANCED!!!!\n");
    }
    
    return 0;
}

/*
    * TIME COMPLEXITY ANALYSIS
    * ========================
    * 
    * All the stack functions: push, pop, peek take constant time,
    * Order of push, pop, peek = O(1)
    * The actual function to check the balance makes a*n processes,
    * Order of balance checking function = O(n)
*/