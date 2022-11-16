#pragma once

#include <iostream>
#define MAXN 10000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */

//! 用负数代表这一集合的rank,parent为负数的结点为根
class UFset
{
    SetType S;
    int size;

public:
    UFset(int N):size(N)
    { /* 初始化并查集 */
        ElementType X;
        for (X = 0; X < N; X++)
            S[X] = -1;
    }

    void Union(SetName Root1, SetName Root2);
    SetName Find(ElementType X);
    void print();
};

void UFset::Union(SetName Root1, SetName Root2)
{ /* 这里默认Root1和Root2是不同集合的根结点 */
    /* 保证小集合并入大集合 */
    if (S[Root2] < S[Root1])
    {                         /* 如果集合2比较大 */
        S[Root2] += S[Root1]; /* 集合1并入集合2  */
        S[Root1] = Root2;
    }
    else
    {                         /* 如果集合1比较大 */
        S[Root1] += S[Root2]; /* 集合2并入集合1  */
        S[Root2] = Root1;
    }
}

SetName UFset::Find(ElementType X)
{                 /* 默认集合元素全部初始化为-1 */
    if (S[X] < 0) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find(S[X]); /* 路径压缩 */
}

void UFset::print()
{
    int count=0;

    for(int i=0;i<size;++i)
    {
        std::cout<<i<<"  p:  "<<S[i]<<std::endl;
        if(S[i]<0)++count;
    }
    std::cout<<"setNum: "<<count<<std::endl;

}