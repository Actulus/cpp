//
// Created by Pati on 11/24/2022.
//

#ifndef LAB9EXTRA2_ACCOUNT_H
#define LAB9EXTRA2_ACCOUNT_H

#include <iostream>

using namespace std;

class Account {
public:
	Account(double balance = 0);
	void deposit(double amount);
	bool withdraw(double amount);
	int getId() const;
	double getBalance() const;
	void print(ostream &os) const;
	friend ostream &operator<<(ostream &os, const Account &account);
private:
	static int counter;
	int id; //generated field
	double balance;
};

#endif //LAB9EXTRA2_ACCOUNT_H
