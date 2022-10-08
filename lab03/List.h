//
// Created by Pati on 10/6/2022.
//

#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include <iostream>
#include <stdexcept>

class List {
public:
/* creates an empty list */
	List();
/* destroys this list */
	~List();
/* returns true if d is in the list - complexity: O(n) */
	bool exists(int d) const;
/* returns the size of the list - complexity: O(1) */
	int size() const;
/* returns true if the list is empty - complexity: O(1) */
	bool empty() const;
/* inserts d into this list as the first element - complexity: O(1) */
	void insertFirst(int d);
/* removes the first element of the list - complexity: O(1) */
/* throws an exception in case of empty list*/
	int removeFirst();
/* removes the first element less than/equal to/greater than d,
depending on the value of df. Does nothing if there is no value
to remove. The enum values are accessed with List::DeleteFlag::LESS,
..., outside the class */
	enum class DeleteFlag {
		LESS, EQUAL, GREATER
	};
	void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);
/* prints the contents of this list */
	void print() const;
/* forbid copying of lists */
	List(const List&) = delete;
	List& operator=(const List&) = delete;
private:
/* number of nodes in the list */
	int nodeCounter{0};
/* a list node */
	struct Node {
		int value; // the node value
		Node* next; // pointer to the next node, nullptr in the last node
		Node(int v, Node* n) : value(v), next(n) {
		}
	};
	Node* first; // pointer to the first node
};


#endif //LAB3_LIST_H
