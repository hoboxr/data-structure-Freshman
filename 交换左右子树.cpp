#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//�Ƚ���T�����ӵ������������ٽ���T���Һ��ӵ���������
//��󽻻�T���������� 
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


























