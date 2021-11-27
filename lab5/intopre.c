#include <stdio.h>
#include <stdlib.h>

#define size 50

//the analysis of each function is written in comments

struct elem{
    char data;
    struct elem* next;
}typedef elem;
//space taken by one structure element = 2, O(1)
elem* head = NULL;

//stack operations

int isEmpty(){  //max time taken = 2, O(1)
    if(head==NULL)
        return 1;

    return 0;
}

void push(char data){   //max time taken = 7, O(1)

    elem *new = (elem*) malloc(sizeof(elem));
    if(!new){
        printf("\n Overflow\n");
        return;
    }

    new->data = data;
    new->next = NULL;

    if(isEmpty()){
        head = new;
    }else{
        new->next = head;
        head = new;
    }
}

char pop(){     //max time taken = 6, O(1)
    if(isEmpty()){
        printf("\nEmpty stack, Underflow");
        return '\0';
    }

    elem *temp = head;
    char tmp = head->data;
    head = head->next;
    free(temp);
    return tmp;
}

char peek(){    //max time taken = 2, O(1)
    if(isEmpty()){
        return '\0';
    }
    return head->data;
}


//general operations

int isOperand(char x){  //max time taken = 2, O(1)
    if((x>='a' && x<='z')||(x>='A' && x<='Z') || (x>='0' && x<='9'))
        return 1;
    else
        return 0;
}


int precedence(char x){     //time taken = 1, O(1)
    switch(x){
        case '+':
        case '-':
                return 1;
                break;
        case '*':
        case '/':
                return 2;
                break;
        case '^':
                return 3;
                break;
        default :
                return 0;
    }
}


//conversion of infix to postfix
void infixtopostfix(char in[], char post[]){
    
    char *ch = in;
    char *po = post;
    while(*ch!='\0'){       //the loop runs n times, O(n)

        if(isOperand(*ch)){     //O(1)
            *po = *ch;
            po++;
        }else if(*ch=='('){     //O(1)
            push(*ch);
        }else if(*ch==')'){     //here the loop can run a constant number of times,
                                //depends o
            while(!isEmpty() && peek()!='('){   
                *po = pop();
                po++;
            }
            pop();
        }else{
            if(precedence(*ch) > precedence(peek())){
                push(*ch);
            }else if(precedence(*ch) == precedence(peek()) && *ch=='^'){
                push(*ch);
            }else{
                while(!isEmpty() && (precedence(*ch)<=precedence(peek()))){
                    *po = pop();
                    po++;
                }
                push(*ch);
            }
        }
        ch++;
    }

    while(!isEmpty()){
        *po=pop();
        po++;
    }
    *po='\0';
}

//function to reverse string

void revstr(char *x){
    int i, n=0;
    char temp;
    for( i=0; x[i]!='\0'; i++)n++;

    for( i=0 ; i< n/2 ; i++){
        temp = x[i];
        x[i] = x[n-1-i];
        x[n-1-i] = temp;
    }
}

//conversion of infix to prefix
void infixtoprefix(char in[], char pre[]){
    //reversing the input

    revstr(in);

    //postfix method with slight changes

    char *ch = in;
    char *pr = pre;

    while(*ch!='\0'){
        if(isOperand(*ch)){
            *pr = *ch;
            pr++;
        }else if(*ch==')'){
            push(*ch);
        }else if(*ch=='('){
            while(!isEmpty() && peek()!=')'){
                *pr = pop();
                pr++;
            }
            pop();
        }else{
            if(precedence(*ch) > precedence(peek())){
                push(*ch);
            }else if(precedence(*ch) == precedence(peek())){

                //when the input order is reversed, the exponentiation order gets reversed,
                //to avoid that have changed that alone

                if(*ch=='^'){
                    while(!isEmpty() && ( precedence (*ch) <= precedence( peek()) ) ){
                        *pr = pop();
                        pr++;
                    }
                }
                push(*ch);
            }else{
                while(!isEmpty() && ( precedence (*ch) <= precedence( peek()) ) ){
                    *pr = pop();
                    pr++;
                }
                push(*ch);
            }
        }
        ch++;
    }

    while(!isEmpty()){
        *pr=pop();
        pr++;
    }
    *pr='\0';   

    //reversing the output
    revstr(pre);

    revstr(in);
}

//driver function

int main(){
    char infix[size], postfix[size], prefix[size], c;
    int i;

    for(i=0; i<size && (c=getchar())!='\n'; i++){
        infix[i] = c;
    }
    infix[i]='\0';

    infixtopostfix(infix, postfix);
    infixtoprefix(infix, prefix);
    printf("\nThe postfix of %s is: %s", infix, postfix);
     printf("\nThe prefix of %s is: %s\n", infix, prefix);
    
    return 0;
}