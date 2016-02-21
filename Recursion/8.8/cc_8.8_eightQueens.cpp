#include <iostream>
#include <vector>
#include <tuple>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

bool checkPos(vector< pair<int, int> > chesses, int m, int n) {
	for (int i = 0; i < chesses.size(); i ++) {
		if (chesses[i].first == m) return false;
		if (chesses[i].second == n) return false;
		if (abs(chesses[i].first - m) == abs(chesses[i].second - n)) return false;
	}
	return true;
}

void printChesses(vector< pair<int, int> > chesses) {
	for (int i = 0; i < chesses.size(); i ++) {
		cout << "(" << chesses[i].first << "," << chesses[i].second << ")-> ";
	}
	cout << endl;
} 

int putNextChess(int size, vector< pair<int, int> > chesses, int i) {
	if (i == size) {
		printChesses(chesses);
		return 1;
	}
	int ways = 0;
	for (int j = 0; j < size; j ++) {
		if (checkPos(chesses, i, j)) {
			chesses.push_back(pair<int, int>(i, j));
			ways += putNextChess(size, chesses, i + 1);
			chesses.pop_back();
		}
	}
	return ways;
}

int main () {
	vector< pair<int, int> > chesses;
	int ways = putNextChess(8, chesses, 0);
	cout << "Ways count: " << ways << endl;
	return 0;
}