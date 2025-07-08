#include <iostream>
using namespace std;


//Khai bao cau truc
struct Node {
	int info;
	Node* next, *prev;
};

struct DoublyLinkedList {
	Node*head, *tail;
};

//khoi tao rong
void init(DoublyLinkedList &l) {
	l.head = NULL;
	l.tail = NULL;
}

Node* createNode(const int x) {
	Node*p = new Node();
	p->info = x;
	p->next = nullptr;
	p->prev = NULL;
	return p;
}


//thao tac tim kiem
Node* search(DoublyLinkedList &l, int key) {
	Node*tmp = l.head;
	while (tmp != NULL && tmp->info != key) {
		tmp = tmp->next;
	}
	return tmp;
}

//thao tac them: dau, cuoi, sau node q
void insFirst(DoublyLinkedList& l, const int x) {
	Node*p = createNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		p->next = l.head;
		l.head->prev = p;
		l. head = p;
	}


}

void insLast(DoublyLinkedList& l , const int x) {
	Node*p = createNode(x);
	if (l.tail == NULL) {
		l.head = l.tail = p;
	}
	else {
		p->prev = l.tail;
		l.tail->next = p;
		l.tail = p;
	}
}
void insAfter(DoublyLinkedList& l, const int x,const int key) {
	Node*q = search(l, key);
	if (q != NULL) {
		Node*p = createNode(x);
		if (q->next != NULL) {
			p->next = q->next;
			q->next->prev = p;
			q->next = p;
			p->prev = q;
		}
		else {
			q->next = p;
			p->prev = q;
		}
		
		
	}
}

// thao tac duyet: tu dau, tu cuoi
//duyet tu trai sang phai
void print1(Node*head) {
	if (head == NULL) {
		cout << "danh sach rong \n";
		return;
	}
	Node*tmp = head;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->next;

	}
	cout << endl;
}
//duyet tu phai sang trai
void print2(Node*tail) {
	if (tail == NULL) {
		cout << "danh sach rong \n";
		return;
	}
	Node*tmp = tail;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->prev;

	}
	cout << endl;
}







//thao tac xoa: dau, cuoi, xoa node q;
int delFirst(DoublyLinkedList& l) {
	if (l.head != NULL) {
		Node*tmp = l.head;
		if (l.head->next == NULL) {
			l.head = l.tail = NULL;
		}
		else {
			l.head = tmp->next;
			tmp->next = nullptr;
			l.head->prev = nullptr;
		}
		delete tmp;
		return 1;//xoa thanh cong
	}
	return -1; //xoa khong thanh cong
}

int delLast(DoublyLinkedList& l) {
	if (l.head != NULL) {
		Node *tmp = l.tail;
		if (l.head->next == NULL) {
			l.head = l.tail = NULL;
		}
		else {
			l.tail = tmp->prev;
			l.tail->next = NULL;
			tmp->prev = NULL;

		}
		delete tmp;
		return 1;
	}
	return -1;
}

//int delNode(DoublyLinkedList&l,int key) {
//	if (l.head != NULL) {
//		Node *q = search(l, key);
//		if (q != NULL) {
//			if (q == l.head) {
//				l.head = q->next;
//				l.head->prev = nullptr;
//				q->next = nullptr;
//			}
//			else if (q == l.tail) {
//				l.tail = q->prev;
//				l.tail->next = nullptr;
//				q->prev = nullptr;
//
//			}
//			else {
//				q->prev->next = q->next;
//				q->prev = nullptr;
//			}
//			delete q;
//			return 1;
//		}
//	}
//	return -1;
//
//}

int delNode(DoublyLinkedList &l, int key) {
	if (l.head != nullptr) {
		Node*q = search(l, key);
		if (q == l.head) {
			delFirst(l);
			return 1;
		}
		if (q == l.tail) {
			delLast(l);
			return 1;
		}

		Node*qPre = q->prev;
		Node*qNext = q->next;

		qNext->prev = nullptr;
		qPre->next = NULL;
		q->next = nullptr;
		q->prev = nullptr;
		return 1;
	}
}


//tim max va min trong danh sach

int compareMax(int a, int b) {
	return a > b;

}
int compareMin(int a, int b) {
	return a < b;
}

Node* findExtremum(DoublyLinkedList l, int func(int a, int b)) {
	if (l.head == nullptr) {
		return NULL;
	}
	Node*tmp = l.head->next;
	Node*res = l.head;
	while (tmp != nullptr) {
		if (func(res->info, tmp->info)) {
			res->info = tmp->info;
		}
		tmp = tmp->next;
	}
	return res;

}



//giai phong danh sach
void detroyList(DoublyLinkedList &l) {
	while (l.head != nullptr) {
		delFirst(l);
	}
}

int main() {

	DoublyLinkedList l;
	init(l);

	insLast(l,2);
	insLast(l, 3);
	insLast(l, 4);
	insLast(l, 5);
	
	print1(l.head);
	

	/*cout << "================KQ SAU KHI XOA=================\n";

	delLast(l);
	print1(l.head);*/

	/*insAfter(l, 2,3);
	cout << "=============KQ THEM============\n";
	print1(l.head);*/

	/*cout << "===============KQ XOA NODE CHI DINH=================\n";
	delNode(l, 3);
	print1(l.head);*/

	cout << "=============KQ CUC TRI=================\n";
	Node*res=findExtremum(l,compareMin);
	cout << res->info << endl;



	//giai phong
	detroyList(l);
	return 0;
}