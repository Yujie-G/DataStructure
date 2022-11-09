//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <ctime>
//
//
//#define RG register 
//#define LL long long 
//#define ULL unsigned long long
//#define INF 0x7fffffff
//#define TAR_LEN 1000
//#define P_LEN 100
//#define TypeNum 3000
//using namespace std;
//
//int main()
//{
//	ofstream outFile("testData.txt");
//
//
//
//	//generate string(only 0, 1)
//	for (int i = 0; i < TypeNum; ++i)
//	{
//		srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand());
//		string temp{ };
//		for (int j = 0; j < TAR_LEN; ++j)
//		{
//			int k = rand();
//			k &= 1;
//			temp += (char)('0' + k);
//			
//		}
//		outFile << temp;
//		outFile << ' ';
//		int begin = rand() % (temp.length() - P_LEN);
//		for (int j = begin; j < begin + P_LEN; ++j)
//		{
//			outFile << temp[j];
//		}
//		outFile << endl;
//		srand(rand()); srand(rand()); srand(rand());
//	}
//
//	//generate char ranged from 'a' to 'j'
//	for (int i = 0; i < TypeNum; ++i)
//	{
//		srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand());
//		string temp{ };
//		for (int j = 0; j < TAR_LEN; ++j)
//		{			
//			temp+= (char)('a' + (int)rand() % 10);
//			
//		}
//		outFile << temp;
//		outFile << ' ';
//		int begin = rand() % (temp.length()- P_LEN);
//		for (int j = begin; j < begin+ P_LEN; ++j)
//		{
//			outFile << temp[j];
//		}
//		outFile << endl;
//		srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand());
//	}
//
//	//generate char from ascii 32-126
//	for (int i = 0; i < TypeNum; ++i)
//	{
//		srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand());
//		string temp{ };
//		for (int j = 0; j < TAR_LEN; ++j)
//		{
//			temp += (char)(33 + (int)rand() % 95);
//		}
//		outFile << temp;
//		outFile << ' ';
//		int begin = rand() % (temp.length() - P_LEN);
//		for (int j = begin; j < begin + P_LEN; ++j)
//		{
//			outFile << temp[j];
//		}
//		outFile << endl;
//		srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand());
//	}
//
//	cout << "generation done!";
//	return 0;
//}