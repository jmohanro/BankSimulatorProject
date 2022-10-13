#include "subAccount.h"
#include "bAccount.h"
#include "windows.h"
#include <algorithm>
#include <vector>

bAccount menuController;																							// controller object allowing us to access functions of bAccount

int sAccount::savCount = 0;																							// static variable initilization for counting how many savings accounts were created
int sAccount::checkCount = 0;
int sAccount::totalCount = 0;

void sAccount::getSavInfo() {																							// gets vital info from user on Savings creation, and stores retrievable info in a vector of pairs
	int userBalance;																								// temp variable on user input balance
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter the initial balance: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> userBalance;
	cout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "    | A new Savings Sub-Account SAV" << sAccNum << " was successfully created." << endl << endl;
	savInfo.push_back(make_pair(sAccNum, userBalance));																// vector of pairs to store sav account info
	setSavInfo(sAccNum, userBalance);																				// sets values individually
	savCount++;																										// adds one account to the total number of savings accounts;
	menuController.displayBankMenu(menuController.getAccNum());														// returns to bank menu upon account creation
	
}

void sAccount::getCheckInfo() {
	char state;																										// sets the state of the account (locked or unlocked)
	int initBalance, mBalance;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter initial Balance: ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> initBalance;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Enter maximum balance capacity of this account: ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> mBalance;
		
	if (mBalance < initBalance) {																					// checks to see if user entered a valid value for their maximum balance
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Error, Maximum balance must be greater than your initial balance, please enter a higher Maximum balance: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> mBalance;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Define initial state: ('L' for locked, otherwise 'U for unlocked): ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> state;
	cout << endl;
	
	if (state == 'l' || state == 'L') {																				// if statement to vary account information output
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "    | A new locked Checking Sub-Account CHK" << cAccNum << " was successfully created." << endl << endl;
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "    | A new unlocked Checking Sub-Account CHK" << cAccNum << " was successfully created." << endl << endl;
	}
	

	checkInfo.push_back(make_pair(cAccNum, initBalance));															// pushes back information into a vector pair for this function call index
	setCheckInfo(cAccNum, initBalance, mBalance, state);															// sets individual values
	checkCount++;																									// adds one account to the total number of checking accounts
	menuController.displayBankMenu(menuController.getAccNum());

}
	
void sAccount::setCheckInfo(int cAccNum, int balance, int maxBalance, char lock) {									// sets information of checking account in this specific index
	this->cAccNum = cAccNum + 1000;
	cAccNum += 1000;
	cBalance = balance;
	cMaxBalance = maxBalance;
	this->lock = lock;
	subAccountBalance += cBalance;																					// adds balance to aggregated balance variable
}


void sAccount::setSavInfo(int accNum, int balance) {																// sets values of savings account individually
	this->sAccNum = accNum + 1000;
	accNum += 1000;																									// adds 10000 to every additional bank account number to give new unique numnber
	sBalance = balance;
	subAccountBalance += sBalance;																					// adds balance to aggregated balance variable
}

void sAccount::displaySavingsAccount() {																			// displays all savings accounts that were created
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "Savings Accounts that were created:" << endl << endl;

	for (int i = 0; i < savInfo.size(); i++) {																		// Displays the account number and balance of specific savings accounts
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "    | Savings Account Number:" << " SAV" << savInfo[i].first << endl << "    | Balance: " << "$" << savInfo[i].second << endl << endl;						
	}
}

void sAccount::displayCheckingAccounts() {																			// Displays the account number and balance of specific checking accounts
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "Checking Accounts that were created: " << endl << endl;

	for (int i = 0; i < checkInfo.size(); i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "    | Checking Account Number:" << " CHK" << checkInfo[i].first << endl << "    | Balance: " << "$" << checkInfo[i].second << endl << endl;
	}
}

void sAccount::modifyAccount() {																					// Allows user to withdraw or deposit into sav or check accounts
	char userSelection, accSelection;
	int accNumber, balance;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Which account would you like to modify? ((S)avings or (C)hecking: ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> accSelection;
	cout << endl;

	if (accSelection == 'S' || 's') {																				// controls which sub-account to modify
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter the number of the Account (X000): ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> accNumber;

		for (int i = 0; i < savInfo.size(); i++) {																	// finds the account number entered by user
			if (savInfo[i].first == accNumber) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "What would you like to do with this account: ((W)ithraw or (D)eposit): ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cin >> userSelection;
				cout << endl;

				if (userSelection == 'w' || userSelection == 'W') {													// allows withdrawing of money from account
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "How much would you like to withrdraw? ";

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cin >> balance;

					sBalance -= balance;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << endl << "    | Your new balance in SAV" << savInfo[i].first << " is $" << sBalance << endl;
				}
				else if (userSelection == 'd' || userSelection == 'D') {											// allows depostiting into sub account
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "How much would you like to deposit? ";

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cin >> balance;
					sBalance += balance;

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << endl << "    | Your new balance in SAV" << savInfo[i].first << " is $" << sBalance << endl;
 				}
			}
		}

	}
	else if (accSelection == 'C' || accSelection == 'c') {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter the number of the Account (X000): ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> accNumber;

		for (int i = 0; i < checkInfo.size(); i++) {
			if (checkInfo[i].first == accNumber) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "What would you like to do with this account: ((W)ithraw or (D)eposit): ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cin >> userSelection;

				cout << endl << endl;
				if (userSelection == 'w' || userSelection == 'W') {													// allows withdrawing of money from account
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "How much would you like to withrdraw? ";

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cin >> balance;

					cBalance -= balance;

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "    | Your new balance in CHK" << checkInfo[i].first << " is $" << cBalance << endl << endl;
				}
				else if (userSelection == 'd' || userSelection == 'D') {											// allows depostiting into sub account
					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "How much would you like to deposit? ";

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cin >> balance;
					cBalance += balance;

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "    | Your new balance in CHK" << checkInfo[i].first << " is $" << cBalance << endl << endl;
				}
			}
		}
	}
	
}

void sAccount::briefAccount() {																						// displays aggregated balances of sub accounts, as well as how many subaccounts were created
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "    | Aggregated balance of the bank account BKN" << menuController.getAccNum() << " with " << getTotalCount() << " sub accounts is: $" << getAggregatedBalance() << endl;
	menuController.displayBankMenu(menuController.getAccNum());
}

void sAccount::closeSubAccount() {																					// navigates to account user wants to close, and deletes it from the savInfo vector

	char selection;
	int number;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "What type of Sub-Account would you like to close ((S)avings or (C)hecking): ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin >> selection;
	cout << endl << endl;

	if (selection == 's' || selection == 'S') {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter the Sub Account SAV Number you want to close (X000): ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> number;

		for (int i = 0; i < savInfo.size(); i++) {
			if (savInfo[i].first == number) {
				savInfo.erase(savInfo.begin() + i);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "    | Savings Sub Account SAV" << number << " was successfully closed. Your new total account balance is: $" << getAggregatedBalance() - savInfo[i].second << endl;
			}
		}
	}
	else if (selection == 'c' || selection == 'C') {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter the Sub Account CHK Number you want to close (X000): ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> number;

		for (int i = 0; i < checkInfo.size(); i++) {
			if (checkInfo[i].first == number) {
				checkInfo.erase(checkInfo.begin() + i);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "    | Saving Sub Account CHK" << number << " was successfully closed. Your new total account balance is : $" << getAggregatedBalance() - checkInfo[i].second << endl;
			}
		}
	}
	menuController.displayBankMenu(number);
}