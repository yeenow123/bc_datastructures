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

void BinaryTree::delete(int num) {
	
}

void BinaryTree::insertNode(Node * leaf, int num) {
	Node * p = new Node;
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

void BinaryTree::InTrav(Node * root) {
	Node * p = root;
	if (p != NULL) {
		BinaryTree::InTrav(p->left);
		cout << p->num << " ";
		BinaryTree::InTrav(p->right);
	}
}

void BinaryTree::PostTrav(Node * root) {
	Node * p = root;
	if (p != NULL) {
		BinaryTree::PostTrav(p->left);
		BinaryTree::PostTrav(p->right);
		cout << p->num << " ";

	}
}

int BinaryTree::nodeCount(Node * root) {
	Node * p = root;
	if (p == NULL) {
		return 0;
	}
	else {
		int count;
		count = 1;
		count += BinaryTree::nodeCount(p->left);
		count += BinaryTree::nodeCount(p->right);
		return count;
	}

}

void BinaryTree::childrenCount(Node * root) {
	Node * p = root;
	int children;

	if (p != NULL) {
		children = 0;
		if (p->left != NULL) { children += 1; }
		if (p->right != NULL) { children += 1; }
		cout << "Node with data " << p->num << " has " << children << " child nodes." << endl;
		BinaryTree::childrenCount(p->left);
		BinaryTree::childrenCount(p->right);
	}
}

