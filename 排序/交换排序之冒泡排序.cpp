//��������֮ð������ 
/*˼��ο����У�https://www.cnblogs.com/hokky/p/8529042.html 
ð������˼·�Ƚϼ򵥣�
�����е��е�����Ԫ�أ����αȽϣ���֤�ұߵ�Ԫ��ʼ�մ�����ߵ�Ԫ�أ�
�� ��һ�ֽ������������һ��Ԫ��һ���ǵ�ǰ���е����ֵ����
�����е���ʣ�µ�n-1��Ԫ���ٴ�ִ�в���1��
���ڳ���Ϊn�����У�һ����Ҫִ��n-1�ֱȽ�
������whileѭ�����Լ���ִ�д�����

*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void BubbleSort(int A[],int size)
{
	for(int j=0;j<size-1;j++)//������ѭ�����ֵ�����ұ�������
	{
		for(int i=0;i<size-1-j;i++)//����Ԫ�صıȽ�
		{
			if(A[i] > A[i+1])//�����Ԫ�ش����ұ�Ԫ�ؽ�������Ԫ�� 
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
	cout<<"#�����ʼ��Ϊ��"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	BubbleSort(A,size);
	cout<<"#���������Ϊ��"<<endl; 
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
