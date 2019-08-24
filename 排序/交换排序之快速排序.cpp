//交换排序之快速排序 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

/*
基本思想：每次循环设置两个指示指针i,j，一个从前往后遍历，一个从后往前遍历；
取一标准值x，从i下标元素开始比较，若A[i]<x,表示顺序正确；否则，将x赋值给A[i],且i++;
同理，下一趟轮到下标j，从后往前与x比较，若A[j]>x，表示顺序正确；否则，将x赋值给A[j]，且j--;
重复以上i++与j--操作直至两者相遇，代表此次快排结束，得到一标准值为中枢的数据序列；
x左边的数都小于或等于它，右边的数都大于或等于它，然后分别在x左右的序列中选择标准值进行相似的操作 
*/ 
void print(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void QuickSort(int A[],int low,int high)
{
	if(low < high)//递归终止条件 
	{
		int i = low,j=high;//初始化指针 
		int x = A[low];//选取标准值 
		while(i<j)//本次快排循环条件 
		{
			while(i<j && A[j] >= x) j--;//代表后面数大于标准值，顺序正确，继续寻找不正确顺序 
			if(i<j) A[i++] = A[j];//对于顺序不对的数，赋值给A[i]且i++
			while(i<j && A[i] <= x) i++;//代表前面数小于标准值，顺序正确，继续寻找不正确顺序
			if(i<j) A[j--] = A[i];//对于顺序不对的数，赋值给A[j]且j--
		}
		A[i] = x;//标准值最终位于中枢 
		QuickSort(A,low,i-1);//递归进行左半序列排序 
		QuickSort(A,i+1,high);//递归进行右半序列排序 
	}
}

int main()
{
	int A[] = {3,6,5,2,1,4,8,9,7};
	int size = sizeof(A) / sizeof(A[0]);
	cout<<"#数组初始化为："<<endl;
	print(A,size);
	
	QuickSort(A,0,size-1);
	cout<<"#数组排序后为："<<endl; 
	print(A,size); 
	return 0;
} 
