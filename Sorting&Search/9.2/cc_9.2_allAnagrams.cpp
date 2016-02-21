#include <iostream>
#include <vector>
#include <tuple>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

string sortedString(string s) {
	string result = "";
	int length = s.length();
	vector<char> charVector;
	for (int i = 0; i < s.length(); i ++) {
		charVector.push_back(s[i]);
	}
	sort(charVector.begin(), charVector.end());
	for (int i = 0; i < charVector.size(); i ++) {
		result += charVector[i];
	}
	return result;
}

bool compareString(string s1, string s2) {
	return sortedString(s1).compare(sortedString(s2));
}

int main() {
	string input[] = {"abc", "ccc", "cav", "act", "bca", "acb"};
	vector<string> inputVector;
	for (int i = 0; i < 6; i ++) {
		inputVector.push_back(input[i]);
	}
	sort(inputVector.begin(), inputVector.end(), compareString);
	for (int i = 0; i < inputVector.size(); i ++) {
		cout << inputVector[i] << " "; 
	}
	cout << endl;
 	return 0;
}