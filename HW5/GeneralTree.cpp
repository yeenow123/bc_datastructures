#include "GeneralTree.h"
#include <iostream>

GeneralTree::GeneralTree() {
	root = NULL;
}

void GeneralTree::insert(node *& p, string name, string relation_name) {
	node * q;
	node * r;	

	if (root == NULL) {
		p = new node;
		p->name = name;
		p->first = NULL;
		p->next = NULL;
	}
	else {
		
		r = new node;
		r->name = name;
		r->first = NULL;
		r->next = NULL;
		
		//Implement searching for name/traversal

		if (p != NULL) {
			//TRY TO GET NON-RECURSIVE WAY TO TRAVERSE
			cout << relation_name << " ";
			in_trav(p->first);

			//Found the father
			if (p->name == relation_name) {
				
				if (p->first == NULL) {

					p->first = r;
					
				}
				else {
					q = p->first;
					while (q->next != NULL) {
						q = q->next;
						
					}
					q->next = r;
				}
				
			}

			in_trav(p->next);

		}

	}	
	
}

void GeneralTree::in_trav(node * proot) {
	node * p = proot;

	if (p != NULL) {

		in_trav(p->first);
		in_trav(p->next);
	}
	
}

void GeneralTree::print_in_trav(node * proot) {
	node * p = proot;

	if (p != NULL) {

		in_trav(p->first);
		cout << p->name << " ";
		in_trav(p->next);
	}
	
}