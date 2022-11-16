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
#define INF 0x7fffffff
using namespace std;

struct Edge
{
    int end;
    int w;
    Edge *adj;
};
class Graph
{
    Edge **G;
    int NodeNum;

public:
    Graph(int n, int edgeNum) : NodeNum(n)
    {
        G = new Edge *[NodeNum + 5]
        { nullptr };
        for (int i = 0; i < edgeNum; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            Edge *t = new Edge;
            t->end = v;
            t->w = w;
            t->adj = nullptr;
            if (!G[u])
            {
                G[u] = t;
            }
            else
            {
                t->adj = G[u];
                G[u] = t;
            }
        }
    }

    void BFS(int begin)
    {
        bool isVis[NodeNum]{0};
        queue<int> Q;
        Q.push(begin);
        while (!Q.empty())
        {
            int b = Q.front();
            Q.pop();
            Edge *tmp = G[b];
            if (isVis[b])
                continue;
            isVis[b] = true;
            cout << b << ' ';

            while (tmp)
            {
                Q.push(tmp->end);
                tmp = tmp->adj;
            }
        }
    }

    bool isVis[1000]{0};
    void DFS(int begin)
    {
        if(isVis[begin]) return;
        isVis[begin] = true;
        cout<<begin<<' ';
        Edge* t = G[begin];
        while(t)
        {
            DFS(t->end);
            t = t->adj;
        }
    }
};
int main()
{
    Graph G1(5, 5);
    G1.DFS(4);
    system("pause");
    return 0;
}