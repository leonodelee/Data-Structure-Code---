//顺序二叉树
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
typedef ElemType SqBiTree[MAXSIZE]; //定义顺序存储二叉树的结构数组
#define ClearBiTree InitBiTree 
/***************结构体定义***************/
typedef struct
{
	int level;//结点的层 
	int order;//本层序号 
}position;
typedef int QElemType;

/***************函数定义***************/
Status InitBiTree(BiTree &T);//二叉树初始化
Status CreateBiTree(BiTree T);//创建二叉树
bool BiTreeEmpty(BiTree &T);//判断二叉树是否为空
int BiTreeDepth(BiTree &T);//求树的深度
int BiTreeRoot(SqBiTree T);//返回根节点 
void Visit(ElemType e);//打印某一结点
void PreOrderTraverse(BiTree &T);//二叉树递归先序遍历 
void InOrderTraverse(BiTree &T);//二叉树递归中序遍历
void PostOrderTraverse(BiTree &T);//二叉树递归后序遍历
int CountLeaf1(BiTree &T);//计算叶子结点数
int CountLeaf2(BiTree &T);//计算叶子结点数
int CountNode(BiTree T);//计算结点数 
int max(int a,int b);//返回较大值
ElemType Parent(BiTree &T,ElemType e);//求父节点的值
BiTree FindNode(BiTree &T,ElemType e);//寻找某个结点，返回指向这个节点的指针
void LeafSibling(BiTree &T,ElemType e);//输出某个结点的左兄弟
void RightSibling(BiTree &T,ElemType e);//输出某个结点的右兄弟 
 
Status levelTraverse(BiTree T);//二叉树层次遍历
Status preOrderTraverseEX(BiTree T);//先序遍历非递归
Status InOrderTraverseEX(BiTree T);//中序遍历非递归
Status PostOrderTraverseEX(BiTree T);//后序遍历非递归
Status DestroyBiTree(BiTree T);//二叉树销毁 

/***************函数实现***************/
void InitBiTree(BiTree &T)//二叉树初始化
{
	T = NULL;
}

void CreateBiTree(BiTree T)//递归创建二叉树， 
{
	ElemType ch;
//	cin>>ch;
	scanf("%c",&ch);
	if(ch == '#')
		T = NULL;
	else
	{
		cout<<"126511"<<endl;
		T = (BiTNode *)malloc(sizeof(BiTNode));//创建新结点加入树 
		if(!T)
			return;	
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

bool BiTreeEmpty(BiTree &T)//判断二叉树是否为空
{
	if(T)
		return false;
	return true;
}

int BiTreeDepth(BiTree &T)//求树的深度
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
	return lDepth > rDepth ? lDepth+1 : rDepth+1;//二叉树深度为左右子树深度较大值加1 
}

void Visit(ElemType e)//打印某一结点
{
	cout<<e<<" ";
}

void PreOrderTraverse(BiTree &T)//二叉树递归先序遍历
{
	if(T)
	{
		Visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);	
	} 
} 

void InOrderTraverse(BiTree &T)//二叉树递归中序遍历
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		Visit(T->data);
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree &T)//二叉树递归后序遍历
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		Visit(T->data);
	}
}

int CountLeaf1(BiTree &T)//计算叶子结点数
{
	int count=0;
	if(T)
	{
		if((T->lchild == NULL) && (T->rchild == NULL))//判断是否为叶子结点 
		{
			count++;	
		}	
		CountLeaf1(T->lchild);
		CountLeaf1(T->rchild);
	}	
	return count;
}
int CountLeaf2(BiTree &T)//计算叶子结点数
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

int CountNode(BiTree T)//计算结点数
{
	if(T == NULL)
		return 0;
	return CountNode(T->lchild)+CountNode(T->rchild);
}

int max(int a,int b)//返回较大值
{
	return a > b ? a : b;	
}

ElemType Parent(BiTree &T,ElemType e)//求父节点的值
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
	return ' ';//失败返回空字符 
}

BiTree FindNode(BiTree &T,ElemType e)//寻找某个结点，返回指向这个节点的指针
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

void LeafSibling(BiTree &T,ElemType e)//输出某个结点的左兄弟
{
	ElemType ch = Parent(T,e);//找到父节点
	BiTree temp = FindNode(T,ch);
	if(temp->lchild != NULL)
	{
		if(temp->lchild->data != e)
		{
			cout<<"此节点的左兄弟为："<<temp->lchild->data<<endl;	
		}	
		else
		{
			cout<<"此节点没有左兄弟"<<endl;
		}
	} 
}
void RightSibling(BiTree &T,ElemType e)//输出某个结点的右兄弟
{
	ElemType ch = Parent(T,e);
	BiTree temp = FindNode(T,ch);
	if(temp->rchild != NULL)
	{
		if(temp->rchild->data != e)
		{
			cout<<"此节点的右兄弟为："<<temp->rchild->data<<endl;
		}
		else
		{
			cout<<"此节点没有右兄弟"<<endl;
		}
	}	
} 
Status DestroyBiTree(BiTree T)//二叉树递归销毁
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
void InitBiTree(BiTree &T);//二叉树初始化
Status CreateBiTree(BiTree &T);//创建二叉树
bool BiTreeEmpty(BiTree &T);//判断二叉树是否为空
int BiTreeDepth(BiTree &T);//求树的深度
void Visit(ElemType e);//打印某一结点
void PreOrderTraverse(BiTree &T);//二叉树递归先序遍历 
void InOrderTraverse(BiTree &T);//二叉树递归中序遍历
void PostOrderTraverse(BiTree &T);//二叉树递归后序遍历
int CountLeaf(BiTree &T);//计算叶子结点数
int max(int a,int b);//返回较大值
ElemType Parent(BiTree &T,ElemType e);//求父节点的值
BiTree FindNode(BiTree &T,ElemType e);//寻找某个结点，返回指向这个节点的指针
void LeafSibling(BiTree &T,ElemType e);//输出某个结点的左兄弟
void RightSibling(BiTree &T,ElemType e);//输出某个结点的右兄弟 
*/ 

/***************主函数测试***************/
int main()
{
	BiTree T;
	InitBiTree(T);
	cout<<"00000000"<<endl;
	cout<<"*请输入树的结点，#结束："<<endl;
	CreateBiTree(T);
	cout<<"6666666"<<endl;
	cout<<"*遍历为："<<endl;
	PreOrderTraverse(T); 
	InOrderTraverse(T);
	PostOrderTraverse(T);
	return 0;
}
