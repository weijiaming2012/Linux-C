# coding: utf-8

def binary_search(key,a,n):
	low=0
	high=n-1
	count=0
	flag=False
	while low<high:
		count+=1
		mid=int((low+high)/2)
		if key>a[mid]:
			low=mid+1
		elif key<a[mid]:
			high=mid-1
		elif key==a[mid]:
			print("查找次数：%d" % count)
			flag=True
			break
	if not flag:
		print("查找元素不存在！")

if __name__=="__main__":
	binary_search(2000,range(3000),3000)
