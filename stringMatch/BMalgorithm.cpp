#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <sstream>
//#include <cmath>
//#include <bitset>
//#include <iomanip>
//#include <cstring>
#include <string>
#include<functional>
#include <algorithm>
#include <vector>
//#include <list>
//#include <queue>
//#include <stack>
//#include <set>
//#include <map>

#define RG register
#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff
using namespace std;

int main()
{

	string tar, p;
	cin >> tar >> p;

	auto it = search(tar.begin(), tar.end(), boyer_moore_searcher(p.begin(), p.end()));
	if (it != tar.end())
		cout << it - tar.begin();
	else
		cout << 'N';

    system("pause");
	return 0;
}