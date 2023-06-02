#include <iostream>
#include "Library.h"

int main() {
	Library library;

	unordered_set<string> authors;
	authors.insert("Stephen Randy Davis");
	Book newBook = *new Book("9-7807-6456-8527", "C++ for Dummies", authors, 408, 2005);

	library.insert(newBook);

	library.import("library.txt", "C++");

	cout << library;

	vector<Book> sortedBooks = library.sorted(SortBy::Year);
	for(auto i : sortedBooks){
		cout << i << endl;
	}

	library.import("library.txt", "");

	sortedBooks = library.sorted(SortBy::Title);
	for(auto i : sortedBooks){
		cout << i << endl;
	}

	library.remove("9-7805-9600-907");

	unordered_set<string> allAuthors = library.authors();
	for(auto a : allAuthors){
		cout << a << "\n";
		vector<Book> authorsBooks = library.authorBooks(a);
		for(auto b : authorsBooks){
			cout << b;
		}
		cout << "\n";
	}

	return 0;
}
