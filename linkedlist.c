#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insertAtBegin(int val)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof *newnode);
	if(newnode==NULL)
	{
		printf("\nOverflow");	
	}
	else
	{
		newnode->data=val;
		newnode->next=head;
		head=newnode;
	}
}
void insertatend(int val)
{
	struct node *newnode,*temp;
	newnode = (struct node *) malloc(sizeof *newnode);
	temp = (struct node *) malloc(sizeof *temp);
	newnode->data=val;
	if(head==NULL)
	{
		head=newnode;
		head->next=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
	}
}
void insertatposition(int val)
{
	int pos,i;
	struct node *newnode,*temp;
	newnode = (struct node *) malloc(sizeof *newnode);
	temp = (struct node *) malloc(sizeof *temp);
	newnode->data=val;
	newnode->next=NULL;
	printf("\nEnter position where you want to insert");
	scanf("\n%d",&pos);
	if(pos<0)
	{
		printf("\nInvalid position");
	}
	else if(head==NULL)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		temp=head;
		for(i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}	
}
void delete_begin()
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof *temp);
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		printf("\nDeleted Value is %d",head->data);
		temp=head->next;
		head=temp;
		//free(temp);
	}
}
void delete_end()
{
	struct node *temp,*ptr;
	temp = (struct node *) malloc(sizeof *temp);
	ptr = (struct node *) malloc(sizeof *ptr);
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else if(head->next==NULL)
	{
		printf("\nDeleted Value is %d",head->data);
		head=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		printf("\nDeleted Value is %d",temp->data);
		free(temp);
	}	
}
void delete_position()				
{
	int pos,i;
	struct node *ptr,*temp;
	ptr = (struct node *) malloc(sizeof *ptr);
	temp = (struct node *) malloc(sizeof *temp);
	printf("\nEnter position from where you want to delete");
	scanf("\n%d",&pos);
	pos-=1;
	if(head==NULL)
	{
		printf("\nList empty");
	}	
	else
	{
		for(i=0;i<pos-1;i++)
		{
			ptr=temp;
			temp=temp->next;
		}
	}
	ptr->next=temp->next;
	printf("\nDeleted Value is %d",ptr->data);
	free(ptr);	
}
void display()
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof *temp);	
	if(head==NULL)
	{
		printf("\nList is empty");	
	}	
	else
	{
		temp=head;
		printf("\nThe list is:\t");
		while(temp!=NULL)
		{
			if (temp->next == NULL) 
			{
            	printf(" %d->NULL", temp->data);
        	}
        	else 
			{
            	printf(" %d->", temp->data);
        	}
        	temp = temp->next; 
		}
	}
}
void search()
{
	struct node *temp;
	int val,i=0;
	printf("\nEnter the value to be searched");
	scanf("%d",&val);
	temp=head;
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data==val)
			{
				printf("\nPresent location is %d",i+1);
			}
			i++;
			temp=temp->next;
		}
	}
}
int main()
{
	int option,choice,val;
	do
	{
		printf("\n***MAIN MENU***\n1.Insert\n2.Delete\n3.Dispaly\n4.Search\n5.Exit");	
    	printf("\nEnter Your Option");
    	scanf("\n%d",&option);
    	switch(option)
    	{
    		case 1: printf("\n Enter the value you want to insert");
    				scanf("%d",&val);
					printf("\n1.Insert at Begining\n2.Insert at end\n3.Insert at position");
    				printf("\nEnter Your Choice");
    				scanf("\n%d",&choice);
    				switch(choice)
    				{
    					case 1: insertAtBegin(val);
    							break;
    					case 2: insertatend(val);
    							break;
    					case 3: insertatposition(val);
    							break;
    					default: printf("\nWrong Choice");
					}
					break;
			case 2: printf("\n1.Delete from Begining\n2.Delete from end\n3.Delete from position");
    				printf("\nEnter Your Choice");
    				scanf("\n%d",&choice);
    				switch(choice)
    				{
    					case 1: delete_begin();
    							break;
    					case 2: delete_end();
    							break;
    					case 3: delete_position();
    							break;
    					default: printf("\nWrong Choice");
					}
					break;
			case 3: display();
					break;
			case 4: search();
					break;
			case 5: exit(0);
			default: printf("\nWrong Choice");
		}
	}while(1);
	return 0;
}


