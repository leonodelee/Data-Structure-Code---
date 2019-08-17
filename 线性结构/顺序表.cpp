#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100//初始化大小 
#define INCREASE 10//不足时新申请大小 
//typedef int ElemType
#define ElemType int 

/***************结构体定义***************/
typedef struct
{
	ElemType *data;//存储数据基址 
	int length;//当前顺序表长度
	int listSize;//当前分配的存储容量 
}SqList;

/******************函数声明******************/
ElemType ListInit_Sq(SqList &L);//顺序表初始化
ElemType ListLength_Sq(SqList &L);//顺序表长度
ElemType LocateElem_Sq(SqList &L,ElemType e,int &pos);//在顺序表中定位数据并将下标赋值给i，返回表示成功与失败 
ElemType GetElemi_Sq(SqList &L,int pos,ElemType &e);//按下标查找元素并将值赋值给e 
ElemType ListInsert_Sq(SqList &L,int pos,ElemType e);//在顺序表第i个下标插入数据e 
ElemType ListDelete_Sq(SqList &L,int pos,ElemType &e);//顺序表删除第i个位置的数并用e返回其值
ElemType ListTraverse_Sq(SqList &L);//顺序表遍历 

/******************函数实现******************/
ElemType ListInit_Sq(SqList &L)//顺序表初始化
{
	L.data = (ElemType *)malloc(MAXSIZE *sizeof(ElemType));
	if(!L.data)
		return 0;
	L.length = 0;
	L.listSize = MAXSIZE;
	return 1;	
} 

ElemType ListLength_Sq(SqList &L)//顺序表长度
{
	return L.length;//返回当前表长 
}

ElemType LocateElem_Sq(SqList &L,ElemType e,int &pos)//在顺序表中定位数据下标 
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.data[i] == e)
		{
			cout<<"*数据"<<e<<"*对应的下标为："<<i<<endl; 
			pos = i;//下标通过pos参数传出去 
			break;
		}	
	} 
	if(i>=L.length)//判断顺序表中是否有此数 
		return 0;
	else
		return 1;
	
} 

ElemType GetElemi_Sq(SqList &L,int pos,ElemType &e)//按下标查找元素并用e返回其值 
{
	//判断位置合法性
	if(pos<0 || pos>L.length-1)//下标值不合法表示定位失败，返回0 
	{
		cout<<"*索引超出范围!!"<<endl; 
		return 0;
	}
	else
	{
		e = L.data[pos-1];
		cout<<"*下标"<<pos<<"*对应的元素为"<<e<<endl; //显示输出下标i对应的元素并赋值给e 
		return 1;//索引定位成功，返回1 
	}
} 

ElemType ListInsert_Sq(SqList &L,int pos,ElemType e)//在顺序表第i个下标插入数据e
{
	//如果顺序表当前表长不足，另外分配空间
	if(L.length >= L.listSize)
	{
		ElemType *newBase = (ElemType *)realloc(L.data,(L.listSize + INCREASE)*sizeof(ElemType));
		L.listSize += INCREASE + L.listSize;
		L.data = newBase;	
	} 
	//判断插入位置合法性                                                                                                                                                         
	if(pos<0 || pos>L.length)
	{
		cout<<"*请检查插入位置合法性！！"<<endl;
		return 0;	
	} 
	//插入操作,插入位置包括其后的元素逐个往后移动，从尾部开始 
	for(int i=L.length-1;i>=pos-1;i--)                        
	{
		L.data[i+1] = L.data[i];
	} 
	L.data[pos]=e;//插入数据
	L.length++;
	return 1; 
}

ElemType ListDelete_Sq(SqList &L,int pos,ElemType &e)//顺序表删除第i个下标的数并用e返回其                          值
{          
	//判断删除下标合理性
	if(pos<0 || pos>L.length-1)
	{
		cout<<"*请检查删除下标的合法性!!"<<endl;
		return 0;
	} 
	e = L.data[pos];
	//pos下标之后的数据前移,由前往后 
	for(int i=pos;i<L.length;i++)
	{
		L.data[i] = L.data[i+1];
	} 
	L.length--;
	return 1;
}
ElemType ListTraverse_Sq(SqList &L)//顺序表遍历 
{
	for(int i=0;i<L.length;i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
}
/*
ElemType ListInit_Sq(SqList &L);//顺序表初始化
ElemType ListLength_Sq(SqList &L);//顺序表长度
ElemType LocateElem_Sq(SqList &L,ElemType e,int &pos);//在顺序表中定位数据并将下标赋值给i，返回表示成功与失败 
ElemType GetElemi_Sq(SqList &L,int pos,ElemType &e);//按下标查找元素并将值赋值给e 
ElemType ListInsert_Sq(SqList &L,int pos,ElemType e);//在顺序表第i个位置插入数据e 
ElemType ListDelete_Sq(SqList &L,int pos,ElemType &e);//顺序表删除第i个位置的数并用e返回其值
ElemType ListTraverse_Sq(SqList &L);//顺序表遍历 
*/

/******************主函数验证******************/
int main()
{
	SqList L;
	int del_num;
	ListInit_Sq(L);
	for(int i=1;i<=10;i++)
		ListInsert_Sq(L,i-1,i);
	cout<<"*顺序表初始化为："<<endl; 
	ListTraverse_Sq(L);
	cout<<"*此时表长为："<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	cout<<"*1、若插入数据位置越界："<<endl;
	ListInsert_Sq(L,12,12);//删除data[5]，顺序表第6个数 
	ListTraverse_Sq(L);
	cout<<"**此时表长为："<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	ListDelete_Sq(L,5,del_num);//删除data[5]，顺序表第6个数 
	ListTraverse_Sq(L);
	cout<<"*2.1、删除的数据是data[pos]："<<del_num<<endl;
	cout<<"***此时表长为："<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	cout<<"*2.2、若删除数据位置越界："<<endl;
	ListDelete_Sq(L,12,del_num);//删除data[5]，顺序表第6个数 
	ListTraverse_Sq(L);
	cout<<"****此时表长为："<<ListLength_Sq(L)<<endl;
	cout<<endl;
	
	cout<<"*3、元素定位："<<endl;
	int loc_pos;
	LocateElem_Sq(L,3,loc_pos);
//	cout<<"*数字3所在的位置为"<<loc_pos<<endl;
	return 0;
}
