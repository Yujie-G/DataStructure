/*! 二叉搜索树，AVL树, B（512阶）树，红黑树
    分析比较这些数据结构对应一系列插入和删除操作的效率。
*/

// todo 1按递增顺序插入N个整数，随机查找1000个数，按相同顺序删除
// todo 2按递增顺序插入N个整数，随机查找1000个数，按相反顺序删除
// todo 3按随机顺序插入N个整数，随机查找1000个数，按随机顺序删除
//  N从10000到400000取值，间隔为20000，以数据规模N为横轴，以运行时间为纵轴，画出不同数据结构对应的操作效率比较图。【插入、删除、查找】分别比较。
//  每一种树一共有3(操作类型-插入、查找、删除）*3(操作方式-1.2.3)类20个，共120个数据。

#include <chrono>
#include <iostream>
#include <sstream>
#include <fstream>
#include "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\Tree\\BST\\BinSearchTree.h"
#include "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\Tree\\AVL\\AVL_Tree.h"
#include "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\Tree\\B_Tree\\B_Tree.h"
#include "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\Tree\\RedBlackTree\\RBTree.h"
using namespace std;

#define BTREE_T 217
#define MINN 10000
#define MANN 400000
#define GroupNum 20
#define SEARCH_TIMES 1000

void Type1_Compare()
{
    cout << "********* Type 1 ***********\n";
    BST_Node *BST = nullptr;
    AVLNode *AVLT = nullptr;
    BTree *BT = new BTree(BTREE_T);
    RBTree *RBT = new RBTree;

    for (int i = 0; i < GroupNum; ++i)
    {
        cout << "------- Group" << i + 1 << "  ";
        stringstream ss;
        ss << i;
        string t;
        ss >> t;
        string path = "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\_LAB\\LAB3_CompareDifferentSearchTree\\seq_";
        path += t;
        ifstream inFile(path);
        int *DATA = new int[MANN + 10], count = 0;
        while (!inFile.eof())
        {
            inFile >> DATA[count];
            ++count;
        }
        --count;
        cout << "count: " << count << "--------\n";
        inFile.close();

        //! Binary Search Tree
        // 1.1  BST insert time
        cout << "1.1 BST Insert:    ";

        auto start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            BST = Insert(DATA[j], BST);
        }
        auto end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 1.2  BST search time
        cout << "1.2 BST Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            Find(rand() % count, BST);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 1.3  BST delete time
        cout << "1.3 BST Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = 0; j < count; ++j)
        {
            BST = Delete(DATA[j], BST);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 2. AVL Tree
        // 2.1 AVL insert
        cout << "2.1 AVL Insert:    ";

        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            AVLT = Insert(AVLT, DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 2.2  AVL search time
        cout << "2.2 AVLT Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            Find(rand() % count, AVLT);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 2.3  AVLT delete time
        cout << "2.3 AVLT Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = 0; j < count; ++j)
        {
            AVLT = Delete(AVLT, DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 3. B-Tree
        // 3.1 BT insert
        cout << "3.1 BT Insert:    ";
        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            BT->insert(DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 3.2  BT search time
        cout << "3.2 BT Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            BT->search(rand() % count);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 3.3  BT delete time
        cout << "3.3 BT Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = 0; j < count; ++j)
        {
            BT->remove(DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 4. RB Tree
        // 4.1 RBT insert
        cout << "4.1 RBTree Insert:    ";
        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            RBT->insert(DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 4.2  RBT search time
        cout << "4.2 RBTree Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            RBT->search(rand() % count);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 4.3  RBT delete time
        cout << "4.3 RBTree Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = 0; j < count; ++j)
        {
            RBT->deleteByVal(DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";
    }
}

void Type2_Compare()
{
    cout << "********* Type 2 ***********\n";
    BST_Node *BST = nullptr;
    AVLNode *AVLT = nullptr;
    BTree *BT = new BTree(BTREE_T);
    RBTree *RBT = new RBTree;

    for (int i = 0; i < GroupNum; ++i)
    {
        cout << "------- Group" << i + 1 << "  ";
        stringstream ss;
        ss << i;
        string t;
        ss >> t;
        string path = "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\_LAB\\LAB3_CompareDifferentSearchTree\\seq_";
        path += t;
        ifstream inFile(path);
        int *DATA = new int[MANN + 10], count = 0;
        while (!inFile.eof())
        {
            inFile >> DATA[count];
            ++count;
        }
        --count;
        cout << "count: " << count << "--------\n";
        inFile.close();

        //! Binary Search Tree
        // 1.1  BST insert time
        cout << "1.1 BST Insert:    ";

        auto start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            BST = Insert(DATA[j], BST);
        }
        auto end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 1.2  BST search time
        cout << "1.2 BST Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            Find(rand() % count, BST);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 1.3  BST delete time
        cout << "1.3 BST Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            BST = Delete(DATA[j], BST);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 2. AVL Tree
        // 2.1 AVL insert
        cout << "2.1 AVL Insert:    ";

        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            AVLT = Insert(AVLT, DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 2.2  AVL search time
        cout << "2.2 AVLT Search:   ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            Find(rand() % count, AVLT);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 2.3  AVLT delete time
        cout << "2.3 AVLT Delete:   ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            AVLT = Delete(AVLT, DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 3. B-Tree
        // 3.1 BT insert
        cout << "3.1 BT Insert:    ";
        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            BT->insert(DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 3.2  BT search time
        cout << "3.2 BT Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            BT->search(rand() % count);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 3.3  BT delete time
        cout << "3.3 BT Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            BT->remove(DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 4. RB Tree
        // 4.1 RBT insert
        cout << "4.1 RBTree Insert:    ";
        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            RBT->insert(DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 4.2  RBT search time
        cout << "4.2 RBTree Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            RBT->search(rand() % count);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 4.3  RBT delete time
        cout << "4.3 RBTree Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            RBT->deleteByVal(DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";
    }
}

void Type3_Compare()
{
    cout << "********* Type 3 ***********\n";
    BST_Node *BST = nullptr;
    AVLNode *AVLT = nullptr;
    BTree *BT = new BTree(BTREE_T);
    RBTree *RBT = new RBTree;

    for (int i = 0; i < GroupNum; ++i)
    {
        cout << "------- Group" << i + 1 << "  ";
        stringstream ss;
        ss << i;
        string t;
        ss >> t;
        string path = "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\_LAB\\LAB3_CompareDifferentSearchTree\\rnd_";
        path += t;
        ifstream inFile(path);
        int *DATA = new int[MANN + 10], count = 0;
        while (!inFile.eof())
        {
            inFile >> DATA[count];
            ++count;
        }
        --count;
        cout << "count: " << count << "--------\n";
        inFile.close();

        //! Binary Search Tree
        // 1.1  BST insert time
        cout << "1.1 BST Insert:    ";

        auto start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            BST = Insert(DATA[j], BST);
        }
        auto end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 1.2  BST search time
        cout << "1.2 BST Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            Find(DATA[rand() % count], BST);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 1.3  BST delete time
        cout << "1.3 BST Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            BST = Delete(DATA[j], BST);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 2. AVL Tree
        // 2.1 AVL insert
        cout << "2.1 AVL Insert:    ";

        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            AVLT = Insert(AVLT, DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 2.2  AVL search time
        cout << "2.2 AVLT Search:   ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            Find(DATA[rand() % count], AVLT);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 2.3  AVLT delete time
        cout << "2.3 AVLT Delete:   ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            AVLT = Delete(AVLT, DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 3. B-Tree
        // 3.1 BT insert
        cout << "3.1 BT Insert:    ";
        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            BT->insert(DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 3.2  BT search time
        cout << "3.2 BT Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            BT->search(DATA[rand() % count]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 3.3  BT delete time
        cout << "3.3 BT Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            BT->remove(DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        //! 4. RB Tree
        // 4.1 RBT insert
        cout << "4.1 RBTree Insert:    ";
        start_time = chrono::steady_clock::now(); // tic
        for (int j = 0; j < count; ++j)
        {
            RBT->insert(DATA[j]);
        }
        end_time = chrono::steady_clock::now(); // toc
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 4.2  RBT search time
        cout << "4.2 RBTree Search:    ";

        start_time = chrono::steady_clock::now();
        for (int j = 0; j < SEARCH_TIMES; ++j)
        {
            srand(rand());
            RBT->search(DATA[rand() % count]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";

        // 4.3  RBT delete time
        cout << "4.3 RBTree Delete:    ";
        start_time = chrono::steady_clock::now();
        for (int j = count - 1; j >= 0; --j)
        {
            RBT->deleteByVal(DATA[j]);
        }
        end_time = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << "us\n";
    }
}

int main()
{
    //Type1_Compare();
    //Type2_Compare();
    Type3_Compare();

    system("pause");
    return 0;
}