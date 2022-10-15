//
// Created by Pati on 10/13/2022.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include "List.h"
#include <vector>

using namespace std;

class Stack {
public:
	Stack();
	~Stack();
	void push(int e);
	int pop();
	bool isEmpty() const;
	void display();

private:
	List *list;
};


#endif //LAB3_STACK_H
