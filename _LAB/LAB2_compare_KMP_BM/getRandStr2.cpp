//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <ctime>
//
//#define P_LEN 500
//
//using namespace std;
//
//int main()
//{
//	ofstream outFile("testData2.txt");
//
//
//	//generate char from ascii 33-126
//	for (int i = 0; i < 50; ++i)
//	{
//		srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand()); srand(rand());
//		string temp{ };
//		for (int j = 0; j < 1000+1000*i; ++j)
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