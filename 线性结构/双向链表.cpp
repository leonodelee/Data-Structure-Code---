#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElemType;  
#define OK 1
#define ERROR 0
#define Status int

/***************�ṹ�嶨��***************/
typedef struct DLNode
{
	ElemType data;
	struct DLNode *prior,*next;//ǰ��ָ���� 
}DLNode,*DLinkList;

/***************��������***************/
void DLinkListInit(DLinkList L);//�����ʼ�� 
DLNode *CreateNode(ElemType x);//(˫����ڵ㸴�ӣ����ó�������)����һ��������Ϊx�Ľ�� 
Status DLinkListCreateH(DLinkList L,ElemType x);//������ͷ�巨 
Status DLinkListCreateT(DLinkList L,ElemType x);//������β�巨
int DLinkListLength(DLinkList L);//������
Status DLinkListInsert(DLinkList L,int i,ElemType x);//�����i��λ�ò���e
Status DLinkListDelete(DLinkList L,ElemType x);//ɾ��������ֵΪx�Ľڵ� 
void DLinkListTraverse(DLinkList L);//�������
Status DLinkListFind(DLinkList L,ElemType x);//Ѱ��������ֵΪx�Ľ�� 
void DLinkListDestroy(DLinkList L);//�������� 
/***************����ʵ��***************/
void DLinkListInit(DLinkList L)//�����ʼ��
{
	if(L == NULL)
		return;
	L->prior = NULL;
	L->next = NULL;
} 
DLNode *CreateNode(ElemType x)//(˫����ڵ㸴�ӣ����ó�������)����һ��������Ϊx�Ľ�� 
{
	DLNode *node = (DLNode*)malloc(sizeof(DLNode));
	node->data = x;
	node->next = NULL;
	node->prior = NULL;
	return node;
}

Status DLinkListCreateH(DLinkList L,ElemType x)//������ͷ�巨
{
	DLNode *node = CreateNode(x);
	node->next = L->next;
	node->prior = L;
	if(node->next != NULL)//�������н��
	{
		node->next->prior = node;	
	} 
	L->next = node;
	return OK;
} 

Status DLinkListCreateT(DLinkList L,ElemType x)//������β�巨
{
	DLNode *node = CreateNode(x);
	DLNode *temp = L;//�ݴ�ͷ���
	
	while(temp->next != NULL)//������Ѱ�ұ�β�����
	{
		temp = temp->next;
	} 
	node->prior = temp;
	temp->next = node;
//	node->next = L;
	return OK;
}

int DLinkListLength(DLinkList L)//������
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

Status DLinkListInsert(DLinkList L,int i,ElemType x)//�����i��λ�ò���e
{
	DLNode *node = (DLNode *)malloc(sizeof(DLNode));
	DLNode *temp = L;
	node->data = x;
	for(int j=i;j>1;j--)//������i-1����� 
	{
		temp = temp->next;
	} 
	if(i<=0)
	{
		cout<<"�������λ�ã���"<<endl;
		return ERROR;
	}
	node->next = temp->next;
	node->next->prior = temp;
	temp->next = node;
	node->prior = temp;
	return OK;
}

Status DLinkListDelete(DLinkList L,ElemType x)//ɾ��������ֵΪe�Ľڵ�
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

void DLinkListTraverse(DLinkList L)//�������
{
	DLNode *node = L;
	for(node = L;node->next!=NULL;node=node->next)
	{
		cout<<""<<node->next->data<<" ";
	}
	cout<<endl;
}

Status DLinkListFind(DLinkList L,ElemType x)//Ѱ��������ֵΪx�Ľ�㣬����λ��
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

void DLinkListDestroy(DLinkList L)//�������� 
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
void DLinkListInit(DLinkList L);//�����ʼ�� 
DLNode *CreateNode(ElemType x);//(˫����ڵ㸴�ӣ����ó�������)����һ��������Ϊx�Ľ�� 
Status DLinkListCreateH(DLinkList L,ElemType x);//������ͷ�巨 
Status DLinkListCreateT(DLinkList L,ElemType x);//������β�巨
int DLinkListLength(DLinkList L);//������
Status DLinkListInsert(DLinkList L,int i,ElemType x);//�����i��λ�ò���e
Status DLinkListDelete(DLinkList L,ElemType x);//ɾ��������ֵΪx�Ľڵ� 
void DLinkListTraverse(DLinkList L);//�������
Status DLinkListFind(DLinkList L,ElemType x);//Ѱ��������ֵΪx�Ľ�� 
void DLinkListDestroy(DLinkList L);//�������� 
*/

/***************����������***************/
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
	cout<<"1����ʼ������Ϊ1-10����ʱ������Ԫ���У�"<<endl; 
	DLinkListTraverse(L);
	cout<<"*��ʱ������Ϊ:"<<DLinkListLength(L)<<endl; 
	
	DLinkListDelete(L,1);
	cout<<"2��ɾ��Ԫ��1��������Ԫ���У�"<<endl;
	DLinkListTraverse(L);
	cout<<"**��ʱ������Ϊ:"<<DLinkListLength(L)<<endl; 
	
	DLinkListInsert(L,3,11); 
	cout<<"3����11�����3��λ�ú�������Ԫ���У�"<<endl;
	DLinkListTraverse(L);
	cout<<"***��ʱ������Ϊ:"<<DLinkListLength(L)<<endl;
	
	cout<<"3����3�����(L->next->next->next11)ǰ(node->prior)��(node->next)λ�õ�Ԫ��Ϊ��"<<endl;
	DLNode *node = L->next->next->next;
	cout<<node->prior->data<<" "<<node->next->data<<endl;
	return 0;
}
