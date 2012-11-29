#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include "BinaryTree.h"

using namespace std;

template<class T> //Converts string to to any type (int, double.. in this case)
T converter(string input) {
	stringstream ss(input);
	T num;
	ss >> num;
	return num;
}

int splitNum(const string &txt, vector<int> &strs, char ch) {
    unsigned int pos = txt.find( ch );
    unsigned int initialPos = 0;
    int num;
    strs.clear();

    // Split the string based on the delimiter 'ch'
    while( pos != string::npos ) {
    	num = converter<int>(txt.substr( initialPos, pos - initialPos + 1 ));
        strs.push_back(num);
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    num = converter<int>(txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ));

    if (num != -999) 
    	strs.push_back(num);

    return strs.size();
}

int split(const string &txt, vector<string> &strs, char ch) {
    unsigned int pos = txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();

    // Split the string based on the delimiter 'ch'
    while( pos != string::npos ) {
        strs.push_back(txt.substr( initialPos, pos - initialPos + 1 ));
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back(txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ));

    return strs.size();
}

void treeInitialize(BinaryTree & BTree, string line) {

	vector <int> tokens;
	int i;

	splitNum(line, tokens, ' ');

	for (i=0; i<tokens.size(); i++) {
		BTree.insert(BTree.root, tokens[i]);

	}


	BTree.InTrav(BTree.root);
	cout << endl;
	BTree.PreTrav(BTree.root);
	cout << endl;
	BTree.PostTrav(BTree.root);
	cout << endl;
	cout << "The tree has " << BTree.nodeCount(BTree.root) << " nodes." << endl;
	//BTree.childrenCount(BTree.root);
	
	//return BTree;
}

void treeChange(BinaryTree & BTree, string line) {

	vector <string> strtokens;
	int i;

	split(line, strtokens, ' ');

	for (i=0; i<strtokens.size(); i+=2) {
		if (strtokens[i] == "Insert ") {
			cout << strtokens[i+1];
			BTree.insert(BTree.root, converter<int>(strtokens[i+1]));
		}
		else {
			BTree.remove(converter<int>(strtokens[i+1]));

		}
	}

	cout << "Inserted and deleted nodes." << endl;
	BTree.InTrav(BTree.root);
	cout << endl;
	BTree.PreTrav(BTree.root);
	cout << endl;
	BTree.PostTrav(BTree.root);
	cout << endl;
	cout << "The tree now has " << BTree.nodeCount(BTree.root) << " nodes." << endl;
	//BTree.childrenCount(BTree.root);
	BTree.deleteTree(BTree.root); //fix this fucking delete tree shitttt
	
	//return BTree;
}

void readFile(string fileName) {
	ifstream file;
	string line;
	int count = 0;

	file.open(fileName.c_str());

	if (file.is_open()) {		
		
		BinaryTree BTree;

		while (getline(file, line)) {
			
			if (count % 2 == 0) {
				cout << "Tree #" << count / 2 << endl;
				treeInitialize(BTree, line);
			}
			else if (count % 2 != 0) {
				treeChange(BTree, line);
			}
			
			count++;

		}
	}
}


int main() {
	readFile("hw4Data.txt");


}