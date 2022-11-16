#include <iostream>
#include <queue>
using namespace std;

int N, M;
struct Edge
{
    /* data */
    int u;
    int v;
    int dis;
    Edge *adj;
    bool operator >(const Edge &n)const { return dis > n.dis; }
};
Edge G[10000];
void init_G()
{
    for (int i = 0; i < N; ++i)
    {
        G[i] = {i, i, 0, nullptr};
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge *t1 = new Edge{u, v, w, nullptr};
        if (G[u].adj)
        {
            t1->adj = G[u].adj;
            G[u].adj = t1;
        }
        else
        {
            G[u].adj = t1;
        }
        Edge *t2 = new Edge{v, u, w, nullptr};
        if (G[v].adj)
        {
            t2->adj = G[v].adj;
            G[v].adj = t2;
        }
        else
        {
            G[v].adj = t2;
        }
    }

}

void prim()
{
    init_G();
    long long minPath = 0;int containNum = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    bool isVis[N]{0};

    Q.push(G[0]);
    while (!Q.empty() && containNum <= N)
    {
        int v = Q.top().v;
        int dis = Q.top().dis;
        Edge *tmp = G[v].adj;
        Q.pop();
        if(isVis[v])continue;
        isVis[v] = 1;
        minPath += dis;
        ++containNum;
        while (tmp)
        {
            if (!isVis[tmp->v])
                Q.push(*tmp);
            tmp = tmp->adj;
        }
    }

    cout << minPath << endl;
}

void test()
{
    N = 4;
    M = 5;
    prim();
}

int main()
{
    test();

    system("pause");
    return 0;
}