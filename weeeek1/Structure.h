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
	void MainMenu();//主菜单-选择单双链表
	void ListMenu();//链表菜单-进行链表操作
	SingleLinkedListNode* SwitchMenu1(SingleLinkedListNode* Shead);//单链表操作
	DoubleLinkedListNode* SwitchMenu2(DoubleLinkedListNode* Dhead);//双链表操作
};

/// <summary>
/// //////
/// </summary>


class SingleLinkedList {
	SingleLinkedListNode* head;
public:

	SingleLinkedList();				// 默认构造函数，什么都不干
	SingleLinkedList(int _data);	// 需要一个头节点的值，构造头节点
	SingleLinkedListNode* DeleteNode(int a, SingleLinkedListNode* head);		//删除节点
	void SortList(SingleLinkedListNode* head);				//排序链表
	void ListChange(SingleLinkedListNode* head);				//奇偶调换
	void FindMiddle(SingleLinkedListNode* head);				//找到链表中点
	void JudgeCircle(SingleLinkedListNode* head);				//判断链表成环
	SingleLinkedListNode* Insert(int NodeData, SingleLinkedListNode* head);		// 插入节点
	void PrintList(SingleLinkedListNode* head);				// 打印链表
	SingleLinkedListNode* RecursionRollBackList(SingleLinkedListNode* head); //递归反转链表
	SingleLinkedListNode* IterativeRollBackList(SingleLinkedListNode* head); //迭代反转链表
};



class DoubleLinkedList {
	DoubleLinkedListNode* head;
public:
	DoubleLinkedList();				// 默认构造函数，什么都不干
	DoubleLinkedList(int _data);	// 需要一个头节点的值，构造头节点
	DoubleLinkedListNode* DeleteNode(int a, DoubleLinkedListNode* head);		//删除节点
	void SortList(DoubleLinkedListNode* head);				//排序链表
	void ListChange(DoubleLinkedListNode* head);				//奇偶调换
	void FindMiddle(DoubleLinkedListNode* head);				//找到链表中点
	void JudgeCircle(DoubleLinkedListNode* head);				//判断链表成环
	DoubleLinkedListNode* Insert(int NodeData, DoubleLinkedListNode* head);		// 插入节点到链表尾部
	void PrintList(DoubleLinkedListNode* head);				// 打印链表
	DoubleLinkedListNode* RecursionRollBackList(DoubleLinkedListNode* head); //递归反转链表
	DoubleLinkedListNode* IterativeRollBackList(DoubleLinkedListNode* head); //迭代反转链表
};