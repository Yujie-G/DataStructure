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
    ifstream inFile("testData2.txt");

    cout << "KMP算法下的匹配所需时间：" << endl;

    while (!inFile.eof())
    {
        string T, p;
        inFile >> T >> p;
        auto start_time = chrono::steady_clock::now();
        KMP(T, p);
        auto end_time = chrono::steady_clock::now();
        auto ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
        cout << ns << " ns" << endl;
    }
    cout << endl;
    inFile.close();

    inFile.open("testData2.txt");
    cout << "BM算法下的匹配所需时间：" << endl;

    while (!inFile.eof())
    {
        string T, p;
        inFile >> T >> p;
        auto start_time = chrono::steady_clock::now();
        auto it = search(T.begin(), T.end(), boyer_moore_searcher(p.begin(), p.end()));
        auto end_time = chrono::steady_clock::now();
        auto ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
        cout << ns << " ns" << endl;
    }
    cout << endl;
    inFile.close();

    return 0;
}