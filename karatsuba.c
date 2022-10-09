#include<stdio.h>
#include<math.h>
int len(int x)                        // count the number of digits in the number
{
	int count=0;
	while(x!=0)
	{
		x/=10;
		count++;
	}
	return count;
}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2; // if num1 > num2 then return num1 else num2
}
int power(int p,int r)
{
	int res=1;
	while(r!=0)
	{
		res *=p;
		r--;
	}
	return res;
}
int Karatsuba(int x,int y)
{
	int n,a,b,c,d,hf;
	int ac,bd,ad_plus_bc;
	if(x<10 && y<10)
	{
		return x*y;
	}
	else
	{
		n=max(len(x),len(y));       
		hf=n/2;
		a = x/(power(10,hf));
		b = x%(power(10,hf));
		c = y/(power(10,hf));
		d = y%(power(10,hf));
		ac = Karatsuba(a,c);
		bd = Karatsuba(b,d);
		ad_plus_bc = Karatsuba((a+b),(c+d)) -ac-bd;
		return ac*(power(10,(2*hf))) + ad_plus_bc *(pow(10,hf)) + bd;
	}
}
int main()
{
	int x,y,ans;
	printf("\n Enter two numbers you want to multiply");
	scanf("%d\t%d",&x,&y);
	ans = Karatsuba(x,y);
	printf("\nResult:\t %d",ans);
	return 0;
}
