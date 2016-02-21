#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
using namespace std;

template<class T>
class Node {
	public:
	Node* leftChild;
	Node* rightChild;
	T value;
	Node () {
		this->value = 0;
		this->next = NULL;
	}
	Node (T v) {
		this->value = v;
		this->next = NULL;
	}
	void appendLeft (Node *child) {
		leftChild = child;
	}
	void appendRight (Node *child) {
		rightChild = child;
	}
};

void initTree(Node<int> *root, vector<int> &array, int begin, int end) {
	
}

int main() {
	return 0;
}