#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElemType;
#define Status int 
#define ERROR 0
#define OK 1
/***************�ṹ�嶨��***************/
typedef struct LNode
{
	int data;//������
	LNode *next;//ָ����һ������ָ���� 
}LNode; 

typedef struct
{
	LNode *front,*rear;
	int length;
}LinkQueue;

/******************��������******************/
Status LinkQueueInit(LinkQueue &Q);//���ӳ�ʼ��
bool IsEmpty(LinkQueue &Q);//�ж������Ƿ�Ϊ�� 
Status enQueue(LinkQueue &Q,ElemType x);//x���
Status deQueue(LinkQueue &Q,ElemType &x);//���ӶӶ�����ֵ��x
int LinkQueueLength(LinkQueue &Q);//���ضӵĳ��ȣ���Ԫ�ظ��� 
void LinkQueueTraverse(LinkQueue &Q);//�������� 
void LinkQueueDestroy(LinkQueue &Q);//�������� 

/******************����ʵ��******************/
Status LinkQueueInit(LinkQueue &Q)//���ӳ�ʼ��
{
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
	Q.rear->next = NULL;
	Q.length = 0;
}

bool IsEmpty(LinkQueue &Q)//�ж������Ƿ�Ϊ�� 
{
	if(Q.front == Q.rear)
		return true;
	return false;
}

Status enQueue(LinkQueue &Q,ElemType x)//x���
{
	LNode *node = (LNode *)malloc(sizeof(LNode));
	node->data = x;
	cout<<"#��ӳɹ�����ӽ������Ϊ��"<<x<<endl;
	node->next = NULL;
	Q.rear->next = node;
	Q.rear = node;//���¶�β 
	Q.length++;
	return OK;
}

Status deQueue(LinkQueue &Q,ElemType &x)//���ӶӶ�����ֵ��x
{
	if(IsEmpty(Q))
	{
		cout<<"#����Ϊ�գ�����ʧ��"<<endl;
		return ERROR;
	}
	LNode *node = Q.front->next;//��¼Ҫ�ͷŵĶ�ͷ���,front��ָ�����ݽ�㣬��ͷ��������� 
	x = node->data;
	cout<<"#���ӳɹ������ӽ������Ϊ��"<<x<<endl;
	Q.front->next = node->next;
	free(node);	
	Q.length--; 
	return OK;
} 

int LinkQueueLength(LinkQueue &Q)//���ضӵĳ��ȣ���Ԫ�ظ���
{
	return Q.length;	
} 

void LinkQueueTraverse(LinkQueue &Q)//�������� 
{
	LNode *node = Q.front->next;
	while(node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

void LinkQueueDestroy(LinkQueue &Q)//��������
{
	if(Q.front == Q.rear)
	{
		cout<<"#����Ϊ��"<<endl;
	}
	LNode *p = Q.front;
	LNode *temp;
	while(p!=NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
} 
/*
Status LinkQueueInit(LinkQueue &Q);//���ӳ�ʼ��
bool IsEmpty(LinkQueue &Q);//�ж������Ƿ�Ϊ�� 
Status enQueue(LinkQueue &Q,ElemType x);//x���
Status deQueue(LinkQueue &Q,ElemType &x);//���ӶӶ�����ֵ��x
int LinkQueueLength(LinkQueue &Q);//���ضӵĳ��ȣ���Ԫ�ظ��� 
void LinkQueueTraverse(LinkQueue &Q);//�������� 
void LinkQueueDestroy(LinkQueue &Q);//�������� 
*/
/******************��������֤******************/
int main()
{
	ElemType denum;
	LinkQueue Q;
	LinkQueueInit(Q);
	cout<<"*1����ʼ����������Ϊ1-10"<<endl;
	for(int i=1;i<11;i++)
	{
		enQueue(Q,i);
	}
	cout<<"#��ʱ���������У�"<<endl;
	LinkQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*2��������в�������2019"<<endl;
	enQueue(Q,2019);
	cout<<"#��ʱ���������У�"<<endl;
	LinkQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*3�����г�������"<<endl;
	deQueue(Q,denum);
	deQueue(Q,denum);
	cout<<"#���ӵĵڶ���Ԫ��Ϊ��"<<denum<<endl;
	cout<<"#��ʱ���������У�"<<endl;
	LinkQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*4��ȥ������в�������111��222��333��444��������Խ��(�����޽�)"<<endl;
	deQueue(Q,denum);deQueue(Q,denum);
	enQueue(Q,111);enQueue(Q,222);enQueue(Q,333);enQueue(Q,444);
	cout<<"#��ʱ���������У�"<<endl;
	LinkQueueTraverse(Q);
	cout<<"#��ʱ���г���Ϊ��"<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	 
	LinkQueueDestroy(Q);
	return 0;
}
