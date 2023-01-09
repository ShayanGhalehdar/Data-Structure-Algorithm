#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <math.h>
int main()
{
	long int i,n,circle=0;
	double x,y;
	n=50000000;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		x=(rand()/(double)(RAND_MAX+1));
		y=(rand()/(double)(RAND_MAX+1));
		if(pow(x,2)+pow(y,2)<1)
			circle++;
	}
	printf("%lf",4*(circle/(float)n));
}

