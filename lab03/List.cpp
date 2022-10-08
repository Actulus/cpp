//
// Created by Pati on 10/6/2022.
//

#include "List.h"

List::List() {
	this->first = nullptr;
}
List::~List() {
	Node *temp = first;
	while(temp) {
		temp = first->next;
		delete first;
		first = temp;
		nodeCounter--;
	}
	temp = nullptr;
	nodeCounter = 0;
}
bool List::exists(int d) const {
	Node *temp = first;
	while(temp){
		if(temp->value == d){
			return true;
		} else {
			temp = first->next;
		}
	}
	temp = nullptr;
	return false;
}
int List::size() const {
	return nodeCounter;
}
bool List::empty() const {
	return nodeCounter == 0;
}
void List::insertFirst(int d) {
	first = new Node(d, first);
	nodeCounter++;
}
int List::removeFirst() {
	if(this->empty()){
		throw std::invalid_argument("Empty list");
	}
	Node *temp = first;
	first = first->next;

	int tempValue = temp->value;
	delete temp;
	nodeCounter--;

	return tempValue;
}
void List::remove(int d, List::DeleteFlag df) {
	Node *temp = nullptr, *temp1 = first, *temp2 = temp1->next;
	while (temp1){
		temp2 = temp1->next;
		if(df == DeleteFlag::LESS){
			if(temp1->value < d){
				if(temp == nullptr){
					temp = temp1;
					delete temp;
					nodeCounter--;
					if(temp2 != nullptr && temp2->next != nullptr){
						temp1 = temp1->next;
						temp2 = temp2->next;
						temp = nullptr;
					}
				} else if (temp2 == nullptr){
					temp->next = nullptr;
					delete temp1;
					nodeCounter--;
					temp1 = nullptr;
				} else {
					temp->next = temp2;
					delete temp1;
					nodeCounter--;
					temp1 = temp2;
					temp2 = temp2->next;
				}
			}
			temp = temp1;
			if(temp1){
				temp1 = temp1->next;
				if(temp2) {
					temp2 = temp2->next;
				}
			}

		} else if(df == DeleteFlag::EQUAL){
			if(temp1->value == d){
				if(temp == nullptr){
					delete temp1;
					nodeCounter--;
					if(temp2 != nullptr && temp2->next != nullptr){
						temp1 = temp2;
						temp2 = temp2->next;
						temp = nullptr;
					}
				} else if (temp2 == nullptr){
					temp->next = nullptr;
					delete temp1;
					nodeCounter--;
					temp1 = nullptr;
				} else {
					temp->next = temp2;
					delete temp1;
					nodeCounter--;
					temp1 = temp2;
					temp2 = temp2->next;
				}
			}
			temp = temp1;
			if(temp1){
				temp1 = temp1->next;
				if(temp2) {
					temp2 = temp2->next;
				}
			}
		} else if(df == DeleteFlag::GREATER){
			if(temp1->value > d){
				if(temp == nullptr){
					temp = temp1;
					delete temp;
					nodeCounter--;
					if(temp2 != nullptr && temp2->next != nullptr){
						temp1 = temp1->next;
						temp2 = temp2->next;
						temp = nullptr;
					}
				} else if (temp2 == nullptr){
					temp->next = nullptr;
					delete temp1;
					nodeCounter--;
					temp1 = nullptr;
				} else {
					temp->next = temp2;
					delete temp1;
					nodeCounter--;
					temp1 = temp2;
					temp2 = temp2->next;
				}
			}
			temp = temp1;
			if(temp1){
				temp1 = temp1->next;
				if(temp2) {
					temp2 = temp2->next;
				}
			}
		}
	}
}
void List::print() const {
	Node* tempNode = first;
	while(tempNode){
		std::cout << tempNode->value << " ";
		tempNode = tempNode->next;
	}
	tempNode = nullptr;
	std::cout << std::endl;
}
