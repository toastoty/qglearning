#include "Structure.h"

DoubleLinkedList::DoubleLinkedList()
{
}

DoubleLinkedList::DoubleLinkedList(int _data)
{
	head = new DoubleLinkedListNode();
	head->data = _data;
	head->previous = nullptr;
	head->next = nullptr;
}

DoubleLinkedListNode* DoubleLinkedList::Insert(int NodeData, DoubleLinkedListNode* head)
{
	if (!head)
	{
		head = new DoubleLinkedListNode();
		head->data = NodeData;
		head->previous = nullptr;
		head->next = nullptr;
		return head;
	}
	DoubleLinkedListNode* NewNode = new DoubleLinkedListNode();
	NewNode->data = NodeData;
	DoubleLinkedListNode* temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = NewNode;
	NewNode->previous = temp;
	NewNode->next = nullptr;
	return head;
}

void DoubleLinkedList::PrintList(DoubleLinkedListNode* head)
{
	if (!head)
	{
		std::cout << "Current list is empty! " << std::endl;
		return;
	}
	DoubleLinkedListNode* temp = head;
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

DoubleLinkedListNode* DoubleLinkedList::DeleteNode(int a, DoubleLinkedListNode* head)
{
	if (!head)
	{
		std::cout << "Current list is empty! " << std::endl;
	}
	DoubleLinkedListNode* temp = head;
	int i = 1;
	while (temp)
	{
		if (a == 1)
		{
			DoubleLinkedListNode* delete1 = head;
			head = head->next;
			delete delete1;
			if (!head)
			{
				return head;
			}
			head->previous = nullptr;
		}
		else if (a == i + 1)
		{
			DoubleLinkedListNode* delete1 = temp->next;
			temp->next = head->next->next;
			delete1->next = nullptr;
			delete1->previous = nullptr;
			delete delete1;

			return head;
		}
		temp = temp->next;
		i++;
	}


}

void DoubleLinkedList::SortList(DoubleLinkedListNode* head)		//链表排序(从大到小）
{
	for (DoubleLinkedListNode* Temp = head; Temp->next != nullptr; Temp = Temp->next)
	{
		for (DoubleLinkedListNode* temp = head; temp->next != nullptr; temp = temp->next)
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
void DoubleLinkedList::JudgeCircle(DoubleLinkedListNode* head)
{

	if (head == NULL || head->next == NULL) {
		std::cout << "该链表不成环" << std::endl;
		return;
	}
	DoubleLinkedListNode* end = head;
	while (end->next)
	{
		end = end->next;
	}
	DoubleLinkedListNode* slow = head->next, * quick = head->next->next;
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
void DoubleLinkedList::ListChange(DoubleLinkedListNode* head)
{
	DoubleLinkedListNode* p1 = head;
	DoubleLinkedListNode* p2 = head->next;

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

void DoubleLinkedList::FindMiddle(DoubleLinkedListNode* head)
{
	DoubleLinkedListNode* slow = head, * quick = head;
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

DoubleLinkedListNode* DoubleLinkedList::RecursionRollBackList(DoubleLinkedListNode* head) //递归反转
{
	//特殊情况
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	DoubleLinkedListNode* newH = DoubleLinkedList::RecursionRollBackList(head->next);//递归循环到链表末尾
	head->next->next = head;//反转每个节点的指向
	head->next = NULL;
	return newH;
}


DoubleLinkedListNode* DoubleLinkedList::IterativeRollBackList(DoubleLinkedListNode* head) //迭代反转
{
	DoubleLinkedListNode* prev = nullptr;
	DoubleLinkedListNode* cur = head;
	while (nullptr != cur) {
		DoubleLinkedListNode* tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return prev;
}
