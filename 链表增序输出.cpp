#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next; 
}node,*linklist;

int creatlinklist(linklist &L)
{
	L=(linklist)malloc(sizeof(node));
	L->next=NULL;
	return 1;
} 

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

int listdelete(linklist &L,int i,int &e)
{
	linklist p;
	p=L;
	int j=1;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(p==NULL||j>i)
	return 0;
	linklist s;
	s=p->next;
	e=s->data;
	p->next=s->next;//�Ե�i���ڵ��ǰһ���ڵ����next�ı���� 
	free(s); 
	return 1;
}

int listinsert(linklist &L,int i,int e)
{
	linklist p=L;
	int j=1;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++; 
	}
	if(p==NULL||j>i)
	return 0;
	linklist s;
	s=(linklist)malloc(sizeof(node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
void dz(linklist &L)
{
    while(L->next != NULL) {
        linklist min = L->next;  // ��ǰ����ĵ�һ���ڵ�
        linklist pre_min = L;    // ��һ���ڵ��ǰһ���ڵ�
        linklist p = min->next;  // ��ǰ����ĵڶ����ڵ�
        linklist pre_p = min;    // �ڶ����ڵ��ǰһ���ڵ�
        
        while (p != NULL) {
            if (p->data < min->data) {
                min = p;
                pre_min = pre_p;
            }
            pre_p = p;
            p = p->next;
        }
        
        printf("%d ", min->data);
        pre_min->next = min->next; // ���������Ƴ���С�ڵ�
        free(min);
    } 
    free(L);
}
 int main()
{
	int e;
	linklist L;
	creatlinklist(L);
	listinsert(L,1,1);
	listinsert(L,2,2);
	listinsert(L,3,3);
	listinsert(L,4,4);
	listinsert(L,5,8);
	listinsert(L,6,7);
	listinsert(L,7,6);
	listinsert(L,8,5);
	print(L);
 	dz(L); 
	return 0;
}











