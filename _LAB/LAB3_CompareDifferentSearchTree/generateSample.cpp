/* VScode_Version */

#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;
#define BEGIN 10000
#define END 400000
#define GAP 20000

int main()
{
    cout<<"generating...\n";
	for(int i=0;BEGIN +i*GAP<=END;++i)
    {
        int N = BEGIN +i*GAP;
        stringstream ss;ss<<i;
        string t;ss>>t;
        srand(rand());srand(rand());

        string path1 = "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\_LAB\\LAB3_CompareDifferentSearchTree\\seq_";
        string path2 = "D:\\Projects_VSCode\\Projects_c_cpp\\Projects\\DataStructure\\_LAB\\LAB3_CompareDifferentSearchTree\\rnd_";
        path1+=t;path2+=t;
        ofstream outFile1(path1), outFile2(path2);
        for(int i=0;i<N;++i)
        {
            outFile1<<i<<'\n';
            outFile2<<rand()<<'\n';
        }
        outFile1.close();
        outFile2.close();

        cout<<i+1<<"th\n";
    }


	return 0;
}