#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
struct SLL
{
	int data;
	struct SLL *next; //Self refrential structure
	};

struct SLL *insert(struct SLL *h,int d)//function to insert a data at end of Linked List
{
    struct SLL *p,*temp;
    p=(struct SLL *)malloc(sizeof(struct SLL));
    if(p==NULL)
		{printf("\n overflows");  //memory not allocated
			
		}
		else
		{
	            p->data=d;
		p->next=NULL;
		if(h==NULL)
		{
			h=p;//Inserting the first node
		}
		else
		{
			temp=h;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
		temp->next=p;
	}
	
}

    return h;
}
struct SLL *insertbefore(struct SLL *h,int d,int k)
//Function to insert a data before a given data
{
	struct SLL *p,*temp,* prev;
    p=(struct SLL *)malloc(sizeof(struct SLL));
    if(p==NULL)
		printf("\noverflows");  //memory not allocated
    
    else
    {temp=h;
		p->data=d;
    while(temp!=NULL&&temp->data!=k)
    {
		prev=temp;
        temp=temp->next;		//traverse in the linked list
	}

	if(temp!=NULL)
	{
		if(temp==h)
{
p->next=temp;
h=p;
}
else
{
		p->next=prev->next;
		prev->next=p;//inserting the node before the given node
	}
	}
	else
	{
		printf("\nData not found");
		p=NULL;
		free(p);
	}
}
	return h;
}
struct SLL *insertafter(struct SLL *h,int d,int k)
//Function to insert the data after the given data 
{
    struct SLL *p,*temp;
    p=(struct SLL *)malloc(sizeof(struct SLL));
    if(p==NULL)
		printf("\noverflows");  //memory not allocated
    temp=h;
    p->data=d;
    while(temp!=NULL&&temp->data!=k)
    {
			temp=temp->next;		//traverse in the linked list
	}

	if(temp!=NULL)
	{
    	if(temp==h)
{
	temp->next=p;
}
else
{
		p->next=temp->next;
		temp->next=p;
}	}
	else
	{
		printf("\nDATa not found");
		
		p=NULL;
		free(p);
	}
	
    
   return h;
}
struct SLL *removegiven(struct SLL *h,int key)
//Function to remove the given data 
{
	struct SLL *temp,*prev;
	temp=prev=h;
	if(h==NULL)
	printf("\n LINKED LIST IS EMPTY.");
	else
	{while(temp!=NULL && temp->data!=key)//If data is in the first node
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp!=NULL&&temp==h)
		{     h=temp->next;
		      temp=NULL;
		    free(temp);  
		}
		if(temp!=NULL)
		{	prev->next=temp->next;
			temp->next=NULL;
			free(temp);
		}
		else
		{
			printf("\n Data not found");
		}
		}
		return h;
		}
		struct SLL *removeLast(struct SLL*h)
		//Function to remove the last node
		{
		struct SLL*tmp, *prev;
		tmp=h;
			if(h!=NULL)
			{
			if(h->next!=NULL)
		{
	            	while(tmp->next!=NULL)
		    {
	                  prev=tmp;
		     tmp=tmp->next;
		     }
			prev->next=NULL;
		       tmp=NULL;
		free(tmp);
		   }	
		else
		{
		h=NULL;
		free(tmp);//free the node
	       }
	  }	
	else
	{ printf("\nLinked List is Empty...");
	}
	return h;
	}
	void display(struct SLL *h)//Function to display the Linked List
             {struct SLL *temp;
	   if(h==NULL)
	  printf("\n Linked list is empty");
	else
	{    temp=h;
	     printf("\nLinked list elements are::");
	     while(temp!=NULL)
		{printf("\n%d",temp->data);
		temp=temp->next;
		}
	}
	}
	int main()
        {
	struct SLL *h;
	int ch,d,key;
	
	h=NULL;
	while (1)
	{
		printf("\n <------***********MENU************---------->");
		printf("\n(1.)INSERT.\n(2.)INSERT AFTER\n(3.)INSERT BEFORE\n(4.)REMOVE THE GIVEN DATA \n(5.)REMOVE LAST\n(6.)DISPLAY\n(7.)EXIT");
		printf("\n Enter your choice::");
		scanf("%d",&ch);
		switch(ch)
		 {
			 case 1:
				printf("\nEnter data to be inserted=");
				scanf("%d",&d);
				h=insert(h,d);
			break;
			case 2:
				printf("\nEnter data to be inserted=");
				scanf("%d",&d);
				printf("\n Enter after which data to be inserted:");
				scanf("%d",&key);
				h=insertafter(h,d,key);
			break;
			case 3:
				printf("\nEnter data to be inserted=");
				scanf("%d",&d);
				printf("\n Enter before which data is to be inserted:");
				scanf("%d",&key);
				h=insertbefore(h,d,key);
				
			break;
			case 4:
				printf("\nEnter data to be removed=");
				scanf("%d",&d);
				h=removegiven(h,d);
			break;
			case 5:
			h=removeLast(h);
			break;
			case 6:
				display(h);
			break;
			
			case 7:
				printf("\n\t\t<-----****THANK YOU****----->");
				exit(0);
			break;
			default:
				printf("Enter a valid choice");
			}
		}
		return 0;
	}
	
	
