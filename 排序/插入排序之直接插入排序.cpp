//插入排序之直接插入排序  
/*思想参考大佬：https://www.cnblogs.com/hokky/p/8529042.html 
#直接插入排序
def insert_sort(L):
    #遍历数组中的所有元素，其中0号索引元素默认已排序，因此从1开始
    for x in range(1,len(L)):
    #将该元素与已排序好的前序数组依次比较，如果该元素小，则交换
    #range(x-1,-1,-1):从x-1倒序循环到0
        for i in range(x-1,-1,-1):
    #判断：如果符合条件则交换
            if L[i] > L[i+1]:
                temp = L[i+1]
                L[i+1] = L[i]
                L[i] = temp
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void InsertSort(int A[],int size)
{
	for(int i=0;i<size;i++)
	{
		int num = A[i];
		int j= i -1;
		while(j >= 0 && A[j] > num)
		{
			A[j+1] = A[j];
			j--;	
		}	
		A[j+1] = num;
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
	
	InsertSort(A,size);
	cout<<"#数组排序后为："<<endl; 
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
