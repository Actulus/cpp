//
// Created by Pati on 11/24/2022.
//

#include "Customer.h"

int Customer::counter{1};

Customer::Customer(const string &firstName, const string &lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->id = counter;
	Customer::counter++;
	//accounts.emplace_back(newAccount(0));
}
const string &Customer::getFirstName() const {
	return this->firstName;
}
void Customer::setFirstName(const string &firstName) {
	this->firstName = firstName;
}
const string &Customer::getLastName() const {
	return this->lastName;
}
void Customer::setLastName(const string &lastName) {
	this->lastName = lastName;
}
Account &Customer::getAccount(int id) {
	std::for_each(accounts.begin(), accounts.end(), [&id](const Account &account) {
		if (account.getId() == id) {
			return account;
		}
	});
}
int Customer::newAccount(double balance) {
	if (balance < 0) {
		cout << "Cannot open new account with negative balance";
		exit(-1);
	}
	Account *newAcc = new Account(balance);
	this->accounts.push_back(*newAcc);
	return newAcc->getId();
}
bool Customer::deleteAccount(int id) {
	try {
		auto new_end = std::remove_if(accounts.begin(), accounts.end(), [&id](const Account &account) {
			return account.getId() == id;
		});
		//erase deletes it from the end
		accounts.erase(new_end, accounts.end());
		return true;
	}
	catch (exception &exception) {
		cout << exception.what();
		return false;
	}
}
int Customer::getNumAccounts() const {
	return accounts.size();
}
void Customer::print(ostream &os) const {
	os << endl << this->getId() << " " << this->getFirstName() << " " << this->getLastName();
	std::for_each(accounts.begin(), accounts.end(), [&os](const Account &account) {
		os << "\n\t";
		account.print(os);
	});
	os << endl;
}
ostream &operator<<(ostream &os, const Customer &customer) {
	customer.print(os);
	return os;
}
Account &Customer::operator[](int index) {
	if (index < 0 || index > accounts.size()) {
		throw out_of_range("Index is not within 0 and accounts size");
	}
	return accounts[index];
}
const Account &Customer::operator[](int index) const {
	if (index < 0 || index > accounts.size()) {
		throw out_of_range("Index is not within 0 and accounts size");
	}
	return accounts[index];
}
