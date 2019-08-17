#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100//初始分配量 
#define INCREASE 10//分配增量 
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
/***************结构体定义***************/
typedef struct 
{
	ElemType *dataBase;//数据基址
	ElemType front,rear;//队头队尾指针；
	int queSize;//当前分配的容量 
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
	Q.dataBase = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
	if(!Q.dataBase)
	{
		printf("#分配内存失败\n");
        return ERROR;
	}
	Q.front = 0;
	Q.rear = 0;
	Q.queSize = MAXSIZE;
	return OK;
}

bool IsEmpty(SqQueue &Q)//判断顺序队是否为空
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

int SqQueueLength(SqQueue &Q)//返回队的长度，即元素个数
{
	return Q.rear-Q.front;
}

Status enQueue(SqQueue &Q,ElemType x)//x入队
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

Status deQueue(SqQueue &Q,ElemType &x)//出队队顶并赋值给x
{
	if(IsEmpty(Q))
	{
		cout<<"#队列为空，出队失败！"<<endl; 
		return ERROR;
	}
	x = Q.dataBase[Q.front];//先进先出
	Q.dataBase[Q.front] = 999; 
	Q.front++;//队头后移 
	return OK; 
} 

void SqQueueTraverse(SqQueue &Q)//遍历顺序队 
{
	int i = Q.front;
	while(i != Q.rear)
	{
		printf("%d ",Q.dataBase[i]);
		i++;
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
Status GetTop(SqQueue &Q,ElemType &x);//取队顶元素赋值给x
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
	cout<<"#空队出队测试："<<endl;
	deQueue(Q,denum);
	cout<<endl;
	 
	cout<<"*1、初始化队列数据为1-10"<<endl;
	for(int i=1;i<11;i++)
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
	
	cout<<"*4、此时队列数组第一个位置数空缺造成浪费(出队时置为999)："<<endl;
	cout<<"Q.dataBase[0]为："<<Q.dataBase[0]<<endl;
	cout<<"Q.dataBase[1]为："<<Q.dataBase[1]<<endl;
	cout<<"Q.dataBase[2]为："<<Q.dataBase[2]<<endl;
	
	
	return 0;
}
