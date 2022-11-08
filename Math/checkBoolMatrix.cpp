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
//#include <queue>
//#include <stack>
//#include <set>
//#include <map>

#define RG register
#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff
using namespace std;
#define MAXN 100

int N;
bool isOK = 1;
bool isCorp = 0;
int M[MAXN+3][MAXN+3];

int* Check()
{
    //int *Result = new int[2]{-1,-1};
    int row = -1, col = -1;
    for(int i=0;i<N;++i)
    {
        int thisLine=0;
        for(int j=0;j<N;++j)
        {
            if(M[i][j])++thisLine;
        }
        if(thisLine & 1)
        {
            if(row !=-1)
            {
                isCorp =1;
                return nullptr;
            }
            isOK = 0;
            row = i;
        }
    }
    for(int i=0;i<N;++i)
    {
        int thisCol=0;
        for(int j=0;j<N;++j)
        {
            if(M[j][i])++thisCol;
        }
        if(thisCol & 1)
        {
            if(col !=-1)
            {
                isCorp =1;
                return nullptr;
            }
            isOK = 0;
            col = i;
        }
    }
    if(!isOK && (col==-1 || row ==-1))isCorp=1;
    return isOK ? nullptr : new int[2]{row, col};
}


int main()
{
	cin>>N;

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>M[i][j];
        }
    }
    int *R = Check();

    if(isOK)
    {
        cout<<"OK";

    }
    else if(isCorp)
    {
        cout<<"Corrupt";
    }
    else
    {
        cout<<"Change bit ("<<R[0]+1<<','<<R[1]+1<<')';
    }

    system("pause");
	return 0;
}