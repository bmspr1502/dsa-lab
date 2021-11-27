#include<stdio.h>
#include<stdlib.h>     
#include<ctype.h>   
#include<string.h>
struct node{
    char data;
    struct node* next;
}*top = NULL;
int push(char n){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(!temp){
        printf("Stack Overflow\n");
        return 1;
    }
    temp->data = n;
    temp->next = top;
    top = temp;
    return 0;
}
char pop(){
    struct node* temp;
    temp = top;
    top = top->next;
    temp->next = NULL;
    return temp->data;
}
int precedence(char x){
	if(x == '^')
		return 3;
	else if(x == '*' || x == '/')
		return 2;
	else if(x == '+' || x == '-')    
		return 1;
	else
		return 0;
}
void postfix(char *a){ 
	printf("Postfix expression: ");
	int i=0;
	char c;
	while(a[i] != '\n'){
		if(isalnum(a[i]))
			printf("%c",a[i]);
		else if((top == NULL) || (top->data == '('))
			push(a[i]);
		else if(a[i] == '(')
			push(a[i]);
		else if(a[i] == ')'){
			while(1){
				c = pop();
				if(c == '(')
					break;
				else
					printf("%c",c);
			}
		}
		else if(precedence(a[i]) > precedence(top->data))
			push(a[i]);
		else if(precedence(a[i]) < precedence(top->data)){
			while(1){
				if(top != NULL && precedence(a[i]) < precedence(top->data))
					printf("%c",pop());
				else{
					if(top != NULL && precedence(a[i]) == precedence(top->data))
						printf("%c",pop());
					push(a[i]);
					break;
				}
			}
		}
		else if(precedence(a[i]) == precedence(top->data)){
			while(1){
				if(top != NULL && precedence(a[i]) == precedence(top->data) && (a[i] != '^'))
					printf("%c",pop());
				else{
					push(a[i]);
					break;
				}
			}
		}
        else
            push(a[i]);
		i++;
	}
	if(top == NULL)
		return;
	while(top != NULL)
		printf("%c",pop());
	return;
}
void prefix(char *b){
	printf("Prefix expression: ");
	int i=0,j=0;
	char c, r[strlen(b)+1];
	while(b[i] != '\0'){
		if(isalnum(b[i])){
			r[j] = b[i];
            j++;
        }
		else if((top == NULL) || (top->data == ')'))
			push(b[i]);
		else if(b[i] == ')')
			push(b[i]);
		else if(b[i] == '('){
			while(1){
				c = pop();
				if(c == ')')
					break;
				else{
					//printf("%c",c);
                    r[j] = c;
                    j++;
                }
			}
		}
		else if(precedence(b[i]) > precedence(top->data))
		 	push(b[i]);
		else if(precedence(b[i]) < precedence(top->data)){
			while(1){
				if(top != NULL&&top->data!=')'){
					//printf("%c",pop());
                    r[j] = pop();
                    j++;
                }
				else{
						push(b[i]);
						break;
				}
			}
		}
	     else if(precedence(b[i]) == precedence(top->data)){
		 	while(1){
		 		if(top != NULL && precedence(b[i]) == precedence(top->data) && (b[i] != '^')){
		 			push(b[i]);
		 			break;
		 		}
		 		else{
		 			//printf("%c",pop());
                    
                    r[j] = pop();
                    j++;
		 			push(b[i]);
		 			break;
		 		}
		 	}
		 }
		i++;
	}
	if(top == NULL)
		return;
	while(top != NULL){
		//printf("%c",pop());
        
        r[j] = pop();
        j++;
	}
    
    r[j] = '\0';
    for(j = strlen(r)-1;j>=0;j--)
        printf("%c",r[j]);
	return;
}
int main(){
    int n=50,i,j;
	char a[n],b[n];
    printf("Enter Infix expression: ");
	fgets(a,n-1,stdin);
	for(i=0,j=strlen(a)-2;j >=0;i++,j--){
		b[i] = a[j];
	}
    b[i] = '\0';
    postfix(a);
	printf("\n");
	prefix(b);                
    return 0;
}