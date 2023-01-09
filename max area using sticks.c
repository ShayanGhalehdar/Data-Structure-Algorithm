#include <stdio.h>
int main()
{
	int i,j,k,n,sort;
	scanf("%d" , &n);
	
	int arr[n+1][5];
	for (i=1;i<=n;i++)
	{
		scanf("%d %d %d %d" , &arr[i][1] , &arr[i][2] ,&arr[i][3] ,&arr[i][4] );
		
		for (j=2;j<=4;j++)
		{
			k=j;
			while (k>=2)
			{
				if(arr[i][k]<arr[i][k-1])
				{
					arr[i][k]+=arr[i][k-1];
					arr[i][k-1]=arr[i][k]-arr[i][k-1];
					arr[i][k]=arr[i][k]-arr[i][k-1];
					if(k==2)
					{
						break;
					}
					if(arr[i][k-1]>=arr[i][k-2])
					{
						break;
					}
					k-=1;
				}
				else
				{
					break;
				}
			}
			continue;
		}			
	}
	for (i=1;i<=n;i++)
	{
		printf("%d\n" , arr[i][1]*arr[i][3]);
	}
	
	/*for (i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n" , arr[i][1] , arr[i][2] ,arr[i][3] ,arr[i][4] );
	}*/
	return 0;
}
