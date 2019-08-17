#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElemType;  
#define OK 1
#define ERROR 0
#define Status int

/***************结构体定义***************/
typedef struct DLNode
{
	ElemType data;
	struct DLNode *prior,*next;//前后指针结点 
}DLNode,*DLinkList;

/***************函数定义***************/
void DLinkListInit(DLinkList L);//链表初始化 
DLNode *CreateNode(ElemType x);//(双链表节点复杂，单拿出来创建)创建一个数据域为x的结点 
Status DLinkListCreateH(DLinkList L,ElemType x);//链表创建头插法 
Status DLinkListCreateT(DLinkList L,ElemType x);//链表创建尾插法
int DLinkListLength(DLinkList L);//链表长度
Status DLinkListInsert(DLinkList L,int i,ElemType x);//链表第i个位置插入e
Status DLinkListDelete(DLinkList L,ElemType x);//删除链表中值为x的节点 
void DLinkListTraverse(DLinkList L);//链表遍历
Status DLinkListFind(DLinkList L,ElemType x);//寻找链表中值为x的结点 
void DLinkListDestroy(DLinkList L);//链表销毁 
/***************函数实现***************/
void DLinkListInit(DLinkList L)//链表初始化
{
	if(L == NULL)
		return;
	L->prior = NULL;
	L->next = NULL;
} 
DLNode *CreateNode(ElemType x)//(双链表节点复杂，单拿出来创建)创建一个数据域为x的结点 
{
	DLNode *node = (DLNode*)malloc(sizeof(DLNode));
	node->data = x;
	node->next = NULL;
	node->prior = NULL;
	return node;
}

Status DLinkListCreateH(DLinkList L,ElemType x)//链表创建头插法
{
	DLNode *node = CreateNode(x);
	node->next = L->next;
	node->prior = L;
	if(node->next != NULL)//若链表有结点
	{
		node->next->prior = node;	
	} 
	L->next = node;
	return OK;
} 

Status DLinkListCreateT(DLinkList L,ElemType x)//链表创建尾插法
{
	DLNode *node = CreateNode(x);
	DLNode *temp = L;//暂存头结点
	
	while(temp->next != NULL)//链表中寻找表尾需遍历
	{
		temp = temp->next;
	} 
	node->prior = temp;
	temp->next = node;
//	node->next = L;
	return OK;
}

int DLinkListLength(DLinkList L)//链表长度
{
	DLNode *node = L;
	int length=0;
	while(node->next != NULL)
	{
		length++;
		node = node->next; 
	} 
	return length;
}

Status DLinkListInsert(DLinkList L,int i,ElemType x)//链表第i个位置插入e
{
	DLNode *node = (DLNode *)malloc(sizeof(DLNode));
	DLNode *temp = L;
	node->data = x;
	for(int j=i;j>1;j--)//遍历至i-1个结点 
	{
		temp = temp->next;
	} 
	if(i<=0)
	{
		cout<<"请检查插入位置！！"<<endl;
		return ERROR;
	}
	node->next = temp->next;
	node->next->prior = temp;
	temp->next = node;
	node->prior = temp;
	return OK;
}

Status DLinkListDelete(DLinkList L,ElemType x)//删除链表中值为e的节点
{
	DLNode *temp;
	DLNode *p = L->next;
	DLNode *pre = L;
	while(p != NULL)
	{
		if(p->data == x)
		{
			pre->next = p->next;
			p->next->prior = pre;
			temp = p;
			free(p);
		}
		p = p->next;
		pre = pre->next;	
	} 
	return OK;
} 

void DLinkListTraverse(DLinkList L)//链表遍历
{
	DLNode *node = L;
	for(node = L;node->next!=NULL;node=node->next)
	{
		cout<<""<<node->next->data<<" ";
	}
	cout<<endl;
}

Status DLinkListFind(DLinkList L,ElemType x)//寻找链表中值为x的结点，返回位置
{
	DLNode *node = CreateNode(x);
	node = L->next;
	int cnt = 0;
	while(node!=L)
	{
		if(node->data == x)
		{
			return cnt; 
			return OK;
		}
		cnt++;
	}
	return ERROR;
} 

void DLinkListDestroy(DLinkList L)//链表销毁 
{
	if(L->next == NULL)
		return;
	DLNode *temp,*ex;
	while(L != NULL)
	{
		for(temp = L->next;temp->next != NULL;)
		{
			ex = temp;
			temp=temp->next;
			free(ex); 	
		}	
	} 
} 
/*
void DLinkListInit(DLinkList L);//链表初始化 
DLNode *CreateNode(ElemType x);//(双链表节点复杂，单拿出来创建)创建一个数据域为x的结点 
Status DLinkListCreateH(DLinkList L,ElemType x);//链表创建头插法 
Status DLinkListCreateT(DLinkList L,ElemType x);//链表创建尾插法
int DLinkListLength(DLinkList L);//链表长度
Status DLinkListInsert(DLinkList L,int i,ElemType x);//链表第i个位置插入e
Status DLinkListDelete(DLinkList L,ElemType x);//删除链表中值为x的节点 
void DLinkListTraverse(DLinkList L);//链表遍历
Status DLinkListFind(DLinkList L,ElemType x);//寻找链表中值为x的结点 
void DLinkListDestroy(DLinkList L);//链表销毁 
*/

/***************主函数测试***************/
int main()
{
	DLinkList L = (DLinkList )malloc(sizeof(DLNode));
//	DLinkList L;
	DLinkListInit(L);
//	L = LinkListCreateH();
	for(int i=1;i<11;i++)
	{
		DLinkListCreateT(L,i);
	}
	//L = LinkListTraverse(L);
	cout<<"1、初始化链表为1-10，此时链表中元素有："<<endl; 
	DLinkListTraverse(L);
	cout<<"*此时链表长度为:"<<DLinkListLength(L)<<endl; 
	
	DLinkListDelete(L,1);
	cout<<"2、删除元素1后链表中元素有："<<endl;
	DLinkListTraverse(L);
	cout<<"**此时链表长度为:"<<DLinkListLength(L)<<endl; 
	
	DLinkListInsert(L,3,11); 
	cout<<"3、将11插入第3个位置后链表中元素有："<<endl;
	DLinkListTraverse(L);
	cout<<"***此时链表长度为:"<<DLinkListLength(L)<<endl;
	
	cout<<"3、第3个结点(L->next->next->next11)前(node->prior)后(node->next)位置的元素为："<<endl;
	DLNode *node = L->next->next->next;
	cout<<node->prior->data<<" "<<node->next->data<<endl;
	return 0;
}
