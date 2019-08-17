//˳�������
//https://www.cnblogs.com/liuzeyu12a/p/10420665.html 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXSIZE 100
typedef char ElemType;
typedef int Status; 
#define OK 1
#define ERROR 0
#define Nil ''
typedef ElemType SqBiTree[MAXSIZE]; //����˳��洢�������Ľṹ����
#define ClearBiTree InitBiTree 
/***************�ṹ�嶨��***************/
typedef struct
{
	int level;//���Ĳ� 
	int order;//������� 
}position;
typedef int QElemType;

/***************��������***************/
Status InitBiTree(BiTree &T);//��������ʼ��
Status CreateBiTree(BiTree T);//����������
bool BiTreeEmpty(BiTree &T);//�ж϶������Ƿ�Ϊ��
int BiTreeDepth(BiTree &T);//���������
int BiTreeRoot(SqBiTree T);//���ظ��ڵ� 
void Visit(ElemType e);//��ӡĳһ���
void PreOrderTraverse(BiTree &T);//�������ݹ�������� 
void InOrderTraverse(BiTree &T);//�������ݹ��������
void PostOrderTraverse(BiTree &T);//�������ݹ�������
int CountLeaf1(BiTree &T);//����Ҷ�ӽ����
int CountLeaf2(BiTree &T);//����Ҷ�ӽ����
int CountNode(BiTree T);//�������� 
int max(int a,int b);//���ؽϴ�ֵ
ElemType Parent(BiTree &T,ElemType e);//�󸸽ڵ��ֵ
BiTree FindNode(BiTree &T,ElemType e);//Ѱ��ĳ����㣬����ָ������ڵ��ָ��
void LeafSibling(BiTree &T,ElemType e);//���ĳ���������ֵ�
void RightSibling(BiTree &T,ElemType e);//���ĳ���������ֵ� 
 
Status levelTraverse(BiTree T);//��������α���
Status preOrderTraverseEX(BiTree T);//��������ǵݹ�
Status InOrderTraverseEX(BiTree T);//��������ǵݹ�
Status PostOrderTraverseEX(BiTree T);//��������ǵݹ�
Status DestroyBiTree(BiTree T);//���������� 

/***************����ʵ��***************/
void InitBiTree(BiTree &T)//��������ʼ��
{
	T = NULL;
}

void CreateBiTree(BiTree T)//�ݹ鴴���������� 
{
	ElemType ch;
//	cin>>ch;
	scanf("%c",&ch);
	if(ch == '#')
		T = NULL;
	else
	{
		cout<<"126511"<<endl;
		T = (BiTNode *)malloc(sizeof(BiTNode));//�����½������� 
		if(!T)
			return;	
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

bool BiTreeEmpty(BiTree &T)//�ж϶������Ƿ�Ϊ��
{
	if(T)
		return false;
	return true;
}

int BiTreeDepth(BiTree &T)//���������
{
	int lDepth,rDepth;
	if(BiTreeEmpty(T))
		return ERROR;
	if(T->lchild)
		lDepth = BiTreeDepth(T->lchild);
	else
		lDepth = 0;
	if(T->rchild)
		rDepth = BiTreeDepth(T->rchild);
	else
		rDepth = 0;
	return lDepth > rDepth ? lDepth+1 : rDepth+1;//���������Ϊ����������Ƚϴ�ֵ��1 
}

void Visit(ElemType e)//��ӡĳһ���
{
	cout<<e<<" ";
}

void PreOrderTraverse(BiTree &T)//�������ݹ��������
{
	if(T)
	{
		Visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);	
	} 
} 

void InOrderTraverse(BiTree &T)//�������ݹ��������
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		Visit(T->data);
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree &T)//�������ݹ�������
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		Visit(T->data);
	}
}

