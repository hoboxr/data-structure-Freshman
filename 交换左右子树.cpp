#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//先交换T的左孩子的左右子树，再交换T的右孩子的左右子树
//最后交换T的左右子树 
void swap(BiTree T)
{
	if(T)
	{
		swap(T->lchild);
		swap(T->rchild);
		BiTree r;
		r=T->lchild;
		T->lchild=T->rchild;
		T->rchild=r;
	}
}


























