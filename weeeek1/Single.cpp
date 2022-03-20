#include "Structure.h"

SingleLinkedList::SingleLinkedList()
{
}

SingleLinkedList::SingleLinkedList(int _data)
{
	head = new SingleLinkedListNode();
	head->data = _data;
	head->next = nullptr;
}

SingleLinkedListNode* SingleLinkedList::Insert(int NodeData, SingleLinkedListNode* Shead)
{
	SingleLinkedList();
	if (!head)
	{
		head = new SingleLinkedListNode();
		head->data = NodeData;
		head->next = nullptr;
		return head;
	}
	SingleLinkedListNode* NewNode = new SingleLinkedListNode();
	NewNode->data = NodeData;
	NewNode->next = nullptr;
	SingleLinkedListNode* temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = NewNode;
	return head;
}

void SingleLinkedList::PrintList(SingleLinkedListNode* head)
{
	if (!head)
	{
		std::cout << "Current list is empty! " << std::endl;
		return;
	}
	SingleLinkedListNode* temp = head;
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

SingleLinkedListNode* SingleLinkedList::DeleteNode(int a, SingleLinkedListNode* head)
{
	if (!head)
	{
		std::cout << "Current list is empty! " << std::endl;
		return head;
	}
	SingleLinkedListNode* temp = head;
	int i = 1;
	while (temp)
	{
		if (a == 1)
		{
			head = head->next;
		}
		else if (a == i + 1)
		{
			SingleLinkedListNode* delete1 = temp->next;
			temp->next = head->next->next;
			delete1->next = nullptr;


		}
		temp = temp->next;
		i++;
	}
	return head;

}

void SingleLinkedList::SortList(SingleLinkedListNode* head)		//链表排序(从大到小）
{
	for (SingleLinkedListNode* Temp = head; Temp->next != nullptr; Temp = Temp->next)
	{
		for (SingleLinkedListNode* temp = head; temp->next != nullptr; temp = temp->next)
		{

			if (temp->data < temp->next->data)
			{

				int swap = temp->data;
				temp->data = temp->next->data;
				temp->next->data = swap;

			}
		}
	}
}
void SingleLinkedList::JudgeCircle(SingleLinkedListNode* head)
{

	if (head == NULL || head->next == NULL) {
		std::cout << "该链表不成环" << std::endl;
		return;
	}
	SingleLinkedListNode* slow = head->next, * quick = head->next->next;
	while (quick != NULL && quick->next != NULL) {
		if (quick == slow) {
			quick = head;
			while (slow != quick) {
				slow = slow->next;
				quick = quick->next;
			}
			std::cout << "该链表成环" << std::endl;
			return;
		}
		quick = quick->next->next;
		slow = slow->next;
	}
	std::cout << "该链表不成环" << std::endl;
	return;

}
void SingleLinkedList::ListChange(SingleLinkedListNode* head)
{
	SingleLinkedListNode* p1 = head;
	SingleLinkedListNode* p2 = head->next;

	while (1)
	{
		int swap = p1->data;
		p1->data = p2->data;
		p2->data = swap;
		if (p1->next->next == nullptr || p2->next->next == nullptr)
		{
			return;
		}
		p1 = p1->next->next, p2 = p2->next->next;

	}
}

void SingleLinkedList::FindMiddle(SingleLinkedListNode* head)
{
	SingleLinkedListNode* slow = head, * quick = head;
	slow = head->next, quick = head->next->next;
	int i = 1;
	int o = 0;
	if (!(head->next))
	{

	}
	else if (!(head->next->next))
	{
		o = 2;
	}

	else
	{

		while (quick != NULL && quick->next != NULL)
		{
			if (quick == nullptr && slow->next != nullptr)
			{
				quick = head;
				while (slow != quick)
				{
					slow = slow->next;
					quick = quick->next;
				}

			}

			i = i++;
			quick = quick->next->next;
			slow = slow->next;
		}
	}
	if (o)
	{
		std::cout << "由于该链表的节点数为偶数，只能得到中间的两个节点序数，其中一个序数为: " << i << std::endl;
		std::cout << "另一个节点序数为: " << o << std::endl;

	}
	else
	{
		std::cout << "该链表的中点的节点序数为： " << i << std::endl;
	}
}

SingleLinkedListNode* SingleLinkedList::RecursionRollBackList(SingleLinkedListNode* head) //递归反转
{
	//特殊情况
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	SingleLinkedListNode* newH = SingleLinkedList::RecursionRollBackList(head->next);//递归循环到链表末尾
	head->next->next = head;//反转每个节点的指向
	head->next = NULL;
	return newH;
}


SingleLinkedListNode* SingleLinkedList::IterativeRollBackList(SingleLinkedListNode* head) //迭代反转
{
	SingleLinkedListNode* prev = nullptr;
	SingleLinkedListNode* cur = head;
	while (nullptr != cur) {
		SingleLinkedListNode* tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return prev;
}