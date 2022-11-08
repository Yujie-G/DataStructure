/*! 一个刚出锅的山芋，在围成一圈的n（以编号1，2，3...n分别表示 ）个孩子间传递。
大家一起数数，从编号为1的孩子开始报数，每数一次，当前拿着山芋的孩子就把山芋交给紧邻其右的孩子。
一旦数到事先约定的某个数k ， 那个人就出列，他的下一个人又从1开始报数，数到数k的那个人就出列。
如此反复，最后剩下的那个孩子就是幸运者。

试实现算法josephus（int n, int k），输出孩子们出列的次序

程序输入：n k

程序输出：孩子们出列的次序
*/
#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <cmath>
//#include <iomanip>
//#include <cstring>
//#include <cstdlib>
//#include <string>
//#include <algorithm>
#include <vector>
#include <list>
//#include <queue>
//#include <stack>
//#include <set>
#include <map>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	list<int> rim;
	for (int i = 1; i < n + 1; i++)
	{
		rim.push_back(i);
	}

	list<int>::iterator tmp = rim.begin();
	while (rim.size() > 1)
	{
		int k = m;
		while (k > 1)
		{
			++tmp;
			if (tmp == rim.end())
				tmp = rim.begin();
			--k;
		}

		cout << *tmp << "->";
		list<int>::iterator target = tmp;
		++tmp;
		rim.erase(target);

		if (tmp == rim.end())
			tmp = rim.begin();
	}

	cout << rim.front();

	return 0;
}