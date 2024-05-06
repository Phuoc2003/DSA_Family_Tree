#pragma once

#include "Node.h"

typedef struct FamilyTree {
	Node* head;
};

void initTree(FamilyTree& tree);
void addNewMember(FamilyTree &tree);
void addParent(FamilyTree& tree, Node* ptr);
void addChild(Node* ptr);
void addSibling(Node* ptr);
Node* traverseSibling(Node* ptr, string name);
Node* traverseChild(Node* ptr, string name);
Node* searchPerson(FamilyTree &tree, string name);
void printInfoMem(FamilyTree& tree);
void option2(FamilyTree& tree);
void console(FamilyTree& tree);