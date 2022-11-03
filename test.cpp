/* VScode_Version */

#include <iostream>
// #include <sstream>
// #include <cmath>
// #include <bitset>
// #include <iomanip>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <vector>
// #include <list>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>

#define RG register
#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff
using namespace std;

int main()
{
    int *a = new int{10};
    delete a;
    if (a == nullptr)
        cout << "dad";
    cout << *a;

    system("pause");
    return 0;
}