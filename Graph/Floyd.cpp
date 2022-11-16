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
#define INF 100000
#define MAXN 1000
using namespace std;

int G[MAXN][MAXN]= {{0, 4, 6, 6, INF, INF, INF},
         {INF, 0, 1, INF, 7, INF, INF},
         {INF, INF, 0, INF, 6, 4, INF},
         {INF, INF, 2, 0, INF, 5, INF},
         {INF, INF, INF, INF, 0, INF, 6},
         {INF, INF, INF, INF, 1, 0, 8},
         {INF, INF, INF, INF, INF, INF, 0}};
int N;
int **path;
int **dis;

bool Floyed()
{
    // init
    path = new int *[N];
    dis = new int *[N];

    for (int i = 0; i < N; ++i)
    {
        path[i] = new int[N];
        dis[i] = new int[N];
        for (int j = 0; j < N; ++j)
        {
            dis[i][j] = G[i][j];
            path[i][j] = -1;
        }
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    if (i == j && dis[i][j] < 0) /* 若发现负值圈 */
                        return false;            /* 不能正确解决，返回错误标记 */
                    path[i][j] = k;
                }
    return true;
}

void print()
{
    cout<<"dis:\n";
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        cout<<dis[i][j]<<' ';
        cout<<endl;
    }
    cout<<"path:\n";
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        cout<<path[i][j]<<' ';
        cout<<endl;
    }
}
int main()
{
    N=7;
    Floyed();
    print();

    system("pause");
    return 0;
}