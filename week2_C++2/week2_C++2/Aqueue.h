#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;

template<typename T>
class QNode {
public:
	T data;
	QNode<T>* qnext;
	QNode(const T& _data) :data(_data) {}
};
template<typename T>
class Aqueue
{
public:
	Aqueue();
	~Aqueue();			//销毁队列
	bool empty(Aqueue& Q);		//判断队列是否为空
	T getHead(Aqueue& Q);		//得到队列首元素
	bool push_back(Aqueue& Q);	//从队列尾插入元素
	void pop(Aqueue& Q);			//删除队列首元素
	void coutQueue(Aqueue& Q);	//打印队列
	void getlength(Aqueue& Q);	//获取队列长度

private:
	QNode<T>* front;
	QNode<T>* rear;
	int count;
};


template<typename T>
class MENU
{
public:
	void Menu();
	void Choose(Aqueue<T> que);
};

template<typename T>
Aqueue<T>::Aqueue()
{
	front = new QNode<T>(0);
	rear = front;
	count = 0;
}

template<typename T>
Aqueue<T>::~Aqueue()
{
	while (front->qnext != nullptr)
	{
		QNode<T>* tmpNode = front;
		front = front->qnext;
		delete tmpNode;
	}
}
template<typename T>
void Aqueue<T>::coutQueue(Aqueue& Q)
{
	QNode<T>* p = Q.front->qnext;
	if (p == NULL)
	{
		cout << "队列为空" << endl;
	}
	cout << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->qnext;
	}
	cout << endl;
}

//判断队列是否为空
template<typename T>
bool Aqueue<T>::empty(Aqueue& Q) {
	if (Q.rear == Q.front) {
		return true;
	}
	else
		return false;
}

//得到队列首元素
template<typename T>
T Aqueue<T>::getHead(Aqueue& Q)
{
	if (empty(Q))
	{
		cout << "该队列为空" << endl;
		return NULL;
	}
	else
	{
		return Q.front->data;
	}
}

template <typename T>
bool Aqueue<T>::push_back(Aqueue& Q)
{
	T b;
	std::cin >> b;
	if (b == 0)
	{
		return false;
	}
	QNode<T>* pnew = new QNode<T>(b);
	pnew->qnext = NULL;
	pnew->data = b;
	Q.rear->qnext = pnew;
	Q.rear = pnew;
	return true;

}

//删除队列首元素
template<typename T>
void Aqueue<T>::pop(Aqueue& Q)
{
	cout << Q.front->qnext->data << endl;
	QNode<T>* p;
	p = Q.front->qnext;
	Q.front->qnext = Q.front->qnext->qnext;
	if (p == NULL)
		return;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
}

//计算队列长度
template <typename T>
void Aqueue<T>::getlength(Aqueue& Q) {
	QNode<T>* p1 = Q.front;
	QNode<T>* p2 = Q.rear;
	while (p1 != p2) {
		p1 = p1->qnext;
		count++;
	}
	cout << "队列长度=" << count << endl;
}
#include "Aqueue.h"

template <typename T>
void MENU<T>::Choose(Aqueue<T> que) {
	while (1)
	{
		Menu();
		char a = 0;
		bool bCon = true;
		while (bCon)
		{
			cin >> a;
			if (a >= '0' && a <= '7')
			{
				bCon = false;

			}
		}
		switch (a)
		{
		case '1':
			std::cout << "\t\t***** 请输入要加入队列的元素,使用回车键分隔,输入 0 结束添加 *****\n";
			while (1)
			{
				if (!que.push_back(que))
				{
					break;
				}
			}
			break;
		case '2':
			cout << "列首元素为:" << endl;
			cout << que.getHead(que) << endl;
			break;
		case '3':
			que.coutQueue(que);
			break;
		case '4':
			que.~Aqueue<T>();
			Aqueue<T>();
			break;
		case '5':
			if (que.empty(que))
				cout << "该队列为空" << endl;
			else
				que.pop(que);
			break;
		case '6':
			que.getlength(que);
			break;
		case '7':
			if (que.empty(que))
				cout << "该队列为空" << endl;
			else
				cout << "该队列不为空" << endl;
			break;

		case '0':
			break;
		}


	}
}
template <typename T>
void MENU<T>::Menu()
{
	std::cout << "\n\t\t********************\n";
	std::cout << "\t\t*1.  添加元素入队  *\n";
	std::cout << "\t\t*2. 获取队列首元素 *\n";
	std::cout << "\t\t*3.  打印当前队列  *\n";
	std::cout << "\t\t*4.    清空队列    *\n";
	std::cout << "\t\t*5.使队列首元素出列*\n";
	std::cout << "\t\t*6.  检测队列长度   *\n";
	std::cout << "\t\t*7.判断队列是否为空*\n";
	std::cout << "\t\t*0.     退 出      *\n";
	std::cout << "\t\t********************\n";

}