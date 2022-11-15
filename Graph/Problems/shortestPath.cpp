// https://www.luogu.com.cn/problem/P1629
/* VScode_Version */

#include <iostream>
// #include <sstream>
// #include <cmath>
// #include <bitset>
// #include <iomanip>
// #include <cstring>
// #include <string>
// #include <algorithm>
#include <vector>
// #include <list>
#include <queue>
// #include <stack>
// #include <set>
// #include <map>

#define RG register
#define LL long long
#define ULL unsigned long long
#define INF 10010
using namespace std;
#define MAXN 1000

int dis[MAXN + 5];
int n;

struct Node
{
    int n;
    int dis;
    bool operator>(const Node &p) const { return dis > p.dis; }
};

vector<Node> G[MAXN + 5];

void dijkstra(int s)
{
    bool isVis[MAXN];
    for (int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
        isVis[i] = 0;
    }
    priority_queue<Node, vector<Node>, greater<Node>> Q;
    Q.push({s, 0});
    dis[s] = 0;
    while (!Q.empty())
    {
        int t = Q.top().n;
        Q.pop();
        if (isVis[t])
            continue;
        isVis[t] = 1;
        for (auto Nd : G[t])
        {
            int _n = Nd.n;
            int d = Nd.dis;
            if (dis[_n] > dis[t] + d)
            {
                dis[_n] = dis[t] + d;
                Q.push({_n, dis[_n]});
            }
        }
    }
}


int main()
{
    int m;
    LL ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    // for(int i=1;i<=n;++i)
    // {
    //     for(auto &j:G[i])
    //     cout<<j.n<<' ';
    //     cout<<'\n';
    // }
    dijkstra(1);
    for (int i = 1; i <= n; ++i)
        ans += dis[i];
    for(int i=2;i<=n;++i)
    {
        dijkstra(i);
        ans+=dis[1];
    }

    cout << ans;
    system("pause");
    return 0;
}