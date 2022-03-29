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
	~Aqueue();			//���ٶ���
	bool empty(Aqueue& Q);		//�ж϶����Ƿ�Ϊ��
	T getHead(Aqueue& Q);		//�õ�������Ԫ��
	bool push_back(Aqueue& Q);	//�Ӷ���β����Ԫ��
	void pop(Aqueue& Q);			//ɾ��������Ԫ��
	void coutQueue(Aqueue& Q);	//��ӡ����
	void getlength(Aqueue& Q);	//��ȡ���г���

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
		cout << "����Ϊ��" << endl;
	}
	cout << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->qnext;
	}
	cout << endl;
}

//�ж϶����Ƿ�Ϊ��
template<typename T>
bool Aqueue<T>::empty(Aqueue& Q) {
	if (Q.rear == Q.front) {
		return true;
	}
	else
		return false;
}

//�õ�������Ԫ��
template<typename T>
T Aqueue<T>::getHead(Aqueue& Q)
{
	if (empty(Q))
	{
		cout << "�ö���Ϊ��" << endl;
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

//ɾ��������Ԫ��
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

//������г���
template <typename T>
void Aqueue<T>::getlength(Aqueue& Q) {
	QNode<T>* p1 = Q.front;
	QNode<T>* p2 = Q.rear;
	while (p1 != p2) {
		p1 = p1->qnext;
		count++;
	}
	cout << "���г���=" << count << endl;
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
			std::cout << "\t\t***** ������Ҫ������е�Ԫ��,ʹ�ûس����ָ�,���� 0 ������� *****\n";
			while (1)
			{
				if (!que.push_back(que))
				{
					break;
				}
			}
			break;
		case '2':
			cout << "����Ԫ��Ϊ:" << endl;
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
				cout << "�ö���Ϊ��" << endl;
			else
				que.pop(que);
			break;
		case '6':
			que.getlength(que);
			break;
		case '7':
			if (que.empty(que))
				cout << "�ö���Ϊ��" << endl;
			else
				cout << "�ö��в�Ϊ��" << endl;
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
	std::cout << "\t\t*1.  ���Ԫ�����  *\n";
	std::cout << "\t\t*2. ��ȡ������Ԫ�� *\n";
	std::cout << "\t\t*3.  ��ӡ��ǰ����  *\n";
	std::cout << "\t\t*4.    ��ն���    *\n";
	std::cout << "\t\t*5.ʹ������Ԫ�س���*\n";
	std::cout << "\t\t*6.  �����г���   *\n";
	std::cout << "\t\t*7.�ж϶����Ƿ�Ϊ��*\n";
	std::cout << "\t\t*0.     �� ��      *\n";
	std::cout << "\t\t********************\n";

}