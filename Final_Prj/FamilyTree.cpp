#include "FamilyTree.h"

void initTree(FamilyTree& tree) {
	tree.head = NULL;
}

void addNewMember(FamilyTree& tree) {
	if (!tree.head) {
		cout << "Cay pha he rong, them thanh vien dau tien vao cay!";
		Node* newEle = getNode();
		tree.head = newEle;
	}
	else {
		cout << "\nCay pha he khong rong. Vui long chon mot trong cac tuy chon sau:\n";
		cout << "1. Them cha.\n";
		cout << "2. Them con.\n";
		cout << "3. Them anh chi.\n";
		
		int choice;
		cout << "Nhap vao lua chon(1/2/3): ";
		cin >> choice;

		string name;
		cout << "Nhap ten thanh vien ton tai trong cay pha he: ";
		cin >> name;
		cin.clear();

		Node* existingMem = searchPerson(tree, name);
		if (!existingMem) {
			cout << "Khong tim thay thanh vien " << name << "\n";
			return;
		}
		
		switch (choice)
		{
		case 1:
			cout << "\nThem cha.";
			addParent(existingMem);
			break;
		case 2:
			cout << "\nThem con.";
			addChild(existingMem);
			break;
		case 3:
			cout << "\nThem anh chi.";
			addSibling(existingMem);
			break;
		default:
			cout << "Lua chon khong hop le!" << endl;
		}
	}
}

void addParent(Node* ptr) {

}

void addChild(Node* ptr) {
	Node* child = getNode();
	if (!ptr->child) {
		ptr->child = child;
		child->parent = ptr;
	}
	else {
		Node* lastChild = ptr->child;
		while (lastChild->sibling) {
			lastChild = lastChild->sibling;
		}
		lastChild->sibling = child;
		lastChild->parent = ptr->parent;
	}
	cout << "\nDa them con.";
}

void addSibling(Node* ptr) {
	Node* sibling = getNode();
	if (!ptr->sibling) {
		ptr->sibling = sibling;
		sibling->parent = ptr->parent;
	}
	else {
		Node* lastSib = ptr->sibling;
		while (lastSib->sibling) {
			lastSib = lastSib->sibling;
		}
		lastSib->sibling = sibling;
		lastSib->parent = ptr->parent;
	}
}

Node* traverseSibling(Node* ptr, string name) {
	Node* p = ptr->sibling;
	while (p) {
		Node* temp=NULL;
		if (p->name == name)
			return p;
		else if ((temp == traverseChild(p, name)) != NULL)
			return temp;
		else
			p = p->sibling;
	}
	return NULL;
}

Node* traverseChild(Node* ptr, string name) {
	Node* p = ptr->child;
	while (p) {
		Node* temp = NULL;
		if (p->name == name)
			return p;
		else if ((temp == traverseSibling(p, name)) != NULL)
			return temp;
		else
			p = p->child;
	}
	return NULL;
}

Node* searchPerson(FamilyTree& tree, string name) {
	Node* temp = NULL;
	if (tree.head->name == name)
		return tree.head;
	else if ((temp = traverseSibling(tree.head, name)) != NULL)
		return temp;
	else if ((temp == traverseChild(tree.head, name)) != NULL)
		return temp;
	return NULL;
}

void printInfoMem(FamilyTree& tree) {
	string name;
	cout << "\nNhap vao ten thanh vien can in thong tin: ";
	cin >> name;
	cin.clear();

	Node* existingMem = searchPerson(tree, name);
	if (!existingMem) {
		cout << "\nKhong tim thay thanh vien " << name << "\n";
		return;
	}
	else {
		cout << "\nThong tin cua thanh vien " << name << ".\n";
		printInfo(existingMem);
		if (!existingMem->child) {
			cout << "\nThanh vien nay khong co con!\n";
			return;
		}
		else {
			Node* p = existingMem->child;
			cout << "\nTen cua cac con cua thanh vien " << name << ": ";
			while (p) {
				cout << p->name << ", ";
				p = p->sibling;
			}
		}
	}
}