int CountLeaf1(BiTree &T)//����Ҷ�ӽ����
{
	int count=0;
	if(T)
	{
		if((T->lchild == NULL) && (T->rchild == NULL))//�ж��Ƿ�ΪҶ�ӽ�� 
		{
			count++;	
		}	
		CountLeaf1(T->lchild);
		CountLeaf1(T->rchild);
	}	
	return count;
}
int CountLeaf2(BiTree &T)//����Ҷ�ӽ����
{
	if(T == NULL)
		return 0;
	if(T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
	{
		return CountLeaf2(T->lchild)+CountLeaf2(T->rchild);
	}
}

int CountNode(BiTree T)//��������
{
	if(T == NULL)
		return 0;
	return CountNode(T->lchild)+CountNode(T->rchild);
}

int max(int a,int b)//���ؽϴ�ֵ
{
	return a > b ? a : b;	
}

ElemType Parent(BiTree &T,ElemType e)//�󸸽ڵ��ֵ
{
	if(T)
	{
		if( T->lchild && (T->lchild->data == e) || T->rchild && (T->rchild->data == e) )
			return T->data;
		else
		{
			Parent(T->lchild,e);
			Parent(T->rchild,e);
		}
	}
	return ' ';//ʧ�ܷ��ؿ��ַ� 
}

BiTree FindNode(BiTree &T,ElemType e)//Ѱ��ĳ����㣬����ָ������ڵ��ָ��
{
	if(T == NULL)
		return NULL;
	if(T->data == e)
		return T;
	BiTree node = FindNode(T->lchild,e);
	if(node != NULL)
		return node;
	else
		return FindNode(T->rchild,e);
}

void LeafSibling(BiTree &T,ElemType e)//���ĳ���������ֵ�
{
	ElemType ch = Parent(T,e);//�ҵ����ڵ�
	BiTree temp = FindNode(T,ch);
	if(temp->lchild != NULL)
	{
		if(temp->lchild->data != e)
		{
			cout<<"�˽ڵ�����ֵ�Ϊ��"<<temp->lchild->data<<endl;	
		}	
		else
		{
			cout<<"�˽ڵ�û�����ֵ�"<<endl;
		}
	} 
}
void RightSibling(BiTree &T,ElemType e)//���ĳ���������ֵ�
{
	ElemType ch = Parent(T,e);
	BiTree temp = FindNode(T,ch);
	if(temp->rchild != NULL)
	{
		if(temp->rchild->data != e)
		{
			cout<<"�˽ڵ�����ֵ�Ϊ��"<<temp->rchild->data<<endl;
		}
		else
		{
			cout<<"�˽ڵ�û�����ֵ�"<<endl;
		}
	}	
} 
Status DestroyBiTree(BiTree T)//�������ݹ�����
{
	BiTNode *TL = NULL,*TR = NULL;
	if(T == NULL)
		return 0;
	TL = T->lchild;
	TR = T->rchild;
	T->lchild = NULL;
	T->rchild = NULL;
	free(T);
	T = NULL;
	DestroyBiTree(TL);
	DestroyBiTree(TR);
	return OK;
} 

/*
void InitBiTree(BiTree &T);//��������ʼ��
Status CreateBiTree(BiTree &T);//����������
bool BiTreeEmpty(BiTree &T);//�ж϶������Ƿ�Ϊ��
int BiTreeDepth(BiTree &T);//���������
void Visit(ElemType e);//��ӡĳһ���
void PreOrderTraverse(BiTree &T);//�������ݹ�������� 
void InOrderTraverse(BiTree &T);//�������ݹ��������
void PostOrderTraverse(BiTree &T);//�������ݹ�������
int CountLeaf(BiTree &T);//����Ҷ�ӽ����
int max(int a,int b);//���ؽϴ�ֵ
ElemType Parent(BiTree &T,ElemType e);//�󸸽ڵ��ֵ
BiTree FindNode(BiTree &T,ElemType e);//Ѱ��ĳ����㣬����ָ������ڵ��ָ��
void LeafSibling(BiTree &T,ElemType e);//���ĳ���������ֵ�
void RightSibling(BiTree &T,ElemType e);//���ĳ���������ֵ� 
*/ 

/***************����������***************/
int main()
{
	BiTree T;
	InitBiTree(T);
	cout<<"00000000"<<endl;
	cout<<"*���������Ľ�㣬#������"<<endl;
	CreateBiTree(T);
	cout<<"6666666"<<endl;
	cout<<"*����Ϊ��"<<endl;
	PreOrderTraverse(T); 
	InOrderTraverse(T);
	PostOrderTraverse(T);
	return 0;
}
