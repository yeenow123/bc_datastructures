#include <cstddef>
#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() { 
	root = NULL;
}

void BinaryTree::insert(int num) {
	if (root != NULL) {
		insertNode(root, num);
	}
	else {
		root = new Node;
		root->num = num;
		root->left = NULL;
		root->right = NULL;	
	}
}

void BinaryTree::insertNode(Node * leaf, int num) {
	Node * p;
	p->num = num;
	p->left = NULL;
	p->right = NULL;

	if (num <= leaf->num) {
		if (leaf->left != NULL)
			BinaryTree::insertNode(leaf->left, num);
		else
			leaf->left = p;
	}
	else if (num > leaf->num) {
		if (leaf->right != NULL)
			BinaryTree::insertNode(leaf->right, num);
		else
			leaf->right = p;
	}
}

void BinaryTree::PreTrav(Node * root) {
	Node * p = root;
	if (p != NULL) {
		cout << p->num << " ";
		BinaryTree::PreTrav(p->left);
		BinaryTree::PreTrav(p->right);
	}
}