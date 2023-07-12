#include<stdio.h>

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
int depth(BiTree T)
{
	int left,right;
	if(T==NULL)
	return 0;
 	else
 	{
 		left=depth(T->lchild);
 		right=depth(T->rchild);
 		return left>right ? (left+1) : (right+1);
	}
 
}

int n=0;
int YZ(BiTree T)
{
 	if(T)
	{
	 	if(T->lchild==NULL&&T->rchild==NULL)
		n++;
		else
		YZ(T->lchild);
		YZ(T->rchild);
	}	
} 










