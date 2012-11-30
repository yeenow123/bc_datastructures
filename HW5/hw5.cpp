#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GeneralTree.h"

using namespace std;

int split(const string &txt, vector<string> &strs, char ch) {
    unsigned int pos = txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();

    // Split the string based on the delimiter 'ch'
    while( pos != string::npos ) {
        strs.push_back(txt.substr( initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back(txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ));

    return strs.size();
}

void readFile(string filename) {
	ifstream file;
	string line;
	vector<string> strvec;

	file.open(filename.c_str());

	if (file.is_open()) {
		GeneralTree tree;
		while (getline(file, line)) {
			
			split(line, strvec, ' ');
			
			tree.insert(tree.root, strvec[0], strvec[1]);

		}
		tree.print_in_trav(tree.root);

	}
}

int main() {
	readFile("hw5Data.txt");

}