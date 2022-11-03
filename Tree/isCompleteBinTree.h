#pragma once
#include <iostream>
#include <queue>
using namespace std;
#define INF 0x7fffffff

struct AVLNode
{
    int Num = -INF;
    AVLNode *left;
    AVLNode *right;
    int height = -INF;
};

void BFS(AVLNode *root)
{
    queue<AVLNode *> Q;
    bool isCompleteBT = 1, lastLine = 0;
    if (root)
        cout << root->Num;
    else
    {
        cout << "\nYes";
        return;
    }
    Q.push(root->left);
    Q.push(root->right);
    while (!Q.empty())
    {
        AVLNode *tmp = Q.front();
        Q.pop();
        if (lastLine && tmp)
        {
            isCompleteBT = 0;
        }
        if (!tmp)
        {
            lastLine = 1;
            continue;
        }
        cout << ' ' << tmp->Num;
        Q.push(tmp->left);
        Q.push(tmp->right);
    }


    if (isCompleteBT)
        cout << "\nYes";
    else
        cout << "\nNo";
    cout << '\n';
}