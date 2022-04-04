#include "sort.h"

void MenuData()
{
	std::cout << "\n\t\t********************\n";
	std::cout << "\t\t*     选择数据量    *\n";
	std::cout << "\t\t*                   *\n";
	std::cout << "\t\t*1.    10000顺序    *\n";
	std::cout << "\t\t*2.    10000逆序    *\n";
	std::cout << "\t\t*3.    50000顺序    *\n";
	std::cout << "\t\t*4.    50000逆序    *\n";
	std::cout << "\t\t*5.   200000顺序    *\n";
	std::cout << "\t\t*6.   200000逆序    *\n";
	std::cout << "\t\t*7.   大量小数据    *\n";
	std::cout << "\t\t*8.    退出程序     *\n";
	std::cout << "\t\t*********************\n";
}
void MenuTinyData()
{
	std::cout << "\n\t\t********************\n";
	std::cout << "\t\t*     选择数据量    *\n";
	std::cout << "\t\t*                   *\n";
	std::cout << "\t\t*1.100个数据*100k次 *\n";
	std::cout << "\t\t*2.10个数据*100k次  *\n";
	std::cout << "\t\t*********************\n";
}
void MenuMeans()
{
	std::cout << "\n\t\t*********************\n";
	std::cout << "\t\t*    选择排序方式    *\n";
	std::cout << "\t\t*                    *\n";
	std::cout << "\t\t*1.    插入排序      *\n";
	std::cout << "\t\t*2.    归并排序      *\n";
	std::cout << "\t\t*3.  快速排序(递归)  *\n";
	std::cout << "\t\t*4. 快速排序(非递归) *\n";
	std::cout << "\t\t*5.    计数排序      *\n";
	std::cout << "\t\t*6.  基数计数排序    *\n";
	std::cout << "\t\t*7.  返回上一菜单    *\n";
	std::cout << "\t\t*********************\n";
}