//
// Created by Pati on 11/3/2022.
//

#include "Item.h"

Item::Item(const string &name, int quantity, Item::Category category) {
	this->name = name;
	this->quantity = quantity;
	this->category = category;
}

const string &Item::getName() const {
	return this->name;
}
int Item::getQuantity() const {
	return this->quantity;
}
Item::Category Item::getCategory() const {
	return this->category;
}
string Item::getCategoryAsString() const {
	switch (this->getCategory()) {
		case Category::FRUIT:
			return "Fruit";
		case Category::BAKERY:
			return "Bakery";
		case Category::DAIRY:
			return "Dairy";
		case Category::MEAT:
			return "Meat";
		case Category::BEVERAGE:
			return "Beverage";
		default:
			break;
	}
}
ostream &operator<<(ostream &os, const Item &item) {
	os << "\t" << item.name << "| quantity: " << item.quantity << " | category: " << item.getCategoryAsString() << endl;
	return os;
}
Item::Item() {
	this->quantity = 1;
	this->name = " ";
	this->category = Category::BAKERY;
}
void Item::setQuantity(int value) {
	this->quantity = value;
}
