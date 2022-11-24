//
// Created by Pati on 11/24/2022.
//

#include "Bank.h"

Bank::Bank(const string &name) {
	this->name = name;
}
int Bank::newCustomer(const string &firstName, const string &lastName) {
	auto *newCustomer = new Customer(firstName, lastName);
	customers.push_back(*newCustomer);
	return newCustomer->getId();
}
bool Bank::deleteCustomer(int id) {
	try {
		auto new_end = std::remove_if(customers.begin(), customers.end(), [&id](const Customer &customer) {
			return customer.getId() == id;
		});
		customers.erase(new_end, customers.end());
		return true;
	}
	catch (exception &exception) {
		cout << exception.what();
		return false;
	}
}
Customer &Bank::getCustomer(int id) {
	auto it = std::find_if(customers.begin(), customers.end(), [&id](const Customer &customer) {
		return customer.getId() == id;
	});
	return *it;
}
void Bank::printCustomers(ostream &os) const {
	cout << "\nAll customers\n";
	std::for_each(customers.begin(), customers.end(), [&os](const Customer &customer) {
		os << customer.getFirstName() << " " << customer.getLastName();
		cout << endl;
	});
	cout << endl;
}
void Bank::printCustomersAndAccounts(ostream &os) const {
	cout << "\nAll customers and their accounts\n";
	std::for_each(customers.begin(), customers.end(), [&os](const Customer &customer) {
		customer.print(os);
	});
	cout << endl;
}
vector<int> Bank::loadCustomers(const string &filename) {
	vector<int> ids;
	std::for_each(customers.begin(), customers.end(), [&ids](const Customer &customer) {
		ids.push_back(customer.getId());
	});
	return ids;
}
