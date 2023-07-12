#include<stdio.h>
int m=0; 
void move(char a,int n,char b)
{
	m++;
	printf("第%d次移动将编号为%d的环从%c移到%c\n",m,n,a,b);
}
void hanoi(int n,char x,char y,char z)//将编号1到n的环从x柱移到z柱 
{
	if(n==1)
	move(x,1,z);
	else
	{
		hanoi(n-1,x,z,y);//将编号1到n-1的环从x柱移到y柱
		move(x,n,z);//将最底层的n环从x柱移到z柱
		hanoi(n-1,y,x,z);// 将编号1到n-1的环从y柱移到z柱
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
