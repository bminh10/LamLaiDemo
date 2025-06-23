#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//khai bao cau truc
//khoi tao rong
//input sinh vien tu file
//them cuoi
//xuat danh sach
//giai phong nut

struct SinhVien {
	long mssv;
	string hoten;
	char ngaysinh[11];
	string quequan;
	double dtb;

};

struct Node {
	//thong tin sinh vien
	SinhVien info;
	//truong next tro toi nut tiep theo
	Node* next;
};
struct LinkedList {
	Node* head;
	Node* tail;
};

void init(LinkedList &a) {
	a.head = nullptr;
	a.tail = nullptr;
}

Node* createNode(SinhVien x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

void xuat1SV(SinhVien sv) {
	cout << "=========================\n";
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Ho ten: " << sv.hoten << endl;
	cout << "Ngay sinh: " << sv.ngaysinh << endl;
	cout << "Que quan: " << sv.quequan << endl;
	cout << "DTB: " << sv.dtb << endl;
	cout << "=========================\n";
}


void addLast(LinkedList& a, SinhVien x) {
	Node* p = createNode(x);
	if (a.head == nullptr) {
		a.head = p;
		
	}
	else {
		Node* tmp = a.tail;
		tmp->next = p;
		
	}
	a.tail = p;

}


void inputFromList(LinkedList &a) {
	ifstream fin("SinhVien.txt");
	
	if (fin.is_open()) {
		
		while (!fin.eof()) {
			SinhVien sv;

			fin >> sv.mssv;
			fin.ignore();
			getline(fin, sv.hoten, '#');
			fin.getline(sv.ngaysinh, 11, '#');
			getline(fin, sv.quequan, '#');
			fin >> sv.dtb;
			
			addLast(a, sv);

		}

		
		fin.close();
	}
}

int delFirst(LinkedList &a) {
	if (a.head != NULL) {
		Node* tmp = a.head;
		if (tmp->next == nullptr) {
			a.head = nullptr;
			a.tail = nullptr;
		}
		else {
			a.head = tmp->next;
			tmp->next = nullptr;
		}
		delete tmp;
		return 1; //xoa thanh cong
	}
	return -1;//xoa khong thanh cong
}


void printList(LinkedList a) {
	if (a.head == NULL) {
		cout << "Danh sach rong \n";
		return;
	}
	Node* tmp = a.head;
	while (tmp != NULL) {
		xuat1SV(tmp->info);
		tmp = tmp->next;
	}
	
	
}

int cleareNode(LinkedList& a) {
	if (a.head != NULL) {
		
		while (a.head!=NULL) {
			delFirst(a);
		}
		return 1; //giai phong thanh cong
	}
	return -1;// danh sach ban dau rong
}





int main() {
	LinkedList a;
	//khoi dong danh sach
	init(a);

	inputFromList(a);

	printList(a);

	cout << "=========================KQ SAU KHI XOA=======================\n";
	delFirst(a);
	printList(a);
	//giai phong

	if (cleareNode(a) != -1) {
		cout << "Giai phong xong !\n";
		printList(a);
	}

	return 0;
}