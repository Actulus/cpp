//
// Created by Pati on 11/24/2022.
//

#include "Frameworks.h"

//region Node
template <class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::Node::Node(T value, OrderedList::Node *node) {
	this->value = value;
	this->next = node;
}
//endregion

//region OrderedList
template <class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList() {

}
template <class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {

}
template <class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
	return numElements == 0;
}
template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T &item) {

}
template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T &item) {

}
template <class T, class LessComp, class Equal>
int const OrderedList<T, LessComp, Equal>::size() {
	return numElements;
}
template <class T, class LessComp, class Equal>
bool const OrderedList<T, LessComp, Equal>::find(T &item) {
	return 0;
}
template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listitems(ostream &os) {

}
//endregion

//region Iterator
template <class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &orderedList) {

}
template <class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
	return false;
}
template <class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
	return nullptr;
}
//endregion