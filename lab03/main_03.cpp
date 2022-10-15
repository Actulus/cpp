#include "Stack.h"

int main() {
	/*std::cout << "----LIST----\n";
	List *list = new List();
	list->insertFirst(4);
	list->insertFirst(2);
	list->insertFirst(7);
	list->insertFirst(1);

	list->print();

	try {
		list->removeFirst();
		list->print();
		list->removeFirst();
		list->print();
		list->removeFirst();
		list->print();
		list->removeFirst();
		list->print();
		list->removeFirst();
	} catch (std::invalid_argument &error) {
		std::cout << error.what();
	}*/

	/*list->remove(2, List::DeleteFlag::EQUAL);
	list->print();*/
	/*list->remove(1, List::DeleteFlag::LESS);
	list->print();*/
	/*list->remove(4, List::DeleteFlag::GREATER);
	list->print();*/


	//----------------STACK---------------
	std::cout << "\n----STACK: Read from rigth to left----\n";
	Stack *stack = new Stack();
	stack->push(5);
	stack->push(2);
	stack->push(7);
	stack->push(1);

	stack->display();

	try {
		stack->pop();
		stack->display();
		stack->pop();
		stack->display();
		stack->pop();
		stack->display();
		stack->pop();
		stack->display();
	} catch (std::invalid_argument &error) {
		std::cout << error.what();
	}

	return 0;
}
