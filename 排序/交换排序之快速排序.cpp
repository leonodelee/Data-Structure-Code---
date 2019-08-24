//��������֮�������� 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

/*
����˼�룺ÿ��ѭ����������ָʾָ��i,j��һ����ǰ���������һ���Ӻ���ǰ������
ȡһ��׼ֵx����i�±�Ԫ�ؿ�ʼ�Ƚϣ���A[i]<x,��ʾ˳����ȷ�����򣬽�x��ֵ��A[i],��i++;
ͬ����һ���ֵ��±�j���Ӻ���ǰ��x�Ƚϣ���A[j]>x����ʾ˳����ȷ�����򣬽�x��ֵ��A[j]����j--;
�ظ�����i++��j--����ֱ����������������˴ο��Ž������õ�һ��׼ֵΪ������������У�
x��ߵ�����С�ڻ���������ұߵ��������ڻ��������Ȼ��ֱ���x���ҵ�������ѡ���׼ֵ�������ƵĲ��� 
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
	if(low < high)//�ݹ���ֹ���� 
	{
		int i = low,j=high;//��ʼ��ָ�� 
		int x = A[low];//ѡȡ��׼ֵ 
		while(i<j)//���ο���ѭ������ 
		{
			while(i<j && A[j] >= x) j--;//������������ڱ�׼ֵ��˳����ȷ������Ѱ�Ҳ���ȷ˳�� 
			if(i<j) A[i++] = A[j];//����˳�򲻶Ե�������ֵ��A[i]��i++
			while(i<j && A[i] <= x) i++;//����ǰ����С�ڱ�׼ֵ��˳����ȷ������Ѱ�Ҳ���ȷ˳��
			if(i<j) A[j--] = A[i];//����˳�򲻶Ե�������ֵ��A[j]��j--
		}
		A[i] = x;//��׼ֵ����λ������ 
		QuickSort(A,low,i-1);//�ݹ��������������� 
		QuickSort(A,i+1,high);//�ݹ�����Ұ��������� 
	}
}

int main()
{
	int A[] = {3,6,5,2,1,4,8,9,7};
	int size = sizeof(A) / sizeof(A[0]);
	cout<<"#�����ʼ��Ϊ��"<<endl;
	print(A,size);
	
	QuickSort(A,0,size-1);
	cout<<"#���������Ϊ��"<<endl; 
	print(A,size); 
	return 0;
} 
