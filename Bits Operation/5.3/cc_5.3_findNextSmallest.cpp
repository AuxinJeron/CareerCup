#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

int numberOfOnes(int input);
int biggerNum(int input);
int complexBiggerNum(int input);

int main() {
	cout << biggerNum(14134) << "\n";
	cout << complexBiggerNum(14134) << "\n";
	return 0;
}

int numberOfOnes(int input) {
	int mask = 1;
	int num = 0;
	while (input != 0) {
		if ((input & mask) == 1) num ++;
		input = input >> 1;
	}
	return num;
}

int biggerNum(int input) {
	int result = input + 1;
	int num = numberOfOnes(input);
	while (numberOfOnes(result) != num) result ++;
	return result;
}

int complexBiggerNum(int input) {
	int temp = input;
	int i = 1;
	int mask = 1;
	bool hasMetOne = false;
	while (temp != 0) {
		if ((temp & mask) != 0) hasMetOne = true;
		else if (hasMetOne == true) break;
		temp = temp >> 1;
		i ++;
	}
	if (hasMetOne == false) return 0;
	temp = input + (1 << (i - 1));
	temp = temp - (1 << (i - 2));
	int currentIndex = 1;
	for (int j = 1; j <= i - 1; j++) {
		if ((temp & (1 << (j - 1))) != 0) {
			temp -= 1 << (j - 1);
			temp += 1 << (currentIndex - 1);
			currentIndex ++;
		}
	}
	return temp;
}







