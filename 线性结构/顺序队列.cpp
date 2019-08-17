#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100//��ʼ������ 
#define INCREASE 10//�������� 
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
/***************�ṹ�嶨��***************/
typedef struct 
{
	ElemType *dataBase;//���ݻ�ַ
	ElemType front,rear;//��ͷ��βָ�룻
	int queSize;//��ǰ��������� 
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
	Q.dataBase = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
	if(!Q.dataBase)
	{
		printf("#�����ڴ�ʧ��\n");
        return ERROR;
	}
	Q.front = 0;
	Q.rear = 0;
	Q.queSize = MAXSIZE;
	return OK;
}

bool IsEmpty(SqQueue &Q)//�ж�˳����Ƿ�Ϊ��
{
	if(Q.front == Q.rear)
		return true;
	return false;
} 

bool IsFull(SqQueue &Q){
    if(Q.rear>=Q.queSize)
        return true;
    return false;
}

int SqQueueLength(SqQueue &Q)//���ضӵĳ��ȣ���Ԫ�ظ���
{
	return Q.rear-Q.front;
}

Status enQueue(SqQueue &Q,ElemType x)//x���
{
	
	if(IsFull(Q))
	{
		Q.dataBase = (ElemType *)realloc(Q.dataBase,(Q.queSize + INCREASE));
		if(!Q.dataBase)
			return ERROR;
	//	S.top = S.data + S.stackSize;
		Q.queSize += INCREASE;
		return ERROR;
	}
	Q.dataBase[Q.rear] = x;
	Q.rear++;
	return OK;
}

Status deQueue(SqQueue &Q,ElemType &x)//���ӶӶ�����ֵ��x
{
	if(IsEmpty(Q))
	{
		cout<<"#����Ϊ�գ�����ʧ�ܣ�"<<endl; 
		return ERROR;
	}
	x = Q.dataBase[Q.front];//�Ƚ��ȳ�
	Q.dataBase[Q.front] = 999; 
	Q.front++;//��ͷ���� 
	return OK; 
} 

void SqQueueTraverse(SqQueue &Q)//����˳��� 
{
	int i = Q.front;
	while(i != Q.rear)
	{
		printf("%d ",Q.dataBase[i]);
		i++;
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
Status GetTop(SqQueue &Q,ElemType &x);//ȡ�Ӷ�Ԫ�ظ�ֵ��x
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
	cout<<"#�նӳ��Ӳ��ԣ�"<<endl;
	deQueue(Q,denum);
	cout<<endl;
	 
	cout<<"*1����ʼ����������Ϊ1-10"<<endl;
	for(int i=1;i<11;i++)
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
	
	cout<<"*4����ʱ���������һ��λ������ȱ����˷�(����ʱ��Ϊ999)��"<<endl;
	cout<<"Q.dataBase[0]Ϊ��"<<Q.dataBase[0]<<endl;
	cout<<"Q.dataBase[1]Ϊ��"<<Q.dataBase[1]<<endl;
	cout<<"Q.dataBase[2]Ϊ��"<<Q.dataBase[2]<<endl;
	
	
	return 0;
}
