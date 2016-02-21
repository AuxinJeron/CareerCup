#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <math.h>
using namespace std;

template<class T>
class Node {
	public:
	Node* leftChild;
	Node* rightChild;
	T value;
	Node () {
		this->value = 0;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
	Node (T v) {
		this->value = v;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
	void appendLeft (Node *child) {
		leftChild = child;
	}
	void appendRight (Node *child) {
		rightChild = child;
	}
};

void createBinaryTree(Node<int> *root, vector<int> &array, int begin, int end) {
	root->value = array[begin];
	cout << "Add int " << array[begin] << "\n";
	int nextLeftBegin = begin + 1;
	int nextLeftEnd = begin + ceil((end - begin) / 2.0f);
	int nextRightBegin = nextLeftEnd + 1;
	int nextRightEnd = end;
	if (nextLeftBegin <= nextLeftEnd && nextLeftEnd < array.size()) {
		root->leftChild = new Node<int>();
		createBinaryTree(root->leftChild, array, nextLeftBegin, nextLeftEnd);
	}
	if (nextRightBegin <= nextRightEnd && nextRightEnd < array.size()) {
		root->rightChild = new Node<int>();
		createBinaryTree(root->rightChild, array, nextRightBegin, nextRightEnd);
	}
}

int main() {
	int input[] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> array(input, input + sizeof(input) / sizeof(int));
	Node<int> *root = new Node<int>();
	createBinaryTree(root, array, 0, array.size() - 1);
	return 0;
}