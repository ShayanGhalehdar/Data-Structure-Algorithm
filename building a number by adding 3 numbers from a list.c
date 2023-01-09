#include <stdio.h>
int main()
{
	int n,i,j,m,f,temp;
	scanf("%d" , &m);
	int list[m];
	for(i=0;i<m;i++)
	{
		scanf("%d" , &list[i]);
	}
	scanf("%d", &n);
	int Q[n];
	for(i=0;i<n;i++)
	{
		scanf("%d" , &Q[i]);
	}
	for(i=0;i<m; i++)
	{     
        for(j=i+1;j<m;j++)
		{     
           if(list[i] > list[j])
		   {    
               temp = list[i];    
               list[i] = list[j];    
               list[j] = temp;    
           }     
        }     
    }    
	for(i=0;i<n;i++)
	{
		f=find(list,Q[i],m);
		if(f==1)
			printf("Yes\n");
		else
			printf("No\n");
	}

}

int find(int list[],int Q,int m)
{
	int i,p,q;
	for (i=0;i<m-1;i++)
    {
    	p=i+1;
    	q=m-1;
    	while(p<q)
    	{
    		if(list[i]+list[p]+list[q]==Q)
    		{
    			return 1;
    			break;
    		}
    		else if(Q<list[i]+list[p]+list[q])
    			q--;
    		else if(Q>list[i]+list[p]+list[q])
    			p++;
    	}
    }
    return 0;
}
	
