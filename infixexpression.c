#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 5
struct stack 	//Declaring the stack.
{
	int data[MAX];
	int top;
};

				
int isEmpty(struct stack *s)	//Function to checks whether the stack is empty or not.
{
	if(s->top==-1)
	return 1;
	else
	return 0;
}
				
int isFull(struct stack *s)	//Function to check whether the stack is full or not.
{
	if(s->top==MAX-1)
	return 1;
	else
	return 0;
}
				
int push(struct stack *s,int d)		//Function to push the data on top of the stack.
{
	if(isFull(s))
	return 0;
	else
	{
		s->top++;
		s->data[s->top]=d;
		return 1;
	}
}
				
int pop(struct stack *s)		//Function to pop the data from the top of the stack.
{
	if(s->top==-1)
	printf("\n\t Stack underflows->");
	else
	{
		int d;
		d=s->data[s->top];
		s->top--;
		return d;
	}
}
int precedence(int a)		//Function to check precedence. 
{
	switch(a)		
	{
		case '-':
		return 1;
		break;
		case '+':
		return 1;
		break;
		case '*':
		return 2;
		break;
		case '/':
		return 2;
		case '$':
		case '^':
		return 3;
		break;
	}
	return 0; 	//If a operand or parenthesis return 0;
	
}
char *convert(char *expr)	//Function to convert infix expression to postfix expression.	
{
char *pexpr;
char c,sc='\0';
int i,j,n;
struct stack st;
st.top=-1;
for(n=0;expr[n]!='\0';n++); 	//Calculates the length of the expression.
pexpr=(char *)malloc(n+1);

for(i=0,j=0;expr[i]!='\0';i++)
{
c=expr[i];
	switch(c)			
	{
		case '-':
		case '+':
		case '*':
		case '/':
		case '$':
		case '^':
		
		/*If an operator is encountered repeatedly pop from the stack and add it to the postfix                           expression each operator (on the top of the stack) which has same or higher   
                            precedence than the encountered operator.*/ 

		while(!isEmpty(&st)&&precedence(st.data[st.top])>=precedence(c))
		{
			sc=pop(&st);
			pexpr[j++]=sc;
		}
		push(&st,c);
		break;
		case '(':
		//If a left parenthesis is encountered push it on the stack.
		push(&st,c);
		break;
		case ')':
 		/*If a left parenthesis is encountered , repeatedly pop from the stack and add each 
operator) on the top of the stack until the left parenthesis is encountered .*/
		while((sc=pop(&st))!='(')
		pexpr[j++]=sc;
		break;
		default:
		//If an operand put it in the postfix expression.
		pexpr[j++]=c;
	}
}
while(!isEmpty(&st))	//pop from the stack until it is empty.
pexpr[j++]=pop(&st);
pexpr[j]='\0';
return pexpr;
}

int main()			
{
	char *infix, *postfix;
	infix=(char*)malloc(1);
	printf("\n Enter infix expression: ");
	scanf("%s",infix);
	postfix=convert(infix);
	printf("\n Postfix expression is : %s\n",postfix);
	return 0;
}
