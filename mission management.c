#include <stdio.h>
int main()
{
	long long int n,x,i,j,cost,m,k;
	scanf("%lld %lld" , &n , &x);
	long long int start[n+1],end[n+1];
	for(i=1;i<=n;i++)
		scanf("%lld %lld",&start[i],&end[i]);
	cost=0;
	
	for(i=1;i<=n-1;i++)
	{
		if(x>=start[i] && x<=end[i])
		{
			printf("%lld %lld %lld\n" , i , x , cost);
			continue;
		}
		else if(x>end[i] && x>end[i+1])
		{
			if(end[i]>=end[i+1])
			{
				cost+=x-end[i];
				x=end[i];
			}
			else
			{
				cost+=x-end[i+1];
				x=end[i+1];
				i-=1;
				continue;
			}
		}
		else if(x<start[i] && x<start[i+1])
		{
			if(start[i]<=start[i+1])
			{
				cost+=start[i]-x;
				x=start[i];
			}
			else
			{
				cost+=start[i+1]-x;
				x=start[i+1];
				i-=1;
				continue;
			}
		}
		
		
		else if(x>end[i] && x<=end[i+1] && x<start[i+1])
			cost+=x-end[i];
		else if (x<start[i] && x>end[i+1])
			cost+=start[i]-x;
		
		
		else if(x>end[i] && x<=end[i+1] && x>=start[i+1])
		{
			if(end[i]>start[i+1])
				m=end[i];
			else
				m=start[i+1];
			j=i+2;
			if(j>n)
				j=n;
			while(x>=start[j] && x<=end[j] && j<n)
			{
				if(start[j]>=m)
					m=start[j];
				j=j+1;
			}
			if(x>=start[j])
			{
				if(start[j]>=m)
					m=start[j];
				cost+=x-m;
				x=m;
				if(x>end[i])
					cost+=x-end[i];
			}
			else if(x<start[j])
				cost+=x-end[i];	
		}
		
		else if(x<start[i] && x<=end[i+1] && x>=start[i+1])
		{
			if(start[i]<end[i+1])
				m=start[i];
			else
				m=end[i+1];
			j=i+2;
			if(j>n)
				j=n;
			while(x>=start[j] && x<=end[j] && j<n)
			{
				if(end[j]<m)
					m=end[j];
				j=j+1;
			}
			if(x<end[j])
			{
				if(end[j]<m)
					m=end[j];
				cost+=m-x;
				x=m;
				if(start[i]>x)
					cost+=start[i]-x;
			}
			else if(x>=end[j])
				cost+=start[i]-x;
		}
		printf("%lld %lld %lld\n" , i , x , cost);
	}
	
	if(x>end[n])
		cost+=x-end[n];
	else if(x<start[n])
		cost+=start[n]-x;
	printf("%lld" , cost);
}
