#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define n_size 7
#define INF 10000000
#define maxn 1000
vector<int> G[n_size] = {{0, 4, 6, 6, INF, INF, INF},
                         {INF, 0, 1, INF, 7, INF, INF},
                         {INF, INF, 0, INF, 6, 4, INF},
                         {INF, INF, 2, 0, INF, 5, INF},
                         {INF, INF, INF, INF, 0, INF, 6},
                         {INF, INF, INF, INF, 1, 0, 8},
                         {INF, INF, INF, INF, INF, INF, 0}};


//! O(n^2) primitive implement
int *Dijkstra(int begin)
{
    int *dis = new int[n_size];
    bool isVisited[n_size];

    // init
    for (int i = 0; i < n_size; ++i)
    {
        isVisited[i] = 0;
        dis[i] = G[begin][i];
    }

    isVisited[begin] = 1;
    int contained_num = 1;

    while (contained_num < n_size)
    {
        int min_ = INF, pos = -1;
        for (int i = 0; i < n_size; ++i)
        {
            if (dis[i] && !isVisited[i] && dis[i] < min_)
            {
                min_ = dis[i];
                pos = i;
            }
        }
        if (pos == -1)
            return nullptr;
        isVisited[pos] = 1;
        ++contained_num;

        // update
        for (int j = 0; j < n_size; ++j)
        {
            if (dis[j] && !isVisited[j])
            {
                dis[j] = min(dis[j], dis[pos] + G[pos][j]);
            }
        }
    }
    return dis;
}

/*************************************************************************************/
//! 优先队列优化版本
struct node
{
    int dis, u;

    bool operator>(const node &a) const { return dis > a.dis; }
};

int dis[maxn], vis[maxn];

void dijkstra(int s)
{
    for(int i=0;i<maxn;++i) dis[i] = INF;
    priority_queue<node, vector<node>, greater<node>> q;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for(int i=0;i<n_size;++i)
        {
            if(dis[i] > dis[u] + G[u][i])
            {
                dis[i] = dis[u] + G[u][i];
                q.push({dis[i], i});
            }
        }
    }
}

int main()
{
    dijkstra(0);
    for(int i=0;i<n_size;++i)
    {
        cout<<dis[i]<<' ';
    }
    system("pause");
    return 0;
}