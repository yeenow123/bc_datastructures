#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

struct TransRecord {
	char transType;
	int custNum;
	int transNum;
	string itemName;
	int qty;
	double cost;
	double payment;
};

struct CustRecord {
	int custNum;
	string custName;
	double balance;
};

int stoInt(string s) {
	istringstream buffer(s);
	int num;
	buffer >> num;
	return num;
}

double stoDbl(string s) {
	istringstream buffer(s);
	double num;
	buffer >> num;
	return num;
}

vector<string> split(string const &input) { 
    stringstream buffer(input);
    vector<string> ret;

    copy(istream_iterator<string>(buffer), 
              istream_iterator<string>(),
              back_inserter(ret));
    return ret;
}

CustRecord buildACustRecord(string line) {
	CustRecord oneRecord;
	vector<string> sVec;

	sVec = split(line);

	oneRecord.custNum = stoInt(sVec[0]);
	oneRecord.custName = sVec[1] + " " + sVec[2];
	oneRecord.balance = stoDbl(sVec[3]);

	return oneRecord;
}

vector<CustRecord> getCustomers(string fileName) {
	vector <CustRecord> records;
	CustRecord eachRecord;
	string line;
	ifstream infile (fileName.c_str());
	if (infile.is_open()) {
		for (int i=0; i<8; i++) {
			getline(infile, line);
			eachRecord = buildACustRecord(line);
			records.push_back(eachRecord);
		}
	}
	infile.close();
	return records;	
}

TransRecord buildATransRecord(string line) {
	TransRecord oneRecord;
	vector<string> sVec;

	sVec = split(line); //Use utility function at top

	oneRecord.custNum = stoInt(sVec[1]);
	oneRecord.transNum = stoInt(sVec[2]);
	
	if (sVec[0] == "P") {
		oneRecord.transType = 'P';
		oneRecord.payment = stoDbl(sVec[3].erase(0, 1));
	}
	else if (sVec[0] == "O") {
		oneRecord.transType = 'O';
		oneRecord.itemName = sVec[3];
		oneRecord.qty = stoInt(sVec[4]);
		oneRecord.cost = stoDbl(sVec[5].erase(0, 1));
	}
	return oneRecord;	
}

vector<TransRecord> getTransactions(string fileName) {
	vector <TransRecord> records;
	TransRecord eachRecord;
	string line;
	ifstream infile (fileName.c_str());
	if (infile.is_open()) {
		for (int i=0; i<34; i++) {
			getline(infile, line);
			eachRecord = buildATransRecord(line);
			records.push_back(eachRecord);
		}
	}
	infile.close();
	return records;
}

void calcRecords(vector<TransRecord> transrecords, vector<CustRecord> custrecords) {
	for (int i=0; i<custrecords.size(); i++) {
		cout << "Customer Name: " << custrecords[i].custName << endl;
		cout << "Customer Number: " << custrecords[i].custNum << endl;
		cout << "Previous Balance: $" <<  custrecords[i].balance << endl;
		for (int j=0; j<transrecords.size(); j++) {
			if (transrecords[j].custNum == custrecords[i].custNum) {
				if (transrecords[j].transType == 'P') {
					cout << "Transaction #" << transrecords[j].transNum << " Payment $" << transrecords[j].payment << endl;
					custrecords[i].balance -= transrecords[j].payment;
				}
				else if (transrecords[j].transType == 'O') {
					cout << "Transaction #" << transrecords[j].transNum << " " << transrecords[j].itemName << " Ordered $" << (transrecords[j].qty * transrecords[j].cost) << endl;
					custrecords[i].balance += (transrecords[j].qty * transrecords[j].cost);					
				}
			}
		}
		if (custrecords[i].balance < 0) custrecords[i].balance = 0;
		cout << "Balance Due: $" << custrecords[i].balance << endl << endl;
	}
}

int main() {
	vector<CustRecord> customers;
	vector<TransRecord> trans;
	customers = getCustomers("MasterFile.txt");
	trans = getTransactions("TransactionFile.txt");
	calcRecords(trans, customers);
}
