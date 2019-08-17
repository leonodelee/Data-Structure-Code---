#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElemType;
#define Status int 
#define ERROR 0
#define OK 1
/***************结构体定义***************/
typedef struct LNode
{
	int data;//数据域
	LNode *next;//指向下一个结点的指针域 
}LNode; 

typedef struct
{
	LNode *front,*rear;
	int length;
}LinkQueue;

/******************函数声明******************/
Status LinkQueueInit(LinkQueue &Q);//链队初始化
bool IsEmpty(LinkQueue &Q);//判断链队是否为空 
Status enQueue(LinkQueue &Q,ElemType x);//x入队
Status deQueue(LinkQueue &Q,ElemType &x);//出队队顶并赋值给x
int LinkQueueLength(LinkQueue &Q);//返回队的长度，即元素个数 
void LinkQueueTraverse(LinkQueue &Q);//遍历链队 
void LinkQueueDestroy(LinkQueue &Q);//销毁链队 

/******************函数实现******************/
Status LinkQueueInit(LinkQueue &Q)//链队初始化
{
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
	Q.rear->next = NULL;
	Q.length = 0;
}

bool IsEmpty(LinkQueue &Q)//判断链队是否为空 
{
	if(Q.front == Q.rear)
		return true;
	return false;
}

Status enQueue(LinkQueue &Q,ElemType x)//x入队
{
	LNode *node = (LNode *)malloc(sizeof(LNode));
	node->data = x;
	cout<<"#入队成功，入队结点数据为："<<x<<endl;
	node->next = NULL;
	Q.rear->next = node;
	Q.rear = node;//更新队尾 
	Q.length++;
	return OK;
}

Status deQueue(LinkQueue &Q,ElemType &x)//出队队顶并赋值给x
{
	if(IsEmpty(Q))
	{
		cout<<"#队列为空，出队失败"<<endl;
		return ERROR;
	}
	LNode *node = Q.front->next;//记录要释放的队头结点,front不指向数据结点，即头结点无数据 
	x = node->data;
	cout<<"#出队成功，出队结点数据为："<<x<<endl;
	Q.front->next = node->next;
	free(node);	
	Q.length--; 
	return OK;
} 

int LinkQueueLength(LinkQueue &Q)//返回队的长度，即元素个数
{
	return Q.length;	
} 

void LinkQueueTraverse(LinkQueue &Q)//遍历链队 
{
	LNode *node = Q.front->next;
	while(node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

void LinkQueueDestroy(LinkQueue &Q)//销毁链队
{
	if(Q.front == Q.rear)
	{
		cout<<"#队列为空"<<endl;
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
Status LinkQueueInit(LinkQueue &Q);//链队初始化
bool IsEmpty(LinkQueue &Q);//判断链队是否为空 
Status enQueue(LinkQueue &Q,ElemType x);//x入队
Status deQueue(LinkQueue &Q,ElemType &x);//出队队顶并赋值给x
int LinkQueueLength(LinkQueue &Q);//返回队的长度，即元素个数 
void LinkQueueTraverse(LinkQueue &Q);//遍历链队 
void LinkQueueDestroy(LinkQueue &Q);//销毁链队 
*/
/******************主函数验证******************/
int main()
{
	ElemType denum;
	LinkQueue Q;
	LinkQueueInit(Q);
	cout<<"*1、初始化队列数据为1-10"<<endl;
	for(int i=1;i<11;i++)
	{
		enQueue(Q,i);
	}
	cout<<"#此时队列中数有："<<endl;
	LinkQueueTraverse(Q);
	cout<<"#此时队列长度为："<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*2、向队列中插入数据2019"<<endl;
	enQueue(Q,2019);
	cout<<"#此时队列中数有："<<endl;
	LinkQueueTraverse(Q);
	cout<<"#此时队列长度为："<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*3、队列出队两次"<<endl;
	deQueue(Q,denum);
	deQueue(Q,denum);
	cout<<"#出队的第二个元素为："<<denum<<endl;
	cout<<"#此时队列中数有："<<endl;
	LinkQueueTraverse(Q);
	cout<<"#此时队列长度为："<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*4、去向队列中插入数据111、222、333、444、，不会越界(链表无界)"<<endl;
	deQueue(Q,denum);deQueue(Q,denum);
	enQueue(Q,111);enQueue(Q,222);enQueue(Q,333);enQueue(Q,444);
	cout<<"#此时队列中数有："<<endl;
	LinkQueueTraverse(Q);
	cout<<"#此时队列长度为："<<LinkQueueLength(Q)<<endl;
	cout<<endl;
	 
	LinkQueueDestroy(Q);
	return 0;
}
