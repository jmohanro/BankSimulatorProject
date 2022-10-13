#include <iostream>
#include "bank.h"
#include "bAccount.h"
#include "subAccount.h"
#include "windows.h"
using namespace std;

	
bAccount controller;													// controller object allowing us to access certain functions withing bAccount
sAccount subController;

int bank::bankCount = 0;


void bank::promptBankInfo() {											// gets bank info from User and sets variables

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter the name of the bank: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	getline(cin, name);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter the address of the bank: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	getline(cin, address);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter the business hours of the bank: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	getline(cin, hours);
	cout << endl;

	setBankInfo(name, address, hours);
	displayMenu();
}

void bank::setBankInfo(string name, string address, string hours) {		// sets bank information
	this->name = name;
	this->address = address;
	this->hours = hours;
}


void bank::displayMenu() {											// displays bank menu options to user
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	char choice;
	cout << "Eligible services for " << getBankName() << endl;
	cout << "    A -- View number of Bank Accounts" << endl << "    B -- View number of Savings Accounts" << endl << "    C -- View number of Checking Accounts" << endl <<
		"    D -- Open a Bank Account" << endl << "    E -- Close Bank Account" << endl << "    F -- Modify Bank Account" << endl << "    G -- Detailed Bank Accounts" << endl <<
		"    H -- Brief Bank Accounts sorted on aggregated balances" << endl << "    Q -- Quit Program" << endl;
	cout << "Please enter your selection: ";

	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> choice;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		if (choice == 'a' || choice == 'A') {						// if-else control statements to determine which function to call based on menu selection
			getBankCount();											// accesses function to retrieve count of banks
		}
		else if (choice == 'b' || choice == 'B') {
			subController.getSavCount();							// accesses funtion to retrieve count of savings accounts
		}
		else if (choice == 'c' || choice == 'C') {
			subController.getCheckCount();							// accesses function to retrieve count of checking accounts
		}
		else if (choice == 'd' || choice == 'D') {
			controller.createBankAccount();							// uses controller to access function in bAccount to create a bank account
			bankCount++;											// increments bank account by 1 every time function is invoked	
		}
		else if (choice == 'e' || choice == 'E') {
			controller.closeAccount();								// uses controller to access function in bAccount to close a specific bank account number
		}
		else if (choice == 'f' || choice == 'F') {
			controller.modifyAccount();								// accesses function to modify information in a specific bank account
		}
		else if (choice == 'g' || choice == 'G') {
			controller.detailedAccounts();							// displays all different accounts
			cout << endl;
		}
		else if (choice == 'h' || choice == 'H') {
			controller.briefAccouts();						 
			cout << endl;											// displays all different accounts and balances
		}
	} while (choice != 'q' && choice != 'Q');						// do - while statement to keep main menu looping until user enters 'Q'
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "Thank you for using our system" << endl;
	system("pause");
}