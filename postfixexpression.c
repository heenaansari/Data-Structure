#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack 
{
	char data[MAX];
	int top;
};
int isfull(struct stack *s)
{
	if(s->top==MAX-1)
	return 1;
	else
	return 0;
}


int isEmpty(struct stack *s)
{
	if(s->top==-1)
	printf("\n stack underflows.");
	return -1;
}

int push(struct stack *s,char d)
{
	if(isfull(s))
	{
		printf("stack overflow");
	}
	
		s->top++;
		  s->data[s->top]=d;
		  return 1;

}



int pop(struct stack *s)
{
	if(s->top==-1)
	
	printf("\nStack underflows");
    

		int d;
		d=s->data[s->top];
		s->top--;
		return d;
	
}



int precedence(char a)
{
	switch(a)
	{
		case '-':
		case '+':
		return 1;
		break;
		case '*':
		case '/':
		return 2;
		break;
		case '$':
		case '^':
		return 3;
		break;
	}
	return 0;
}

		
char * convert(char *expr)
{
	char *pexpr,sc='\0',c;
	struct stack st;
	int i,n,j;
	st.top=-1;
	for(n=0;expr[n]!='\0';n++);
	pexpr=(char*)malloc(n+1);
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
			w=isEmpty(&st);
			while(w!=-1 && precedence(st.data[st.top])>=precedence(c))
			{
				sc=pop(&st);
				pexpr[j++]=sc;
			}
			push(&st,c);
			break;
			case '(':
			push(&st,c);
			break;
			case ')':
			while((sc=pop(&st))!='(')
			pexpr[j++]=pop(&st);
			pexpr[j]='\0';
			default:
			pexpr[j++]=c;
		}
	}
	while(!isEmpty(&st))
	pexpr[j++]=pop(&st);
	pexpr[j]='\0';
	return pexpr;
}


		
	
int main()
{
	char *infix,*postfix;
	infix=(char*)malloc(1);
	printf("\nEnter the Infix expression::");
	scanf("%s",infix);
	postfix=convert(infix);
	printf("\nPostfix Expression is::%s",postfix);
	return 0;
}
