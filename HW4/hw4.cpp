#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "BinaryTree.h"

using namespace std;

template<class T> //Converts string to to any type (int, double.. in this case)
T converter(string input) {
	stringstream ss(input);
	T num;
	ss >> num;
	return num;
}

int split(const string &txt, vector<int> &strs, char ch)
{
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

void readFile(string fileName) {
	ifstream file;
	string line;
	vector <int> tokens;
	int i;

	file.open(fileName.c_str());

	if (file.is_open()) {
		while (getline(file, line)) {
			split(line, tokens, ' ');
			for (i=0; i<tokens.size(); i++) {
				//Create BTree and do stuff with it!

				cout << tokens[i];
			}			
		}
	}
}



int main() {
	BinaryTree BTree;
	BTree.insert(5);
	BTree.insert(6);
	BTree.insert(7);
	BTree.insert(2);
	BTree.insert(6);


	//BTree.PostTrav(BTree.root);
	//BTree.remove(2);
	//BTree.PostTrav(BTree.root);

	readFile("hw4Data.txt");

}