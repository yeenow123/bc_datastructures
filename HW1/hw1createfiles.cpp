
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

double fRand(double fMin, double fMax) {
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

double round_nplaces(double value, int to) {
	double places = pow(10.00, to);
	return round(value * places) / places;
}

void CreateTransactionFile() {
	ofstream myfile;
	int randType, randCust, randTrans, randQty, randItem;
	double randCost, randPay;
	char type;
	string items[5] = { "Milk", "iPod", "Pencil", "Bike", "Flash Drive"};
	myfile.open("TransactionFile.txt");
	for (int i=1; i<35; i++) {
		randType = rand() % 2;
		randItem = rand() % 5;
		randCust = rand() % 9 + 1;
		randTrans = rand() % 900 + 100;
		randQty = rand() % 10 + 1;
		randCost = fRand(20, 200);
		randPay = fRand(20, 200);
		if (randType == 0) {
			type = 'O';
			myfile << type << " 000" << randCust << " 0" << randTrans << " " << items[randItem] << " " << randQty << " $" << round_nplaces(randCost, 2) << endl;  
		}
		else if (randType == 1) {
			type = 'P';
			myfile << type << " 000" << randCust << " 0" << randTrans << " $" << round_nplaces(randPay, 2) << endl;
		}
		
	}
}

void CreateMasterFile() {
	ofstream myfile;
	string names[9] = { "Judith Gonzales", "Alexander Berry", "Cassandra Webb", "Ross Kelley", "Harriet Byrd", "Rudolph Perez", "Guillermo Hardy", "Terence Leonard", "Andre Willi" };
	myfile.open("MasterFileTest.txt");
	for (int i=1; i<9; i++) {
		myfile << "000" << i << " " << setw(20) << names[i] << " " << (rand() % 6000) << endl;
	}
}