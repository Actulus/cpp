//
// Created by Pati on 11/24/2022.
//

#include "Account.h"

int Account::counter{1};

Account::Account(double balance) {
	this->balance = balance;
	this->id = counter;
	Account::counter++;
}
void Account::deposit(double amount) {
	if (amount > 0) {
		this->balance += amount;
	}
}
bool Account::withdraw(double amount) {
	if (this->balance > 0 && this->balance >= amount) {
		balance -= amount;
		return true;
	} else {
		cout << "\n\nCannot wihtdraw the amount: " << amount << endl;
		return false;
	}
}
int Account::getId() const {
	return this->id;
}
double Account::getBalance() const {
	return this->balance;
}
void Account::print(ostream &os) const {
	os << "Account ID: " << this->getId() << " balance: " << this->balance;
}
ostream &operator<<(ostream &os, const Account &account) {
	account.print(os);
	return os;
}
