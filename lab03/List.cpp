//
// Created by Pati on 10/6/2022.
//

#include "List.h"

List::List() {
	this->first = nullptr;
}
List::~List() {
	Node *temp = first;
	while (temp) {
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
	while (temp) {
		if (temp->value == d) {
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
	if (this->empty()) {
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
	if (empty()) {
		return;
	}
	Node *temp = first;
	Node *prev = nullptr;
	if (df == List::DeleteFlag::EQUAL) {
		if (temp != nullptr && temp->value == d) {
			first = temp->next;
			delete temp;
			return;
		}
		while (temp != nullptr && temp->value != d) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == nullptr) {
			return;
		}

		prev->next = temp->next;
		delete temp;
	} else if (df == List::DeleteFlag::LESS) {
		Node *temp = first, *prev;

		while (temp != nullptr && temp->value < d) {
			first = temp->next;
			delete temp;
			temp = first;
		}

		while (temp != nullptr) {
			while (temp != nullptr && temp->value >= d) {
				prev = temp;
				temp = temp->next;
			}

			if (temp == nullptr) {
				return;
			}

			prev->next = temp->next;
			delete temp;

			temp = prev->next;
		}
	} else if (df == List::DeleteFlag::GREATER) {
		Node *temp = first, *prev;

		while (temp != nullptr && temp->value > d) {
			first = temp->next;
			delete temp;
			temp = first;
		}

		while (temp != nullptr) {
			while (temp != nullptr && temp->value <= d) {
				prev = temp;
				temp = temp->next;
			}

			if (temp == nullptr) {
				return;
			}

			prev->next = temp->next;
			delete temp;

			temp = prev->next;
		}
	} else {
		throw std::runtime_error("Invalid flag");
	}
}
void List::print() const {
	Node *tempNode = first;
	while (tempNode) {
		std::cout << tempNode->value << " ";
		tempNode = tempNode->next;
	}
	tempNode = nullptr;
	std::cout << std::endl;
}
