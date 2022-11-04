/** 任意n个互异点均将实轴分为n一1段有界区间,另加两段无界的
其中，哪一段最长？//maxGap
采用分桶策略，可改进至O(n)时间
找到最左点、最右点//一趟线性扫描
将有效范围均匀地划分为n一1段（桶）//相当于散列表
通过散列，将各点归入对应的桶//模余法
在各桶中，动态记录最左点、最右点//可能相同甚至没有
算出相邻（非空）桶之间的“距离'//一趟遍历足矣
最大的距离即maxGap//画家算法
※正确性：maxGap至少与（相邻的）两个桶相交
等价地，定义MaxGap的点不可能属于同一个桶
*/

#include <iostream>
using namespace std;
#define INF 0x7FFFFFFF

int seed;
int rand() { return (((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff); }
int rand32()
{
    return ((rand() << 16) + (rand() << 1) + rand() % 2);
}

int main()
{
    int maxGap = 0;
    int NodeNum;
    cin >> NodeNum >> seed;
    int Min = INF, Max = 0;
    int *Node = new int[NodeNum]{0};
    for (int i = 0; i < NodeNum; ++i)
    {
        int tmp = rand32();
        Node[i] = tmp;
        Min = min(Min, tmp);
        Max = max(Max, tmp);
    }
    int squeeze = (Max - Min + 1) / (NodeNum - 1) + !!((Max - Min + 1) % (NodeNum - 1));

    int *hash = new int[3 * (NodeNum - 1)]{0};
    for (int i = 0; i < NodeNum; ++i)
    {
        int pos = 3 * ((Node[i] - Min) / squeeze);
        if (!hash[pos])
        {
            hash[pos] = 1;
            hash[pos + 1] = hash[pos + 2] = Node[i];
        }
        else
        {
            if (Node[i] < hash[pos + 1])
                hash[pos + 1] = Node[i];
            if (Node[i] > hash[pos + 2])
                hash[pos + 2] = Node[i];
        }
    }

    int left = 0, right = 0;
    for (int i = 0; i < 3 * NodeNum - 1; i += 3)
    {
        if (hash[i])
        {
            right = hash[i + 1];
            maxGap = max(maxGap, right - left);
            left = hash[i + 2];
        }
    }

    cout << maxGap;
}
