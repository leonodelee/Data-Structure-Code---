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
	ElemType *data;//动态分配空间基址 
	ElemType top;//栈顶,记录距离基址的距离，代表数据data[top-1] 
	int stackSize;//当前分配的存储空间 
}SqStack; 

/******************函数声明******************/
Status SqStackInit(SqStack &S);//顺序栈初始化
bool IsEmpty(SqStack &S);//判断顺序栈是否为空 
Status GetTop(SqStack &S,ElemType &x);//取栈顶元素赋值给x
Status Push(SqStack &S,ElemType x);//x入栈
Status Pop(SqStack &S,ElemType &x);//出栈栈顶并赋值给x
int SqStackLength(SqStack S);//返回栈的长度，即元素个数 
void SqStackTraverse(SqStack S);//遍历顺序栈 
void SqStackDestroy(SqStack &S);//销毁顺序栈 

/******************函数实现******************/
Status SqStackInit(SqStack &S)//顺序栈初始化
{
	S.data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if(!S.data)
		return ERROR;
	S.top = -1;
	S.stackSize = MAXSIZE;
	return OK;	
} 

bool IsEmpty(SqStack &S)//判断顺序栈是否为空 
{
	return S.top == -1 ? true : false;
//	if(S.top == -1)
///		return true;
//	return false;
}

Status GetTop(SqStack &S,ElemType &x)//取栈顶元素赋值给x
{
	//判断栈是否空
	//if(S.top == -1)
	if(IsEmpty(S)) 
		return ERROR;
	x = S.data[S.top];//数组下标0开始 
	return OK;
}

Status Push(SqStack &S,ElemType x)//x入栈
{
	//判断栈满则动态分配内存
	if(S.top >= S.stackSize)
	{
		S.data = (ElemType *)realloc(S.data,(S.stackSize + INCREASE));
		if(!S.data)
			return ERROR;
	//	S.top = S.data + S.stackSize;
		S.stackSize += INCREASE;
	}
	//先加一再入栈并赋值 
	S.data[++S.top] = x;
	return OK;
}

Status Pop(SqStack &S,ElemType &x)//出栈栈顶元素并赋值给x
{
	//判断栈空不 
	if(IsEmpty(S))
	{
		return ERROR;
	}
	x = S.data[S.top--];//top先赋值，再自减 
	return OK;
}

int StackLength(SqStack S)//返回栈的长度，即元素个数 
{
	return S.top+1;
}
void StackTraverse(SqStack S)//遍历顺序栈 
{
	while(S.top != -1)
	{
		cout<<S.data[S.top]<<" ";
		S.top--;
	}
	cout<<endl;
}
void SqStackDestroy(SqStack &S)//销毁顺序栈 
{
	free(S.data);
	S.top =  -1;
	S.stackSize = MAXSIZE;
}
/******************主函数验证******************/
int main()
{
	SqStack S;
	int topNum,popNum=0;
	 
	SqStackInit(S);//初始化
	cout<<"1、初始化输入1-10 "<<endl;
	for(int i=1;i<11;i++)//初始化输入1-10 
		Push(S,i); 
	StackTraverse(S); 
	cout<<"*栈长为"<<StackLength(S)<<endl; 
	cout<<endl;
	
	GetTop(S,topNum);
	cout<<"2、取栈顶元素"<<"*为："<<topNum<<endl;
	cout<<endl;
	 
	Pop(S,popNum);
	cout<<"3、输出栈顶元素为"<<popNum<<endl;
	StackTraverse(S); 
	cout<<"**栈长为"<<StackLength(S)<<endl;
	
	SqStackDestroy(S);//栈销毁 
	return 0;
}
