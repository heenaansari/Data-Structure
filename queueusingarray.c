#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 5
struct queue		//Declaring a linear queue
{
    int data[MAX];
    int front,rear;
};
void intialize(struct queue *q)	//Function for intializing the linear queue
{q->front=q->rear=-1;
}
int isFull(struct queue *q)		//Function to check  whether the queue is full or not
{
    return((q->rear==MAX-1)?1:0);
}
int isEmpty(struct queue *q)   //Function to check  whether the queue is Empty or not

{
    return((q->rear==-1)?1:0);
}
int insert(struct queue *q,int d)  //Function to insert element in linear queue
{
    if(isFull(q))  //if Queue is full return 0.
    return 0;
    else
    {q->rear++;
        q->data[q->rear]=d;
    if(q->front==-1)
    q->front=0;
    return 1;
    }
}
void display(struct queue *q)		//Function to display element of queue.
{
    int i;
    if (isEmpty(q))
    printf("\n Queue is Empty.");
    else
    {printf("Queue size %d\nFront= %d\nRear= %d",MAX,q->front,q->rear);
        printf("\n Queue elements are =\n");
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d\n",q->data[i]);
        }
    }
}
int delete(struct queue *q)			//Function to delete element in linear queue
{int d;
d=q->data[q->front];
if(q->front==q->rear)
q->front=q->rear=-1;
else
q->front++;
return d;
}
int search(struct queue *q,int k)		//Function to searh element in linear queue
{
	int i;
	for(i=q->front;i!=q->rear;i++)
	{if(q->data[i]==k)		//If data is found return the value of index.
	return i;
    }
if(q->data[i]==k)   //Checks whether data is present at rear end
return i;
else
return -1;		//If data not present return -1
}
int main()
{int ch,r,d;
struct queue q;
intialize(&q);
while(1)
{
    printf("\n\t\t<-----***MENU***----->");
    printf("\n(1)INSERT.\n(2)DELETE.\n(3)SEARCH\n(4)DISPLAY.\n(5)EXIT.\n");
    printf("\n Enter your choice::");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    printf("\nEnter data to be inserted=");
    scanf("%d",&d);
    if(insert(&q,d))
    printf("Insertion done successfully");
    else
    printf("\nQueue is Full");
    break;
    case 2:
    if(isEmpty(&q)==1)
     printf("\nQueue is Empty.");
    else
    {r=delete(&q);
    printf("\n Deleted element is =%d",r);
    }
    break;
    case 3:
    printf("\nEnter data to be searched=");
    scanf("%d",&d);
    r=search(&q,d);
    if(r!=-1)
    printf("%d found on location %d",d,r+1);
    else
    printf("\n %d not found",d);
    break;
    case 4:
    display(&q);
    break;
    
    case 5:
    printf("\n\t\t<-----****THANK YOU****----->");
    exit(0);
    break;
    default:
    printf("Enter a valid choice");
}
    
}
return 0;
}









