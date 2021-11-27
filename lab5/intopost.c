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
    free(temp);
    return tmp;
}

char peek(){
    if(isEmpty()){
        return '\0';
    }
    return head->data;
}

void display(elem *ptr){
    if(ptr==NULL){
        return;
    }
    display(ptr->next);
    printf("%c ", ptr->data);
    
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

//changing funcion

void infixtopostfix(char *in, char *post){
    char *ptr = in;
    char *out = post;
    *post = '\0';
    printf("\n\tCharacter\tStack \t\t\t\tOutput");
    printf("\n\t=========\t===== \t\t\t\t======\n");

    while(*ptr != '\0'){
        if(isOperand(*ptr)){
            *out = *ptr;
            *(out+1) = '\0';
            out++;
        }else if(*ptr == '('){
            push(*ptr);
        }else if(*ptr == ')'){
            while(!isEmpty() && peek()!='('){
                *out = pop();
                *(out+1) = '\0';
                out++;
            }
            pop();
        } else {
            if(precedence(*ptr) > precedence(peek())){
                push(*ptr);
            }else if(precedence(*ptr) <= precedence(peek())){
                if(*ptr=='^'){
                    push(*ptr);
                }else{
                    while(!isEmpty() && precedence(*ptr)<=precedence(peek())){
                        *out = pop();
                        *(out+1) = '\0';
                        out++;
                    }
                    push(*ptr);
                }
            }
        }
        
        printf("\n\t%c \t\t",*ptr);
        display(head);
        printf("\t\t\t\t%s", post);
        ptr++;
    }
    if(!isEmpty()){
        printf("\nPopping: ");
        display(head);
        while(!isEmpty()){
                *out = pop();
                *(out+1) = '\0';
                out++;
        }
    }
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
    //infixtoprefix(infix, prefix);
    printf("\nThe postfix of %s is: %s\n", infix, postfix);
//  printf("\nThe prefix of %s is: %s\n", infix, prefix);
    
    return 0;
}