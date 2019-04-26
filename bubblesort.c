#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,t;
	printf("\n Enter the size of the array::");
	scanf("%d",&n);
	int a[n];
	printf("\n Enter the elments of array::");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("\n Sorted array is::");
	for(i=0;i<n;i++)
	{printf("\n %d",a[i]);
}
return 0;		
		
}
