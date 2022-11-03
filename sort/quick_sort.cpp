#include <iostream>
using namespace std;

void quickSort(int* arr, int begin, int end) {
	if (begin < end) {
		int temp = arr[begin];
		int i = begin, j = end;
		while (i < j) {
			while (j > i && arr[j] > temp)
				j--;
			arr[i] = arr[j];
			while (i < j && arr[i] < temp)
				i++;
			arr[j] = arr[i];
		}
		arr[i] = temp;
		quickSort(arr, begin, i - 1);
		quickSort(arr, i + 1, end);


	}
	else return;
}


int main(){
	int f[] = { 9,45,43,66,4,5,53,8,11};
	quickSort(f, 0, 8);
	for (int i = 0; i < 9; i++)
		cout << f[i] << ' ';




	return 0;
}
