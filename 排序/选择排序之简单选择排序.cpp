//ѡ������֮��ѡ���� 
//https://blog.csdn.net/flowing_wind/article/details/81100405
/*˼��ο����У�https://www.cnblogs.com/hokky/p/8529042.html 
��ѡ������Ļ���˼�룺�Ƚ�+������
�Ӵ����������У��ҵ��ؼ�����С��Ԫ�أ�
�����СԪ�ز��Ǵ��������еĵ�һ��Ԫ�أ�����͵�һ��Ԫ�ػ�����
�����µ� N - 1 ��Ԫ���У��ҳ��ؼ�����С��Ԫ�أ��ظ�(1)��(2)����ֱ�����������
������ǿ��Է��֣���ѡ������Ҳ��ͨ������ѭ��ʵ�֡�
��һ��ѭ�������α������е��е�ÿһ��Ԫ��
�ڶ���ѭ�����������õ��ĵ�ǰԪ�����������µ�Ԫ�ؽ��бȽϣ�������СԪ�ص��������򽻻���
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
		for(int j = i+1;j<size;j++)//������������Сֵ����������		
		{
			if(A[min] > A[j])
				min = j;
		}
		if(min != i)//������ѭ������Сֵ�ƶ��������� 
			Swap(A,min,i);
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
	
	SelectSort(A,size);
	cout<<"#���������Ϊ��"<<endl; 
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
