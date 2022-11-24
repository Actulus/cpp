//
// Created by Pati on 11/24/2022.
//

#ifndef LAB10_ORDERLIST_H
#define LAB10_ORDERLIST_H

#include <functional>
#include <iostream>

using namespace std;

// Class declaration
template <class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;

// Class definition
template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
	struct Node {
		T value;
		Node *next;
		Node(T value, Node *next) {
			this->value = value;
			this->next = next;
		}
	};

private:
	Node *first;
	int numElements;

public:
	OrderedList();
	~OrderedList();
	bool isEmpty();
	void insert(T &);
	void remove(T &);
	int size();
	bool find(T &);
	void listitems(ostream &);

	friend class Iterator<T, LessComp, Equal>;

};

template <class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList() {
	this->first = nullptr;
	this->numElements = 0;
}

template <class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
	Node *temp = first;
	while (temp) {
		temp = first->next;
		delete first;
		first = temp;
		//numElements--;
	}
	//temp = nullptr;
	numElements = 0;
}

template <class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
	return numElements == 0;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T &value) {
	Node *temp1 = this->first, *temp2, *newNode;
	newNode = new Node(value, nullptr);
	if (isEmpty()) {
		this->first = newNode;
		this->numElements++;
		return;
	}

	while (temp1 != nullptr && LessComp()(temp1->value, value)) {
		temp2 = temp1;
		temp1 = temp1->next;
	}

	if (temp1 == this->first) {
		newNode->next = this->first;
		this->first = newNode;
		this->numElements++;
		return;
	}

	if (temp1 == nullptr) {
		temp2->next = newNode;
		numElements++;
		return;
	}
	newNode->next = temp2->next;
	temp2->next = newNode;
	numElements++;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T &value) {
	Node *elozo = this->first, *aktualis = this->first;

	while (aktualis->next != nullptr) {
		if (aktualis->value == value && aktualis == this->first) {
			this->first = this->first->next;
			delete aktualis;
			aktualis = this->first;
			continue;
		}
		if (aktualis->value == value) {
			elozo->next = aktualis->next;
			delete aktualis;
			aktualis = elozo->next;
			continue;
		}
		elozo = aktualis;
		aktualis = aktualis->next;
	}
	elozo = nullptr;
}

template <class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() {
	return this->numElements;
}

template <class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T &value) {
	Node *temp = first;
	while (temp != nullptr) {
		if (Equal()(temp->value, value)) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listitems(ostream &os) {
	Node *temp = first;
	while (temp != nullptr) {
		os << temp->value << " ";
		temp = temp->next;
	}
	os << endl;
}


// region Class definition Iterator
template <class T, class LessComp, class Equal>
class Iterator {
private:
	OrderedList<T, LessComp, Equal> &list;
	typename OrderedList<T, LessComp, Equal>::Node *act;

public:
	Iterator(OrderedList<T, LessComp, Equal> &);
	bool hasNext();
	T next();
};

template <class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &orderedList):list(orderedList),
                                                                                     act(orderedList.first) {
	//ures konstruktor, mert megfeleltetjuk az elemet
}

template <class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
	return act->next != nullptr;
}
template <class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
	act = act->next;
	return act->value;
}
//endregion


#endif //LAB10_ORDERLIST_H
