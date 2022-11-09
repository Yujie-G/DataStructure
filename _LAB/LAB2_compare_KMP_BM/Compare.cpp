// C++ Version
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

#define TypeNum 3000
using namespace std;

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

bool KMP(string T, string p)
{
    string S = p + '#' + T;
    vector<int> V = prefix_function(S);
    for (auto j : V)
    {
        if (j == p.length())
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    ifstream inFile("testData.txt");

    int i = 0;

    auto start_time = chrono::steady_clock::now();
    while (!inFile.eof())
    {
        ++i;
        string T, p;
        inFile >> T >> p;
        KMP(T, p);

        if (i % TypeNum == 0)
        {
            auto end_time = chrono::steady_clock::now();
            auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "KMP算法下3000个类型" << i / TypeNum << "随机串的匹配时间: " << ms << " ms" << endl;

            start_time = chrono::steady_clock::now();
        }
    }
    cout << endl;
    inFile.close();

    inFile.open("testData.txt");
    int j = 0;
    start_time = chrono::steady_clock::now();
    while (!inFile.eof())
    {
        ++j;
        string T, p;
        inFile >> T >> p;
        // BM algorithm
        auto it = search(T.begin(), T.end(), boyer_moore_searcher(p.begin(), p.end()));

        if (j % TypeNum == 0)
        {
            auto end_time = chrono::steady_clock::now();
            auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "BM算法下3000个类型" << j / TypeNum << "随机串的匹配时间: " << ms << " ms" << endl;

            start_time = chrono::steady_clock::now();
        }
    }
    inFile.close();

    return 0;
}