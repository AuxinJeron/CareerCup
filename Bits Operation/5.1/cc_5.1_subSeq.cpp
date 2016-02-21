#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

void updateBits(int M, int N, int i, int j);

int main() {
	int M = 0x40;
	int N = 0x15;
	int i = 2;
	int j = 6;
	cout << M << "\n";
	cout << N << "\n";

	updateBits(M, N, i, j);

	return 0;
}

void updateBits(int M, int N, int i, int j) {
	// ideas of using mask
	int max = ~0; // two complements so max = -1
	int left = max - ((1 << j) - 1);
	int right = (1 << i) - 1;
	int mask = N & (left | right);
	int result = mask | (M << i);
	cout << result << "\n";
}