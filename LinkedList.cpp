#include "wave.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct SinhVien
{
	long mssv;
	string hoTen;
	char ngaySinh[11];
	string queQuan;
	double dtb;
};

void nhap1Sv(SinhVien& sv) {
	cout << "Nhap MSSV: ";
	cin >> sv.mssv;
	cout << "Nhap ho ten: ";
	cin.ignore(1);
	getline(cin, sv.hoTen, '\n');
	cout << "Nhap ngay sinh: ";
	cin >> sv.ngaySinh;
	cout << "Nhap que quan: ";
	cin.ignore(1);
	getline(cin, sv.queQuan);
	cout << "Nhap diem TB: ";
	cin >> sv.dtb;
}

void xuat1Sv(SinhVien sv) {
	cout << "===============================\n";
	cout << "ID: ";
	cout << sv.mssv << endl;
	cout << "Ho va ten: ";
	cout << sv.hoTen << endl;
	cout << "Ngay sinh: ";
	cout << sv.ngaySinh << endl;
	cout << "Que quan: ";
	cout << sv.queQuan << endl;
	cout << "Diem trung binh: ";
	cout << sv.dtb << endl;
	cout << "===============================\n";
}

template <typename T>
void inputListFromFile(Node<T>*& head) {
	ifstream fin("SinhVien.txt");

	if (fin.is_open()) {

		while (!fin.eof()) {
			SinhVien sv;

			fin >> sv.mssv;
			fin.ignore();
			getline(fin, sv.hoTen, '#');
			fin.getline(sv.ngaySinh, 11, '#');
			getline(fin, sv.queQuan, '#');
			fin >> sv.dtb;

			insertFirst(head, sv);
		}

		fin.close();
	}
}
template <typename T>
bool delNode(Node<T>*& head, const int key) {
	Node<T>* q = head;
	Node<T>* qPrev = NULL;

	while (q != NULL && q->info.mssv != key) {
		qPrev = q;
		q = q->next;
	}

	if (q == NULL)
		return false;

	if (qPrev == NULL) {
		head = head->next;
	}
	else
		qPrev->next = q->next;

	q->next = NULL;
	delete q;
	return true;
}

template <typename T>
//Truy xuat phan tu thu i
Node<T>* getNodeAt(Node<T>*& head, int index) {
	Node<T>* p = head;
	int i = 0;

	while (p != NULL && i < index) {
		p = p->next;
		i++;
	}

	return p;
}
//Thao tac tim kiem
template <typename T>
Node<T>* search(Node<T>* head, int id) {
	Node<T>* p = head;
	while (p != NULL && p->info.mssv != id) {
		p = p->next;
	}
	return p;
}

int compareID(SinhVien sv1, SinhVien sv2) {
	return sv1.mssv - sv2.mssv;
}
//Sap xep


template <typename T>

void sort(Node<T>* head,int func(T,T)) {
	if (head != NULL) {
		for (Node<T>* i = head; i->next != NULL; i = i->next) {
			for (Node<T>* j = i->next; j != NULL; j = j->next) {
				if (func(i->info, j->info)<0) {
					swap(i->info, j->info);
				}
			}
		}
	}
}
template <typename T>
void insertOrdered(Node<T>*& head, T x) {
	if (head == NULL || head->info.mssv > x.mssv) {
		insertFirst(head, x);
		return;
	}

	Node<T>* p = createNode(x);
	Node<T>* q = head;

	while (q->next != NULL && q->next->info.mssv < x.mssv) {
		q = q->next;
	}

	p->next = q->next;
	q->next = p;
}
//Duyet danh sach
template <typename T>
void printList(Node<T>* head) {
	if (head == NULL) {
		cout << "Danh sach rong!\n";
		return;
	}

	Node<T>* tmp = head;
	while (tmp != NULL) {
		xuat1Sv(tmp->info);
		tmp = tmp->next;
	}

}



int main() {
	Node<SinhVien>*head;
	init(head);

	inputListFromFile(head);

	printList(head);

	cout << "=================KQ SAP XEP===================\n";
	sort(head, compareID);
	printList(head);

	detroyList(head);
	return 0;
}