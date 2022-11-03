#include <iostream>

using namespace std;

#include "Shopping_list.h"
#include "Item.h"


int main() {
	cout << endl << "########## Items          ######################" << endl << endl;

	Item a("Apple", 5, Item::Category::FRUIT);
	Item b("Bread", 8, Item::Category::BAKERY);
	Item c("Watermelon", 2, Item::Category::FRUIT);
	Item d("Cheese", 3, Item::Category::DAIRY);
	Item e("Tuna", 1, Item::Category::MEAT);
	Item f("Steak", 4, Item::Category::MEAT);
	Item g("Donut", 6, Item::Category::BAKERY);
	Item h("Cider", 2, Item::Category::BEVERAGE);
	Item i("Wine", 1, Item::Category::BEVERAGE);
	Item j("Water", 12, Item::Category::BEVERAGE);
	Item k("Soda", 3, Item::Category::BEVERAGE);
	Item l("Butter", 1, Item::Category::DAIRY);
	Item m("Yogurt", 5, Item::Category::DAIRY);

	cout << "An item named " << a.getName() << " is needed in " << a.getQuantity()
	     << " quantities and has the category of " << a.getCategoryAsString() << "." << endl;
	cout << "An item named " << b.getName() << " is needed in " << b.getQuantity()
	     << " quantities and has the category of " << b.getCategoryAsString() << "." << endl;
	cout << endl << "In table format:" << endl;
	cout << a << b << endl;

	cout << endl << "########## Shopping Lists ######################" << endl << endl;
	Shopping_list list(5);

	list.addNewItem(a);
	list.addNewItem(b);
	list.addNewItem(c);
	list.addNewItem(d);
	list.addNewItem(e);

	try {
		list.addNewItem(f);
	}
	catch (out_of_range &e) {
		cout << e.what() << endl;
	}

	cout << "Original list #1:" << endl;
	cout << list;
	cout << endl << "List #1 sorted by categories:" << endl;
	list.sortByCategory();
	cout << list;

	cout << "List #2 is a copy of list #1." << endl;
	Shopping_list list2(list);
	cout << list2;
	cout << "Increasing capacity by 10 and adding new items:" << endl;
	list2.increaseCapacityBy(10);

	list2.addNewItem(g);
	list2.addNewItem(h);
	list2.addNewItem(i);
	list2.addNewItem(j);
	list2.addNewItem(k);
	list2.addNewItem(l);
	list2.addNewItem(m);

	cout << list2;
	cout << "List #2 has " << list2.getCount() << " elements." << endl;

	cout << endl << "Printing only dairy products from List #2:" << endl;
	list2.printCategoryItems(Item::Category::DAIRY);

	cout << endl << "Printing the third item's category on List #2: " << endl;
	cout << std::setw(10) << list2[2].getCategoryAsString() << endl;

	cout << endl << "Shopping list #3 is a merge of List #1 and List #2:" << endl;
	Shopping_list list3;
	list3 = list2 + list;
	cout << list3;

	cout << endl << "###############################################" << endl;
	return 0;
}
