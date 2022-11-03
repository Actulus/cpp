#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include "Item.h"
#include <ostream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Shopping_list {
public:
	Shopping_list(int capacity = 7);
	Shopping_list(const Shopping_list &what);
	Shopping_list(Shopping_list &&what) noexcept;
	~Shopping_list();

	int getCount() const;

	void addNewItem(Item item);
	void sortByCategory();
	void printCategoryItems(Item::Category category);
	void increaseCapacityBy(int value);

	Item operator[](int index);
	const Item operator[](int index) const;

	Shopping_list &operator=(const Shopping_list &what);
	Shopping_list &operator=(Shopping_list &&what);

	friend Shopping_list operator+(const Shopping_list &list1, const Shopping_list &list2);
	friend ostream &operator<<(ostream &os, const Shopping_list &list);

private:
	int capacity;
	Item *list;
	int count;
};

#endif // SHOPPING_LIST_H
