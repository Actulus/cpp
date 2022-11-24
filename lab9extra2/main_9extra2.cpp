#include "Account.h"
#include "Customer.h"
#include "Bank.h"
#include <fstream>
#include <random>

void ex1();
void ex2();
void ex3();

int main() {
	//ex1();
	//ex2();
	ex3();
	return 0;
}

void ex1() {
	Account *account1 = new Account(0);
	account1->print(cout);

	account1->deposit(1000);
	account1->print(cout);

	account1->withdraw(500);
	account1->print(cout);

	account1->withdraw(1000);
	account1->print(cout);
}

void ex2() {
	Customer *customer1 = new Customer("Joe", "Smith");
	customer1->newAccount(0);
	customer1->newAccount(1000);
	cout << *customer1;
	customer1->deleteAccount(1);
	cout << *customer1;
}

void ex3() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> nrs(100, 2000);

	ifstream fin;
	fin.open("customers.txt");
	if (fin.fail()) {
		throw runtime_error("Could not open file");
	}

	Bank *bank = new Bank("BCR");
	string fname, lname;
	int nrCustomers = 0;
	while (fin.good()) {
		fin >> fname >> lname;
		nrCustomers++;
		bank->newCustomer(fname, lname);
	}

	bank->printCustomers(cout);

	for (auto account = 0; account <= 2; ++account) {
		auto check1 = nrs(mt);
		auto check2 = nrs(mt);
		auto check3 = nrs(mt);
		bank->getCustomer(1).newAccount(check1);
		bank->getCustomer(2).newAccount(check2);
		bank->getCustomer(3).newAccount(check3);
	}

	bank->printCustomersAndAccounts(cout);

	bank->getCustomer(1)[0].deposit(500);
	bank->getCustomer(1)[1].withdraw(500);

	bank->printCustomersAndAccounts(cout);
}