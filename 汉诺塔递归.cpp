#include<stdio.h>
int m=0; 
void move(char a,int n,char b)
{
	m++;
	printf("��%d���ƶ������Ϊ%d�Ļ���%c�Ƶ�%c\n",m,n,a,b);
}
void hanoi(int n,char x,char y,char z)//�����1��n�Ļ���x���Ƶ�z�� 
{
	if(n==1)
	move(x,1,z);
	else
	{
		hanoi(n-1,x,z,y);//�����1��n-1�Ļ���x���Ƶ�y��
		move(x,n,z);//����ײ��n����x���Ƶ�z��
		hanoi(n-1,y,x,z);// �����1��n-1�Ļ���y���Ƶ�z��
	}
}
int main()
{
	int n;
	char x,y,z;
	x='a';
	y='b';
	z='c';
	scanf("%d",&n);
	hanoi(n,x,y,z);
	return 0;
}
