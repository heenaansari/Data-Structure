
//EXPIREMENT NO::2
//TITLE:: Implement stack using arrays.
																								//	Learner::Ansari Heena
																								//	
																									
																								
										
  #include<stdio.h>
  #include<unistd.h>
  #include<stdlib.h>
  #define max 5
  struct stack		//Declaraing a Stack.
  {
	  int data[max];
	  int top;
  };
 void intialize(struct stack *s)	//Function for Intializing the stack.
  {s->top=-1;  		
  }
  
  int isEmpty(struct stack *s)	//Checks whether stack is empty or not.
  {
	  if(s->top==1)
	  {return 1;		//Returns 1 if stack is Empty.
	  }
	  else
	  {return 0;		//Returns 0 if stack is not Empty.
	  }
  }

  int isFull(struct stack *s)	  //Checks whether stack if full or not.
  {
	  if(s->top==max-1)         //Returns 1 if stack is full.
	  {return 1;
	  }
	  else
	  {return 0;			//Returns 0 if stack is not Full.
	  }
  }
  
  int push(struct stack *s,int d)	//Pushes element into the stack
  {
	  if(isFull(s))			//Checks whether the stack is full or not
	  return 0;				//Returns 0 if stack is not Full.
	  else
	  {						//If stack is not full, data is pushed in stack.
		  s->top++;
		  s->data[s->top]=d;
		  return 1;
	  }
  }
  
  void pop(struct stack *s)  	//Pops element from the stack
  {int d;
	  if(s->top==-1)			//Checks whether stack is Empty, if empty data cannot be popped.
	  {printf("\n Stack Underflows.");
	  }
	  else
	  {d=s->data[s->top];
		  s->top--;
		  printf("\nPopped Data is %d",d);
	  }
	  
  }
  
  void peek(struct stack*s)        //Peeps data from the stack 	  
  { int d;
	  if(s->top==-1)				//Checks whether stack is Empty, if empty data cannot be peeked.
	  printf("\nStack underflows.");
	  else
	  {d=s->data[s->top--];      //Peeks the data from the stack.
		  printf("\n Data at peek is::%d",d);
	  }
}
  void display(struct stack *s)     //Displays data from the stack 
 	  
  {int i;
	  if(s->top==-1)          //Checks whether stack is Empty, if empty  no data can be displayed.
	  printf("\nStack is empty.");
	  else
	  {
		  printf("\nStack elements are::");  //Displays data of stack.
		  for(i=s->top;i>=0;i--)
		  {printf("%d\n\t\t    ",s->data[i]);
		  }
	  }
  }
  int main()
  {
	  int ch,d;
	  struct stack s;    //Declaring the variable of stack.
	  intialize(&s);		//Calling the intialize function.
	  while(1)
	  {
		  printf("\n\t\t\t\t******MENU*******");
		  printf("\n(1).PUSH.\n(2).POP.\n(3).PEEK.\n(4).DISPLAY.\n(5).EXIT.");
		  printf("\n   Enter your choice::");
		  scanf("%d",&ch);
		  switch(ch)
		  {
			  case 1:
			  printf("\n Enter Data to be Pushed::");
			  scanf("%d",&d);
			  if(push(&s,d))
			  {
				  printf("\nData Pushed Successfully");
			  }
			  else
			  {
				  printf("\nCannot Push Data..Stack overflows.");
			  }
			  break;
			  case 2:
			  pop(&s);
			  break;
			  case 3:
			  peek(&s);
			  break;
			  case 4:
			  display(&s);
			  break;
			  case 5:
			  printf("\nThank you.\nHope you visit again.");
			  exit(0);
			  
			  default:
			  printf("\nPlease enter a valid choice.");
		  }
	  }
  }
  

        
	  
	  
