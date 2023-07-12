#include<stdio.h>

int search1(int *a,int n,int key)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==key)
		return i;
	}
	return 0; 
}

int search2(int *a,int n,int key)
{
	a[0]=key;
	for(int i=n;i>=0;i--)
	{
		if(a[i]==key)
		return i;
	}
}

int Binary_search1(int *a,int n,int key)
{
	int low=1;
	int high=n;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		return mid;
		else if(a[mid]<key)
		low=mid+1;
		else if(a[mid]>key)
		high=mid-1;
	}
	return 0;
}

int Binary_search2(int *a,int n1,int n2,int key)
{
	int low=n1;
	int high=n2;
	int mid=(low+high)/2;
	while(low<=high)
	{
	if(a[mid]==key)
	return mid;
	if(a[mid]<key)
	return Binary_search2(a,mid+1,n2,key);
	if(a[mid]>key)
	return Binary_search2(a,n1,mid-1,key);
	}
	return 0;
}

int main()
{
	int a[11]={7,2,3,4,5,6,7,8,9,10,11};
	int arr[11]={3,4,5,6,7,8,22,33,44,55,66};
	if(search1(a,11,5))
	printf("找到了\n"); 
	else printf("未找到\n"); 
	if(search1(a,11,7))
	printf("找到了\n");
	else printf("未找到\n");
	if(Binary_search1(arr,11,89))
	printf("找到了\n");
	else printf("未找到\n");
	if(Binary_search2(arr,0,11,0))
	printf("找到了\n");
	else printf("未找到\n");
	return 0;
}















