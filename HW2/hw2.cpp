#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iomanip>
using namespace std;

//Convert name of city to array number
int processText(vector<string> card) {
	if (card[1] == "New York") return 0;
	else if (card[1] == "Los Angeles") return 1;
	else if (card[1] == "Miami") return 2;
	else if (card[1] == "Houston") return 3;
	else if (card[1] == "Chicago") return 4;
}

string cityName(int num) {
	if (num == 0) return "New York";
	else if (num == 1) return "Los Angeles";
	else if (num == 2) return "Miami";
	else if (num == 3) return "Houston";
	else if (num == 4) return "Chicago";
}

int stoInt(string s) {
	istringstream buffer(s);
	int num;
	buffer >> num;
	return num;
}

vector<string> splitSpec(string input) {
	vector<string> output;
	stringstream ss;
	string conversion;
	string numbers = input.substr(input.find_first_of("0123456789"), input.length());
	int currPos = 0;
	int lastPos = numbers.find_first_not_of("0123456789", currPos) - currPos;

	ss << input.at(0);
	ss >> conversion;
	output.push_back(conversion); // Get shipment/order
	output.push_back(input.substr(2, input.find_first_of("0123456789")-3)); // Get city name

	// FIX THIS FOR THE LAST NUMBER AND THE UN-ADJUSTABLE FOR LOOP!
	for (int i=0; i<3; i++) { 
		output.push_back(numbers.substr(currPos, lastPos));
		currPos += lastPos + 1;
		lastPos = numbers.find_first_not_of("0123456789", currPos) - currPos;
	}
	return output;
}

void readFile(string fileName) {
	int whsNum;
	int i, j, k;
	int max = 0;
	int maxWhsNum, remaining;
	vector<int> maxWhs;
	vector < vector<int> > whs(5, vector<int>(3)); // Vector of warehouses and their 3 items
	vector<string> card; // One line of ship/order data

	ifstream infile;
	string line;

	infile.open(fileName.c_str());

	if (infile.is_open()) {
		while (!infile.eof()) {

			getline(infile, line);
			card = splitSpec(line);
			whsNum = processText(card);

			if (card[0] == "s") {
				whs[whsNum][0] += stoInt(card[2]);
				whs[whsNum][1] += stoInt(card[3]);
				whs[whsNum][2] += stoInt(card[4]);
				cout << card[1] << " " << whs[whsNum][0] << " " << whs[whsNum][1] << " " << whs[whsNum][2] << endl;
			}
			else if (card[0] == "o") {
				i = 0;
				j = 2;
				k = 0;
				for (i;i<3;i++) { 
					// If the warehouse has enough of the item to ship
					if (whs[whsNum][i] >= stoInt(card[j])) {
						whs[whsNum][i] -= stoInt(card[j]);
						
					}
					else {
						// Get the warehouse number with most qty of item
						for (k; k<5; k++) {
							if (max <= whs[k][i]) {
								max = whs[k][i];
								maxWhsNum = k;

							}
						}
						if ((max + whs[whsNum][i]) >= stoInt(card[j])) {
							remaining = whs[whsNum][i] % stoInt(card[j]);
							whs[whsNum][i] = 0;
							whs[maxWhsNum][i] -= remaining;
							cout << remaining << " of item" << i << " shipped from " << cityName(maxWhsNum) << " to " << card[1] << endl;
							cout << cityName(maxWhsNum) << " " << whs[maxWhsNum][0] << " " << whs[maxWhsNum][1] << " " << whs[maxWhsNum][2] << endl;
						}
						else {
							cout << "Order unfilled" << endl;
						}
					}
					j++;
				}
				cout << card[1] << " " << whs[whsNum][0] << " " << whs[whsNum][1] << " " << whs[whsNum][2] << endl;

			}
		}
	}
}

int main() {
	readFile("hw2Data.txt");

}