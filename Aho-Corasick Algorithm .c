#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,j,k,l,s,minlen,sumi,sumj,maxcom=0,start,end,next;
	scanf("%d",&n);
	int c[n],c1[n],arr[n][100],CompatbilityMatrix[n][n];
	float Priority[n][n],maxpriority=0,iterate=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		c1[i]=c[i];
	}
	char str[n][20];
	for(i=0;i<n;i++)
	{
   		scanf("%s",str[i]);
   	}
   	for(i=0;i<n;i++)
   	{
   		for(j=0;j<strlen(str[i]);j++)
   		{
   			arr[i][j]=str[i][j]-97;
   		}
   	}
   	
   	for(i=0;i<n;i++)
   	{
   		for(j=0;j<n;j++)
   		{	
   			CompatbilityMatrix[i][j]=0;
   			sumi=0;
   			sumj=0;
   			if(strlen(str[i])<strlen(str[j]))
   				minlen=strlen(str[i]);
   			else
   				minlen=strlen(str[j]);
   			for(k=0;k<minlen;k++)
   			{
   				sumi+=arr[i][strlen(str[i])-k-1];
   				sumj+=arr[j][k];
   				if(sumi==sumj)
   				{
	   				for(l=0;l<=k;l++)
		   			{
		   				if(arr[i][strlen(str[i])-k+l-1]==arr[j][l] && l==k && (i!=j || k+1!=strlen(str[i])))
		   				{
		   					CompatbilityMatrix[i][j]=k+1;
		   				}
		   			}
		   		}
	   		}
	   		Priority[i][j]=(float)(c[j])/(strlen(str[j])-CompatbilityMatrix[i][j]);
   			if(Priority[i][j]>maxpriority)
   			{
   				maxpriority=Priority[i][j];
   				start=j;
   				end=i;
   			}
   			if(i==j && Priority[i][j]>iterate)
   				iterate=Priority[i][j];
   		}
   	}
   	/*
   	for(i=0;i<n;i++)
   	{
   		for(j=0;j<n;j++)
   		{
   			Priority[i][j]=(float)(c[j])/(strlen(str[j])-CompatbilityMatrix[i][j]);
   			if(Priority[i][j]>maxpriority)
   			{
   				maxpriority=Priority[i][j];
   				start=j;
   				end=i;
   			}
   		}
   	}*/
   	//printf("%d %d\n" , start,end);
   	int visited[n];
   	int length;
   	int score;
   	for(i=0;i<n;i++)
   	{
   		visited[i]=0;
   	}
   	visited[start]=1;
   	length=strlen(str[start]);
   	score=c[start];
   	int current=start;

   	while(visited[end]==0)
   	{
   		maxpriority=0;
   		for(i=0;i<n;i++)
   		{
   			if(visited[i]==0)
   			{
   				if(Priority[current][i]>maxpriority)
   				{
   					maxpriority=Priority[current][i];
   					next=i;
   				}
   			}
   		}
   		//printf("%f %d\n",maxpriority,next);
   		visited[next]=1;
   		length=length+strlen(str[next])-CompatbilityMatrix[current][next];
   		score=score+c[next];
   		current=next;
   	}
   	/*for(i=0;i<n;i++)
   	{
   		printf("%d ",visited[i]);
   	}
   	printf("\n");
   	
   	
   	for(i=0;i<n;i++)
   	{
   		for(j=0;j<n;j++)
   		{
   			printf("%f ",Priority[i][j]);
   		}
   		printf("\n");
   	}
   	for(i=0;i<n;i++)
   	{
   		for(j=0;j<n;j++)
   		{
   			printf("%d ",CompatbilityMatrix[i][j]);
   		}
   		printf("\n");
   	}*/
	if((float)score/(length-CompatbilityMatrix[end][start])>iterate)
		iterate=(float)score/(length-CompatbilityMatrix[end][start]);
   	printf("%f",iterate);
}
