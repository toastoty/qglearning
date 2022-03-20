//#include"Structure.h"
//
//void Menu::MainMenu(void)
//{
//	std::cout << "\n\t\t********************\n";
//	std::cout << "\t\t*1.    单向链表      *\n";
//	std::cout << "\t\t*2.    双向链表      *\n";
//	std::cout << "\t\t********************\n";
//}
//void Menu::ListMenu(void)
//{
//	std::cout << "\n\t\t********************\n";
//	std::cout << "\t\t*1.  添加链表节点  *\n";
//	std::cout << "\t\t*2.  删除链表节点  *\n";
//	std::cout << "\t\t*3.    排序链表    *\n";
//	std::cout << "\t\t*4.  显示当前链表  *\n";
//	std::cout << "\t\t*5.   奇偶调换     *\n";
//	std::cout << "\t\t*6.  找到链表中点  *\n";
//	std::cout << "\t\t*7.判断链表是否成环*\n";
//	std::cout << "\t\t*8.     帮 助      *\n";
//	std::cout << "\t\t*9.     退 出      *\n";
//	std::cout << "\t\t********************\n";
//
//}
//void Menu::SwitchMenu1(void)
//{
//	int a = 0;
//	std::cin >> a;
//	switch (a)
//	{
//	case 1:
//		SingleLinkedList::SingleLinkedList(0);
//		std::cout << "\t\t***** 请添加链表元素，支持连续添加，使用回车键分隔 *****\n";
//		int a;
//		std::cin >> a;
//		SingleLinkedList::Insert(a);
//		break;
//	case 2:
//		SingleLinkedList::
//			deleteNode();
//		break;
//	case 3:
//		sortNode();
//		break;
//	case 4:
//		showNode();
//		break;
//	case 5:
//		change1_2();
//		break;
//	case 6:
//		findMiddle();
//		break;
//	case 7:
//		judgeCircle();
//		break;
//	case 8:
//		help();
//		break;
//	case 9:
//		exit(0);
//	}
//}
//void Menu::SwitchMenu2(void)
//{
//	int a = 0;
//	cin >> a;
//	switch (a)
//	{
//	case 1:
//		Num.addNode();
//		break;
//	case 2:
//		deleteNode();
//		break;
//	case 3:
//		sortNode();
//		break;
//	case 4:
//		showNode();
//		break;
//	case 5:
//		change1_2();
//		break;
//	case 6:
//		findMiddle();
//		break;
//	case 7:
//		judgeCircle();
//		break;
//	case 8:
//		help();
//		break;
//	case 9:
//		exit(0);
//	}
//}
//
//SingleLinkedList::SingleLinkedList()
//{
//}
//
//SingleLinkedList::SingleLinkedList(int _data)
//{
//	head = new SingleLinkedListNode();
//	head->data = _data;
//	head->next = nullptr;
//}
//
//void SingleLinkedList::Insert(int NodeData)
//{
//	if (!head)
//	{
//		head = new SingleLinkedListNode();
//		head->data = NodeData;
//		head->next = nullptr;
//		return;
//	}
//	SingleLinkedListNode* NewNode = new SingleLinkedListNode();
//	NewNode->data = NodeData;
//	NewNode->next = nullptr;
//	SingleLinkedListNode* temp = head;
//	while (temp->next)
//	{
//		temp = temp->next;
//	}
//	temp->next = NewNode;
//}
//
//void SingleLinkedList::PrintList()
//{
//	if (!head)
//	{
//		std::cout << "Current list is empty! " << std::endl;
//		return;
//	}
//	SingleLinkedListNode* temp = head;
//	while (temp)
//	{
//		std::cout << temp->data << " ";
//		temp = temp->next;
//	}
//}
//
//DoubleLinkedList::DoubleLinkedList()
//{
//}
//
//DoubleLinkedList::DoubleLinkedList(int _data)
//{
//	head = new DoubleLinkedListNode();
//	head->data = _data;
//	head->previous = nullptr;
//	head->next = nullptr;
//}
//
//void DoubleLinkedList::Insert(int NodeData)
//{
//	if (!head)
//	{
//		head = new DoubleLinkedListNode();
//		head->data = NodeData;
//		head->previous = nullptr;
//		head->next = nullptr;
//		return;
//	}
//	DoubleLinkedListNode* NewNode = new DoubleLinkedListNode();
//	NewNode->data = NodeData;
//	DoubleLinkedListNode* temp = head;
//	while (temp->next)
//	{
//		temp = temp->next;
//	}
//	temp->next = NewNode;
//	NewNode->previous = temp;
//	NewNode->next = nullptr;
//}
//
//void DoubleLinkedList::PrintList()
//{
//	if (!head)
//	{
//		std::cout << "Current list is empty! " << std::endl;
//		return;
//	}
//	DoubleLinkedListNode* temp = head;
//	while (temp)
//	{
//		std::cout << temp->data << " ";
//		temp = temp->next;
//	}
//}
