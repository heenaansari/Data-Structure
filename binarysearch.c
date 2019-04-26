//Program for binary search
//Learner :Ansari Heena
#include<stdio.h>
#include<stdlib.h>
int ser;
int binarySer(int a[],int n,int k) 	//function for binary search
{
	int low,upper,mid;
	low=0;
	upper=n-1;
	for(mid=(low+upper)/2,ser=1;low<=upper;mid=(low+upper)/2,ser++)		//condition for finding mid element
	{
		if(k==a[mid])	//to check whether the mid element is equal to key element
		return mid;
		if(k>a[mid])	//to compare whether the key element is greater or not
		low=mid+1;		//if greater increment low by 1
		else
		upper=mid-1;	//if smaller decrement upper by 1
	}
	return -1;
}	
	
int main()		//main function
{	int a[20],n,i,ch,k;
	
	while(1)		//infinite loop 
	{
		printf("\n\t\t<------*************MENU****************-------------->");
		printf("\n1. Binary Search\n2. Exit\n\tEnter your Choice :: ");
		scanf("%d",&ch);
		switch (ch)	//using switch case
		{
			case 1:
		
	     printf("\nEnter Total no. of elements ::");
	     scanf("%d",&n);
	     for(i=0;i<n;i++)
	     {
		 printf("\nEnter elements ::");
		 scanf("%d",&a[i]);
           	}
			printf("\n\tEnter key elements to search ::");
			scanf("%d",&k);
			i=binarySer(a,n,k);		
			if(i==-1)
			printf("\nKey Element does not exist.");
			else
			printf("\nKey Element exist at location %d",i);
			printf("\nTotal No. of searches/comparisons done: %d",ser);
			break;
			case 3: 
			exit(0);	
			break;
            default:
            printf("Enter a valid choice");
		}
	}
	return 0;
}
