#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int arr[MAX];
int n=0;
void insert()
{
	int i,pos,value;
    printf("\n Enter element and the position where you want to insert");
	scanf("%d %d",&value,&pos);
	pos=pos-1;
	if(n==MAX || pos<0 || pos>n)
	{
		printf("\nList is full");
	}
    for(i=n;i>=pos;i--)
	{
        arr[i]=arr[i-1];
    }
	arr[pos]=value;
    n=n+1;
}

void del()
{
	int i,pos;
	printf("\n Enter the position from where you want to delete the element");
    scanf("%d",&pos);
    if(pos>n)
        printf("\nDeletion not possible");
    else{
    	for(i=pos-1;i<n;i++)
		{
            arr[i]=arr[i+1];
        }
	}
	n-=1;
}

void search()
{
	int flag=0,i,value;
	printf("\nEnter element to be searched");
    scanf("%d",&value);
    for(i=0;i<n;i++)
	{
    	if(arr[i]==value)
		{
            printf("\nElement found at %d",i+1);
            flag=1;
        }
    }
    if(flag==0)
	{
    	printf("\nElement not found");
	}
}
void display()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\t%d",arr[i]);
	}
	if(n==0)
	{
    	printf("\nList is empty");
	}
}
int main()
{
    int i,option;
    printf("\nEnter max number of elements in array");
    scanf("\t%d",&n);
    printf("\nEnter array elements");
    for(i=0;i<n;i++)
	{
        scanf("\n%d",&arr[i]);
    }
    do
	{
    	printf("\n*****MAIN MENU*****\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit");
    	printf("\nEnter your choice");
    	scanf("%d",&option);
    	switch(option)
		{
    		case 1: insert();
    			break;
    		case 2: del();
    			break;
    		case 3: search();
    			break;
    		case 4: display();
    				break;
    		case 5:exit(0);
    		default: printf("\nInvalid choice");
		}
	}while(1);
	return 0;
}
