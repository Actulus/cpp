//
// Created by Pati on 10/13/2022.
//

#include "Stack.h"

Stack::Stack() {
	this->top = nullptr;
}
Stack::~Stack() {
}
void Stack::push(int e) {
	Node *temp = new Node();
	if(!temp){
		throw std::invalid_argument("Stack owerflow");
	}

	temp->data = e;
	temp->link = top;
	top = temp;
	//list->insertFirst(e);
}
int Stack::pop() {
	Node *temp;

	if(isEmpty()){
		throw std::invalid_argument("Stack underflow");
	} else {
		temp = top;
		top = top->link;
		free(temp);
		//list->remove(top->data, List::DeleteFlag::EQUAL);
	}

	return 0;
}
bool Stack::isEmpty() const {
	return top == nullptr;
}
void Stack::display() {
	Node *temp;

	if(top == nullptr) {
		throw std::invalid_argument("Stack underflow");
	} else {
		temp = top;
		while (temp != nullptr){
			std::cout << temp->data;
			temp = temp->link;
			if(temp != nullptr){
				std::cout << " -> ";
			}
		}
		std::cout << std::endl;
	}
}
