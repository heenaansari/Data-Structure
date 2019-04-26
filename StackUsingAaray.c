#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define max 50
struct stack
{
	int data[max];
	int top;
};
void intialize(struct stack *s)
{
	s->top=-1;
}
int isEmpty(struct stack *s)
{
	if((s->top)==-1)
	return 1;
	else 
	return 0;
}
int isFull(struct stack *s)
{
	if((s->top)==max-1)
	return 1;
	else 
	return 0;
	
}
void push(struct stack *s,int d)
{
	if(isFull(s))
	printf("\nStack is full");
	else
	{
		s->top++;
		s->data[s->top]=d;
		printf("\n Data Pushed successfully");
	}
}
void pop(struct stack *s)
{
	if(isEmpty(s))
	printf("\nStack is empty");
	else
	{
		int d=s->data[s->top];
		s->top--;
		printf("\n Popped data is %d",d);
	}
}
void peek(struct stack *s)
{
	if(isEmpty(s))
	printf("\nStack is empty");
	else
	{
		int d=s->data[s->top];
		
		printf("\n Peek data is %d",d);
	}
}
void display(struct stack *s)
{int i;
	if(isEmpty(s))
	printf("\nstack empty");
	else
	{ printf("\n Elements are::");
		for(i=s->top;i>=0;i--)
		{
			printf("\n%d",s->data[i]);
		}
	}
}
void search(struct stack *s,int d)
{int i,count=0;
	if(isEmpty(s))
	printf("\nstack is empty");
	else
	{for(i=s->top;i>=0;i--)
		{
			if((s->data[i])==d)
			{printf("\nData found ");
			count++;
			break;
		}
		}
		if(count==0)
		printf("\n Data not found");
	}
}
		

int main()
{
	struct stack st;
	int ch,d;
	intialize(&st);
	while(1)
	{ 
		printf("\n\t\t\t\t\tMENU");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Dispaly\n5.Search\n6.Exit");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
			printf("\n Enter a number : ");
			scanf("%d",&d);
			push(&st,d);
			break;
			case 2:
			pop(&st);
			break;
			case 3:
			peek(&st);
			break;
			case 4:
			display(&st);
			break;
			case 5:
			printf("\nEnter a number : ");
			scanf("%d",&d);
			search(&st,d);
			break;
			case 6:
			exit(0);
			break;
			default:
			printf("\nEnter a valid choice");
		}
	}
	return 0;
}
