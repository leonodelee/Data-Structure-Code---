//选择排序之堆排序 
/*
堆的本质还是二叉树，且是以数组存储的顺序存储结构，不过规定父节点的左右孩子结点值必须大于（或小于）父节点的值
以大根堆为例，首先根据原始数据构造大根堆，然后每次去除最大值对剩下的堆重新调整为大根堆，
持续下去即可对原数据序列进行排序 
*/
#include <iostream>
#include <cstdlib>
using namespace std;

void Print(int *A,int n) 
{
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void swap(int *a,int *b)//用于交换结点 
{
	int p;
	p = *a;
	*a = *b;
	*b = p;
}

void AdjustHeap(int *A,int i,int len)
{
	int j = i*2+1;//初始化为左子节点 
	while(j<len)
	{
		//建立大根堆
		if(j+1 < len && A[j] < A[j+1])//获取右孩子结点较大值
		{
			j++;
		}	
		//将左右孩子结点较大值与根节点比较
		if(A[i] > A[j])//根节点值大，不需调整 
		{
			break;
		}
		swap(&A[i],&A[j]);
		//转移到下一层调整 
		i = j;
		j = 2*i+1;
	}	
} 

void MakeHeap(int *A,int n)//构建大根堆
{
	int i;
	for(i = n/2-1;i>=0;i--)//从尾端最后一个子树进行排序 
	{
		AdjustHeap(A,i,n);	
	}	
} 

void HeapSort(int *A,int len)//堆排序 
{
	int i = 0;
	MakeHeap(A,len);//构建大根堆 
	//排出最大元素为有序序列，对剩余的元素继续进行排序 
	for(i = len-1;i>=0;i--)//从尾端开始进行调整 
	{
		swap(&A[i],&A[0]);//交换首尾元素 
		AdjustHeap(A,0,i);//继续进行调整 
	}
} 
int main()
{
	int A[] = {3,6,5,2,1,4,8,9,7};
	int size = sizeof(A) / sizeof(A[0]);
	cout<<"#数组初始化为："<<endl;
	Print(A,size);
	
	HeapSort(A,size);
	cout<<"#数组堆排序后为："<<endl; 
	Print(A,size);
	return 0;
} 
