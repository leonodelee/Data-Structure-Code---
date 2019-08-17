#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXSIZE 7//初始分配量 
#define INCREASE 10//分配增量 
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
/***************结构体定义***************/
typedef struct 
{
	ElemType data[MAXSIZE];//数据基址
	ElemType front,rear;//队头队尾指针；
	int length;//当前分配的容量 
}SqQueue;

/******************函数声明******************/
Status SqQueueInit(SqQueue &Q);//顺序队初始化
bool IsEmpty(SqQueue &Q);//判断顺序队是否为空 
bool IsFull(SqQueue &Q);//判断顺序队是否满 
Status enQueue(SqQueue &Q,ElemType x);//x入队
Status deQueue(SqQueue &Q,ElemType &x);//出队队顶并赋值给x
int SqQueueLength(SqQueue &Q);//返回队的长度，即元素个数 
void SqQueueTraverse(SqQueue &Q);//遍历顺序队 
void SqQueueDestroy(SqQueue &Q);//销毁顺序队 

/******************函数实现******************/
Status SqQueueInit(SqQueue &Q)//顺序队初始化
{
	Q.front = 0;
	Q.rear = 0;
//	Q.length = 0;
	return OK;
}

bool IsEmpty(SqQueue &Q)//判断顺序队是否为空
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

int SqQueueLength(SqQueue &Q)//返回队的长度，即元素个数
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status enQueue(SqQueue &Q,ElemType x)//x入队
{
	if(!IsFull(Q))
	{
		int insertIndex = Q.rear % MAXSIZE;
		Q.rear = (Q.rear + 1) % MAXSIZE;
		Q.data[insertIndex] = x;
		cout<<"#插入成功,插入位置为："<<insertIndex<<endl;
		return OK;
	}
	else
	{
		cout<<"#队列是满的，入队失败！"<<endl;
		return ERROR;
	}
	
}

Status deQueue(SqQueue &Q,ElemType &x)//出队队顶并赋值给x
{
	if(IsEmpty(Q))
	{
		cout<<"#队列为空，出队失败！"<<endl; 
		return ERROR;
	}
	x = Q.data[Q.front];//先进先出
	Q.front = (Q.front + 1)%MAXSIZE;//队头后移
	cout<<"#出队成功！出队元素为："<<x<<endl; 
	return OK; 
} 

void SqQueueTraverse(SqQueue &Q)//遍历顺序队 
{
	int i = Q.front;
	while(i != Q.rear)
	{
		printf("%d ",Q.data[i]);
		i = (i+1)%MAXSIZE;
	}
	cout<<endl;
} 

void SqQueueDestroy(SqQueue &Q)//销毁顺序队
{
	Q.front = 0;
	Q.rear = 0;	
} 

/*
Status SqQueueInit(SqQueue &Q);//顺序队初始化
bool IsEmpty(SqQueue &Q);//判断顺序队是否为空 
bool IsFull(SqQueue &Q);//判断顺序队是否满 
Status enQueue(SqQueue &Q,ElemType x);//x入队
Status deQueue(SqQueue &Q,ElemType &x);//出队队顶并赋值给x
int SqQueueLength(SqQueue &Q);//返回队的长度，即元素个数 
void SqQueueTraverse(SqQueue &Q);//遍历顺序队 
void SqQueueDestroy(SqQueue &Q);//销毁顺序队 
*/

/******************主函数验证******************/
int main()
{
	ElemType denum;
	SqQueue Q;
	SqQueueInit(Q);
	cout<<"*1、初始化队列数据为1-5,MAXSIZE为7，队里最多6个数"<<endl;
	for(int i=1;i<6;i++)
	{
		enQueue(Q,i);
	}
	cout<<"#此时队列中数有："<<endl;
	SqQueueTraverse(Q);
	cout<<"#此时队列长度为："<<SqQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*2、向队列中插入数据2019"<<endl;
	enQueue(Q,2019);
	cout<<"#此时队列中数有："<<endl;
	SqQueueTraverse(Q);
	cout<<"#此时队列长度为："<<SqQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*3、队列出队两次"<<endl;
	deQueue(Q,denum);
	deQueue(Q,denum);
	cout<<"#出队的第二个元素为："<<denum<<endl;
	cout<<"#此时队列中数有："<<endl;
	SqQueueTraverse(Q);
	cout<<"#此时队列长度为："<<SqQueueLength(Q)<<endl;
	cout<<endl;
	cout<<"*2、向队列中插入数据11、22，体现循环性"<<endl;
	enQueue(Q,11);enQueue(Q,22);
	cout<<"#此时队列中数有："<<endl;
	SqQueueTraverse(Q);
	cout<<"#此时队列长度为："<<SqQueueLength(Q)<<endl;
	cout<<endl;
	
	cout<<"*2、去除4个元素，向队列中插入6个数据111、222、333、444、，越界"<<endl;
	deQueue(Q,denum);deQueue(Q,denum);
	enQueue(Q,111);enQueue(Q,222);enQueue(Q,333);enQueue(Q,444);
	cout<<"#此时队列中数有："<<endl;
	SqQueueTraverse(Q);
	cout<<endl;
	 
	SqQueueDestroy(Q);
	return 0;
}
