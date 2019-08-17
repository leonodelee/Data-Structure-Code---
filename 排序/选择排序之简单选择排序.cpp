//选择排序之简单选择序 
//https://blog.csdn.net/flowing_wind/article/details/81100405
/*思想参考大佬：https://www.cnblogs.com/hokky/p/8529042.html 
简单选择排序的基本思想：比较+交换。
从待排序序列中，找到关键字最小的元素；
如果最小元素不是待排序序列的第一个元素，将其和第一个元素互换；
从余下的 N - 1 个元素中，找出关键字最小的元素，重复(1)、(2)步，直到排序结束。
因此我们可以发现，简单选择排序也是通过两层循环实现。
第一层循环：依次遍历序列当中的每一个元素
第二层循环：将遍历得到的当前元素依次与余下的元素进行比较，符合最小元素的条件，则交换。
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
void Swap(int A[],int i,int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void SelectSort(int A[],int size)
{
	for(int i=0;i<size-1;i++)
	{
		int min = i;
		for(int j = i+1;j<size;j++)//从无序区找最小值加入有序区		
		{
			if(A[min] > A[j])
				min = j;
		}
		if(min != i)//将本次循环的最小值移动到有序区 
			Swap(A,min,i);
	} 
}

int main()
{
	int A[] = {3,6,5,2,1,4,8,9,7};
	int size = sizeof(A) / sizeof(A[0]);
	cout<<"#数组初始化为："<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	SelectSort(A,size);
	cout<<"#数组排序后为："<<endl; 
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
