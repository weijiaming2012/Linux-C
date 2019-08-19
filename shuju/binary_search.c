#include<stdio.h>

int binary_search(int key,int a[],int n)
{
	int low,high,mid,count=0,flag=0;
	low=0;
	high=n-1;
	while(low<high)
	{
		count++;
		mid=(low+high)/2;
		if(key<a[mid])
		{
			high=mid-1;
		}
		else if(key>a[mid])
		{
			low=mid+1;
		}
		else if(key==a[mid])
		{
			flag=1;
			printf("查找成功！\n查找%d次！a[%d]=%d\n",count,mid,key);
			break;
		}
	}
	if(!flag)
	{
		printf("查找元素不存在！\n");
	}
	return 0;
}

int main()
{
	int i,key,a[100],n;
	printf("请输入数组长度:");
	scanf("%d",&n);
	printf("请输入数组元素：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("请输入你需要查找的元素：");
	scanf("%d",&key);
	binary_search(key,a,n);

	return 0;
}
