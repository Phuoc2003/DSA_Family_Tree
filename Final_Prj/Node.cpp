#include "Node.h"

Node* getNode() {
	string name;
	unsigned int dob;
	cout << "\nNhap ho va ten: ";
	cin >> name;
	cin.clear();

	cout << "Nhap ngay sinh: ";
	cin >> dob;

	Node* p = new Node;
	if (p == NULL) {
		cout << "Khong du bo nho!";
		return NULL;
	}

	p->name = name;
	p->dob = dob;
	p->parent = NULL;
	p->sibling = NULL;
	p->child = NULL;
	return p;
}

void printInfo(Node* p) {
	cout << "\nHo va ten: " << p->name;
	cout << "\nNgay thang nam sinh: " << p->dob;
}