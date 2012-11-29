#include <iostream>
#include <fstream>
#include <string>
#include "GeneralTree.h"

using namespace std;

void readFile(string filename) {
	ifstream file;
	string line;

	file.open(filename.c_str());

	if (file.is_open()) {
		while (getline(file, line)) {


		}

	}
}

int main() {
	GeneralTree tree;

	tree.insert(tree.root, "Jones", "Tom");
	tree.insert(tree.root, "Bob", "Jones");
	tree.insert(tree.root, "Brian", "Jones");
	tree.insert(tree.root, "Michael", "Brian");

	//tree.print_in_trav(tree.root);
}