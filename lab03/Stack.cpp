//
// Created by Pati on 10/13/2022.
//

#include "Stack.h"

Stack::Stack() {
	list = new List();
}

Stack::~Stack() {
	delete list;
}

void Stack::push(int e) {
	list->insertFirst(e);
}

int Stack::pop() {
	int popped;
	if (isEmpty()) {
		throw runtime_error("Stack is empty!");
	}

	try {
		popped = list->removeFirst();
	} catch (runtime_error &error) {
		cout << error.what();
		exit(-1);
	}
	return popped;
}
bool Stack::isEmpty() const {
	return list->empty();
}
void Stack::display() {
	list->print();
}
