//交换排序之冒泡排序 
/*思想参考大佬：https://www.cnblogs.com/hokky/p/8529042.html 
冒泡排序思路比较简单：
将序列当中的左右元素，依次比较，保证右边的元素始终大于左边的元素；
（ 第一轮结束后，序列最后一个元素一定是当前序列的最大值；）
对序列当中剩下的n-1个元素再次执行步骤1。
对于长度为n的序列，一共需要执行n-1轮比较
（利用while循环可以减少执行次数）

*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void BubbleSort(int A[],int size)
{
	for(int j=0;j<size-1;j++)//将本次循环最大值放置右边有序区
	{
		for(int i=0;i<size-1-j;i++)//相邻元素的比较
		{
			if(A[i] > A[i+1])//若左边元素大于右边元素交换相邻元素 
			{
				int temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;	
			}	
		}	
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
	
	BubbleSort(A,size);
	cout<<"#数组排序后为："<<endl; 
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
