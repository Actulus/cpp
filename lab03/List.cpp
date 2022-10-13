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
	Node *previous = nullptr, *current = first, *following = current->next;
	while (current){
		if(df == DeleteFlag::LESS){
			if(current->value < d){
				if (previous == nullptr && following != nullptr){
					previous = current;
					current = following;
					following = current->next; //following->next
					delete previous;
					previous = nullptr;
				} else if(previous != nullptr && following != nullptr){
					previous->next = current->next;
					delete current;
					current = previous->next;
					current->next = following->next;
				} else if(previous != nullptr && following == nullptr){
					current->next = nullptr;
					previous->next = nullptr;
					delete current;
					current = nullptr;
				}
			} else {
				previous = current;
				current = current->next;
				following = current->next;
			}
		} else if(df == DeleteFlag::EQUAL) {
			if(current->value == d){
				if (previous == nullptr && following != nullptr){
					previous = current;
					current = following;
					following = current->next; //following->next
					delete previous;
					previous = nullptr;
				} else if(previous != nullptr && following != nullptr){
					previous->next = current->next;
					delete current;
					current = previous->next;
					current->next = following->next;
				} else if(previous != nullptr && following == nullptr){
					current->next = nullptr;
					previous->next = nullptr;
					delete current;
					current = nullptr;
				}
			} else {
				previous = current;
				current = current->next;
				following = current->next;
			}
		} else if(df == DeleteFlag::GREATER){
			if(current->value == d){
				if (previous == nullptr && following != nullptr){
					previous = current;
					current = following;
					following = current->next; //following->next
					delete previous;
					previous = nullptr;
				} else if(previous != nullptr && following != nullptr){
					previous->next = current->next;
					delete current;
					current = previous->next;
					current->next = following->next;
				} else if(previous != nullptr && following == nullptr){
					current->next = nullptr;
					previous->next = nullptr;
					delete current;
					current = nullptr;
				}
			} else {
				previous = current;
				current = current->next;
				following = current->next;
			}
		} else {
			std::cout << "Invalid flag!" << std::endl;
			exit(-1);
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
