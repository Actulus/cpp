//
// Created by Pati on 11/24/2022.
//

#ifndef LAB10_FRAMEWORKS_H
#define LAB10_FRAMEWORKS_H

#include <functional>
#include <iostream>

using namespace std;

// Class declaration
//T - type of elements
template <class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;

// Class definition
template <class T, class LessComp = less<T>, class Equal = equal_to<T> >

class OrderedList {
	struct Node {
	public:
		T value;
		Node *next;
		Node(T value, Node *node);
	};

private:
	Node *first;
	int numElements;

public:
	OrderedList();
	~OrderedList();
	bool isEmpty();
	void insert(T &item);
	void remove(T &item);
	int const size();
	bool const find(T &item);
	void listitems(ostream &os);

	friend class Iterator<T, LessComp, Equal>;
};


// Class definition
template <class T, class LessComp, class Equal>
class Iterator {
	OrderedList<T, LessComp, Equal> &list;
	typename OrderedList<T, LessComp, Equal>::Node *act;
	Iterator(OrderedList<T, LessComp, Equal> &orderedList);
	bool hasNext();
	T next();
};


#endif //LAB10_FRAMEWORKS_H
