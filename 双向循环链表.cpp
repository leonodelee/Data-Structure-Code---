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
void DLinkListTraverseH(DLinkList L);//�����������
void DLinkListTraverseT(DLinkList L);//���������
int DLinkListFind(DLinkList L,ElemType x);//Ѱ��������ֵΪx�Ľ�� 
void DLinkListDestroy(DLinkList L);//�������� 

/***************����ʵ��***************/
void DLinkListInit(DLinkList L)//�����ʼ��
{
	if(L == NULL)
		return;
 	L->next = L;
	L->prior = L;
//	L->next = L;
//	L->prior = L; 
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
	if(node->next != L)//�������н��
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
	
	while(temp->next != L)//������Ѱ�ұ�β�����
	{
		temp = temp->next;
	} 
	temp->next = node;
	node->prior = temp;
	node->next = L;
	L->prior = node;
	return OK;
}

int DLinkListLength(DLinkList L)//������
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

void DLinkListTraverseH(DLinkList L)//�����������
{
	DLNode *node = L;
	for(node = L;node->next!=L;node=node->next)
	{
		cout<<node->next->data<<" ";
	}
	cout<<endl;
}

void DLinkListTraverseT(DLinkList L)//���������
{
	DLNode *node = L->prior;
	while(node != L)
	{
		cout<<node->data<<" ";
		node=node->prior;
	}
	cout<<endl;
}

int DLinkListFind(DLinkList L,ElemType x)//Ѱ��������ֵΪx�Ľ�㣬����λ��
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

void DLinkListDestroy(DLinkList L)//�������� 
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
	int findNum; 
	DLinkListInit(L);
//	L = LinkListCreateH();
	for(int i=1;i<11;i++)
	{
		DLinkListCreateT(L,i);
	}
	//L = LinkListTraverse(L);
	cout<<"1����ʼ������Ϊ1-10����ʱ������Ԫ����(��������͵��������һ��)��"<<endl; 
	DLinkListTraverseH(L);
	DLinkListTraverseT(L);
	cout<<"*��ʱ������Ϊ:"<<DLinkListLength(L)<<endl; 
	cout<<endl;
	
	DLinkListDelete(L,1);
	cout<<"2��ɾ��Ԫ��1��������Ԫ���У�"<<endl;
	DLinkListTraverseH(L);
	cout<<"**��ʱ������Ϊ:"<<DLinkListLength(L)<<endl; 
	cout<<endl;
	
	DLinkListInsert(L,3,11); 
	cout<<"3����11�����3��λ�ú�������Ԫ���У�"<<endl;
	DLinkListTraverseH(L);
	cout<<"***��ʱ������Ϊ:"<<DLinkListLength(L)<<endl;
	cout<<endl;
	
	cout<<"4����3�����(L->next->next->next11)ǰ(node->prior)��(node->next)λ�õ�Ԫ��Ϊ��"<<endl;
	DLNode *node = L->next->next->next;
	cout<<node->prior->data<<" "<<node->next->data<<endl;
	cout<<endl;
	
	cout<<"5��11���ڵ�λ��Ϊ��";
	findNum =DLinkListFind(L,11); 
	cout<<findNum<<endl;
	cout<<endl;
	
	cout<<"6��ѭ������֤��"<<endl;
	cout<<"6.1 ͷ����ǰһ���������Ϊ��"<<L->prior->data<<endl;
	DLNode *node2=L;int n=10;
	while(n--)
	{
		node2=node2->next;
	}
	cout<<"6.2 β���ĺ�һ�����(ͷ���L������)����һ����������Ϊ��"<<node2->next->next->data<<endl;
	DLinkListDestroy(L);
	return 0;
}
