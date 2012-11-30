#include "GeneralTree.h"
#include <iostream>

GeneralTree::GeneralTree() {
	root = NULL;
}

void GeneralTree::insert(node * q, string name, string relation_name) {
	node * p;
	node * r; //Node to add the tree
	bool found = false;	

	if (root == NULL) {
		q = new node;
		q->name = name;
		q->visited = false;
		q->first = NULL;
		q->next = NULL;
		q->parent = NULL;
		root = q;
	}
	else {
		
		r = new node;
		r->name = name;
		r->visited = false;
		r->first = NULL;
		r->next = NULL;
		r->parent = NULL;
		
		//Implement searching for name/traversal

		if (q != NULL) {
			
			q = root;
			
			//Non-recursive traversal of binary tree with visited boolean and parent node reference
			while ((q != root && root->visited == false) || !found) {
				if (q->visited == false) {

					if (q->name == relation_name) {

						found = true;
						if (q->first == NULL) {
								r->parent = q;
	
								q->first = r;	

						}
						else {
							p = q->first;
							while (p->next != NULL) {
								p = p->next;								
							}
							r->parent = p;

							p->next = r;
						}

					}
					q->visited = true;
				}
				else if (q->first != NULL && q->first->visited != true) {		
					q = q->first;

				}
				else if (q->next != NULL && q->next->visited != true) {
					q = q->next;
						
				}				
																
				else {
				
					q = q->parent;
				}
					
			}
			reset_visited(root);

		}
	}		
}

void GeneralTree::reset_visited(node * proot) {
	node * p = proot;

	if (p!= NULL) {
		reset_visited(p->first);
		p->visited = false;
		reset_visited(p->next);
	}
}

void GeneralTree::print_in_trav(node * proot) {
	node * p = proot;

	if (p != NULL) {

		print_in_trav(p->first);
		cout << p->name << " ";
		print_in_trav(p->next);
	}
	
}