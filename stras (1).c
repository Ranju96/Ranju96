#include<stdio.h>
int main()
{
	int arr[2][2],brr[2][2],ans[2][2];
	int i,j,a[7],b[7],m[7];
	printf("\nEnter first array elements");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nEnter second array elements");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&brr[i][j]);
		}
	}
	a[0]= arr[0][0] + arr[1][1];
	a[1]= arr[0][1] - arr[1][1];
	a[2]= arr[0][0] - arr[1][0];
	a[3]= arr[0][0] + arr[0][1];
	a[4]= arr[1][0] + arr[1][1];
	a[5]= arr[0][0];
	a[6] = arr[1][1];
	
	b[0]= brr[0][0] + brr[1][1];
	b[1]= brr[1][0] + brr[1][1];
	b[2]= brr[0][0] + brr[0][1];
	b[3]= brr[1][1];
	b[4]= brr[0][0];
	b[5]= brr[0][1]-brr[1][1];
	b[6] = brr[1][0]-brr[0][0];
	
	for(i=0;i<7;i++)
	{
		m[i] = a[i]*b[i];
	}
	
	ans[0][0]= m[0]+m[1]-m[3]+m[6];
	ans[0][1]= m[3]+m[5];
	ans[1][0]= m[4]+m[6];
	ans[1][1]= m[0]-m[2]-m[4]+m[5];
	
	printf("\nResulting array is:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",ans[i][j]);
		}
		printf("\n");
	}
	
}
