#pragma once

#include<iostream>
struct SingleLinkedListNode {
	int data;
	SingleLinkedListNode* next;
};
struct DoubleLinkedListNode {
	int data;
	DoubleLinkedListNode* previous;
	DoubleLinkedListNode* next;
};
class Menu
{
public:
	void MainMenu();//���˵�-ѡ��˫����
	void ListMenu();//����˵�-�����������
	SingleLinkedListNode* SwitchMenu1(SingleLinkedListNode* Shead);//���������
	DoubleLinkedListNode* SwitchMenu2(DoubleLinkedListNode* Dhead);//˫�������
};

/// <summary>
/// //////
/// </summary>


class SingleLinkedList {
	SingleLinkedListNode* head;
public:

	SingleLinkedList();				// Ĭ�Ϲ��캯����ʲô������
	SingleLinkedList(int _data);	// ��Ҫһ��ͷ�ڵ��ֵ������ͷ�ڵ�
	SingleLinkedListNode* DeleteNode(int a, SingleLinkedListNode* head);		//ɾ���ڵ�
	void SortList(SingleLinkedListNode* head);				//��������
	void ListChange(SingleLinkedListNode* head);				//��ż����
	void FindMiddle(SingleLinkedListNode* head);				//�ҵ������е�
	void JudgeCircle(SingleLinkedListNode* head);				//�ж�����ɻ�
	SingleLinkedListNode* Insert(int NodeData, SingleLinkedListNode* head);		// ����ڵ�
	void PrintList(SingleLinkedListNode* head);				// ��ӡ����
	SingleLinkedListNode* RecursionRollBackList(SingleLinkedListNode* head); //�ݹ鷴ת����
	SingleLinkedListNode* IterativeRollBackList(SingleLinkedListNode* head); //������ת����
};



class DoubleLinkedList {
	DoubleLinkedListNode* head;
public:
	DoubleLinkedList();				// Ĭ�Ϲ��캯����ʲô������
	DoubleLinkedList(int _data);	// ��Ҫһ��ͷ�ڵ��ֵ������ͷ�ڵ�
	DoubleLinkedListNode* DeleteNode(int a, DoubleLinkedListNode* head);		//ɾ���ڵ�
	void SortList(DoubleLinkedListNode* head);				//��������
	void ListChange(DoubleLinkedListNode* head);				//��ż����
	void FindMiddle(DoubleLinkedListNode* head);				//�ҵ������е�
	void JudgeCircle(DoubleLinkedListNode* head);				//�ж�����ɻ�
	DoubleLinkedListNode* Insert(int NodeData, DoubleLinkedListNode* head);		// ����ڵ㵽����β��
	void PrintList(DoubleLinkedListNode* head);				// ��ӡ����
	DoubleLinkedListNode* RecursionRollBackList(DoubleLinkedListNode* head); //�ݹ鷴ת����
	DoubleLinkedListNode* IterativeRollBackList(DoubleLinkedListNode* head); //������ת����
};