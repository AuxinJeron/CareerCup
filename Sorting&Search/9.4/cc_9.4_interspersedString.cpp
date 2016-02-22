#include <iostream>
#include <vector>
#include <tuple>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

int positionBetween(vector<string> array, int start, int begin, int end) {
	int startUp = start + 1;
	int startDown = start - 1;
	while (array[startUp] == "" && array[startDown] == "") {
		startUp ++;
		startDown --;
	}
	if (startDown <= begin && startUp >= end) return -1;
	if (array[startDown].compare(array[begin]) >= 0 && array[startDown].compare(array[end]) <= 0 && startDown > begin && array[startDown] != "") 
		return startDown;
	else if (array[startUp].compare(array[begin]) >= 0 && array[startUp].compare(array[end]) <= 0 && startUp < end && array[startUp] != "")
		return startUp;
	return -1;
}

int positionFor(vector<string> array, string target, int begin, int end) {
	if (array[begin] == "") 
		begin = positionBetween(array, 0, 0, end);
	if (array[end] == "") 
		end = positionBetween(array, end, 0, end);
	int median = (begin + end) / 2;
	if (array[median] == "") 
		median = positionBetween(array, median, begin, end);
	if (median == -1 || begin == -1 || end == -1) return -1;
	if (array[median].compare(target) == 0) return median;
	else if (array[median].compare(target) > 0) 
		return positionFor(array, target, begin, median - 1);
	else 
		return positionFor(array, target, median + 1, end);
}

int main() {
	string input[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	vector<string> inputVector;
	for (int i = 0; i < 13; i ++) {
		inputVector.push_back(input[i]);
	}
	cout << positionFor(inputVector, "ballcar", 0,10) << endl;
	return 0;
}