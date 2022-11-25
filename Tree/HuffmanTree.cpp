/* VScode_Version */

#include <iostream>
//#include <sstream>
//#include <cmath>
//#include <bitset>
//#include <iomanip>
//#include <cstring>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <list>
#include <queue>
//#include <stack>
//#include <set>
//#include <map>

#define RG register
#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff
using namespace std;


struct Node
{
    int weight;
    Node *left;
    Node *right;
    bool operator>(const Node& a)const{
        return weight>a.weight;
    }
};

Node* BuildHuffman()
{
    int leaf_num;cin>>leaf_num;
    priority_queue<Node,vector<Node>,greater<Node>>Q;

    for(int i=0;i<leaf_num;++i)
    {
        int w;cin>>w;
        Node *t = new Node{w,nullptr,nullptr};
        Q.push(*t);
    }

    while(Q.size()>1)
    {
        Node *left = nullptr, *right=nullptr;
        left = new Node{Q.top()};
        Q.pop();
        if(!Q.empty())
        {
            right = new Node{Q.top()};
            Q.pop();
        }
        Node *t = new Node;
        if(left && right)
        {
            t->weight = left->weight + right->weight;
        }
        else
        {
            t->weight = left->weight;
        }
        t->left = left;t->right = right;
        Q.push(*t);


    }
    // while(!Q.empty())
    // {
    //     cout<<Q.top().weight<<endl;
    //     Q.pop();
    // }
    Node *root = new Node{Q.top()};
    return root;

}

void Traverse(Node* root)
{
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* tmp = Q.front();
        Q.pop();
        cout<<tmp->weight<<endl;
        if(tmp->left)Q.push(tmp->left);
        if(tmp->right)Q.push(tmp->right);
    }

}
int main()
{
	Node* root = BuildHuffman();
    Traverse(root);


    system("pause");
	return 0;
}