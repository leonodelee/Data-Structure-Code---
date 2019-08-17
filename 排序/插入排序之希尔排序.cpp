//插入排序之希尔排序
#include <iostream>
#include <cstdlib>
using namespace std;

void print(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);	
	}	
	printf("\n");
} 

void ShellSort(int A[],int n)//希尔排序代码，A为待排序数组，n为数组中数的个数 
{
	int i,j,gap;
	for(gap=n/2;gap>0;gap/=2)//步长初始化为n/2，并逐次减半
	{
		//gap个组，每一组执行直接插入排序
		for(i=0;i<gap;i++)
		{
			for(j=i+gap;j<n;j+=gap)//每组组内遍历 
			{
				if(A[j] < A[j-gap])
				{
					int temp = A[j];//该步没有会出错排序结果为3 6 6 6 6 6 8 9 9
					int k = j - gap;
					while(k>=0 && A[k] > A[j])
					{
						A[k+gap] = A[k];
						k -= gap;
					}
					A[k+gap] = temp;//此处直接写A[j]会出错？？？ 
				}
			}
		}	
	} 
}
int main()
{
	int A[] = {3,6,5,2,1,4,8,9,7};
	int size = sizeof(A) / sizeof(A[0]);
	cout<<"#数组初始化为："<<endl;
	print(A,size);
	
	ShellSort(A,size);
	cout<<"#数组排序后为："<<endl; 
	print(A,size);
	return 0;
} 

/*
算法思想：将数组按照步长gap分组，然后每组用直接插入排序的方法进行排序；
之后每次将gap减半进行循环，直至gap==1完成排序 
*/
