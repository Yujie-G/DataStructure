#include <queue>
#include <iostream>
using namespace std;
#define MAXN 1000
#define HEAD 0x7fffffff

class MaxHeap
{
    int CurrentSize;
    int *heap;
    void sortMax();

public:
    MaxHeap() : CurrentSize(0)
    {
        heap = new int[MAXN];
        heap[0] = HEAD;
    };
    ~MaxHeap() { delete[] heap; }
    void array2MaxHeap(int *, int);
    void Insert(const int &x);
    void deleteMax();
    void BFS();
};

void MaxHeap::sortMax()
{
    for (int i = CurrentSize / 2; i >= 1; i--)
    { // 从叶子结点的上一层开始
        int y = heap[i];
        int c = 2 * i;
        while (c <= CurrentSize)
        {
            if (c < CurrentSize && heap[c] <= heap[c + 1])
                ++c; // 选择大的孩子
            if (y >= heap[c])
                break;

            heap[c / 2] = heap[c]; // 交换
            c *= 2;                // 继续找其孩子
        }
        heap[c / 2] = y;
    }
}

void MaxHeap::Insert(const int &x)
{

    int i = ++CurrentSize;
    while (i != 1 && x > heap[i / 2])
    {
        // i不是根节点，且其值大于父节点的值，需要继续调整
        heap[i] = heap[i / 2]; // 父节点下降
        i /= 2;                // 继续向上，搜寻正确位置
    }

    heap[i] = x;
}

void MaxHeap::deleteMax()
{                                //
    int y = heap[CurrentSize--]; // 取最后一个节点，从根开始重整

    int i = 1, ci = 2;
    while (ci <= CurrentSize)
    {
        // 使ci指向i的两个孩子中较大者
        if (ci < CurrentSize && heap[ci] < heap[ci + 1])
            ci++;
        if (y >= heap[ci])
            break; // y的值大于等于孩子节点，退出

        // 继续向下，重整堆
        heap[i] = heap[ci]; // 大于父节点的孩子节点上升
        i = ci;             // 向下一层，继续搜索正确位置
        ci *= 2;
    }
    heap[i] = y;
}

void MaxHeap::BFS()
{
    for (int i = 1; i <= CurrentSize; ++i)
    {
        cout << heap[i] << ' ';
    }
    cout << '\n';
}

void MaxHeap::array2MaxHeap(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        heap[i + 1] = arr[i];
        ++CurrentSize;
    }
    this->sortMax();
}
