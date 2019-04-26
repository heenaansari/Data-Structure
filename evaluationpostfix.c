		/*
								Experiment No.4
			Title : Evaluation of Postfix expression.
											
			In this experiment, a program is written to evaluate a postfix expression.
			This program has user defined function like empty, push, pop and eval.				
		*/

		#include <stdio.h>
		#include <stdlib.h>
		#include <math.h>
		#include <stdbool.h>
		#define MAX 50

		struct stack	//stack structure
		{
			int data[MAX];
			int top;
		};

		bool empty(struct stack *s)	//check stack empty or not
		{
			return (s->top==-1)?true:false;
		}

		void push(struct stack *s,int ele)	//function to push element
		{
			if(s->top < MAX-1)
			s->data[++s->top]=ele;	//pushing element in stack
			else
			printf("\nStack Overflow..");
		}

		int pop(struct stack *s)	//function to pop
		{
			if(!empty(s))
			return s->data[s->top--];	//processing element from stack
			else
			return -1;
		}

		int eval(char *expr)	//function for evaluation of postfix expression
		{
			char c;
			int i,res,op2,x;
			struct stack st;
			st.top=-1;		//initializing stack
			
			for(i=0;expr[i]!='\0';i++)
			{
				c=expr[i];
				switch(c)
				{
					//case for operators
					case '+':
					op2=pop(&st);
					res=pop(&st)+op2; 
					push(&st,res);
					break;
					
					case '-':
					op2=pop(&st);
					res=pop(&st)-op2;
					push(&st,res);
					break;
					
					case '*':
					op2=pop(&st);
					res=pop(&st)*op2;
					push(&st,res);
					break;
					
					case '/':
					op2=pop(&st);
					res=pop(&st)/op2;
					push(&st,res);
					break;
					
					case '^':
					case '$':
					op2=pop(&st);
					x=pop(&st);
					res=pow(x,op2);
					push(&st,res);
					break;
					
					default:		//default case for operands
					push(&st,c-'0');	
				}
			}
			return pop(&st);	//returning the final value
		}

		int main()	//main function
		{
			char* postfix;
			int res;
			postfix=(char*)malloc(1);	//creating a postfix expression
			printf("\nEnter Postfix Expression : ");
			scanf("%s",postfix);
			res=eval(postfix);
			printf("\nEvaluation of Postfix is : %d\n",res);
			
			return 0;
		}

		/*
		Conclusion: In this experiment, we evaluated postfix expression using userdefined functions like empty, push, pop and eval.
		Output:

		Enter Postfix Expression : 478*+

		Evaluation of Postfix is : 60
		*/

