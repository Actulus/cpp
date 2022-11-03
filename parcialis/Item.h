#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <ostream>
#include <iostream>
#include <iomanip>

using namespace std;

class Item {
public:
	enum class Category {
		FRUIT, BAKERY, DAIRY, MEAT, BEVERAGE
	};

	Item(const string &name, int quantity, Category category);
	Item();

	const string &getName() const;
	int getQuantity() const;
	Item::Category getCategory() const;
	string getCategoryAsString() const;
	void setQuantity(int value);

	friend ostream &operator<<(ostream &os, const Item &item);

private:
	string name;
	int quantity;
	Category category;
};

#endif // ITEM_H
