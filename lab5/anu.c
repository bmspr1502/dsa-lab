#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

struct stack{
    char oper;
    struct stack *next;
}*top = NULL;
typedef struct stack stack;
char post[max],rev[max],post1[max],pre[max];

int isOperand(char c){
    return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>=48 && c<=57); 
}
int isEmpty(){
    if(top)
        return 0;
    else
        return 1;
}
int push(char c){
    stack* node = (stack*) malloc(sizeof(stack));
    if(!node){
        printf("Stack overflow.\n");
        return -1;
    }
    else{
        node->oper = c;
        node->next = top;
        top = node;
    }
    return 0;
}
char peek(){
    if(isEmpty()){
        printf("Stack underflow.\n");
        return '$';
    }
    else 
        return top->oper;
}
void pop(){
    if(isEmpty())
        printf("Stack underflow.\n");
    else
        top = top->next;
}
int precedence(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return -1;
}
void postfix(char in[]){
    int k = -1,i;
    for(i=0;in[i]!='\n';i++){
        if(isOperand(in[i]))
            post[++k] = in[i];
        else if(in[i]=='(')
            push(in[i]);
        else if(in[i]==')'){
            while(!isEmpty() && peek()!='('){
                post[++k] = peek();
                pop();
            }
            pop();
        }
        
        else{ //if it's an operator
            if(in[i]=='^'){
                if(precedence(in[i])==precedence(peek()))
                    push(in[i]);
                else{
                    while(!isEmpty() && precedence(in[i]) <= precedence(peek()) ){
                        post[++k] = peek();
                        pop();
                }
                push(in[i]);
                }
            }
            else{
                while(!isEmpty() && precedence(in[i]) <= precedence(peek()) ){
                    post[++k] = peek();
                    pop();
                }
                push(in[i]);
            }
        }
    }
    while(!isEmpty()){
        post[++k] = peek();
        pop();
    }
    post[++k] = '\0';
}
void strrev(char a[]){
    int k=-1,i=0;
    while(a[i]!='\n')
        ++i;
    for(--i;i>=0;--i){
        switch (a[i])
        {
        case '(':
            a[i] = ')';
            break;
        case ')':
            a[i] = '(';
            break;
        }
        rev[++k] = a[i];
    }
    rev[++k] = '\n';
}
void postfix1(char in[]){
    int k = -1,i;
    for(i=0;in[i]!='\n';i++){
        if(isOperand(in[i]))
            post1[++k] = in[i];
        else if(in[i]=='(')
            push(in[i]);
        else if(in[i]==')'){
            while(!isEmpty() && peek()!='('){
                post1[++k] = peek();
                pop();
            }
            pop();
        }
        else{ //if it's an operator
            if(!isEmpty() && precedence(in[i]) == precedence(peek())){
                if(in[i]=='^'){
                    while(!isEmpty() && precedence(in[i]) <= precedence(peek())){
                        post1[++k] = peek();
                        pop();
                    }
                }
                    push(in[i]);
            }
            else{
                    while(!isEmpty() && (precedence(in[i]) <= precedence(peek()) )){
                        post1[++k] = peek();
                        pop();
                    }
                    push(in[i]);
                }
            }
                
        
    }
    while(!isEmpty()){
        post1[++k] = peek();
        pop();
    }
    post1[++k] = '\0';
}
void strrev1(char a[]){
    int k=-1,i=0;
    while(a[i]!='\0')
        ++i;
    for(--i;i>=0;--i)
        pre[++k] = a[i];
    pre[++k] = '\0';
}
void main(){
    char in[max];
    printf("\nEnter the infix expression : ");
    fgets(in,max,stdin);
    postfix(in);
    strrev(in);
    postfix1(rev);
    strrev1(post1);
    printf("Postfix expression : %s\n",post);
    printf("Prefix expression : %s\n\n",pre);
}