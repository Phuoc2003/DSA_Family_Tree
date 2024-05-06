#include "FamilyTree.h"

int main() {
	FamilyTree tree;
	initTree(tree);
	addNewMember(tree);
	for (int i = 0; i < 2; i++) {
		addNewMember(tree);
	}
	printInfoMem(tree);
	return 1;
}