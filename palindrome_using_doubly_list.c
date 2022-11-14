#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
void insert(char val)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof *newnode);
	newnode->data=val;
	newnode->prev=NULL;
	newnode->next=head;
	if(head!=NULL)
	{
		head->prev=newnode;
	}
	head=newnode;
}
bool check_Palindrome()
{
	if(head==NULL)
	{
		return true;
	}
	struct node *left,*right;
	left = (struct node *) malloc(sizeof *left);
	right = (struct node *) malloc(sizeof *right);
	left=head;
	right=head;
	while(right->next!=NULL)
	{
		right=right->next;	
	}
	while(left!=right)
	{
		if(left->data!=right->data)
		{
			return false;
		}
		left=left->next;
		right=right->prev;
	}
	return true;
}
int main()
{
	int i,n;
	printf("\nEnter the list length");
	scanf("%d",&n);
	char str[n];
	printf("\nEnter list:\t");
	scanf("%s",str);
	for (i = 0; str[i] != '\0'; i++) {
		insert(str[i]);
	}
	check_Palindrome() ? printf("\nIs Palindrome"): printf("\nNot Palindrome");
	return 0;
}

