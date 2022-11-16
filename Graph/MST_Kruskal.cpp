#include "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\Union_Find_Set.h"
#include <iostream>
#include <queue>
#include <algorithm>
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

class Solution {  //Kruskal
public:
    struct edge{
        int s,e,w;
        edge(int a,int b,int c):s(a),e(b),w(c){}
        bool operator <(const edge& g){return w<g.w;}
    };
    int find(int n){
        if(fa[n]==n) return n;
        fa[n]=find(fa[n]);
        return fa[n];
    }
    vector<int> fa;
    vector<edge> nums;
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i=0;i<points.size();i++) fa.push_back(i);
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                nums.push_back(edge(i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])));
            }
        }
        sort(nums.begin(),nums.end());
        int cnt=0,res=0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i].s,b=nums[i].e,c=nums[i].w;
            int na=find(a),nb=find(b);
            if(na!=nb){
                cnt++;
                res+=c;
                fa[na]=nb;
            }
            if(cnt==points.size()-1) break;
        }
        return res;
    }
};

int main()
{
    test();
    system("pause");
    return 0;
}
