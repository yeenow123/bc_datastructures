#include <cstddef>
#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() { 
	root = NULL;
}

void BinaryTree::insert(Node *& node, int num) {
	
	if (node == NULL) {
		node = new Node;
		node->num = num;
		node->left = NULL;
		node->right = NULL;	
	}
	else {
		if (num == node->num)
			cout << "The number is a duplicate value." << endl;

		else if (num < node->num)
			insert(node->left, num);
		else
			insert(node->right, num);
	}
}

void BinaryTree::remove(int num) {
	Node * c;
	Node * tc;
	bool found = false;


	if (root == NULL)
		cout << "The tree is empty." << endl;
	else {

		c = root;
		tc = root;


		while (c != NULL && !found) { // Look for the number in tree
			if (c->num == num) {
				found = true;
				
			}
			else {
				tc = c;
				if (c->num > num)
					c = c->left;
				else
					c = c->right;
			}
		}

		if (c == NULL)
			cout << "The number is not in the tree." << endl;
		else if (found) {

			if (c == root) {
				
				removeNode(c); 
				root = c;
			}
			else if (tc->num > num) {
				removeNode(tc->left);
							
			}
			else {
				removeNode(tc->right);
				
			}
		}
		else
			cout << "The number is not in the tree." << endl;
	}

}

void BinaryTree::removeNode(Node *& p) {
	Node * c;
	Node * tc;
	Node * temp;

	if (p == NULL) 
		cout << "The node chosen to be deleted is NULL." << endl;
	else if (p->left == NULL && p->right == NULL) { // Node has no children
		temp = p;
		p = NULL;
		delete temp;

	}
	else if (p->left == NULL) { // Node has right child

		temp = p;
		p = temp->right;
		delete temp;
		

	}
	else if (p->right == NULL) { // Node has left child
		temp = p;
		p = temp->left;
		delete temp;

	}
	else { // Node has two children

		c = p->left;
		tc = NULL;

		while (c->right != NULL) {

			tc = c;
			c = c->right;
		}

		p->num = c->num;

		if (tc == NULL) {
			
			p->left = c->left;
		}
		else {
		 	tc->right = c->left;
		 	
		}

		delete c;

	}

}

// void BinaryTree::insertNode(Node *& leaf, int num) {
// 	Node * p = new Node;
// 	p->num = num;
// 	p->left = NULL;
// 	p->right = NULL;


// 	if (num == leaf->num) { cout << num << " is a duplicate value." << endl;
// 	cout << num << " "; }

// 	else if (num < leaf->num) {
// 		if (leaf->left != NULL)
// 			insertNode(leaf->left, num);
// 		else
// 			leaf->left = p;
// 	}
// 	else if (num > leaf->num) {
// 		if (leaf->right != NULL)
// 			insertNode(leaf->right, num);
// 		else
// 			leaf->right = p;
// 	}
// }

void BinaryTree::PreTrav(Node * root) {
	Node * p = root;
	if (p != NULL) {
		cout << p->num << " ";
		PreTrav(p->left);
		PreTrav(p->right);
	}
	
}

void BinaryTree::InTrav(Node * root) {
	Node * p = root;
	if (p != NULL) {
		InTrav(p->left);
		cout << p->num << " ";
		InTrav(p->right);
	}
	
}

void BinaryTree::PostTrav(Node * root) {
	Node * p = root;
	if (p != NULL) {
		PostTrav(p->left);
		PostTrav(p->right);
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
		count += nodeCount(p->left);
		count += nodeCount(p->right);
		return count;
		cout << "There are " << count << " nodes in the tree." << endl;
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
		childrenCount(p->left);
		childrenCount(p->right);
	}
}

void BinaryTree::deleteTree(Node * proot) {
	Node * p = proot;
	if (p != NULL) {
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
		root = NULL;
	}

}

