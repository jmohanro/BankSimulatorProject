#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "bank.h"
#include "subAccount.h"
using namespace std;


class bAccount : public sAccount{											// inheritance to allow bAccount access to subAccounts vectors
	private: 
	string fName, lName, ssn;												// respective variables for name of account holder, ssn. accNum initially set to 1000
	int accNum = 1000;
	
public:
	vector <pair <string, int>> bankAccount;								// vector of pairs to store bank account info (Name, accNum)
	bAccount() {															// default construtor of bank account
		fName = "n/a";
		lName = "n/a";
		ssn = "XXX-XX-XXXX";

	}
	void createBankAccount();												// function info provided in bAccount.cpp
	void displayBankMenu(int accNumber);
	void setBankInfo(string fName, int accNum);
	int getAccNum() { return accNum; }
	void closeAccount();
	bool searchVec(int num);
	void modifyAccount();
	void briefAccouts();
	void detailedAccounts();
};

