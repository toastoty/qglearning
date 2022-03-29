#pragma once
#define dataType int
#include <iostream>
using namespace std;
template<typename DataType>
struct Node
{
	DataType data;
	Node<DataType>* next;
};

template<typename DataType>
class LinkStack
{
public:

	LinkStack()			//初始化栈
	{
		top = nullptr;
	}
	~LinkStack();	//栈的销毁
	void Push(DataType x);//入栈
	DataType Pop();      //出栈
	void clear();	//栈的清除
	void stackLength()//检测栈的长度
	{
		if (!top)
		{
			return;
		}
		Node<DataType>* p = top;
		while (!p)
		{
			p = p->next;
			(*length)++;
		}
	}
	DataType GetTop(void)		//得到栈顶元素
	{
		if (top != nullptr)
		{
			return top->data;
		}
		else
			cout << "栈空!" << endl;
		return NULL;
	}

	int Empty()		//判断栈是否为空
	{
		if (top == nullptr)
			return 1;
		return 0;
	}
private:
	Node<DataType>* top;
	int* length = nullptr;
};

class MENU
{
public:
	static void Menu(void)
	{
		std::cout << "\n\t\t********************\n";
		std::cout << "\t\t*1.  添加元素入栈  *\n";
		std::cout << "\t\t*2.  获取栈顶元素  *\n";
		std::cout << "\t\t*3.   输出栈元素   *\n";
		std::cout << "\t\t*4.     清空栈     *\n";
		std::cout << "\t\t*5.     销毁栈     *\n";
		std::cout << "\t\t*6.   检测栈长度   *\n";
		std::cout << "\t\t*7. 判断栈是否为空 *\n";
		std::cout << "\t\t*0.     退 出      *\n";
		std::cout << "\t\t********************\n";

	}
	static void Choose(LinkStack<dataType> LS) {
		while (1)
		{
			Menu();
			int a = 0;
			std::cin >> a;

			switch (a)
			{
			case 1:


				std::cout << "\t\t***** 请添加入栈元素,使用回车键分隔,输入 0 结束添加 *****\n";
				dataType b;
				std::cin >> b;
				while (b)
				{
					LS.Push(b);
					std::cin >> b;
				}
				break;
			case 2:
				cout << "栈顶元素为:" << endl;
				cout << LS.GetTop() << endl;
				break;
			case 3:
				cout << LS.Pop() << endl;
				break;
			case 4:
				LS.clear();
				break;
			case 5:
				LS.~LinkStack();
				break;
			case 6:
				LS.stackLength();
				break;
			case 7:
				LS.Empty();
				break;

			case 0:
				break;
			}
		}
	}
};

