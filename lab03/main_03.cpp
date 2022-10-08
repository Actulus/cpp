#include "List.h"

int main() {
	List *list = new List();
	list->insertFirst(4);
	list->insertFirst(2);
	list->insertFirst(7);
	list->insertFirst(1);

	list->print();

	/*try {
		list->removeFirst();
		list->removeFirst();
		list->removeFirst();
		list->removeFirst();
		list->removeFirst();
	} catch(std::invalid_argument &error){
		std::cout << error.what();
	}*/

	/*list->remove(2, List::DeleteFlag::EQUAL);
	list->print();*/
	/*list->remove(2, List::DeleteFlag::LESS);
	list->print();*/
	list->remove(1, List::DeleteFlag::EQUAL);
	list->print();


	return 0;
}
