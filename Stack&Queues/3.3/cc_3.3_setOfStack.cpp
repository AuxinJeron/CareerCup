#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
using namespace std;

template<class T>
class Node {
	public:
	Node* next;
	T value;
	Node () {
		this->value = 0;
		this->next = NULL;
	}
	Node (T v) {
		this->value = v;
		this->next = NULL;
	}
	void append (T value) {
		Node end = Node(value);
		append(end);
	}
	void append (Node *end) {
		Node* n = this;
		while (n->next != NULL) n = n->next;
		printf("end address is %p\n", end);
		n->next = end;
		printf("next pointer value is %p\n", n->next);
	}
};

template<class T>
class Stack {
	private:
		Node<T> *top;
	public:
		Stack () {
			top = new Node<T>();
		}
		void pop() {

		}
		void push() {

		}
 
};

int main () {
	Node<int> *n1 = new Node<int>(1);
	Node<int> *n2 = new Node<int>(2);
	n1->append(n2);
	printf("n1 pointer address is %p\n", n1);
	printf("n1 next pointer address is %p\n", n1->next);
	printf("n2 pointer address is %p\n", n2);
	delete n1;
	delete n2;
	return 0;
}
