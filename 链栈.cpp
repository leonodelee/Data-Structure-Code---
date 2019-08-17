#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define ElemType int
#define Status int 
#define OK 1
#define ERROR 0 
/***************�ṹ�嶨��***************/
//ָ�������ݽṹ 
typedef struct StackNode
{
	ElemType data;//����
	struct StackNode *next;//ָ����һ������ָ���� 
}StackNode,*LinkStackPtr;
//��ջ���ݽṹ 
typedef struct LinkStack
{
	int length;//ջ�Ĵ�С
	LinkStackPtr top;//ջ��Ԫ�� 
}LinkStack;

/******************��������******************/
Status LinkStackInit(LinkStack &S);//��ջ��ʼ��
//LinkStack *LinkStackInit();//��ջ��ʼ��
Status IsEmpty(LinkStack &S);//�ж���ջ�Ƿ�Ϊ�� 
Status GetTop(LinkStack &S,ElemType &x);//ȡջ��Ԫ�ظ�ֵ��x
Status Push(LinkStack &S,ElemType x);//x��ջ
Status Pop(LinkStack &S,ElemType &x);//��ջջ������ֵ��x
int LinkStackLength(LinkStack S);//����ջ�ĳ��ȣ���Ԫ�ظ��� 
void LinkStackTraverse(LinkStack &S);//������ջ 
Status LinkStackDestroy(LinkStack &S);//������ջ 

/******************����ʵ��******************/
Status LinkStackInit(LinkStack &S)
{
	S.top = (StackNode *)malloc(sizeof(StackNode));
	if(S.top==NULL)
	{
		cout<<"*����ռ�ʧ��"<<endl;
		return ERROR;	
	}
	S.top->next = NULL;
	S.top->data = 999;//��ͷ���Ļ��������� 
	S.length = 0;
	return OK;
}
/*
LinkStack *LinkStackInit()//��ջ��ʼ��
{
	LinkStack *S = (LinkStack *)malloc(sizeof(LinkStack));
	S->top = NULL;
	S->length = 0;
	return S;
}
*/
Status IsEmpty(LinkStack &S)//�ж���ջ�Ƿ�Ϊ�� 
{
	if(S.length > 0)
		return ERROR;
	return OK;
}

Status GetTop(LinkStack &S,ElemType &x)//ȡջ��Ԫ�ظ�ֵ��x
{
	if(IsEmpty(S))
	{
		 return ERROR;
	}
	x = S.top->data;//ȡջ��Ԫ��
	return OK;
}

Status Push(LinkStack &S,ElemType x)//x��ջ
{
	LinkStackPtr newnode = (LinkStackPtr)malloc(sizeof(StackNode));//�������洢���� 
	newnode->data = x;
	newnode->next = S.top;//ͷ�巨 
	S.top = newnode;//����ջ�� 
	S.length++;
	return OK;
}

Status Pop(LinkStack &S,ElemType &x)//��ջջ������ֵ��x
{
	if(IsEmpty(S))
	{
		return ERROR;
	}
	x = S.top->data;
	LinkStackPtr temp = S.top;;//��¼��ջ�Ľ��
	S.top = S.top->next;
	free(temp);//�ͷų�ջ�����ռ�ռ�
	S.length--;
	return OK; 
} 

int LinkStackLength(LinkStack S)//����ջ�ĳ��ȣ���Ԫ�ظ���
{
	if(!IsEmpty(S))
		return S.length;
	return 0;	
} 

void LinkStackTraverse(LinkStack &S)//������ջ
{
	LinkStackPtr H = S.top;//����ָ��
	while(H->next)
	{
		cout<<H->data<<" ";
		H=H->next;
	}
	cout<<endl;	
} 
Status LinkStackDestroy(LinkStack &S)//������ջ
{
	LinkStackPtr temp;//��¼Ҫɾ���Ľ�� 
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
Status LinkStackInit(LinkStack &S);//��ջ��ʼ��
Status IsEmpty(LinkStack &S);//�ж���ջ�Ƿ�Ϊ�� 
Status GetTop(LinkStack &S,ElemType &x);//ȡջ��Ԫ�ظ�ֵ��x
Status Push(LinkStack &S,ElemType x);//x��ջ
Status Pop(LinkStack &S,ElemType &x);//��ջջ������ֵ��x
int LinkStackLength(LinkStack S);//����ջ�ĳ��ȣ���Ԫ�ظ��� 
void LinkStackTraverse(LinkStack S);//������ջ 
ElemType LinkStackDestroy(LinkStack &S);//������ջ 
*/

/******************��������֤******************/
int main()
{
	LinkStack S;
	int topNum,popNum;
	LinkStackInit(S);
	cout<<"1����ʼ����ջ����Ϊ1-10"<<endl; 
	for(int i=1;i<11;i++)
		Push(S,i);
	cout<<"#��ǰջ��Ԫ��Ϊ��"<<endl;
	LinkStackTraverse(S);
	cout<<"#��ǰջ��Ԫ�ظ���Ϊ��"<<LinkStackLength(S)<<endl;
	cout<<endl;
	
	GetTop(S,topNum);
	cout<<"2����ǰջ��Ԫ��Ϊ��"<<topNum<<endl;
	cout<<endl;
	
	cout<<"3����������ջ��Ԫ��"<<endl;
	Pop(S,popNum);
	cout<<"#���е�һ��Ϊ��"<<popNum<<endl;
	Pop(S,popNum);
	cout<<"#���еڶ���Ϊ��"<<popNum<<endl;
	cout<<endl; 
	cout<<"3����ǰջ��Ԫ��Ϊ��"<<endl;
	LinkStackTraverse(S);
	GetTop(S,topNum);
	cout<<"#��ǰջ��Ԫ��Ϊ��"<<topNum<<endl;
	cout<<"#��ǰջ��Ԫ�ظ���Ϊ��"<<LinkStackLength(S)<<endl;
	return 0;
}
