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

	LinkStack()			//��ʼ��ջ
	{
		top = nullptr;
	}
	~LinkStack();	//ջ������
	void Push(DataType x);//��ջ
	DataType Pop();      //��ջ
	void clear();	//ջ�����
	void stackLength()//���ջ�ĳ���
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
	DataType GetTop(void)		//�õ�ջ��Ԫ��
	{
		if (top != nullptr)
		{
			return top->data;
		}
		else
			cout << "ջ��!" << endl;
		return NULL;
	}

	int Empty()		//�ж�ջ�Ƿ�Ϊ��
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
		std::cout << "\t\t*1.  ���Ԫ����ջ  *\n";
		std::cout << "\t\t*2.  ��ȡջ��Ԫ��  *\n";
		std::cout << "\t\t*3.   ���ջԪ��   *\n";
		std::cout << "\t\t*4.     ���ջ     *\n";
		std::cout << "\t\t*5.     ����ջ     *\n";
		std::cout << "\t\t*6.   ���ջ����   *\n";
		std::cout << "\t\t*7. �ж�ջ�Ƿ�Ϊ�� *\n";
		std::cout << "\t\t*0.     �� ��      *\n";
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


				std::cout << "\t\t***** �������ջԪ��,ʹ�ûس����ָ�,���� 0 ������� *****\n";
				dataType b;
				std::cin >> b;
				while (b)
				{
					LS.Push(b);
					std::cin >> b;
				}
				break;
			case 2:
				cout << "ջ��Ԫ��Ϊ:" << endl;
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

