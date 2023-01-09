#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	long int i,j,n;
	double num,sum,finsum=0;
	srand(time(0));
	n=5000000;
	for(i=0;i<n;i++)
	{
		sum=0;
		j=0;
		while(sum<1)
		{
			num=(rand()/(double)(RAND_MAX));
			sum+=num;
			j++;
		}
		finsum+=j;
	}
	printf("%lf",finsum/(double)n);
}

