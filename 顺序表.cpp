#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100//��ʼ����С 
#define INCREASE 10//����ʱ�������С 
//typedef int ElemType
#define ElemType int 

/***************�ṹ�嶨��***************/
typedef struct
{
	ElemType *data;//�洢���ݻ�ַ 
	int length;//��ǰ˳�����
	int listSize;//��ǰ����Ĵ洢���� 
}SqList;

/******************��������******************/
ElemType ListInit_Sq(SqList &L);//˳����ʼ��
ElemType ListLength_Sq(SqList &L);//˳�����
ElemType LocateElem_Sq(SqList &L,ElemType e,int &pos);//��˳����ж�λ���ݲ����±긳ֵ��i�����ر�ʾ�ɹ���ʧ�� 
ElemType GetElemi_Sq(SqList &L,int pos,ElemType &e);//���±����Ԫ�ز���ֵ��ֵ��e 
ElemType ListInsert_Sq(SqList &L,int pos,ElemType e);//��˳����i���±��������e 
ElemType ListDelete_Sq(SqList &L,int pos,ElemType &e);//˳���ɾ����i��λ�õ�������e������ֵ
ElemType ListTraverse_Sq(SqList &L);//˳������ 

/******************����ʵ��******************/
ElemType ListInit_Sq(SqList &L)//˳����ʼ��
{
	L.data = (ElemType *)malloc(MAXSIZE *sizeof(ElemType));
	if(!L.data)
		return 0;
	L.length = 0;
	L.listSize = MAXSIZE;
	return 1;	
} 

ElemType ListLength_Sq(SqList &L)//˳�����
{
	return L.length;//���ص�ǰ�� 
}

ElemType LocateElem_Sq(SqList &L,ElemType e,int &pos)//��˳����ж�λ�����±� 
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.data[i] == e)
		{
			cout<<"*����"<<e<<"*��Ӧ���±�Ϊ��"<<i<<endl; 
			pos = i;//�±�ͨ��pos��������ȥ 
			break;
		}	
	} 
	if(i>=L.length)//�ж�˳������Ƿ��д��� 
		return 0;
	else
		return 1;
	
} 

ElemType GetElemi_Sq(SqList &L,int pos,ElemType &e)//���±����Ԫ�ز���e������ֵ 
{
	//�ж�λ�úϷ���
	if(pos<0 || pos>L.length-1)//�±�ֵ���Ϸ���ʾ��λʧ�ܣ�����0 
	{
		cout<<"*����������Χ!!"<<endl; 
		return 0;
	}
	else
	{
		e = L.data[pos-1];
		cout<<"*�±�"<<pos<<"*��Ӧ��Ԫ��Ϊ"<<e<<endl; //��ʾ����±�i��Ӧ��Ԫ�ز���ֵ��e 
		return 1;//������λ�ɹ�������1 
	}
} 

ElemType ListInsert_Sq(SqList &L,int pos,ElemType e)//��˳����i���±��������e
{
	//���˳���ǰ�����㣬�������ռ�
	if(L.length >= L.listSize)
	{
		ElemType *newBase = (ElemType *)realloc(L.data,(L.listSize + INCREASE)*sizeof(ElemType));
		L.listSize += INCREASE + L.listSize;
		L.data = newBase;	
	} 
	//�жϲ���λ�úϷ���                                                                                                                                                         
	if(pos<0 || pos>L.length)
	{
		cout<<"*�������λ�úϷ��ԣ���"<<endl;
		return 0;	
	} 
	//�������,����λ�ð�������Ԫ����������ƶ�����β����ʼ 
	for(int i=L.length-1;i>=pos-1;i--)                        
	{
		L.data[i+1] = L.data[i];
	} 
	L.data[pos]=e;//��������
	L.length++;
	return 1; 
}

ElemType ListDelete_Sq(SqList &L,int pos,ElemType &e)//˳���ɾ����i���±��������e������                          ֵ
{          
	//�ж�ɾ���±������
	if(pos<0 || pos>L.length-1)
	{
		cout<<"*����ɾ���±�ĺϷ���!!"<<endl;
		return 0;
	} 
	e = L.data[pos];
	//pos�±�֮�������ǰ��,��ǰ���� 
	for(int i=pos;i<L.length;i++)
	{
		L.data[i] = L.data[i+1];
	} 
	L.length--;
	return 1;
}
ElemType ListTraverse_Sq(SqList &L)//˳������ 
{
	for(int i=0;i<L.length;i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
}
/*
ElemType ListInit_Sq(SqList &L);//˳����ʼ��
ElemType ListLength_Sq(SqList &L);//˳�����
ElemType LocateElem_Sq(SqList &L,ElemType e,int &pos);//��˳����ж�λ���ݲ����±긳ֵ��i�����ر�ʾ�ɹ���ʧ�� 
ElemType GetElemi_Sq(SqList &L,int pos,ElemType &e);//���±����Ԫ�ز���ֵ��ֵ��e 
ElemType ListInsert_Sq(SqList &L,int pos,ElemType e);//��˳����i��λ�ò�������e 
ElemType ListDelete_Sq(SqList &L,int pos,ElemType &e);//˳���ɾ����i��λ�õ�������e������ֵ
ElemType ListTraverse_Sq(SqList &L);//˳������ 
*/

/******************��������֤******************/
int main()
{
	SqList L;
	int del_num;
	ListInit_Sq(L);
	for(int i=1;i<=10;i++)
		ListInsert_Sq(L,i-1,i);
	cout<<"*˳����ʼ��Ϊ��"<<endl; 
	ListTraverse_Sq(L);
	cout<<"*��ʱ��Ϊ��"<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	cout<<"*1������������λ��Խ�磺"<<endl;
	ListInsert_Sq(L,12,12);//ɾ��data[5]��˳����6���� 
	ListTraverse_Sq(L);
	cout<<"**��ʱ��Ϊ��"<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	ListDelete_Sq(L,5,del_num);//ɾ��data[5]��˳����6���� 
	ListTraverse_Sq(L);
	cout<<"*2.1��ɾ����������data[pos]��"<<del_num<<endl;
	cout<<"***��ʱ��Ϊ��"<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	cout<<"*2.2����ɾ������λ��Խ�磺"<<endl;
	ListDelete_Sq(L,12,del_num);//ɾ��data[5]��˳����6���� 
	ListTraverse_Sq(L);
	cout<<"****��ʱ��Ϊ��"<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	cout<<"*3��Ԫ�ض�λ��"<<endl;
	int loc_pos;
	LocateElem_Sq(L,3,loc_pos);
//	cout<<"*����3���ڵ�λ��Ϊ"<<loc_pos<<endl;
	return 0;
}
