#include "sort.h"

void SortMeans::ValueAssignment()
{
	res.clear();
	ifstream data("test.txt"); //����ȡ�ļ���Ŀ¼
	string line;
	while (getline(data, line)) {
		stringstream ss; //������
		ss << line; //�����д�ֵ
		if (!ss.eof()) {
			int temp;
			while (ss >> temp) //��ȡint����
				res.push_back(temp); //���浽vector
		}
	}
	n = res.size();
}

void SortMeans::ValuePrint()
{

	for (int i = 0; i < n; i++)
		cout << res[i] << endl;

}
int SortMeans::ValueSave()
{
	while (1)
	{
		MenuData();
		int a = 0;
		ofstream f("test.txt", ios::ate);
		cin >> a;
		int j = 0;
		int n = 10;

		switch (a)
		{
		case 1:

			for (int i = 0; i < 1000; i++)
			{
				for (; j < n; ++j) {
					f << j << " ";
				}
				n += 10;
				f << "\n";
			}
			break;
		case 2:
			n = 9989;
			j = 9999;
			for (int i = 0; i < 1000; i++)
			{
				for (; j > n; --j) {
					f << j << " ";
				}
				n -= 10;
				f << "\n";
			}
			break;
		case 3:
			for (int i = 0; i < 5000; i++)
			{
				for (; j < n; ++j) {
					f << j << " ";
				}
				n += 10;
				f << "\n";
			}
			break;
		case 4:
			n = 49989;
			j = 49999;
			for (int i = 0; i < 5000; i++)
			{
				for (; j > n; --j) {
					f << j << " ";
				}
				n -= 10;
				f << "\n";
			}
			break;
		case 5:
			for (int i = 0; i < 20000; i++)
			{
				for (; j < n; ++j) {
					f << j << " ";
				}
				n += 10;
				f << "\n";
			}
			break;
		case 6:
			n = 199989;
			j = 199999;
			for (int i = 0; i < 20000; i++)
			{
				for (; j > n; --j) {
					f << j << " ";
				}
				n -= 10;
				f << "\n";
			}
			break;
		case 7:

			while (1)
			{
				MenuTinyData();
				int b = 0;
				cin >> b;
				switch (b)
				{
				case 1:
					//һ�ٸ�����
					for (int i = 0; i < 10; i++)
					{
						for (; j < n; ++j) {
							f << j << " ";
						}
						n += 10;
						f << "\n";
					}
					break;
				case 2:
					//ʮ������
					for (int i = 0; i < 1; i++)
					{
						for (; j < n; ++j) {
							f << j << " ";
						}
						n += 10;
						f << "\n";
					}
					break;
				case 0:

					break;
				default:
					cin >> b;
					break;
				}
				if (b > 0 && b < 3)
					break;
			}
			break;

		case 8:
			exit(0);
		default:
			cin >> a;
			break;
		case 0:
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max());
			cout << "��������ȷ������" << endl;
			cin >> a;
			break;
		}

		if (a > 0 && a < 9)
			return a;
		break;
	}

}

void SortMeans::InsertSort()
{
	int i, j, tmp;

	for (i = 1; i < n; i++)
	{
		j = i;
		tmp = res[i];
		while (j > 0 && tmp < res[j - 1])
		{
			res[j] = res[j - 1];
			j--;
		}
		res[j] = tmp;
	}

}

vector<int> SortMeans::merge(vector<int> a, vector<int> b)
{
	res.clear();
	vector<int> res;
	size_t ai = 0, bi = 0;
	while (ai < a.size() && bi < b.size())
	{
		if (a[ai] <= b[bi])
			res.push_back(a[ai++]);
		else
			res.push_back(b[bi++]);
	}
	if (ai == a.size())
		res.insert(res.end(), b.begin() + bi, b.end());
	else if (bi == b.size())
		res.insert(res.end(), a.begin() + ai, a.end());
	return res;
}

