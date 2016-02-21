#include <iostream>
#include <vector>
#include <tuple>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

int getPosition(int array[], int size, int target, int begin, int end) {
	int median = (begin + end) / 2;
	if (array[median] == target) return median;
	if (array[begin] <= array[end]) {
		if (target <= array[median]) 
			return getPosition(array, size, target, begin, median);
		else 
			return getPosition(array, size, target, median, end);
	}
	else if (array[begin] <= array[median]) {
		if (array[begin] <= target && target <= array[median])
			return getPosition(array, size, target, begin, median);
		else 
			return getPosition(array, size, target, median, end);
	}
	else {
		if (array[median] <= target && target <= array[end])
			return getPosition(array, size, target, median, end);
		else return getPosition(array, size, target, begin, median);
	}
}

int main() {
	int array[] = {1, 2, 3, 6, 7, 10};
	cout << getPosition(array, 6, 2, 0, 5) << endl;;
	return 0;
}