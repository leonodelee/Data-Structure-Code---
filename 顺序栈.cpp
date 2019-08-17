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
	ElemType *data;//��̬����ռ��ַ 
	ElemType top;//ջ��,��¼�����ַ�ľ��룬��������data[top-1] 
	int stackSize;//��ǰ����Ĵ洢�ռ� 
}SqStack; 

/******************��������******************/
Status SqStackInit(SqStack &S);//˳��ջ��ʼ��
bool IsEmpty(SqStack &S);//�ж�˳��ջ�Ƿ�Ϊ�� 
Status GetTop(SqStack &S,ElemType &x);//ȡջ��Ԫ�ظ�ֵ��x
Status Push(SqStack &S,ElemType x);//x��ջ
Status Pop(SqStack &S,ElemType &x);//��ջջ������ֵ��x
int SqStackLength(SqStack S);//����ջ�ĳ��ȣ���Ԫ�ظ��� 
void SqStackTraverse(SqStack S);//����˳��ջ 
void SqStackDestroy(SqStack &S);//����˳��ջ 

/******************����ʵ��******************/
Status SqStackInit(SqStack &S)//˳��ջ��ʼ��
{
	S.data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if(!S.data)
		return ERROR;
	S.top = -1;
	S.stackSize = MAXSIZE;
	return OK;	
} 

bool IsEmpty(SqStack &S)//�ж�˳��ջ�Ƿ�Ϊ�� 
{
	return S.top == -1 ? true : false;
//	if(S.top == -1)
///		return true;
//	return false;
}

Status GetTop(SqStack &S,ElemType &x)//ȡջ��Ԫ�ظ�ֵ��x
{
	//�ж�ջ�Ƿ��
	//if(S.top == -1)
	if(IsEmpty(S)) 
		return ERROR;
	x = S.data[S.top];//�����±�0��ʼ 
	return OK;
}

Status Push(SqStack &S,ElemType x)//x��ջ
{
	//�ж�ջ����̬�����ڴ�
	if(S.top >= S.stackSize)
	{
		S.data = (ElemType *)realloc(S.data,(S.stackSize + INCREASE));
		if(!S.data)
			return ERROR;
	//	S.top = S.data + S.stackSize;
		S.stackSize += INCREASE;
	}
	//�ȼ�һ����ջ����ֵ 
	S.data[++S.top] = x;
	return OK;
}

Status Pop(SqStack &S,ElemType &x)//��ջջ��Ԫ�ز���ֵ��x
{
	//�ж�ջ�ղ� 
	if(IsEmpty(S))
	{
		return ERROR;
	}
	x = S.data[S.top--];//top�ȸ�ֵ�����Լ� 
	return OK;
}

int StackLength(SqStack S)//����ջ�ĳ��ȣ���Ԫ�ظ��� 
{
	return S.top+1;
}
void StackTraverse(SqStack S)//����˳��ջ 
{
	while(S.top != -1)
	{
		cout<<S.data[S.top]<<" ";
		S.top--;
	}
	cout<<endl;
}
void SqStackDestroy(SqStack &S)//����˳��ջ 
{
	free(S.data);
	S.top =  -1;
	S.stackSize = MAXSIZE;
}
/******************��������֤******************/
int main()
{
	SqStack S;
	int topNum,popNum=0;
	 
	SqStackInit(S);//��ʼ��
	cout<<"1����ʼ������1-10 "<<endl;
	for(int i=1;i<11;i++)//��ʼ������1-10 
		Push(S,i); 
	StackTraverse(S); 
	cout<<"*ջ��Ϊ"<<StackLength(S)<<endl; 
	cout<<endl;
	
	GetTop(S,topNum);
	cout<<"2��ȡջ��Ԫ��"<<"*Ϊ��"<<topNum<<endl;
	cout<<endl;
	 
	Pop(S,popNum);
	cout<<"3�����ջ��Ԫ��Ϊ"<<popNum<<endl;
	StackTraverse(S); 
	cout<<"**ջ��Ϊ"<<StackLength(S)<<endl;
	
	SqStackDestroy(S);//ջ���� 
	return 0;
}
