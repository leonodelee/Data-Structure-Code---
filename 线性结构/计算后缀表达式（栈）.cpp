#include <iostream> 
#include <cstring>
#include <stack>
using namespace std;

int getPriority(char ch)
{//��ȡ���ȼ�
	if(ch == '(') return 1;
	else if(ch == '+' || ch == '-') return 2;
	else if(ch == '*' || ch == '/')	return 3;
	else return 4; 
}

string getPostfixExpression(string str)
{   //����׺���ʽת��Ϊ��׺���ʽ
	//Ĭ������Ϸ�
	stack<char> mystack;
	int size = str.size();
	int i= 0 ;
	char tmp;
	string res = "";
	while(i < size)
	{
		if(str[i] >= '0' && str[i]<='9')
		{//����ֱ�ӽ��ַ��� 
			res.push_back(str[i]);
		}
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{//����ǲ����� 
			if(mystack.empty())
			{//ջ���ǿյ�ֱ�ӽ�ջ 
				mystack.push(str[i]);	
			}	
			else
			{
				while(!mystack.empty())
				{
					tmp = mystack.top();
					//����ջ��Ԫ���뵱ǰ�������Ա�
					if(getPriority(tmp) >= getPriority(str[i]))
					{//��ջ��Ԫ�رȵ�ǰ���������ȼ��� 
						res.push_back(tmp);//����ջ�������������׺���ʽ 
						mystack.pop();
					}
					else break;//��ջ��Ԫ�رȵ�ǰ���������ȼ��ͣ����� 
				}
				mystack.push(str[i]);//����һ���Ὣ���������ջ
			}
		}
		else//�������� 
		{
			if(str[i] == '(') mystack.push(str[i]);	//�����Ž�����ջ 
			else
			{//����������ţ���������ջ�е�һ��������ǰ���еĲ����������������ŵ��� 
				while(mystack.top() != '(')	
				{//��������ջ�е�һ��������ǰ���еĲ����������׺���ʽ�ַ����� 
					tmp = mystack.top();
					res.push_back(tmp);
					mystack.pop(); 
				}
				mystack.pop(); //�������ŵ��� 
			} 
		}	
		i++;//while(i<size)ѭ�� 
	} 
	//�������
	while(!mystack.empty())
	{//������ջ��Ϊ�� 
		tmp = mystack.top();
		res.push_back(tmp);//���μ����׺���ʽ 
		mystack.pop();	
	} 
	return res;//���غ�׺���ʽ 
}

int calculator(string str)
{//�����׺���ʽ��ֵ��Ĭ����׺���ʽ�������ֶ���һλ�ģ���0~9֮��
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
		{//ȡ����ջ����������Ԫ���������ջ���Ĳ������������� 
			num2 = mystack.top();
			mystack.pop();
			num1 = mystack.top();
			mystack.pop();
			if(str[i] == '+')	result = num1 + num2;
			else if(str[i] == '-') result = num1 - num2;
			else if(str[i] == '*') result = num1 * num2;
			else if(str[i] == '/') result = num1 / num2;
			mystack.push(result);//������������ѹ������ջ��Ϊ��һ��������Ҳ����� 
		}
	}  
	return mystack.top();//���������� 
} 

int main()
{
	string str="1+(2-3)*4+4/2";
    cout <<"��׺���ʽΪ:"<< endl << str << endl;
    string res = getPostfixExpression(str);
    cout <<"��׺���ʽΪ:"<< endl << res << endl;
    int num_res = calculator(res);
    cout <<"������:"<< endl << num_res << endl;
    system("pause");
    return 0;
}
