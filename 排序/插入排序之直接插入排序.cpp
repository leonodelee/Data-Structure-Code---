//��������ֱ֮�Ӳ�������  
/*˼��ο����У�https://www.cnblogs.com/hokky/p/8529042.html 
#ֱ�Ӳ�������
def insert_sort(L):
    #���������е�����Ԫ�أ�����0������Ԫ��Ĭ����������˴�1��ʼ
    for x in range(1,len(L)):
    #����Ԫ����������õ�ǰ���������αȽϣ������Ԫ��С���򽻻�
    #range(x-1,-1,-1):��x-1����ѭ����0
        for i in range(x-1,-1,-1):
    #�жϣ�������������򽻻�
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
	cout<<"#�����ʼ��Ϊ��"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	InsertSort(A,size);
	cout<<"#���������Ϊ��"<<endl; 
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
