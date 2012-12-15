#include "GeneralTree.h"
#include <iostream>

GeneralTree::GeneralTree() {
	root = NULL;
}

void GeneralTree::insert(node * q, string name, string relation_name, int sons) {
	node * p;
	node * r; //Node to add the tree
	bool found = false;	

	if (root == NULL) {
		q = new node;
		q->name = name;
		q->sons = sons;
		q->visited = false;
		q->first = NULL;
		q->next = NULL;
		q->parent = NULL;
		root = q;
	}
	else {
		
		r = new node;
		r->name = name;
		r->sons = sons;
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

					//Check for the father?
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
		cout << p->name << endl;
		print_in_trav(p->next);
	}
	
}

void GeneralTree::father_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;
				node * current = p;
				node * parent = p->parent;
			
				while (parent != NULL && current != parent->first) {
					current = parent;
					parent = current->parent;
				}

				if (parent == NULL) 
					cout << name << " has no father." << endl;
				else 
					cout << name << "'s father is " << parent->name << "." << endl;
			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::sons_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;
				node * fs = p->first;
				cout << "The sons of " << name << " are: " << endl;
				while (fs != NULL) {
					cout << fs->name << endl;
					fs = fs->next;
				}

			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::brothers_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;
				node * younger = p->next;		
				
				cout << "The brothers of " << name << " are:" << endl;

				//Checking younger brothers
				while (younger != NULL) {
					cout << younger->name << endl;
					younger = younger->next;
					
				}

				node * current = p;
				node * older = p->parent;

				//Checking older brothers
				while (older != NULL && current != older->first) {
					cout << older->name << endl;
					current = older;
					older = current->parent;
				}

			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::youngest_brother_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;	

				node * younger = p;

				while (younger->next != NULL) {
					younger = younger->next; 
				}

				cout << "The youngest brother of " << name << " is " << younger->name << endl;

			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::oldest_brother_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;	

				node * current = p;
				node * older = p->parent;

				while (older != NULL && current != older->first) {
					current = older;
					older = current->parent;
				}

				cout << "The oldest brother of " << name << " is " << current->name << endl;

			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::oldest_son_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;	

				if (p->first != NULL) {
					cout << "The oldest son of " << name << " is " << p->first->name << endl;
				}
				else
					cout << name << " has no sons." << endl;

			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::youngest_son_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;	

				if (p->first == NULL) {
					cout << name << " has no sons." << endl;
				}
				else {
					node * first = p->first;

					while (first->next != NULL) {
						first = first->next;
					}

					cout << "The youngest son of " << name << " is " << first->name << endl;
				}

			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::grandfather_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;
				node * current = p;
				node * parent = p->parent;
			
				while (parent != NULL && current != parent->first) {
					current = parent;
					parent = current->parent;
				}

				if (parent->parent == NULL) 
					cout << name << " has no grandfather." << endl;
				else 
					cout << name << "'s grandfather is " << parent->parent->name << "." << endl;
			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}

void GeneralTree::uncles_p(string name) {
	node * p;
	node * q;
	p = root;
	q = root;
	bool found = false;

	while (root->visited == false || !found) {
		if (p->visited == false) {

			if (p->name == name) {
				found = true;
				node * current = p;
				node * parent = p->parent;
			
				while (parent != NULL && current != parent->first) {
					current = parent;
					parent = current->parent;
				}

				node * younger = parent->next;

				cout << "The uncles of " << name << " are: " << endl;

				//Go through younger uncles
				while (younger != NULL) {
					cout << younger->name << endl;
					younger = younger->next;
				}

				current = parent;
				node * older = parent->parent;

				//Go through older uncles
				while (older != NULL && current != older->first) {
					cout << older->name << endl;
					current = older;
					older = current->parent;
				}
			}
			p->visited = true;
		}
		else if (p->first != NULL && p->first->visited != true) {
			q = p;		
			p = p->first;

		}
		else if (p->next != NULL && p->next->visited != true) {
			q = p;
			p = p->next;
				
		}				
														
		else {
		
			p = p->parent;
		}
			
	}
	reset_visited(root);

}