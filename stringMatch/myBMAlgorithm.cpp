//#include <iostream>
//#include <fstream>
//#include <chrono>
//#include <vector>
//#include <string>
//#include<functional>
//#include <algorithm>
//
//
//using namespace std;
//# define NO_OF_CHARS 256
//#define MAXN 10000
//#define TypeNum 3000
//
//void bulidBadCharTable(string str, int badchar[NO_OF_CHARS])
//{
//	int i;
//	int size = str.length();
//	// Initialize all occurrences as -1
//	for (i = 0; i < NO_OF_CHARS; i++)
//		badchar[i] = -1;
//
//	// Fill the actual value of last occurrence
//	// of a character
//	for (i = 0; i < size; i++)
//		badchar[(int)str[i]] = i;
//}
//
//// preprocessing for strong good suffix rule
//void preprocess_strong_suffix(int* shift, int* bpos,string pat)
//{
//	// m is the length of pattern 
//	int m = pat.length();
//	int i = m, j = m + 1;
//	bpos[i] = j;
//
//	while (i > 0)
//	{
//		/*if character at position i-1 is not equivalent to
//		  character at j-1, then continue searching to right
//		  of the pattern for border */
//		while (j <= m && pat[i - 1] != pat[j - 1])
//		{
//			/* the character preceding the occurrence of t in
//			   pattern P is different than the mismatching character in P,
//			   we stop skipping the occurrences and shift the pattern
//			   from i to j */
//			if (shift[j] == 0)
//				shift[j] = j - i;
//
//			//Update the position of next border 
//			j = bpos[j];
//		}
//		/* p[i-1] matched with p[j-1], border is found.
//		   store the  beginning position of border */
//		i--; j--;
//		bpos[i] = j;
//	}
//}
//
////Preprocessing for case 2
//void preprocess_case2(int* shift, int* bpos,string pat)
//{
//	int m = pat.length();
//	int i, j;
//	j = bpos[0];
//	for (i = 0; i <= m; i++)
//	{
//		/* set the border position of the first character of the pattern
//		   to all indices in array shift having shift[i] = 0 */
//		if (shift[i] == 0)
//			shift[i] = j;
//
//		/* suffix becomes shorter than bpos[0], use the position of
//		   next widest border as value of j */
//		if (i == j)
//			j = bpos[j];
//	}
//}
//
//
//int BM_Algorithm(string txt, string pat)
//{
//	int m = pat.size();
//	int n = txt.size();
//
//	int *badchar = new int[NO_OF_CHARS]{0};
//	//int* suffix = (int*)malloc(sizeof(int) * m);
//	//bool* prefix = (bool*)malloc(sizeof(bool) * m);
//
//	/* Fill the bad character array by calling
//	the preprocessing function bulidBadCharTable()
//	for given pattern */
//	bulidBadCharTable(pat, badchar);
//	int* shift = new int[MAXN] { 0 };
//	int *bpos = new int[MAXN]{ 0 };
//	preprocess_strong_suffix(shift, bpos, pat);
//	preprocess_case2(shift, bpos, pat);
//
//	int s = 0; // s is shift of the pattern with
//	// respect to text
//	while (s <= (n - m))
//	{
//		int j = m - 1;
//
//		/* Keep reducing index j of pattern while
//		characters of pattern and text are
//		matching at this shift s */
//		while (j >= 0 && pat[j] == txt[s + j])
//			j--;
//
//		/* If the pattern is present at current
//		shift, then index j will become -1 after
//		the above loop */
//		if (j < 0)
//		{
//			delete[]badchar;
//			delete[]shift;
//			delete[]bpos;
//			return s;
//
//			/* Shift the pattern so that the next
//			character in text aligns with the last
//			occurrence of it in pattern.
//			The condition s+m < n is necessary for
//			the case when pattern occurs at the end
//			of text */
//			//s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
//
//		}
//
//		else
//		{
//			int numBc = j - badchar[txt[s + j]];//bc移动的位数
//			int numGs = shift[j+1];
//			s += max(numBc, numGs);
//			//s += numGs;
//		}
//	}
//	delete[]badchar;
//	delete[]shift;
//	delete[]bpos;
//	return -1;
//}
//
//void speedCompare_stl_myBM()
//{
//	ifstream inFile("testData.txt");
//
//	int i = 0;
//
//	auto start_time = chrono::steady_clock::now();
//	while (!inFile.eof())
//	{
//		++i;
//		string T, p;
//		inFile >> T >> p;
//		//cout<<"pos: "<<BM_Algorithm(T, p)<<'\n';
//		BM_Algorithm(T, p);
//
//		if (i % TypeNum == 0)
//		{
//			auto end_time = chrono::steady_clock::now();
//			auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
//			cout << "自实现算法下3000个类型" << i / TypeNum << "随机串的匹配时间: " << ms << " ms" << endl;
//
//			start_time = chrono::steady_clock::now();
//		}
//	}
//	cout << endl;
//	inFile.close();
//
//	inFile.open("testData.txt");
//	int j = 0;
//	start_time = chrono::steady_clock::now();
//	while (!inFile.eof())
//	{
//		++j;
//		string T, p;
//		inFile >> T >> p;
//		//BM algorithm
//		auto it = search(T.begin(), T.end(), boyer_moore_searcher(p.begin(), p.end()));
//
//		if (j % TypeNum == 0)
//		{
//			auto end_time = chrono::steady_clock::now();
//			auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
//			cout << "内置BM算法下3000个类型" << j / TypeNum << "随机串的匹配时间: " << ms << " ms" << endl;
//
//			start_time = chrono::steady_clock::now();
//		}
//	}
//	inFile.close();
//}
//
//int main()
//{
//	string t = "1011010101101",p="1010";
//	cout<<BM_Algorithm(t,p);
//
//	//speedCompare_stl_myBM();
//	
//	return 0;
//}