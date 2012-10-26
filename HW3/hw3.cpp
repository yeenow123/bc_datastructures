#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Bad global variables?
const double markup = 1.30;
int discCounter = 0;

struct Record {
	double cost, discount;
	int qty;
	Record * next;
};

vector<string> getInput(string line) {
	stringstream ss(line);
	string buffer;
	vector<string> tokens;

	while (ss >> buffer) {
		tokens.push_back(buffer);
	}
	return tokens;
}

template<class T> //Converts string to to any type (int, double.. in this case)
T converter(string input) {
	stringstream ss(input);
	T num;
	ss >> num;
	return num;
}

int Length(Record * head) {
	Record * current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

void displayList(Record * head) {
	Record * current = head;
	unsigned int recordNum = 1;

	cout << "Remaining widgets and their purchase price:" << endl;

	while (current != NULL) {
		cout << "Record #" << recordNum << " has " << current->qty << " widgets remaining at a price of $" << current->cost << endl;
		current = current->next;
		recordNum += 1;
	}
}

Record * receiveRecord(Record *& head, int qty, double cost, double discount=1.00) {
	Record * newRec = new Record;
	newRec->qty = qty;
	newRec->cost = cost;
	newRec->discount = discount;
	newRec->next = NULL;
	Record * current = head;

	if (current == NULL) {
		head = newRec;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newRec;
	}
	cout << "Received " << qty << " units at a price of $" << cost << endl;
	return head;
}

Record * salesRecord(Record *&head, int qtyNeeded) {
	Record * current = head;
	int totalUnits = 0;
	static double totalPrice = 0;

	while (current != NULL && qtyNeeded > 0) {

		//Keep track of promotion counter (need better way of doing this)
		if (discCounter > 0) discCounter -= 1;
		else if (discCounter <= 0) current->discount = 1.00;

		double currDollars = current->cost * current->discount * markup;

		if (current->qty > qtyNeeded) { 
			current->qty -= qtyNeeded;			
			totalUnits += qtyNeeded;
			totalPrice += (qtyNeeded * currDollars);
			cout << qtyNeeded << " at $" << currDollars << " each   Sales: $" << (qtyNeeded * currDollars) << endl;
			qtyNeeded = 0;
			break;
		}
		else if (current->qty <= qtyNeeded) {
			qtyNeeded -= current->qty;
			totalUnits += current->qty;
			totalPrice += (current->qty * currDollars);
			head = current->next;
			cout << current->qty << " at $" << currDollars << " each   Sales: $" << (current->qty * currDollars) << endl;
			delete current;
		}
		
		current = current->next;

	}

	cout << totalUnits << " Widgets sold" << endl;
	cout << "Total Sales: $" << totalPrice << endl;
	if (current == NULL && qtyNeeded > 0) {
		cout << "Remainder of " << qtyNeeded << " Widgets not available" << endl;
	}
	return head;
}

Record * discountRecord(Record *&head, double discount) {
	Record * current = head;

	discCounter = 2;

	while (current != NULL) {
		current->discount = (100 - discount) / 100;
		current = current->next;
	}

	cout << "The next two customers will receive a discount of " << discount << "%" << endl;
}

void readLines(string fileName) {
	ifstream inputFile;
	string line;
	vector <string> tokens;
	Record * head = NULL;
	inputFile.open(fileName.c_str());

	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
			tokens = getInput(line);
			
			if 		(tokens[0] == "R") receiveRecord(head, converter<int>(tokens[1]), converter<double>(tokens[2]));
			else if (tokens[0] == "P") discountRecord(head, converter<double>(tokens[1]));
			else if (tokens[0] == "S") salesRecord(head, converter<int>(tokens[1]));
		}
	}
	displayList(head);
}

int main() {
	readLines("hw3Data.txt");
}