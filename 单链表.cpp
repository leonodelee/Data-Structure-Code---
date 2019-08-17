#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElemType;  
/***************�ṹ�嶨��***************/
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

/***************��������***************/
LNode *LinkListInit();//�����ʼ�� 
LinkList LinkListCreateH();//������ͷ�巨 
LinkList LinkListCreateT();//������β�巨
int LinkListLength();//������
LinkList LinkListInsert(LinkList L,int i,ElemType e);//�����i��λ�ò���e
LinkList LinkListDelete(LinkList L,ElemType e);//ɾ��������ֵΪe�Ľڵ� 
void LinkListTraverse(LinkList L);//�������

/***************����ʵ��***************/
LNode *LinkListInit()//�����ʼ��
{
	LNode *L = (LNode*)malloc(sizeof(LNode));//����ڵ�ռ�
	if(L==NULL)
	{
		cout<<"*����ռ�ʧ��"<<endl;	
	}	
	L->next = NULL;
	return L;
} 

LinkList LinkListCreateH()//������ͷ�巨
{
	LNode *L;
	L = (LNode *)malloc(sizeof(LNode));//�½�ͷ���
	L->next = NULL;
	ElemType x;
	while(scanf("%d",&x) != EOF)
	{
		LNode *p;
		p = (LNode *)malloc(sizeof(LNode));//���������½��洢����
		p->data = x;
		p->next = L->next;
		L->next = p;//p��Ϊͷ���	
	}	
	return L;
} 

LinkList LinkListCreateT()//������β�巨
{
	LNode *L = (LNode *)malloc(sizeof(LNode));//�½�ͷ���
	L->next = NULL;
	LNode *T = L;//����β��㣬��ʼʱ��ͷ����غ� 
	ElemType x;
	while(scanf("%d",&x) != EOF)
	{
		LNode *p = (LNode *)malloc(sizeof(LNode));//�����½�����洢����
		p->data = x;
		T->next	= p;
		T = p;//β������ 
	} 
	T->next = NULL;//βָ��ʼ��ָ��NULL 
	return L; 
}

int LinkListLength(LinkList L)//������
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
LinkList LinkListInsert(LinkList L,int i,ElemType e)//�����i��λ�ò���e
{
	LNode *node = (LNode *)malloc(sizeof(LNode));//�����½�� 
	node->data = e;
	LNode *temp = L;
	//�жϲ���λ��i�Ϸ���
	if(i > LinkListLength(L))
	{
		cout<<"*�������λ�õĺϷ���"<<endl;
		return NULL;	
	} 
	for(int j=1;j<i;j++)//�ҵ�iǰһ�����
	{
		temp = temp->next;	
	} 
	node->next = temp->next;
	temp->next = node;
	return L;
}

LinkList LinkListDelete(LinkList L,ElemType e)//ɾ��������ֵΪe�Ľڵ� 
{
	LNode *p = L;
	LNode *pre = L;
	while(p->next != NULL)//������pΪβ���ʱ
	{
		pre = p;//���û�ҵ���ÿ�θ���˫ָ�� 
		p = p->next;	
		if(p->data == e)
		{
			if(p->next == NULL)//����β���,pre�ÿ� 
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

void LinkListTraverse(LinkList L)//�������
{
	LNode *temp = L->next;//�������������ݵ�ͷ��� 
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;	
	}	
	cout<<endl;
} 

/***************����������***************/
int main()
{
	LinkList L;
//	L = LinkListCreateH();
	L = LinkListCreateT();
	//L = LinkListTraverse(L);
	cout<<"1��ʱ������Ԫ���У�"<<endl; 
	LinkListTraverse(L);
	cout<<"*��ʱ������Ϊ:"<<LinkListLength(L)<<endl; 
	
	LinkListDelete(L,1);
	cout<<"2ɾ��Ԫ��1��������Ԫ���У�"<<endl;
	LinkListTraverse(L);
	cout<<"**��ʱ������Ϊ:"<<LinkListLength(L)<<endl; 
	
	LinkListInsert(L,3,11); 
	cout<<"3��λ��1������Ԫ��4��������Ԫ���У�"<<endl;
	LinkListTraverse(L);
	 
	cout<<"4�����λ��15����Խ�磩����Ԫ��15���У�"<<endl;
	LinkListInsert(L,15,15);
	LinkListTraverse(L);
	cout<<"***��ʱ������Ϊ:"<<LinkListLength(L)<<endl; 
	return 0;
}
