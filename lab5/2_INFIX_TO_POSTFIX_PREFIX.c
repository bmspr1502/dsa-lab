#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 50

struct stack{
	char data;
	struct stack *next;
};
struct stack *top = NULL;

struct stack *getNode(char data)
{
	struct stack *ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

int isEmpty()
{
	return top == NULL;
}

void push(char data)
{
	struct stack *newNode = getNode(data);
	if(isEmpty())
		top = newNode;
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

char pop()
{
    char pop;
	if(isEmpty());
	else
	{
		pop = top->data;
		struct stack *temp = top;
		top = top->next;
		free(temp);
	}
	return pop;
}

char peek()
{
	return (top) ? top->data : -1;
}

int isOperand(char val)
{
	if((val >= 'A' && val <= 'Z') || (val >= 'a' && val <= 'z'))
		return 1;
	else
		return 0;
}

int isOperator(char val)
{
	if(val == '+' || val == '-' || val == '*' || val == '/' || val == '^')
		return 1;
	else
		return 0;
}

int precedence(char val)
{
	if(val == '^')
		return 3;
	else if(val == '*' || val == '/')
		return 2;
	else if(val == '+' || val == '-')
		return 1;
	else
		return -1;
}

void infix_to_postfix(char in[N], char post[N])
{
	int i, j=0;
	
	for(i = 0; in[i] ;i++)
	{
		if(isOperand(in[i]))
			post[j++] = in[i];
		else if(in[i] == '(')
			push(in[i]);
		else if(in[i] == ')')
		{
			while(!isEmpty() && peek() != '(')
			{
				post[j++] = peek();
				pop();
			}
			if(peek() == '(')
				pop();
		}
		else if(isOperator(in[i]))
		{
			if(isEmpty())
				push(in[i]);
			else if(!isEmpty())
			{
				if(precedence(in[i]) > precedence(peek()) )
					push(in[i]);
				else if( precedence(in[i]) == precedence(peek())  && in[i] == '^' )
					push(in[i]);
				else
				{
					while(!isEmpty() && precedence(in[i]) <= precedence(peek()))
					{
						post[j++] = peek();
						pop();
					}
					push(in[i]);
				}
			}
		}
	}
	while(!isEmpty())
	{
		post[j++] = peek();
		pop();
	}
	post[j] = '\0';
}

void reverse(char in[N])
{
	strrev(in);
	
	int i;
	for(i = 0; in[i] ; i++)
	{
		if(in[i] == '(')
			in[i] = ')';
		else if(in[i] == ')')
			in[i] = '(';
	}
}

void infix_to_prefix(char in[N], char post[N])
{
	reverse(in);
	
	int i, j = 0;
	
	for(i = 0; in[i] ;i++)
	{
		if(isOperand(in[i]))
			post[j++] = in[i];
		else if(in[i] == '(')
			push(in[i]);
		else if(in[i] == ')')
		{
			while(!isEmpty() && peek() != '(')
			{
				post[j++] = peek();
				pop();
			}
			if(peek() == '(')
				pop();
		}
		else if(isOperator(in[i]))
		{
			if(isEmpty())
				push(in[i]);
			else if(!isEmpty())
			{
				if( precedence(in[i])> precedence(peek()) )
					push(in[i]);
				else if( precedence(in[i]) == precedence(peek())  && in[i] == '^' )
				{
					while( !isEmpty() && precedence(in[i]) == precedence(peek()) )
					{
						post[j++] = peek();
						pop();
					}
					push(in[i]);
				}
				else if( precedence(in[i]) == precedence(peek()) )
					push(in[i]);
				else
				{
					while( !isEmpty() && precedence(in[i]) < precedence(peek()) )
					{
						post[j++] = peek();
						pop();
					}
					push(in[i]);
				}
			}
		}
	}
	while(!isEmpty())
	{
		post[j++] = peek();
		pop();
	}
	post[j] = '\0';
	
	strrev(post);
}

int main()
{
	char in[N], post[N];
	
	printf("Infix Expression : ");
	scanf("%s",in);
	
	infix_to_postfix(in, post);
	printf("\nPostfix Expression : %s",post);

    infix_to_prefix(in, post);
	printf("\nPrefix Expression : %s",post);
	
	return 0;
}
