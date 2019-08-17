#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXSIZE 7//��ʼ������ 
#define INCREASE 10//�������� 
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
/***************�ṹ�嶨��***************/
typedef struct 
{
	ElemType data[MAXSIZE];//���ݻ�ַ
	ElemType front,rear;//��ͷ��βָ�룻
	int length;//��ǰ��������� 
}SqQueue;

/******************��������******************/
Status SqQueueInit(SqQueue &Q);//˳��ӳ�ʼ��
bool IsEmpty(SqQueue &Q);//�ж�˳����Ƿ�Ϊ�� 
bool IsFull(SqQueue &Q);//�ж�˳����Ƿ��� 
Status enQueue(SqQueue &Q,ElemType x);//x���
Status deQueue(SqQueue &Q,ElemType &x);//���ӶӶ�����ֵ��x
int SqQueueLength(SqQueue &Q);//���ضӵĳ��ȣ���Ԫ�ظ��� 
void SqQueueTraverse(SqQueue &Q);//����˳��� 
void SqQueueDestroy(SqQueue &Q);//����˳��� 

/******************����ʵ��******************/
Status SqQueueInit(SqQueue &Q)//˳��ӳ�ʼ��
{
	Q.front = 0;
	Q.rear = 0;
//	Q.length = 0;
	return OK;
}

bool IsEmpty(SqQueue &Q)//�ж�˳����Ƿ�Ϊ��
{
	if(Q.front == Q.rear)
		return true;
	return false;
} 

bool IsFull(SqQueue &Q){
    if(((Q.rear + 1) % MAXSIZE) == Q.front)
        return true;
    return false;
}

int SqQueueLength(SqQueue &Q)//���ضӵĳ��ȣ���Ԫ�ظ���
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status enQueue(SqQueue &Q,ElemType x)//x���
{
	if(!IsFull(Q))
	{
		int insertIndex = Q.rear % MAXSIZE;
		Q.rear = (Q.rear + 1) % MAXSIZE;
		Q.data[insertIndex] = x;
		cout<<"#����ɹ�,����λ��Ϊ��"<<insertIndex<<endl;
		return OK;
	}
	else
	{
		cout<<"#���������ģ����ʧ�ܣ�"<<endl;
		return ERROR;
	}
	
}

Status deQueue(SqQueue &Q,ElemType &x)//���ӶӶ�����ֵ��x
{
	if(IsEmpty(Q))
	{
		cout<<"#����Ϊ�գ�����ʧ�ܣ�"<<endl; 
		return ERROR;
	}
	x = Q.data[Q.front];//�Ƚ��ȳ�
	Q.front = (Q.front + 1)%MAXSIZE;//��ͷ����
	cout<<"#���ӳɹ�������Ԫ��Ϊ��"<<x<<endl; 
	return OK; 
} 

void SqQueueTraverse(SqQueue &Q)//����˳��� 
{
	int i = Q.front;
	while(i != Q.rear)
	{
		printf("%d ",Q.data[i]);
		i = (i+1)%MAXSIZE;
	}
	cout<<endl;
} 

void SqQueueDestroy(SqQueue &Q)//����˳���
{
	Q.front = 0;
	Q.rear = 0;	
} 

/*
Status SqQueueInit(SqQueue &Q);//˳��ӳ�ʼ��
bool IsEmpty(SqQueue &Q);//�ж�˳����Ƿ�Ϊ�� 
bool IsFull(SqQueue &Q);//�ж�˳����Ƿ��� 
Status enQueue(SqQueue &Q,ElemType x);//x���
Status deQueue(SqQueue &Q,ElemType &x);//���ӶӶ�����ֵ��x
int SqQueueLength(SqQueue &Q);//���ضӵĳ��ȣ���Ԫ�ظ��� 
void SqQueueTraverse(SqQueue &Q);//����˳��� 
void SqQueueDestroy(SqQueue &Q);//����˳��� 
*/

/******************��������֤******************/
int main()
{
	ElemType denum;
	SqQueue Q;
	SqQueueInit(Q);
	cout<<"*1����ʼ����������Ϊ1-5,MAXSIZEΪ7���������6����"<<endl;
	for(int i=1;i<6;i++)
	{
		enQueue(Q,i);
	}
	cout<<"#��ʱ���������У�"<<endl;
	SqQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<SqQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*2��������в�������2019"<<endl;
	enQueue(Q,2019);
	cout<<"#��ʱ���������У�"<<endl;
	SqQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<SqQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*3�����г�������"<<endl;
	deQueue(Q,denum);
	deQueue(Q,denum);
	cout<<"#���ӵĵڶ���Ԫ��Ϊ��"<<denum<<endl;
	cout<<"#��ʱ���������У�"<<endl;
	SqQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<SqQueueLength(Q)<<endl;
	cout<<endl;
	cout<<"*2��������в�������11��22������ѭ����"<<endl;
	enQueue(Q,11);enQueue(Q,22);
	cout<<"#��ʱ���������У�"<<endl;
	SqQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<SqQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*2��ȥ��4��Ԫ�أ�������в���6������111��222��333��444����Խ��"<<endl;
	deQueue(Q,denum);deQueue(Q,denum);
	enQueue(Q,111);enQueue(Q,222);enQueue(Q,333);enQueue(Q,444);
	cout<<"#��ʱ���������У�"<<endl;
	SqQueueTraverse(Q);
	cout<<endl;
	 
	SqQueueDestroy(Q);
	return 0;
}
