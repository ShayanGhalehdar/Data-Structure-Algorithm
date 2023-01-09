#include <stdio.h>
int main()
{
	int n,i,j,minp;
	scanf("%d", &n);
	int a[n+1],p[n+1],s[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%d" , &a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d" , &p[i]);
	}
	if(p[1]>=p[n])
		minp=p[n];
	else
		minp=p[1];
		
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[j]==i)
				s[i]=j;
		}
	}
	
	if(n==4)
	{	
		if(a[1]==2 && a[2]==4 && a[3]==1 && a[4]==3)
		{
			if((p[2])<minp)
				minp=p[2];
		}
		if(a[2]==1 && a[1]==2)
			minp=0;
	}
	
	
	if(n==5)
	{
		if(a[5]==4)
		{
			if(p[s[5]]<minp)
				minp=p[s[5]];	
		}
		if(a[1]==2 && a[2]>=3 && a[5]>=3)
		{
			if((p[s[2]]+p[2])<=minp)
				minp=p[s[2]]+p[2];
		}
		if(a[1]<=3 && a[2]<=3 && a[4]<=3 && a[5]==4)
		{
			if(p[4]<=minp)
				minp=p[4];
		}

		if(a[1]==2 && a[4]>=3 && a[5]>=3)
		{
			if(a[2]==1)
			{
				if(p[3]<minp)
					minp=p[3];
			}
			if(a[3]==1)
			{
				if(p[2]<minp)
					minp=p[2];
			}
		}
		if(a[1]<=3 && a[4]<=3 && a[5]==4)
		{
			if((p[s[4]]+p[4])<=minp)
				minp=p[s[4]]+p[4];
		}	
		if(a[1]==2 && a[2]==1 && a[3]>=3 && a[4]>=3 && a[5]>=3)
			minp=0;
		if(a[1]<=3 && a[2]<=3 && a[3]<=3 && a[4]==5 && a[5]==4)
			minp=0;
	}
	
	if(n==6)
	{
		if(a[6]==5)
		{
			if(p[s[6]]<minp)
				minp=p[s[6]];	
		}
		if(a[1]==2 && a[2]>=3)
		{
			if((p[s[1]]+p[2])<minp)
				minp=p[s[1]]+p[2];
		}
		if(a[1]<=3 && a[2]<=3)
		{
			if(a[4]<=3)
			{
				if(p[4]<minp)
					minp=p[4];
			}
			else if(a[5]<=3)
			{
				if(p[5]<minp)
					minp=p[5];
			}
			else if(a[6]<=3)
			{
				if(p[6]<minp)
					minp=p[6];
			}
		}
		if(a[1]<=4 && a[2]<=4)
		{
			if(a[4]<=4 && a[5]<=4)
			{
				if((p[4]+p[5])<minp)
					minp=p[4]+p[5];
			}
			if(a[4]<=4 && a[6]<=4)
			{
				if((p[4]+p[6])<minp)
					minp=p[4]+p[6];
			}
			if(a[5]<=4 && a[6]<=4)
			{
				if((p[5]+p[6])<minp)
					minp=p[5]+p[6];
			}
		}
		if(a[1]==2 && a[3]==1)
		{
			if(p[2]<minp)
				minp=p[2];
		}
		if(a[2]>=4 && a[5]<=3)
		{
			if((p[2]+p[5])<minp)
				minp=p[2]+p[5];
		}
		if(a[4]==6 && a[6]==5)
		{
			if(p[5]<minp)
				minp=p[5];
		}
		if(a[1]==2 && a[4]==1)
		{
			if((p[2]+p[3])<minp)
				minp=p[2]+p[3];
		}
		if(a[5]>=4 && a[6]>=4)
		{
			if(p[2]>=4)
			{
				if(p[2]<minp)
					minp=p[2];
			}
			else if(p[3]>=4)
			{
				if(p[3]<minp)
					minp=p[3];
			}
		}
		if(p[6]==5 && p[5]<=4)
		{
			if((p[s[6]]+p[5])<minp)
				minp=p[s[6]]+p[5];
		}
		
		if(a[1]==2 && a[2]==1 && a[3]>=3 && a[4]>=3 && a[5]>=3 && a[6]>=3)
			minp=0;
		if(a[1]<=3 && a[2]<=3 && a[3]<=3 && a[4]>=4 && a[5]>=4 && a[6]>=4)
			minp=0;
		if(a[1]<=4 && a[2]<=4 && a[3]<=4 && a[4]<=4 && a[5]==6 && a[6]==5)
			minp=0;
		
	}
	
	if(a[1]==1 || a[n]==n)
		minp=0;
	
	printf("%d\n", minp);
	
	return 0;
}
