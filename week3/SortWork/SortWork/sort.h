#include <vector>
#include<iostream>
#include <fstream>
#include <sstream>
#include<time.h>
#include<stack>
using namespace std;
void MenuMeans();
void MenuData();
void MenuTinyData();
class SortMeans
{
public:
	//插入排序
	void InsertSort();
	//归并排序
	vector<int> merge(vector<int> a, vector<int> b);
	vector<int> MergeSort(vector<int>& a);
	//快速排序
	void QuickSort(vector<int>& a, int L, int R); //递归版本
	void QuickSortPlus(vector<int>& a, int left, int right);		//非递归版本
	//计数排序
	void CountSort();
	//基数计数排序
	void RadixCountSort();

public:
	void ValueAssignment();
	void ValuePrint();
	int ValueSave();	//返回值若为7，则即将进行小数据多次排序

public:
	vector<int> res;
	int n = res.size();


};