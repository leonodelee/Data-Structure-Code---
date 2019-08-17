#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElemType;  
/***************结构体定义***************/
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

/***************函数定义***************/
LNode *LinkListInit();//链表初始化 
LinkList LinkListCreateH();//链表创建头插法 
LinkList LinkListCreateT();//链表创建尾插法
int LinkListLength();//链表长度
LinkList LinkListInsert(LinkList L,int i,ElemType e);//链表第i个位置插入e
LinkList LinkListDelete(LinkList L,ElemType e);//删除链表中值为e的节点 
void LinkListTraverse(LinkList L);//链表遍历

/***************函数实现***************/
LNode *LinkListInit()//链表初始化
{
	LNode *L = (LNode*)malloc(sizeof(LNode));//申请节点空间
	if(L==NULL)
	{
		cout<<"*申请空间失败"<<endl;	
	}	
	L->next = NULL;
	return L;
} 

LinkList LinkListCreateH()//链表创建头插法
{
	LNode *L;
	L = (LNode *)malloc(sizeof(LNode));//新建头结点
	L->next = NULL;
	ElemType x;
	while(scanf("%d",&x) != EOF)
	{
		LNode *p;
		p = (LNode *)malloc(sizeof(LNode));//创建链表新结点存储数据
		p->data = x;
		p->next = L->next;
		L->next = p;//p成为头结点	
	}	
	return L;
} 

LinkList LinkListCreateT()//链表创建尾插法
{
	LNode *L = (LNode *)malloc(sizeof(LNode));//新建头结点
	L->next = NULL;
	LNode *T = L;//创建尾结点，初始时和头结点重合 
	ElemType x;
	while(scanf("%d",&x) != EOF)
	{
		LNode *p = (LNode *)malloc(sizeof(LNode));//创建新结点来存储数据
		p->data = x;
		T->next	= p;
		T = p;//尾结点更新 
	} 
	T->next = NULL;//尾指针始终指向NULL 
	return L; 
}

int LinkListLength(LinkList L)//链表长度
{
	int length = 0;
	LNode *temp = L;
	while(temp->next != NULL)
	{
		temp = temp->next;
		length++;	
	}	
	return length;
} 
LinkList LinkListInsert(LinkList L,int i,ElemType e)//链表第i个位置插入e
{
	LNode *node = (LNode *)malloc(sizeof(LNode));//创建新结点 
	node->data = e;
	LNode *temp = L;
	//判断插入位置i合法性
	if(i > LinkListLength(L))
	{
		cout<<"*请检查插入位置的合法性"<<endl;
		return NULL;	
	} 
	for(int j=1;j<i;j++)//找到i前一个结点
	{
		temp = temp->next;	
	} 
	node->next = temp->next;
	temp->next = node;
	return L;
}

LinkList LinkListDelete(LinkList L,ElemType e)//删除链表中值为e的节点 
{
	LNode *p = L;
	LNode *pre = L;
	while(p->next != NULL)//遍历至p为尾结点时
	{
		pre = p;//如果没找到，每次更新双指针 
		p = p->next;	
		if(p->data == e)
		{
			if(p->next == NULL)//若是尾结点,pre置空 
			{
				pre = NULL;
				free(p);	
				return L;
			} 
			else
			{
				pre->next = p->next;
				free(p);
				return L;
			}
		}
	} 
}

void LinkListTraverse(LinkList L)//链表遍历
{
	LNode *temp = L->next;//跳过不包含数据的头结点 
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;	
	}	
	cout<<endl;
} 

/***************主函数测试***************/
int main()
{
	LinkList L;
//	L = LinkListCreateH();
	L = LinkListCreateT();
	//L = LinkListTraverse(L);
	cout<<"1此时链表中元素有："<<endl; 
	LinkListTraverse(L);
	cout<<"*此时链表长度为:"<<LinkListLength(L)<<endl; 
	
	LinkListDelete(L,1);
	cout<<"2删除元素1后链表中元素有："<<endl;
	LinkListTraverse(L);
	cout<<"**此时链表长度为:"<<LinkListLength(L)<<endl; 
	
	LinkListInsert(L,3,11); 
	cout<<"3在位置1处增加元素4后链表中元素有："<<endl;
	LinkListTraverse(L);
	 
	cout<<"4如果在位置15处（越界）增加元素15后有："<<endl;
	LinkListInsert(L,15,15);
	LinkListTraverse(L);
	cout<<"***此时链表长度为:"<<LinkListLength(L)<<endl; 
	return 0;
}
