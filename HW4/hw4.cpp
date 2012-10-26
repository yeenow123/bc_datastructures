#include <string>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree BTree;
	BTree.insert(5);
	BTree.insert(6);
	BTree.insert(7);
	BTree.insert(2);

	BTree.PostTrav(BTree.root);
	BTree.childrenCount(BTree.root);
}