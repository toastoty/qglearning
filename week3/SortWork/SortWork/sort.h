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
	//��������
	void InsertSort();
	//�鲢����
	vector<int> merge(vector<int> a, vector<int> b);
	vector<int> MergeSort(vector<int>& a);
	//��������
	void QuickSort(vector<int>& a, int L, int R); //�ݹ�汾
	void QuickSortPlus(vector<int>& a, int left, int right);		//�ǵݹ�汾
	//��������
	void CountSort();
	//������������
	void RadixCountSort();

public:
	void ValueAssignment();
	void ValuePrint();
	int ValueSave();	//����ֵ��Ϊ7���򼴽�����С���ݶ������

public:
	vector<int> res;
	int n = res.size();


};