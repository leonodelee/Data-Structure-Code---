#include <iostream> 
#include <cstring>
#include <stack>
using namespace std;

int getPriority(char ch)
{//获取优先级
	if(ch == '(') return 1;
	else if(ch == '+' || ch == '-') return 2;
	else if(ch == '*' || ch == '/')	return 3;
	else return 4; 
}

string getPostfixExpression(string str)
{   //将中缀表达式转化为后缀表达式
	//默认输入合法
	stack<char> mystack;
	int size = str.size();
	int i= 0 ;
	char tmp;
	string res = "";
	while(i < size)
	{
		if(str[i] >= '0' && str[i]<='9')
		{//数字直接进字符串 
			res.push_back(str[i]);
		}
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{//如果是操作符 
			if(mystack.empty())
			{//栈中是空的直接进栈 
				mystack.push(str[i]);	
			}	
			else
			{
				while(!mystack.empty())
				{
					tmp = mystack.top();
					//弹出栈顶元素与当前操作符对比
					if(getPriority(tmp) >= getPriority(str[i]))
					{//若栈顶元素比当前操作符优先级高 
						res.push_back(tmp);//弹出栈顶操作符加入后缀表达式 
						mystack.pop();
					}
					else break;//若栈顶元素比当前操作符优先级低，跳过 
				}
				mystack.push(str[i]);//最终一定会将该运算符入栈
			}
		}
		else//处理括号 
		{
			if(str[i] == '(') mystack.push(str[i]);	//左括号进符号栈 
			else
			{//如果是右括号，弹出符号栈中第一个左括号前所有的操作符，并将左括号弹出 
				while(mystack.top() != '(')	
				{//弹出符号栈中第一个左括号前所有的操作符加入后缀表达式字符串里 
					tmp = mystack.top();
					res.push_back(tmp);
					mystack.pop(); 
				}
				mystack.pop(); //将左括号弹出 
			} 
		}	
		i++;//while(i<size)循环 
	} 
	//遍历完后
	while(!mystack.empty())
	{//若符号栈不为空 
		tmp = mystack.top();
		res.push_back(tmp);//依次加入后缀表达式 
		mystack.pop();	
	} 
	return res;//返回后缀表达式 
}

int calculator(string str)
{//计算后缀表达式的值，默认中缀表达式所有数字都是一位的，在0~9之间
	stack<int> mystack;
	int size = str.size();
	int num1,num2,result;
	for(int i=0;i<size;i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			mystack.push(str[i] - '0');	
		}
		else
		{//取数字栈顶两个数字元素与操作符栈顶的操作符进行运算 
			num2 = mystack.top();
			mystack.pop();
			num1 = mystack.top();
			mystack.pop();
			if(str[i] == '+')	result = num1 + num2;
			else if(str[i] == '-') result = num1 - num2;
			else if(str[i] == '*') result = num1 * num2;
			else if(str[i] == '/') result = num1 / num2;
			mystack.push(result);//将本次运算结果压入数字栈作为下一次运算的右操作数 
		}
	}  
	return mystack.top();//返回运算结果 
} 

int main()
{
	string str="1+(2-3)*4+4/2";
    cout <<"中缀表达式为:"<< endl << str << endl;
    string res = getPostfixExpression(str);
    cout <<"后缀表达式为:"<< endl << res << endl;
    int num_res = calculator(res);
    cout <<"计算结果:"<< endl << num_res << endl;
    system("pause");
    return 0;
}
