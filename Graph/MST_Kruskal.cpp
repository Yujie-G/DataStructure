#include "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\Union_Find_Set.h"
#include <iostream>
#include <queue>
using namespace std;

int N, M;
struct Edge
{
    /* data */
    int begin;
    int end;
    int w;
    bool operator>(const Edge &a) const { return w > a.w; }
};

priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
void init_EdgeQ()
{
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Q.push({u, v, w});
    }
}
void kruskal()
{
    UFset Fore(N);
    init_EdgeQ();
    long long minPath = 0;

    while (!Q.empty())
    {
        Edge tmp = Q.top();
        Q.pop();
        int root1 = Fore.Find(tmp.begin);
        int root2 = Fore.Find(tmp.end);
        if (root1 == root2)
            continue;

        Fore.Union(root1, root2);
        minPath += tmp.w;
    }
    cout << minPath;
    //Fore.print();
}


void test()
{
    N = 4;M=5;
    kruskal();
}

int main()
{
    test();
    system("pause");
    return 0;
}
