#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define ElemType int
#define Status int 
#define OK 1
#define ERROR 0 
/***************结构体定义***************/
//指针结点数据结构 
typedef struct StackNode
{
	ElemType data;//数据
	struct StackNode *next;//指向下一个结点的指针域 
}StackNode,*LinkStackPtr;
//链栈数据结构 
typedef struct LinkStack
{
	int length;//栈的大小
	LinkStackPtr top;//栈顶元素 
}LinkStack;

/******************函数声明******************/
Status LinkStackInit(LinkStack &S);//链栈初始化
//LinkStack *LinkStackInit();//链栈初始化
Status IsEmpty(LinkStack &S);//判断链栈是否为空 
Status GetTop(LinkStack &S,ElemType &x);//取栈顶元素赋值给x
Status Push(LinkStack &S,ElemType x);//x入栈
Status Pop(LinkStack &S,ElemType &x);//出栈栈顶并赋值给x
int LinkStackLength(LinkStack S);//返回栈的长度，即元素个数 
void LinkStackTraverse(LinkStack &S);//遍历链栈 
Status LinkStackDestroy(LinkStack &S);//销毁链栈 

/******************函数实现******************/
Status LinkStackInit(LinkStack &S)
{
	S.top = (StackNode *)malloc(sizeof(StackNode));
	if(S.top==NULL)
	{
		cout<<"*申请空间失败"<<endl;
		return ERROR;	
	}
	S.top->next = NULL;
	S.top->data = 999;//带头结点的话不存数据 
	S.length = 0;
	return OK;
}
/*
LinkStack *LinkStackInit()//链栈初始化
{
	LinkStack *S = (LinkStack *)malloc(sizeof(LinkStack));
	S->top = NULL;
	S->length = 0;
	return S;
}
*/
Status IsEmpty(LinkStack &S)//判断链栈是否为空 
{
	if(S.length > 0)
		return ERROR;
	return OK;
}

Status GetTop(LinkStack &S,ElemType &x)//取栈顶元素赋值给x
{
	if(IsEmpty(S))
	{
		 return ERROR;
	}
	x = S.top->data;//取栈顶元素
	return OK;
}

Status Push(LinkStack &S,ElemType x)//x入栈
{
	LinkStackPtr newnode = (LinkStackPtr)malloc(sizeof(StackNode));//创建结点存储数据 
	newnode->data = x;
	newnode->next = S.top;//头插法 
	S.top = newnode;//更新栈顶 
	S.length++;
	return OK;
}

Status Pop(LinkStack &S,ElemType &x)//出栈栈顶并赋值给x
{
	if(IsEmpty(S))
	{
		return ERROR;
	}
	x = S.top->data;
	LinkStackPtr temp = S.top;;//记录出栈的结点
	S.top = S.top->next;
	free(temp);//释放出栈结点所占空间
	S.length--;
	return OK; 
} 

int LinkStackLength(LinkStack S)//返回栈的长度，即元素个数
{
	if(!IsEmpty(S))
		return S.length;
	return 0;	
} 

void LinkStackTraverse(LinkStack &S)//遍历链栈
{
	LinkStackPtr H = S.top;//遍历指针
	while(H->next)
	{
		cout<<H->data<<" ";
		H=H->next;
	}
	cout<<endl;	
} 
Status LinkStackDestroy(LinkStack &S)//销毁链栈
{
	LinkStackPtr temp;//记录要删除的结点 
	while(!IsEmpty(S))
	{
		temp = S.top;
		S.top = S.top->next;
		free(temp);
		S.length--; 
	}
//	free(S);
	return OK;
} 
/*
Status LinkStackInit(LinkStack &S);//链栈初始化
Status IsEmpty(LinkStack &S);//判断链栈是否为空 
Status GetTop(LinkStack &S,ElemType &x);//取栈顶元素赋值给x
Status Push(LinkStack &S,ElemType x);//x入栈
Status Pop(LinkStack &S,ElemType &x);//出栈栈顶并赋值给x
int LinkStackLength(LinkStack S);//返回栈的长度，即元素个数 
void LinkStackTraverse(LinkStack S);//遍历链栈 
ElemType LinkStackDestroy(LinkStack &S);//销毁链栈 
*/

/******************主函数验证******************/
int main()
{
	LinkStack S;
	int topNum,popNum;
	LinkStackInit(S);
	cout<<"1、初始化链栈数据为1-10"<<endl; 
	for(int i=1;i<11;i++)
		Push(S,i);
	cout<<"#当前栈中元素为："<<endl;
	LinkStackTraverse(S);
	cout<<"#当前栈中元素个数为："<<LinkStackLength(S)<<endl;
	cout<<endl;
	
	GetTop(S,topNum);
	cout<<"2、当前栈顶元素为："<<topNum<<endl;
	cout<<endl;
	
	cout<<"3、弹出两个栈顶元素"<<endl;
	Pop(S,popNum);
	cout<<"#其中第一个为："<<popNum<<endl;
	Pop(S,popNum);
	cout<<"#其中第二个为："<<popNum<<endl;
	cout<<endl; 
	cout<<"3、当前栈中元素为："<<endl;
	LinkStackTraverse(S);
	GetTop(S,topNum);
	cout<<"#当前栈顶元素为："<<topNum<<endl;
	cout<<"#当前栈中元素个数为："<<LinkStackLength(S)<<endl;
	return 0;
}
