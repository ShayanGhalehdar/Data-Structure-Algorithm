#include <stdio.h>
#include <stdlib.h>

long long int Grapes;
struct Gereh
{
    long long int data;
    struct Gereh *Right_Baby;
    struct Gereh *Left_Baby; 
};

struct Gereh* New_Gereh(long long int x)
{
    struct Gereh *myGereh;
    myGereh = malloc(sizeof(struct Gereh));
    myGereh->data = x;
    myGereh->Left_Baby = NULL;
    myGereh->Right_Baby = NULL;
    return myGereh;
}

long long int search(struct Gereh* Tree, int x)
{
	if(Tree == NULL)
        return 0;
    if(Tree->data == x)
        return 1;
    if (Tree->data < x)
        return search(Tree->Right_Baby, x);
 	else
    	return search(Tree->Left_Baby, x);
}

struct Gereh* insert(struct Gereh *Tree, long long int x)
{
    if(Tree==NULL)
        return New_Gereh(x);
    else if(x>Tree->data)
        Tree->Right_Baby = insert(Tree->Right_Baby, x);
    else
        Tree->Left_Baby = insert(Tree->Left_Baby,x);
    return Tree;
}

void MostLeftGrapes(struct Gereh* Tree, long long int level, long long int* max_level) 
{ 
  if (Tree == NULL) 
    return; 
  
  if (*max_level < level) 
  { 
    *max_level = level;
    Grapes+=Tree->data;
  } 

  MostLeftGrapes(Tree->Left_Baby, level + 1, max_level); 
  MostLeftGrapes(Tree->Right_Baby, level + 1, max_level); 
} 

int main()
{
	long long int i,n,q;
	scanf("%lld %lld",&n, &q);
	long long int BST[n+1];
	long long int Leaf[q+1];
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&BST[i]);
	}
	for(i=1;i<=q;i++)
	{
		scanf("%lld",&Leaf[i]);
	}
	
	struct Gereh *Tree;
	if(n!=0)
		Tree = New_Gereh(BST[1]);
	for(i=2;i<=n;i++)
	{
		if(search(Tree,BST[i])==0)
			Tree = insert(Tree,BST[i]);
	}
	
	long long int max_level = 0; 
	Grapes=0;
	if(n!=0)
	{
		MostLeftGrapes(Tree, 1, &max_level);
		printf("%lld",Grapes); 
	}
	else if(n==0)
		printf("0");
	for(i=1;i<=q;i++)
	{
		if(search(Tree,Leaf[i])==0)
			Tree = insert(Tree,Leaf[i]);
			
			Grapes=0;
			max_level = 0;
			MostLeftGrapes(Tree, 1, &max_level);
			printf("\n%lld",Grapes); 
	}
}		
