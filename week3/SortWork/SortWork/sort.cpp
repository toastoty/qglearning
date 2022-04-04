#include "sort.h"

void SortMeans::ValueAssignment()
{
	res.clear();
	ifstream data("test.txt"); //待读取文件的目录
	string line;
	while (getline(data, line)) {
		stringstream ss; //输入流
		ss << line; //向流中传值
		if (!ss.eof()) {
			int temp;
			while (ss >> temp) //提取int数据
				res.push_back(temp); //保存到vector
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
					//一百个数据
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
					//十个数据
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
			cout << "请输入正确的数字" << endl;
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
void SortMeans::QuickSort(vector<int>& a, int L, int R)//递归版本
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

//划分算法
int Partition(vector<int> a, int low, int high)
{
	//假设每次都以第一个元素作为枢轴值，进行一趟划分：
	int pivot = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= pivot)
			--high;
		a[low] = a[high];  //停下来做交换 
		while (low < high && a[low] <= pivot)
			++low;
		a[high] = a[low];  //停下来做交换 
	}

	a[low] = pivot;  //pivot的最终落点 
	return low;
}

void SortMeans::QuickSortPlus(vector<int>& a, int left, int right)
{
	//手动利用栈来存储每次分块快排的起始点
	//栈非空时循环获取中轴入栈
	stack<int> s;
	if (left < right)
	{
		int boundary = Partition(a, left, right);

		if (boundary - 1 > left) //确保左分区存在 
		{
			//将左分区端点入栈 
			s.push(left);
			s.push(boundary - 1);
		}
		if (boundary + 1 < right) //确保右分区存在 
		{
			s.push(boundary + 1);
			s.push(right);
		}

		while (!s.empty())
		{
			//得到某分区的左右边界 
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();

			boundary = Partition(a, l, r);
			if (boundary - 1 > l) //确保左分区存在 
			{
				//将左分区端点入栈 
				s.push(l);
				s.push(boundary - 1);
			}
			if (boundary + 1 < r) //确保右分区存在 
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
	cout << "用时为:" << double(end - start) / CLOCKS_PER_SEC << endl;
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
			k = (res[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (res[j] / radix) % 10;
			tmp[count[k] - 1] = res[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到res中
			res[j] = tmp[j];
		radix = radix * 10;

	}
	end = clock();
	cout << "用时为:" << double(end - start) / CLOCKS_PER_SEC << endl;
}