//ѡ������֮������ 
/*
�ѵı��ʻ��Ƕ�����������������洢��˳��洢�ṹ�������涨���ڵ�����Һ��ӽ��ֵ������ڣ���С�ڣ����ڵ��ֵ
�Դ����Ϊ�������ȸ���ԭʼ���ݹ������ѣ�Ȼ��ÿ��ȥ�����ֵ��ʣ�µĶ����µ���Ϊ����ѣ�
������ȥ���ɶ�ԭ�������н������� 
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

void swap(int *a,int *b)//���ڽ������ 
{
	int p;
	p = *a;
	*a = *b;
	*b = p;
}

void AdjustHeap(int *A,int i,int len)
{
	int j = i*2+1;//��ʼ��Ϊ���ӽڵ� 
	while(j<len)
	{
		//���������
		if(j+1 < len && A[j] < A[j+1])//��ȡ�Һ��ӽ��ϴ�ֵ
		{
			j++;
		}	
		//�����Һ��ӽ��ϴ�ֵ����ڵ�Ƚ�
		if(A[i] > A[j])//���ڵ�ֵ�󣬲������ 
		{
			break;
		}
		swap(&A[i],&A[j]);
		//ת�Ƶ���һ����� 
		i = j;
		j = 2*i+1;
	}	
} 

void MakeHeap(int *A,int n)//���������
{
	int i;
	for(i = n/2-1;i>=0;i--)//��β�����һ�������������� 
	{
		AdjustHeap(A,i,n);	
	}	
} 

void HeapSort(int *A,int len)//������ 
{
	int i = 0;
	MakeHeap(A,len);//��������� 
	//�ų����Ԫ��Ϊ�������У���ʣ���Ԫ�ؼ����������� 
	for(i = len-1;i>=0;i--)//��β�˿�ʼ���е��� 
	{
		swap(&A[i],&A[0]);//������βԪ�� 
		AdjustHeap(A,0,i);//�������е��� 
	}
} 
int main()
{
	int A[] = {3,6,5,2,1,4,8,9,7};
	int size = sizeof(A) / sizeof(A[0]);
	cout<<"#�����ʼ��Ϊ��"<<endl;
	Print(A,size);
	
	HeapSort(A,size);
	cout<<"#����������Ϊ��"<<endl; 
	Print(A,size);
	return 0;
} 
