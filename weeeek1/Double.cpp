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

void DoubleLinkedList::SortList(DoubleLinkedListNode* head)		//��������(�Ӵ�С��
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
		std::cout << "�������ɻ�" << std::endl;
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
			std::cout << "������ɻ�" << std::endl;
			return;
		}
		quick = quick->next->next;
		slow = slow->next;
	}
	std::cout << "�������ɻ�" << std::endl;
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
		std::cout << "���ڸ�����Ľڵ���Ϊż����ֻ�ܵõ��м�������ڵ�����������һ������Ϊ: " << i << std::endl;
		std::cout << "��һ���ڵ�����Ϊ: " << o << std::endl;

	}
	else
	{
		std::cout << "��������е�Ľڵ�����Ϊ�� " << i << std::endl;
	}
}

DoubleLinkedListNode* DoubleLinkedList::RecursionRollBackList(DoubleLinkedListNode* head) //�ݹ鷴ת
{
	//�������
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	DoubleLinkedListNode* newH = DoubleLinkedList::RecursionRollBackList(head->next);//�ݹ�ѭ��������ĩβ
	head->next->next = head;//��תÿ���ڵ��ָ��
	head->next = NULL;
	return newH;
}


DoubleLinkedListNode* DoubleLinkedList::IterativeRollBackList(DoubleLinkedListNode* head) //������ת
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
