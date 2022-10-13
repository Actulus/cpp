//
// Created by Pati on 10/13/2022.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include "List.h"

class Stack {
public:
	Stack();
	~Stack();
	void push(int e);
	int pop();
	bool isEmpty() const;
	void display();

private:
	List *list = new List();
	struct Node {
		int data;
		Node *link;
	};
	Node *top;
};


#endif //LAB3_STACK_H
