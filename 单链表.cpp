#include<stdio.h>
#include<stdlib.h>
typedef  int ElemType;
typedef struct Node{
	 ElemType data;
	 struct Node *next;
}Node ,*linklist;

void creatlist(linklist &L)
{
	linklist p;
	int i;
	L =(linklist)malloc(sizeof(Node));
	L->next=NULL;
	//��ʼһ��1��10�ĵ�����
	for(i=1;i<=10;i++)
	{
		p = (linklist)malloc(sizeof(Node));//����һ���½��
		p->data =i;//����ֵ
		p->next =L->next;
		L->next =p;//�嵽��ͷ
	}
}

//ȡ��i��Ԫ��
int Getelem (linklist L,int i,  ElemType &e)
{
	int j;
	linklist p;
	p=L->next;
	j=1;
	while(p!=NULL &&j<i)
	{
		p=p->next;
		++j;
	}
	if(p==NULL||j>i)
		return 0;
	e=p->data;
	return 1;
}

//�ڵ�i��������Ԫ��
int listinsert(linklist &L,int i,ElemType e)
{
	int j;
	linklist p,s;
	p=L ;
	j=1;
	while(p!=NULL &&j<i)
	{
		p=p->next;
		++j;
	}
	if(p==NULL||j>i)
		return 0;
	s = (linklist)malloc(sizeof(Node));
	s->data =e;
	s->next =p->next;
	p->next =s;
	return 1;
}

//ɾ����i��λ�õ�Ԫ��,����e����
int listdelete(linklist &L,int i,ElemType &e)
{

	int j;
	linklist p,s;
	p=L ;
	j=1;
	while(p!=NULL &&j<i)
	{
		p=p->next;
		++j;
	}
	if(p==NULL||j>i)
		return 0;
	s=p->next;
	p->next=s->next;
	e=s->data;
	free(s);
	return 1;
}

//��ӡ���������Ԫ��
void print(linklist L)
{
	linklist p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}



int main()
{
	//��ʼ��
	int i;
	ElemType e;
	linklist L;
	creatlist(L);
	printf("��ʼ����Ϊ:");
	print(L);

	//ȡ��6����
	i=6;
	Getelem (L,i,e);
	printf("��%d��Ԫ��Ϊ: %d",i,e);
	printf("\n");

	//�ڵ�4λ����34
	i=4;
	e=34;
	listinsert( L, i, e);
	printf("�����%dλ������Ԫ��Ϊ%d������������Ϊ��",i,e);
	print(L);

	//ɾ����7λ
	i=7;
	listdelete( L, i, e);
	printf("ɾ����%dλ��ɾ����Ԫ��Ϊ%d��ɾ���������Ϊ��",i,e);
	print(L);
	return 0;
}

