#include "Structure.h"

void Menu::MainMenu()
{
	std::cout << "\n\t\t********************\n";
	std::cout << "\t\t*1.    ��������      *\n";
	std::cout << "\t\t*2.    ˫������      *\n";
	std::cout << "\t\t********************\n";
	int c;
	std::cin >> c;
	bool o = true;
	SingleLinkedListNode* Shead = new(SingleLinkedListNode);
	DoubleLinkedListNode* Dhead = nullptr;
	Shead->next = nullptr;

	while (1)
	{
		switch (c)
		{
		case 1:


			o = SwitchMenu1(Shead);
			break;
		case 2:

			o = SwitchMenu2(Dhead);
			break;
		default:
			std::cout << "\t\t*** ��������ȷ���� ***\n" << std::endl;
			break;

		}
		system("cls");
		std::cout << "\n\t\t********************\n";
		std::cout << "\t\t*1.    ��������      *\n";
		std::cout << "\t\t*2.    ˫������      *\n";
		std::cout << "\t\t********************\n";
		std::cin >> c;
	}
}

void Menu::ListMenu(void)
{
	std::cout << "\n\t\t********************\n";
	std::cout << "\t\t*1.  �������ڵ�  *\n";
	std::cout << "\t\t*2.  ɾ������ڵ�  *\n";
	std::cout << "\t\t*3.    ��������    *\n";
	std::cout << "\t\t*4.  ��ʾ��ǰ����  *\n";
	std::cout << "\t\t*5.   ��ż����     *\n";
	std::cout << "\t\t*6.  �ҵ������е�  *\n";
	std::cout << "\t\t*7.�ж������Ƿ�ɻ�*\n";
	std::cout << "\t\t*8.     �� ��      *\n";
	std::cout << "\t\t*9.    ��ת����    *\n";
	std::cout << "\t\t*0.     �� ��      *\n";
	std::cout << "\t\t********************\n";

}

SingleLinkedListNode* Menu::SwitchMenu1(SingleLinkedListNode* Shead)
{
	SingleLinkedList SL;
	while (1)
	{
		ListMenu();
		int a = 0;
		std::cin >> a;

		switch (a)
		{
		case 1:

			SingleLinkedList::SingleLinkedList();
			std::cout << "\t\t***** ���������Ԫ��,ʹ�ûس����ָ�,���� 0 ������� *****\n";
			int b;
			std::cin >> b;
			while (b)
			{
				Shead = SL.Insert(b, Shead);
				std::cin >> b;
			}
			break;
		case 2:
			int c;
			SL.PrintList(Shead);
			std::cout << "\t\t***** ��������ɾ���Ľڵ����,ʹ�ûس����ָ�,���� 0 ����ɾ�� *****\n";
			std::cin >> c;
			while (c)
			{

				SL.DeleteNode(c, Shead);
				SL.PrintList(Shead);
				std::cin >> c;
			}
			break;
		case 3:
			SL.SortList(Shead);
			SL.PrintList(Shead);
			break;
		case 4:
			SL.PrintList(Shead);
			break;
		case 5:
			SL.ListChange(Shead);
			SL.PrintList(Shead);
			break;
		case 6:
			SL.FindMiddle(Shead);
			break;
		case 7:
			SL.JudgeCircle(Shead);
			break;
		case 8:
			std::cout << "\t\t** ��ǰΪ��������  **" << std::endl;
			break;
		case 9:
			int d;
			std::cout << "\t\t*   ѡ��ת��ʽ   *\n";
			std::cout << "\t\t********************\n";
			std::cout << "\t\t*1.    �ݹ鷴ת    *\n";
			std::cout << "\t\t*2.    ������ת    *\n";
			std::cout << "\t\t********************\n";
			std::cin >> d;

			switch (d)
			{
			case 1:
				Shead = SL.RecursionRollBackList(Shead);
				break;
			case 2:
				Shead = SL.IterativeRollBackList(Shead);
				break;
			default:
				std::cout << "\t\t*** ��������ȷ���� ***\n" << std::endl;
				std::cin >> d;
				break;
			}
			SL.PrintList(Shead);
			break;
		case 0:
			return Shead;
			break;
		}
	}
}
DoubleLinkedListNode* Menu::SwitchMenu2(DoubleLinkedListNode* Dhead)
{
	DoubleLinkedList DL;
	while (1)
	{
		ListMenu();
		int a = 0;
		std::cin >> a;

		switch (a)
		{
		case 1:

			DoubleLinkedList::DoubleLinkedList();
			std::cout << "\t\t***** ���������Ԫ��,ʹ�ûس����ָ�,���� 0 ������� *****\n";
			int b;
			std::cin >> b;
			while (b)
			{
				Dhead = DL.Insert(b, Dhead);
				std::cin >> b;
			}
			break;
		case 2:
			int c;
			DL.PrintList(Dhead);
			std::cout << "\t\t***** ��������ɾ���Ľڵ����,ʹ�ûس����ָ�,���� 0 ����ɾ�� *****\n";
			std::cin >> c;
			while (c)
			{

				Dhead = DL.DeleteNode(c, Dhead);
				DL.PrintList(Dhead);
				std::cin >> c;
			}
			break;
		case 3:
			DL.SortList(Dhead);
			DL.PrintList(Dhead);
			break;
		case 4:
			DL.PrintList(Dhead);
			break;
		case 5:
			DL.ListChange(Dhead);
			DL.PrintList(Dhead);
			break;
		case 6:
			DL.FindMiddle(Dhead);
			break;
		case 7:
			DL.JudgeCircle(Dhead);
			break;
		case 8:
			std::cout << "\t\t** ��ǰΪ˫������  **" << std::endl;
			break;
		case 9:
			int d;
			std::cout << "\t\t*   ѡ��ת��ʽ   *\n";
			std::cout << "\t\t********************\n";
			std::cout << "\t\t*1.    �ݹ鷴ת    *\n";
			std::cout << "\t\t*2.    ������ת    *\n";
			std::cout << "\t\t********************\n";
			std::cin >> d;

			switch (d)
			{
			case 1:
				Dhead = DL.RecursionRollBackList(Dhead);
				break;
			case 2:
				Dhead = DL.IterativeRollBackList(Dhead);
				break;
			default:
				std::cout << "\t\t*** ��������ȷ���� ***\n" << std::endl;
				std::cin >> d;
				break;
			}
			DL.PrintList(Dhead);
			break;
		case 0:
			return Dhead;
			break;
		}
	}
}
