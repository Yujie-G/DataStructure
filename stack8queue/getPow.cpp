/*! 题目描述

给定一个常数项为0的二元一次多项式，求该多项式的幂。

设未知数为x,y，输入为x和y的整数系数a,b以及整数幂n，输出形如以下样式

求幂运算的结果，按照x的幂降序排列
Input Format

输入未知数整数系数 a,b (-100<a,b<100),n (1<n<6)
Output Format

幂运算的结果的多项式，按照x幂降序排列
Example
Input

2 3 2
Output

4x^2+12xy+9y^2
说明

幂为1时不输出^1

系数为1时不输出系数，-1只输出负号。
*/
#include <iostream>
// #include <sstream>
// #include <cmath>
// #include <bitset>
// #include <iomanip>
// #include <cstring>
// #include <string>
#include <algorithm>
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

struct Son
{
    LL num = 0;
    int p = 0;
};

Son dp[6][35];
int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
    {
        cout << 0;
        return 0;
    }
    int n;
    cin >> n;
    dp[1][1].p = 1;

    dp[1][1].num = a;
    dp[1][2].num = b;
    for (int i = 2; i <= 5; ++i)
    {
        for (int j = 1; j <= (2 << i - 2); ++j)
        {
            dp[i][j].num = dp[i - 1][j].num * a;
            dp[i][j].p = dp[i - 1][j].p + 1;

            dp[i][(2 << i - 1) + 1 - j].num = dp[i - 1][(2 << i - 2) + 1 - j].num * b;
            dp[i][(2 << i - 1) + 1 - j].p = dp[i - 1][(2 << i - 2) + 1 - j].p;
        }
    }

    sort(dp[n] + 1, dp[n] + (2 << n - 1), [](Son a, Son b)
         { return a.p > b.p; });

    LL tmp_p = n, num = 0;
    // bool flag_ = 0;
    for (int i = 1; i <= (2 << n - 1); ++i)
    {
        if (dp[n][i].p == tmp_p)
        {
            num += dp[n][i].num;
        }
        else
        {
            // print former
            if (num == 0)
                goto K;
            if (num == -1)
            {
                cout << '-';
                goto L;
            }
            if (num == 1)
                goto L;
            if (num > 0 && i != 2)
                cout << '+' << num;
            else
                cout << num;

        L:
            cout << "x";
            if (tmp_p != 1)
                cout << "^" << tmp_p;
            if (n - tmp_p == 1)
                cout << "y";
            else if (n - tmp_p == 0)
                ;
            else
                cout << "y^" << n - tmp_p;

        K:
            //
            num = dp[n][i].num;
            tmp_p = dp[n][i].p;
        }
    }
    if (num == 0)
        return 0;
    if (num == 1)
    {
        if (a == 0)
            goto J;
        cout << '+';
    }
    else if (num == -1)
        cout << '-';
    else if (num > 0 && a != 0)
        cout << '+' << num;
    else
        cout << num;
J:
    cout << "y^" << n - tmp_p;

    return 0;
}