#include <iostream>
#include <vector>
#include <tuple>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

void mergeSort(vector<int> &vector1, vector<int> &vector2) {
	int i = 0;
	int j = 0;
	// later the vector will be change so not use the iterator here 
	//vector<int>::iterator it = vector1.begin();
	for (j = 0; j < vector2.size(); j++) {
		while(vector2[j] > vector1[i] && i < vector1.size() - 1) i++;
		if (vector2[j] <= vector1[i]) {
			vector1.insert(vector1.begin() + i, vector2[j]);
			i ++;
		}
		else if (i >= vector1.size()) {
			vector1.push_back(vector2[j]);
		}
	}
}

int main() {
	int array1[] = {1, 5, 6, 7, 9, 10, 35};
	int array2[] = {5, 6, 9};
	vector<int> vector1 = vector<int>(array1, array1 + sizeof(array1) / sizeof(int));
	vector<int> vector2 = vector<int>(array2, array2 + sizeof(array2) / sizeof(int));
	mergeSort(vector1, vector2);
	for (int i = 0; i < vector1.size(); i ++) {
		cout << vector1[i] << " ";
	}
	cout << endl;
	return 0;
}