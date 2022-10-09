#include<stdio.h>
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{
	int n,i,j,sum=0;
	printf("\nEnter the number of jobs");
	scanf("%d",&n);
	int job[n],profit[n],deadline[n];
	j=0;
	printf("\nEnter the profit and deadline of the jobs");
	for(i=0;i<n;i++)
	{
		job[i]=++j;
		scanf("%d",&profit[i]);
		scanf("%d",&deadline[i]);	
	}
	printf("\nJob \tProfit \tDeadline \n");
	for(i=0;i<n;i++)
	{
		printf("J%d \t%d \t%d\n",job[i],profit[i],deadline[i]);
	}
	//Arrange jobs in decreasing order of profits along with their corresponding deadline
	int temp1,temp2,temp3;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(profit[i]<profit[j])
			{
				temp1=profit[i];
				profit[i]=profit[j];
				profit[j]=temp1;
				
				temp2=deadline[i];
				deadline[i]=deadline[j];
				deadline[j]=temp2;
				
				temp3=job[i];
				job[i]=job[j];
				job[j]=temp3;
			}
		}
	}
	printf("\nJobs after arrangement are:\n");
	printf("\nJob \tProfit \tDeadline \n");
	for(i=0;i<n;i++)
	{
		printf("J%d \t%d \t%d\n",job[i],profit[i],deadline[i]);
	}
	// Find maximum deadline
	int max_deadline=deadline[0];
	for(i=1;i<n;i++)
	{
		if(max_deadline<deadline[i])
		{
			max_deadline=deadline[i];
		}
	}
	printf("\nMaximum Deadline is: %d\n",max_deadline);
	// Assign a time slot array with 0 
	int slot[max_deadline];
	for(i=1;i<=max_deadline;i++)
	{
		slot[i]=0;
	}
	// Assign slots with job id and calculate the max profit alongside
	for(i=0;i<n;i++)
	{
		j=min(max_deadline,deadline[i]);
		while(j>=1)
		{
			if(slot[j]==0)
			{
				slot[j]=job[i];
				sum = sum + profit[i];
				printf("\t%d",sum);
				break;
			}
			j--;
		}
	}	
	printf("\nMaximum profit is:\t%d",sum);
	printf("\nJob Sequence is:\t");
	for(i=1;i<=max_deadline;i++)
	{
		printf("J%d\t",slot[i]);
	}
	return 0;
}
