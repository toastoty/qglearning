
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<iostream>
#include<string.h>
using namespace std;
stack<int> q1;//����ջ
stack<char> q2;//����ջ
int flag = 0;//�����жϵ�һλ�ǡ�-�������
int flag2 = 0;//�����жϵ�һλ�ǡ�-�������
int flag1 = 0;//�����жϳ�����0�����

void calculate(stack<int>& q1, char s)
{
	int x, y, z;
	switch (s)
	{
	case '+':
	{
		x = q1.top();
		q1.pop();
		y = q1.top();
		q1.pop();
		z = x + y;
		q1.push(z);
		break;
	}
	case '-':
	{
		x = q1.top(); q1.pop();
		y = q1.top(); q1.pop();
		z = y - x;
		q1.push(z);
		break;
	}
	case '*':
	{
		x = q1.top(); q1.pop();
		y = q1.top(); q1.pop();
		z = x * y;
		q1.push(z);
		break;
	}
	case '/':
	{
		x = q1.top(); q1.pop();
		y = q1.top(); q1.pop();
		if (x == 0)
		{
			flag1 = 1;
			break;
		}
		z = y / x;
		q1.push(z);
		break;
	}
	}

}
//����������ʾ�������ȼ�
int fuhao(char s)
{
	if (s == '+' || s == '-')
		return 1;
	if (s == '*' || s == '/')
		return 2;
	if (s == '(' || s == ')')
		return 3;
	if (s == '#')
		return -1;
}
//������ջ������ջ��ջ�Լ�����ĺ���
void function(char a[100])
{
	q2.push('#');//�ڷ���ջ����һ����#������ֹ������ջ��Ϊ�յ�ʱ�����쳣
	int len = strlen(a);
	if (a[0] == '-')//�����һ�������Ǹ��ŵ������Ҫ��������
	{
		flag2 = 1;
		a[0] = '0';
	}
	for (int i = 0; i < len; i++)
	{
		if (a[i] == '(')
		{
			q2.push(a[i]);
		}
		else if (a[i] == ')')
		{
			while (q2.top() != '(')
			{
				calculate(q1, q2.top());
				q2.pop();
			}
			q2.pop();

		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			int num = 0;
			//ʶ������ ֱ�����������ַ���
			while (a[i] >= '0' && a[i] <= '9')
			{
				num *= 10;
				num += (a[i] - '0');
				i++;
			}
			i--;
			if (flag2 == 1 && flag == 0)//�Ե�һλ�Ǹ����ĵ�������
				num *= -1;
			q1.push(num);
			flag = 1;
		}
		else
		{
			if (a[i] == '+' || a[i] == '-')
			{
				if ((fuhao(q2.top()) >= fuhao(a[i])) && q2.top() != '(')
				{
					while (fuhao(q2.top()) >= fuhao(a[i]) && q2.top() != '(')
					{
						calculate(q1, q2.top());
						q2.pop();

					}
					q2.push(a[i]);
				}
				else
				{
					q2.push(a[i]);

				}
			}
			else if (a[i] == '*' || a[i] == '/')
			{
				if (fuhao(q2.top()) == fuhao(a[i]))
				{
					calculate(q1, q2.top());
					if (flag1 == 1)
					{
						printf("error");
						return;
					}
					q2.pop();
					q2.push(a[i]);

				}
				else
				{
					q2.push(a[i]);
				}
			}
		}
	}
	//�ַ�ջ��ʱ�������
	while (q2.top() != '#')
	{
		calculate(q1, q2.top());
		if (flag1 == 1)
		{
			printf("error");
			return;
		}
		q2.pop();
	}
	printf("%d", q1.top());

}

int main()
{
	cout << "֧�ַ��� '+', '-', '*', '/', '(', ')'" << endl;
	char a[100];

	scanf_s("%s", a, 100);
	function(a);


	return 0;
}

