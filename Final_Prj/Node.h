#pragma once

#include <iostream>

using namespace std;

typedef struct Node {
	string name;
	unsigned int dob; //Nam sinh
	Node* parent;
	Node* sibling;
	Node* child;
};

Node* getNode();
void printInfo(Node* p);