vector<int> SortMeans::MergeSort(vector<int>& a)
{

	if (a.size() < 2)
		return a;
	const size_t mid = a.size() / 2;
	vector<int> left(a.begin(), a.begin() + mid);
	vector<int> right(a.begin() + mid, a.end());
	return merge(MergeSort(left), MergeSort(right));


}
void SortMeans::QuickSort(vector<int>& a, int L, int R)//�ݹ�汾
{

	if (L >= R)
		return;
	int left = L, right = R;
	int pivot = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= pivot)
		{
			right--;
		}
		if (left < right)
		{
			a[left++] = a[right];
		}
		while (left < right && a[left] <= pivot)
		{
			left++;
		}
		if (left < right)
		{
			a[right--] = a[left];
		}
		if (left >= right)
		{
			a[left] = pivot;
		}
	}
	QuickSort(a, L, right - 1);
	QuickSort(a, right + 1, R);
}

//�����㷨
int Partition(vector<int> a, int low, int high)
{
	//����ÿ�ζ��Ե�һ��Ԫ����Ϊ����ֵ������һ�˻��֣�
	int pivot = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= pivot)
			--high;
		a[low] = a[high];  //ͣ���������� 
		while (low < high && a[low] <= pivot)
			++low;
		a[high] = a[low];  //ͣ���������� 
	}

	a[low] = pivot;  //pivot��������� 
	return low;
}

void SortMeans::QuickSortPlus(vector<int>& a, int left, int right)
{
	//�ֶ�����ջ���洢ÿ�ηֿ���ŵ���ʼ��
	//ջ�ǿ�ʱѭ����ȡ������ջ
	stack<int> s;
	if (left < right)
	{
		int boundary = Partition(a, left, right);

		if (boundary - 1 > left) //ȷ����������� 
		{
			//��������˵���ջ 
			s.push(left);
			s.push(boundary - 1);
		}
		if (boundary + 1 < right) //ȷ���ҷ������� 
		{
			s.push(boundary + 1);
			s.push(right);
		}

		while (!s.empty())
		{
			//�õ�ĳ���������ұ߽� 
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();

			boundary = Partition(a, l, r);
			if (boundary - 1 > l) //ȷ����������� 
			{
				//��������˵���ջ 
				s.push(l);
				s.push(boundary - 1);
			}
			if (boundary + 1 < r) //ȷ���ҷ������� 
			{
				s.push(boundary + 1);
				s.push(r);
			}
		}
	}

}
void SortMeans::CountSort()
{
	clock_t start, end;
	start = clock();
	int max = res[0], min = res[0];
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] > max)
		{
			max = res[i];
		}
		if (res[i] < min)
		{
			min = res[i];
		}
	}
	vector<int> tempList;
	for (int i = 0; i < (max - min) + 2; i++)
	{
		tempList.push_back(0);
	}

	for (int i = 0; i < res.size(); i++)
	{
		tempList[res[i] - min]++;
	}
	res.clear();

	for (int j = 0; j < tempList.size(); j++)
	{
		while (tempList[j] > 0)
		{
			tempList[j]--;
			res.push_back(j + min);
		}
	}
	end = clock();
	cout << "��ʱΪ:" << double(end - start) / CLOCKS_PER_SEC << endl;
}
void SortMeans::RadixCountSort()
{
	clock_t start, end;
	start = clock();
	int max = 1;
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (res[i] >= p)
		{
			p *= 10;
			++max;
		}
	}
	vector<int> tmp(n);
	int i, j, k;
	int count[10];
	int radix = 1;
	for (i = 1; i <= max; i++)
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; j < n; j++)
		{
			k = (res[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
		for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (res[j] / radix) % 10;
			tmp[count[k] - 1] = res[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�res��
			res[j] = tmp[j];
		radix = radix * 10;

	}
	end = clock();
	cout << "��ʱΪ:" << double(end - start) / CLOCKS_PER_SEC << endl;
}