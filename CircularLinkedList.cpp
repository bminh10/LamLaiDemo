#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* next;
};

struct CircularLinkedList {
	Node*head, *tail;
};

//khoi tao rong
void init(CircularLinkedList& l) {
	l.head = nullptr;
	l.tail = nullptr;
}

Node*createNode(const int x) {
	Node*p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}


//them dau
void insFirst(CircularLinkedList &l, const int x) {
	Node* p = createNode(x);
	if (l.head == NULL) {
		l.head =l.tail= p;
		
		l.tail->next = l.head;
	}
	else {
		p->next = l.head;
		l.tail ->next = p;
		l.head = p;

		
	}



}

void delFirst(CircularLinkedList &l) {
	if (l.head != nullptr) {
		Node*tmp = l.head;
		if (l.head == l.tail) {
			l.head = l.tail = nullptr;
		}
		else {
			l.head = tmp->next;
			l.tail->next = l.head;
		}
		delete tmp;
	}
}



//duyet dnah sach
void print(CircularLinkedList l) {
	if (l.head == nullptr) {
		cout << "Danh sach rong";
		cout << endl;
		return;
	}

	Node*tmp = l.head;

	while (tmp->next != l.head) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << tmp->info;
	cout << endl;
}
//detroy list
void detroyList(CircularLinkedList &l) {
	while (l.head != nullptr) {
		delFirst(l);
	}
}



int main() {
	CircularLinkedList l;
	init(l);

	insFirst(l, 3);
	insFirst(l, 2);

	print(l);


	cout << "xoaaa" << endl;
	delFirst(l);
	print(l);

	detroyList(l);
	if (l.head == nullptr) {
		cout << "rong \n";
	}
}