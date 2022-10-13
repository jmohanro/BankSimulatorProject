#include <iostream>
#include <algorithm>
#include "bAccount.h"
#include "bank.h"
#include "subAccount.h"
#include "windows.h"
	
bank controller;
sAccount sController;


void bAccount::createBankAccount() {												// Creates bank account and stores retrievable information in a vector, as well as individually initializes variables
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter the first name of the account holder: ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> fName;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter the last name of the account holder: ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> lName;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter SSN of account holder: ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> ssn;
	cout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "    | A new bank account BKN" << accNum << " has been created." << endl << endl;
	bankAccount.push_back(make_pair(fName, accNum));
	setBankInfo(fName, accNum);
	displayBankMenu(accNum);											     		// displays bank account menu following creation of account
}

void bAccount::setBankInfo(string fName, int accNum) {								// sets bank info individually
	this->fName = fName;
	this->accNum = accNum;
}

void bAccount::displayBankMenu(int accNumber) {										// displays menu of options within bank account following its creation
	char choice;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Eligible Services for Bank Account BKN" << accNumber << endl;
	cout << "    A -- Open Savings Sub-Account" << endl << "    B -- Open Checking Sub-Account" << endl << "    C -- Modify Sub-Account" << endl << "    D -- Close Sub-Account" << endl <<
		"    E -- Detailed Bank Info sorted on Sub-Account Balances" << endl << "    F -- Brief Bank Info" << endl << "    Q -- Return to Main Menu" << endl;
	cout << "Please enter your selection: ";
	
	cin >> choice;
	
	if (choice == 'a' || choice == 'A') {											// if-else control statements to determine which function to call based on menu selection
		sController.getSavInfo();													// controller allowing access to savings.h function that will create the first sub account
	}
	else if (choice == 'b' || choice == 'B') {
		sController.getCheckInfo();													// accesses function to open a checking account
	}
	else if (choice == 'c' || choice == 'C'){
		sController.modifyAccount();												// accesses function to modify any sub account
	}
	else if (choice == 'd' || choice == 'D') {
		sController.closeSubAccount();												// accesses function that will close any specific sub account
	}
	else if (choice == 'e' || choice == 'E') {
		sController.displaySavingsAccount();										// displays all sub accounts with their account number and balance
		cout << endl;
		sController.displayCheckingAccounts();
		displayBankMenu(accNumber);
	}
	else if (choice == 'f' || choice == 'F') {
		sController.briefAccount();													// briefs aggregated balances of various subaccounts in the bank account
	}
	else if (choice == 'q' || choice == 'Q') {
		controller.displayMenu();													// quit case that will take user back to main menu 
	}

}



void bAccount::closeAccount() {														// Function to find bank account that user wants to delete

	int userNum;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "What is the Bank Number you would like to close (x000): ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> userNum;
	cout << endl;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << endl << "Ok, Searching for BKN" << userNum << endl;

	searchVec(userNum);
	if (true) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "Account found, successfully deleted BKN" << userNum << endl << endl;
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Cannot find account." << endl;
	}
	controller.displayMenu();
}

bool bAccount::searchVec(int num) {													// Function that searches for Bank Number that user enters

	for (auto& e : bankAccount) {
		if (e.second == num) {
			return true;
		}
		else {
			return false;
		}
	}
}

void bAccount::modifyAccount() {													// sets menu to specific bank account 
	int accNumber;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter the BKN number you want to modify (X000): ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> accNumber;
	cout << endl;

	displayBankMenu(accNumber);
}

void bAccount::briefAccouts() {													// provides information on all bank assets

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "    | Bank Name: " << controller.getBankName() << endl <<
		"    | Bank Address: " << controller.getAddress() << endl <<
		"    | Bank Working Hours: " << controller.getHours() << endl <<
		"    | Aggregated Balance: $" << sController.getAggregatedBalance() << endl <<
		"    | Consists of " << controller.getBankCount() << " bank accounts" << endl;

	controller.displayMenu();
}

void bAccount::detailedAccounts() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "    | Bank Name: " << controller.getBankName() << endl <<
		"    | Bank Address: " << controller.getAddress() << endl <<
		"    | Bank Working Hours: " << controller.getHours() << endl <<
		"    | Aggregated Balance: $" << sController.getAggregatedBalance() << endl <<
		"    | Consists of " << controller.getBankCount() << " bank accounts" << endl << endl;

	for (int i = 0; i < bankAccount.size(); i++) {													// Gets information of Bank accounts
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "    | Bank Account Number: BKN" << bankAccount[i].second << endl <<
			"    | Account Holder Full Name: " << bankAccount[i].first << lName << endl <<
			"    | Account Holder SSN: " << ssn << endl <<
			"    | Aggregated Balance: $" << sController.getAggregatedBalance() << endl <<
			"    | Consists of " << sController.getTotalCount() << " Sub-Accounts" << endl;
			
		for (int j = 0; j < savInfo.size(); j++) {													// gets information of savings sub accounts within the index of bank account
			cout << "    | Sub-Account Number: SAV" << savInfo[j].first << endl << endl <<
				"    | Balance: " << savInfo[j].second << endl << endl;
			}

		for (int l = 0; l < checkInfo.size(); l++) {												// gets information of checking sub account withing the index of bank account
			cout << "    | Sub-Account Number: CHK" << checkInfo[l].first << endl << endl <<
				"    | Balance: " << checkInfo[l].second << endl << endl;
		}
	}

}