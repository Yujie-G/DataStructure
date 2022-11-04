// C++ Version
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>

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
vector<int> V;

bool KMP(string T, string p)
{
    string S = p + '#' + T;
    V = prefix_function(S);
    for (int i = p.length() + 1; i < V.size(); ++i)
    {
        if (V[i] == p.length())
        {
            cout << i - 2 * p.length() + 1 << endl;
        }
    }
    return 0;
}

int main()
{

    string s1, s2;
    cin >> s1 >> s2;

    KMP(s1, s2);
    for (int i = 0; i < s2.length(); ++i)
    {
        cout << V[i] << ' ';
    }

    return 0;
}