#pragma once
#include <iostream>
#include <string>
#include "bAccount.h"
using namespace std;

class bank {
protected: 
	string name, address, hours;										// variable for bank info
	int totalBalance = 0;												// totalBalance to collect aggregated balances of all accounts
	int static bankCount;												// static variable of bankCount to count how many bank accounts have been created
public: 

	bank() {															// default contructor
		name = "n/a";
		address = "n/a";
		hours = "n/a";
	}

	void promptBankInfo();												// funtion info found in bank.cpp
	void setBankInfo(string name, string address, string hours);
	string getBankName() const { return name; }
	string getAddress() const { return address; }
	string getHours() const { return hours; }
	void displayMenu();
	int getAggregateBalance() const { return totalBalance; }
	int getBankCount() const { return bankCount; }
};

