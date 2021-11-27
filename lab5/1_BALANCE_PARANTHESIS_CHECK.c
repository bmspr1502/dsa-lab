#include<stdio.h>
#include<stdlib.h>
#define N 50

int top = -1;
int stack[N];

void push(char);
char pop();
int isMatch(char, char);
int isBalanced(char*);

int main()
{
    char exp[N];
    printf("Enter an expression : ");
    scanf("%s", exp);

    if(isBalanced(exp))
        printf("BALANCED\n");
    else
        printf("NOT BALANCED\n");

    return 0;
}

int isBalanced(char *exp)
{
    for(int i=0; exp ;i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top==-1)
                return 0;
            else
                return (isMatch(pop(), exp[i]));
        }
    }

    if(top == -1)
        return 1;
    else
        return 0;        
}

int isMatch(char a,char b)
{
    if(a=='[' && b==']')
            return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='(' && b==')')
            return 1;
    return 0;
}

void push(char c)
{
	if(top == N-1)
		printf("Stack Overflow\n");
	else
		stack[++top] = c;
}

char pop()
{
	if(top == -1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
	return stack[top--];
}