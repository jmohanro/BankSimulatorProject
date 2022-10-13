#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class sAccount {
protected: 
	int sAccNum = 1000, cAccNum = 1000, sBalance = 0, cBalance = 0, cMaxBalance = 0, subAccountBalance = 0;	
	static int savCount;
	static int totalCount;
	char lock;
	static int checkCount;
	static int size;

public: 
	
	
	vector <pair <int, int>> savInfo;													// vector of pairs to store savings account info (accNum, balance)
	vector <pair <int, int>> checkInfo;													// vector of pairs to store checking account info (cAccNum, cBalance)
	void setSavInfo(int accNum, int balance);											// all function descriptions in savings.cpp
	void setCheckInfo(int cAccNum, int cBalance, int maxBalance, char lock);

	int getSavAccNum() const { return sAccNum; }
	int getCheckAccNum() const { return cAccNum; }

	int getSavBalance() const { return sBalance; }
	int getCheckBalance() const { return cBalance; }

	void getSavInfo();
	void getCheckInfo();

	int getSavCount() const { return savCount; }
	int getCheckCount() const { return checkCount; }
	int getTotalCount() const { return totalCount + savCount + checkCount; }

	void displaySavingsAccount();
	void displayCheckingAccounts();

	void briefAccount();
	int getAggregatedBalance() const { return subAccountBalance; }

	void modifyAccount();
	void closeSubAccount();
};

		