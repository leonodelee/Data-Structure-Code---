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
void DLinkListTraverseH(DLinkList L);//链表正序遍历
void DLinkListTraverseT(DLinkList L);//链表倒序遍历
int DLinkListFind(DLinkList L,ElemType x);//寻找链表中值为x的结点 
void DLinkListDestroy(DLinkList L);//链表销毁 

/***************函数实现***************/
void DLinkListInit(DLinkList L)//链表初始化
{
	if(L == NULL)
		return;
 	L->next = L;
	L->prior = L;
//	L->next = L;
//	L->prior = L; 
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
	if(node->next != L)//若链表有结点
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
	
	while(temp->next != L)//链表中寻找表尾需遍历
	{
		temp = temp->next;
	} 
	temp->next = node;
	node->prior = temp;
	node->next = L;
	L->prior = node;
	return OK;
}

int DLinkListLength(DLinkList L)//链表长度
{
	DLNode *node = L;
	int length=0;
	while(node->next != L)
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
	while(p != L)
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

void DLinkListTraverseH(DLinkList L)//链表正序遍历
{
	DLNode *node = L;
	for(node = L;node->next!=L;node=node->next)
	{
		cout<<node->next->data<<" ";
	}
	cout<<endl;
}

void DLinkListTraverseT(DLinkList L)//链表倒序遍历
{
	DLNode *node = L->prior;
	while(node != L)
	{
		cout<<node->data<<" ";
		node=node->prior;
	}
	cout<<endl;
}

int DLinkListFind(DLinkList L,ElemType x)//寻找链表中值为x的结点，返回位置
{
	DLNode *node = CreateNode(x);
	node = L->next;
	int cnt = 1;
	while(node != L)
	{
		if(node->data == x)
		{
			return cnt;
		}
		node = node->next; 
		cnt++;
	}
	return 0;
} 

void DLinkListDestroy(DLinkList L)//链表销毁 
{
	DLNode *p = L->next;
	if(p == L)
		return;
	while(p != L)
	{
		DLNode *ex = p;
		p=p->next;
		free(ex); 	
		ex = NULL;	
	} 
	free(p);
	p = NULL;
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
	int findNum; 
	DLinkListInit(L);
//	L = LinkListCreateH();
	for(int i=1;i<11;i++)
	{
		DLinkListCreateT(L,i);
	}
	//L = LinkListTraverse(L);
	cout<<"1、初始化链表为1-10，此时链表中元素有(正序输出和倒序输出各一次)："<<endl; 
	DLinkListTraverseH(L);
	DLinkListTraverseT(L);
	cout<<"*此时链表长度为:"<<DLinkListLength(L)<<endl; 
	cout<<endl;
	
	DLinkListDelete(L,1);
	cout<<"2、删除元素1后链表中元素有："<<endl;
	DLinkListTraverseH(L);
	cout<<"**此时链表长度为:"<<DLinkListLength(L)<<endl; 
	cout<<endl;
	
	DLinkListInsert(L,3,11); 
	cout<<"3、将11插入第3个位置后链表中元素有："<<endl;
	DLinkListTraverseH(L);
	cout<<"***此时链表长度为:"<<DLinkListLength(L)<<endl;
	cout<<endl;
	
	cout<<"4、第3个结点(L->next->next->next11)前(node->prior)后(node->next)位置的元素为："<<endl;
	DLNode *node = L->next->next->next;
	cout<<node->prior->data<<" "<<node->next->data<<endl;
	cout<<endl;
	
	cout<<"5、11所在的位置为：";
	findNum =DLinkListFind(L,11); 
	cout<<findNum<<endl;
	cout<<endl;
	
	cout<<"6、循环性验证："<<endl;
	cout<<"6.1 头结点的前一个结点数据为："<<L->prior->data<<endl;
	DLNode *node2=L;int n=10;
	while(n--)
	{
		node2=node2->next;
	}
	cout<<"6.2 尾结点的后一个结点(头结点L无数据)的下一个结点的数据为："<<node2->next->next->data<<endl;
	DLinkListDestroy(L);
	return 0;
}
