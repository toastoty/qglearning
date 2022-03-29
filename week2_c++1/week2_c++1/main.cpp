#include "linkstack.h"

template<typename DataType>
void LinkStack<DataType>::Push(DataType x) //入栈
{
	Node<DataType>* s = new Node<DataType>;
	s->data = x;
	s->next = top;
	top = s;
}

template<typename DataType>
DataType LinkStack<DataType>::Pop() //出栈
{
	if (top == nullptr)
	{
		cout << "栈空！" << endl;
		return NULL;
	}
	DataType x = top->data;
	Node<DataType>* p = top;
	top = top->next;
	delete p;
	return x;
}

template<typename DataType>
LinkStack<DataType>::~LinkStack() //栈的销毁
{

	while (top != nullptr)
	{
		Node<DataType>* p = top;
		top = p->next;
		delete p;
	}
}
template<typename DataType>
void LinkStack<DataType>::clear(void) //栈的清除
{
	while (top != nullptr)
	{
		Node<DataType>* p = top;
		top = p->next;
		p = NULL;
	}
}

int main()
{
	LinkStack<dataType> my_linkstack;
	MENU::Menu();
	MENU::Choose(my_linkstack);
}