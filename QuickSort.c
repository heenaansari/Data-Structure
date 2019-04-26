#include<stdio.h>
#include<stdlib.h>
int counter=1;

int partition(int a[],int low,int high)
{

int i,j,k,pivot;
pivot=a[low];
i=low;
j=high;
while (i<j)
{
while(a[i]<=pivot && i<high)
i++;
while(a[j]>pivot && j>low)
j--;

if(i<j)
{
k=a[i];
a[i]=a[j];
a[j]=k;
}
}
a[low]=a[j];
a[j]=pivot;
counter++;
return j;
}

void quicksort (int a[],int low,int high)
{
   
int p,i;


if(low<high)
{
 printf("\n\nITERATION = %d\n\nLow=%d and High=%d",counter,low,high);
 for(i=low;i<=high;i++)
 printf("\t%d",a[i]);
 p=partition(a,low,high);
 quicksort(a,low,p-1);
 quicksort(a,p+1,high);
}
}

int main()
{

int a[20],n,i;

while (1)
{
printf("\nENTER TOTAL NUMBER OF ELEMENTS ::");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nENTER THE ELEMENT ::");
scanf("%d",&a[i]);
}
quicksort(a,0,n-1);
printf("\n\n\t SORTED LIST IS...\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
counter=1;
}
return 0;
}

