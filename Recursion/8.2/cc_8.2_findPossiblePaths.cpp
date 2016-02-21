#include <iostream>
#include <vector>
#include <tuple>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

void printPaths(vector< pair<int, int> > paths) {
	for (int i = 0; i < paths.size(); i ++) {
		cout << "(" << paths[i].first << "," << paths[i].second << ") -> ";
	}
	cout << endl;
}

void printPaths(int grid[8][8], int size) {
	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j ++) {
			if (grid[i][j] == 1) cout << "(" << i << "," << j << ") -> ";
		}
	}
	cout << endl;
}

void moveOn(int grid[8][8], int size, vector< pair <int, int> > paths, pair<int, int> pos) {
	grid[pos.first][pos.second] = 1;
	paths.push_back(pos);
	if (pos.first + 1 == size && pos.second + 1 == size) {
		cout << "first method:\n";
		printPaths(grid, size);
		cout << "second method:\n";
		printPaths(paths);
	}
	if (pos.first + 1 < size) {
		pair<int, int> newPos = pair<int, int>(pos.first + 1, pos.second);
		moveOn(grid, size, paths, newPos);
	}
	if (pos.second + 1 < size) {
		pair<int, int> newPos = pair<int, int>(pos.first, pos.second + 1);
		moveOn(grid, size, paths, newPos);
	}
	grid[pos.first][pos.second] = 0; 
}

int main() {
	int grid[8][8];
	for (int i = 0; i < 8; i ++) {
		for (int j = 0; j < 8; j ++) {
			grid[i][j] = 0;
		}
	}
	vector< pair<int, int> > paths;
	moveOn(grid, 8, paths, pair<int, int> (0, 0));
	return 0;
}