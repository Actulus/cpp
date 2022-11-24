#include <iostream>
#include "BST.h"
#include "NodeBST.h"
//#include "ArrayBST.h"
using namespace std;

int main() {
	BST *tree = new NodeBST();
	//BST * tree = new ArrayBST( 10000 );

	for (int i = 0; i < 10; ++i) {
		int r = rand() % 10;
		cout << "\n" << i << ". Insert random number " << r << endl;
		tree->insert(r);
		cout << "Inorder: ";
		tree->print_inorder();
	}
	cout << "\n***********************" << endl;
	// Test case 1: insert 1
	std::cout << "Test case 1: Insert 1 ";
	tree->insert(1);
	if (tree->find(1))
		std::cout << "Passed!\n";
	else
		std::cout << "Failed! Tree should contain 1.\n";
	tree->print_inorder();
	cout << endl;


	// Test case 2: insert 7
	std::cout << "Test case 2: Insert 7 ";
	tree->insert(7);
	if (tree->find(1) && tree->find(7))
		std::cout << "Passed!\n";
	else
		std::cout << "Failed! Tree should contain 1, 7.\n";
	tree->print_inorder();
	cout << endl;

	// Test case 3: insert 18
	std::cout << "Test case 3: Insert 18 ";
	tree->insert(18);
	if (tree->find(18) && tree->find(7) && tree->find(1))
		std::cout << "Passed!\n";
	else
		std::cout << "Failed! Tree should contain -1, 1, 7.\n";
	tree->print_inorder();
	cout << endl;

	// ADD YOUR TESTS HERE
	cout << "\nINORDER: ";
	tree->print_inorder();
	cout << "\nPREORDER: ";
	tree->print_preorder();
	cout << "\nPOSTORDER: ";
	tree->print_postorder();
	return 0;
}
