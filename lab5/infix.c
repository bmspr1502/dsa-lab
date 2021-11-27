#include <stdio.h>
#include <stdlib.h>


#define size 50

struct elem{
    char data;
    struct elem* next;
}typedef elem;

elem* head = NULL;

//stack operations

int isEmpty(){
    if(head==NULL)
        return 1;

    return 0;
}

void push(char data){

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

char pop(){
    if(isEmpty()){
        printf("\nEmpty stack, Underflow");
        return '\0';
    }

    elem *temp = head;
    char tmp = head->data;
    head = head->next;
//    printf("\n Deallocating %c", tmp);
    free(temp);
    return tmp;
}

char peek(){
    if(isEmpty()){
        return '\0';
    }
    return head->data;
}

//general operations

int isOperand(char x){
    if((x>='a' && x<='z')||(x>='A' && x<='Z') || (x>='0' && x<='9'))
        return 1;
    else
        return 0;
}


int precedence(char x){
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

//conversion function

void infixtopostfix(char in[], char post[]){
    /*
    char *ch = in;
    char *po = post;
    while(*ch!='\0'){
        if(isOperand(*ch)){
            *po = *ch;
            po++;
        }else if(*ch=='('){
            push(*ch);
        }else if(*ch==')'){
            while(!isEmpty() && peek()!='('){
                *po = pop();
                po++;
            }
            pop();
        }else{
            if(precedence(*ch) > precedence(peek())){
                push(*ch);
            }else if(precedence(*ch) == precedence(peek())){
                push(*ch);
            }else{
                while(!isEmpty() && (precedence(*ch)<precedence(peek()))){
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
    */
   char *ch = in;
    char *pr = post;

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
}

void revstr(char *x){
    int i, n=0;
    char temp;
    for( i=0; x[i]!='\0'; i++)n++;

    for( i=0 ; i< n/2 ; i++){
        temp = x[i];
        x[i] = x[n-1-i];
        x[n-1-i] = temp;
    }
    for(i=0; x[i]!='\0';i++){
        if(x[i]=='(')
            x[i] = ')';
        else if(x[i]==')')
            x[i] = '(';
    }
}


void infixtoprefix(char in[], char pre[]){

    revstr(in);
    /*
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
    */
   infixtopostfix(in,pre);

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