#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE  100 
//1����ɹ����У�0��-1����ʧ�� 
typedef int ElemType; //ElemType ������������������Ϊint 
typedef struct{
	int *elem;//���飬�洢Ԫ�� 
	int length;//�� 
	int listsize;//���������� 
}SqList;
 
void InitList(SqList &L)
//����һ���յ����Ա�L
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));//��̬����ռ�
	L.length=0;//��ʼ���������ݣ���Ϊ0 
	L.listsize=LIST_INIT_SIZE;
}

void Destroy(SqList &L)
//�������Ա�L
{
	free(L.elem);
	L.elem=NULL; 
}
void ClearList(SqList &L)
//������Ա�
{
	L.length=0;
}

int GetElem(SqList L,int i,int &e)
//��e����L�е�i��Ԫ��
{
	if(i<1||i>L.length)
		return 0;
	if(!L.elem)
		return -1;
//�ж�i�Ƿ�Ϸ� 		
	e=L.elem[i-1];
	return 1;
}

int listdelete(SqList &L,int i,int &e)
//ɾ����i��Ԫ�أ�����e����
{
	int j;
	if(i<1||i>L.length)
		return 0;
	if(!L.elem)
		return -1;
	//�ж�i�Ƿ�Ϸ� 
	e=L.elem[i-1];	
	for(j=i-1;j<L.length-1;j++)     //�ӵ�i��Ԫ�ص������ڸ�Ԫ�� 
	L.elem[j]=L.elem[j+1];          //���λ�����һ��λ�õ�Ԫ��ֵ 
	L.length--;//����֮���� 
	return 1;
}

int listsert(SqList &L,int i,int e)
//�ڵ�i��λ�ò����µ�Ԫ��e
{
	int j;
	if(i<1||i>L.length+1)
		return 0;
	if(!L.elem)
		return -1;
		//�ж�i�Ƿ�Ϸ� 
	for(j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];      //�����һ��Ԫ�ص���i��Ԫ������ ����ţ��ճ���i��λ�� 
		L.elem[i-1]=e;              //�ڵ�i��λ���ϲ���e 
	L.length++;                     //������1 
	return 1;
}

void print(SqList L)
//�����������Ԫ�� 
{
	int i;
	for(i=0;i<L.length;i++)
	printf("%d ",L.elem[i]); 
}

int main()
{
//��ʼ�� 	
	SqList L;
	ElemType e=0,i=1,j=1,k=0;
	InitList(L);                           
	printf("��ʼ��L��L.length=%d\n",L.length);
	
//�Ա���Ԫ�ؽ��г�ʼ���븳ֵ	
	for(i=1,j=1;j<=5,i<=5;i++,j++)
	listsert(L,i,j);                    
	printf("�������������ǣ�"); 
	print(L);
	printf("�������ݺ�L.length=%d\n",L.length);
	
//�����ڵ�4��λ�ò���8 
	listsert(L,4,8);                  
	printf("�������������ǣ�");
	print(L);
	printf("�������ݺ�L.length=%d\n",L.length);
	
//����ȡ����5��λ�õ�����	
	GetElem(L,5,e);
	printf("��5��������:%d\n",e); 
	
//����ɾ����2��λ���ϵ�Ԫ��	
	listdelete(L,2,e);
	printf("ɾ����2��Ԫ��ֵΪ��%d ",e);
	printf("�������������ǣ�");
	print(L);
	printf("ɾ�����ݺ�L.length=%d\n",L.length);
	
//��ձ�
	ClearList(L);
	printf("��ձ��L.length=%d\n",L.length); 
	
//���ٱ�
 	Destroy(L);
	if(!L.elem) printf("���Ѿ�������");
	else printf("��δ������"); 
	return 0;
} 



























