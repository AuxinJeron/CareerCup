#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

void printBinaryRepresention(string input);

int main() {
	string input = "3234.7232";
	printBinaryRepresention(input);
	return 0;
}

void printBinaryRepresention(string input) {
	int dotIndex = input.find(".");
	string intString = input.substr(0, dotIndex);
	string decimalString = input.substr(dotIndex + 1, input.length());
	cout << intString + "." + decimalString << "\n";
	int a = 
	string intPart = "";
	string decimalPart = "";
}