#include "sort.h"

int main()
{
	SortMeans single;
LOOP:int a = single.ValueSave();//若选择小数据排序则a=7

	while (1)
	{
		int n = 1;
		if (a == 7)
		{
			n = 100000;
		}
		int b = 0;
		MenuMeans();
		cin >> b;
		switch (b)
		{
		case 1:
			single.ValueAssignment();
			clock_t start1, end1;
			start1 = clock();
			for (int i = 0; i < n; i++) {
				single.InsertSort();
			}
			end1 = clock();
			cout << "用时为:" << double(end1 - start1) / CLOCKS_PER_SEC << endl;
			break;
		case 2:
			single.ValueAssignment();
			clock_t start2, end2;
			start2 = clock();
			for (int i = 0; i < n; i++) {
				single.res = single.MergeSort(single.res);
			}
			end2 = clock();
			cout << "用时为:" << double(end2 - start2) / CLOCKS_PER_SEC << endl;
			break;
		case 3:
			single.ValueAssignment();
			clock_t start3, end3;
			start3 = clock();
			for (int i = 0; i < n; i++) {
				single.QuickSort(single.res, 0, single.n - 1);
			}
			end3 = clock();
			cout << "用时为:" << double(end3 - start3) / CLOCKS_PER_SEC << endl;
			break;
		case 4:
			single.ValueAssignment();
			clock_t start4, end4;
			start4 = clock();
			for (int i = 0; i < n; i++) {
				single.QuickSortPlus(single.res, 0, single.n - 1);
			}
			end4 = clock();
			cout << "用时为:" << double(end4 - start4) / CLOCKS_PER_SEC << endl;
			break;
		case 5:
			single.ValueAssignment();
			clock_t start5, end5;
			start5 = clock();
			for (int i = 0; i < n; i++) {
				single.CountSort();
			}
			end5 = clock();
			cout << "用时为:" << double(end5 - start5) / CLOCKS_PER_SEC << endl;
			break;
		case 6:
			single.ValueAssignment();
			clock_t start6, end6;
			start6 = clock();
			for (int i = 0; i < n; i++) {
				single.RadixCountSort();
			}
			end6 = clock();
			cout << "用时为:" << double(end6 - start6) / CLOCKS_PER_SEC << endl;

			break;
		case 7:
			goto LOOP;
			break;
		case 0:
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max());
			cout << "请输入正确的数字" << endl;
			cin >> b;
			break;
		default:
			cin >> b;
			break;
		}
		if (b > 0 && b < 8)
			break;
	}
}
