//
// Created by Pati on 11/3/2022.
//

#include <cstring>
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
	}
}
Shopping_list::Shopping_list(Shopping_list &&what) noexcept {
	delete[]this->list;
//	this->list->setQuantity(0);
	this->capacity = 0;
	this->count = 0;

	this->capacity = what.capacity;
//	this->list->setQuantity(what.list->getQuantity());
	this->count = what.count;
	this->list = what.list;

	delete[]what.list;
	what.list = nullptr;
	what.capacity = 0;
	what.count = 0;
}
Shopping_list::~Shopping_list() {
	if (this->list != nullptr) {
		this->capacity = 0;
//		this->list->setQuantity(0);
		this->count = 0;
//		delete[]this->list;
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
		//cout << getCount();
//		cout << count;
//		list[count] = item;
		list[count] = Item(item.getName(), item.getQuantity(), item.getCategory());
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
	for (int i = 0; i < count; ++i) {
		if (list[i].getCategory() == category) {
			cout << list[i] << "\n";
		}
	}
}
void Shopping_list::increaseCapacityBy(int value) {
	int oldcap = this->capacity;
	this->capacity = this->capacity + value;
	Item *newList = new Item[this->capacity];
	memcpy(newList, this->list, oldcap * sizeof(Item));
	delete[] this->list;
	this->list = newList;
}
Item Shopping_list::operator[](int index) {
	return list[index];
}
const Item Shopping_list::operator[](int index) const {
	return this->list[index];
}
Shopping_list &Shopping_list::operator=(const Shopping_list &what) {
/*
	delete[] this->list;
	this->list = nullptr;
*/

	this->capacity = what.capacity;
//	this->list->setQuantity(what.list->getQuantity());
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
//	this->list->setQuantity(what.list->getQuantity());
	this->count = what.count;
	this->list = what.list;

	delete[]what.list;
	what.list = nullptr;

	return *this;
}
Shopping_list operator+(const Shopping_list &list1, const Shopping_list &list2) {
	Shopping_list temp(list1.capacity + list2.capacity);
/*
	temp->capacity = list1.capacity + list2.capacity;
	temp->list = new Item[temp->capacity];
	temp->count = 0;
*/

	for (int i = 0; i < list1.count; ++i) {
		temp.addNewItem(list1.list[i]);
		temp.count++;
	}


	for (int i = 0; i < temp.capacity; ++i) {
		for (int k = 0; k < list2.count; ++k) {
			if (temp.list[i].getName() == list2.list[k].getName()) {
				int nr = temp.list[i].getQuantity() + list2.list[k].getQuantity();
				temp.list[i].setQuantity(nr);
			} else {
//				temp->list[temp->count] = list2.list[k];
				temp.count++;
			}
		}
	}
	return temp;
}
ostream &operator<<(ostream &os, const Shopping_list &list) {
	for (int i = 0; i < list.count; ++i) {
		os << list[i] << endl;
	}
	os << endl;
	return os;
}