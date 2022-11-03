//
// Created by Pati on 11/3/2022.
//

#include "Shopping_list.h"

Shopping_list::Shopping_list(int capacity) {
	this->capacity = capacity;
	this->list = new Item[this->capacity];
	for (int i = 0; i < this->capacity; ++i) {
		this->list[i] = Item();
	}
	this->count = 0;
}
Shopping_list::Shopping_list(const Shopping_list &what) {
	this->capacity = what.capacity;
	this->list = new Item[this->capacity];
	this->count = what.count;
	for (int i = 0; i < this->count; ++i) {
		this->list[i] = what.list[i];
//		count++;
	}
}
Shopping_list::Shopping_list(Shopping_list &&what) noexcept {
	delete[]this->list;
	this->capacity = 0;
	this->count = 0;

	this->capacity = what.capacity;
	this->count = what.count;
	this->list = what.list;

	what.list = nullptr;
	what.capacity = 0;
	what.count = 0;
}
Shopping_list::~Shopping_list() {
	if (this->list != nullptr) {
		this->capacity = 0;
		this->count = 0;
		delete[]this->list;
		this->list = nullptr;
	}
}
int Shopping_list::getCount() const {
	return this->count;
}
void Shopping_list::addNewItem(Item item) {
	if (this->count == this->capacity) {
		throw out_of_range("Nincs eleg hely");
	}

	bool flag = false; //nincs benne
	for (int i = 0; i < this->count; ++i) {
		if (list[i].getName() == item.getName()) {
			flag = true;
		}
	}

	if (flag) {
		for (int i = 0; i < count; ++i) {
			if (list[i].getName() == item.getName()) {
				int temp = list[i].getQuantity() + item.getQuantity();
				list[i].setQuantity(temp);
			}
		}
	} else {
//		cout << count;
		list[count] = item;
//		list[count] = Item(item.getName(), item.getQuantity(), item.getCategory());
		count++;

	}
}

void Shopping_list::sortByCategory() {
	Item temp;
	for (int i = 0; i < capacity; ++i) {
		for (int j = 0; j < capacity - 1; ++j) {
			if (list[i].getCategory() < list[j].getCategory()) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}
void Shopping_list::printCategoryItems(Item::Category category) {
	for (int i = 0; i < capacity; ++i) {
		if (list[i].getCategory() == category) {
			cout << list[i] << "\n";
		}
	}
}
void Shopping_list::increaseCapacityBy(int value) {
	this->capacity = this->capacity + value;
}
Item Shopping_list::operator[](int index) {
	return list[index];
}
const Item Shopping_list::operator[](int index) const {
	return list[index];
}
Shopping_list &Shopping_list::operator=(const Shopping_list &what) {
/*
	delete[] this->list;
	this->list = nullptr;
*/

	this->capacity = what.capacity;
	this->count = what.count;
	this->list = new Item[this->capacity];
	for (int i = 0; i < this->count; ++i) {
		this->list[i] = what.list[i];
	}
	return *this;
}
Shopping_list &Shopping_list::operator=(Shopping_list &&what) {
	delete[] this->list;
	this->list = nullptr;

	this->capacity = what.capacity;
	this->count = what.count;
	this->list = what.list;

	what.list = nullptr;

	return *this;
}
Shopping_list operator+(const Shopping_list &list1, const Shopping_list &list2) {
	auto *temp = new Shopping_list();
	temp->capacity = list1.capacity + list2.capacity;
	temp->list = new Item[temp->capacity];
	temp->count = 0;

	for (int i = 0; i < list1.count; ++i) {
		temp->list[temp->count] = list1.list[i];
		temp->count++;
	}

	for (int i = 0; i < temp->count; ++i) {
		for (int k = 0; k < list2.count; ++k) {
			if (temp->list[i].getName() == list2.list[k].getName()) {
				int nr = temp->list[i].getQuantity() + list2.list[k].getQuantity();
				temp->list[i].setQuantity(nr);
			} else {
				temp->list[temp->count] = list2.list[k];
				temp->count++;
			}
		}
	}

	return *temp;
}
ostream &operator<<(ostream &os, const Shopping_list &list) {
	for (int i = 0; i < list.capacity; ++i) {
		os << list[i];
	}
	os << endl;
	return os;
}