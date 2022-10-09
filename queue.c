#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int n,q[MAX];
int front=-1,rear=-1;
void enqueue(int val)
{
	if(front==-1)
	{
		front=0;
	}
	rear++;
	q[rear]=val;
}
void dequeue()
{
	int val;
	if(front>rear)
	{
		printf("\nQueue is empty");
	}
	else
	{
		val=q[front];
		front++;
		printf("\n Value removed is %d\t",val);
    }
}
void isfront()
{
	if(front>rear)
	{
		printf("\n Queue empty");
		return;
	}
	int val=q[front];
	printf("\nValue is %d\t",val);
}
void display()
{
	int i;
	if(front>rear)
	{
		printf("\n Queue empty");
	}
	else
	{
		printf("\nQueue Elements are:\t");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",q[i]);	
		}
	}
}
int main()
{
	int option,val;
	do
	{
		printf("\n******MAIN MENU******\n1.Insert\n2.Delete\n3.Front\n4.Display\n5.Exit");
		printf("\nEnter your choice");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("\nEnter value to insert");
					scanf("%d",&val);
					enqueue(val);
					break;
			case 2: dequeue();
					break;
			case 3: isfront();
					break;
			case 4: display();
					break;
			case 5: exit(0);
			default: printf("\nInvalid Choice");
		}
	}while(1);
}
