//
// Created by Pati on 6/2/2023.
//

#ifndef FELKESZITO3_LIBRARY_H
#define FELKESZITO3_LIBRARY_H

#include "Book.h"
#include <unordered_map>
#include <vector>
#include <sstream>

enum SortBy {
	Title,
	Page,
	Year
};

class Library {
private:
	std::unordered_map<string, Book> books;

public:
	int count();
	void import(string filename, string filter);
	void insert(Book book);
	void remove(string isbn);
	vector<Book> sorted(SortBy mode);
	unordered_set<string> authors();
	vector<Book> authorBooks(string author);
	friend ostream& operator << (ostream& os, const Library& library);
};

bool sortByTitle(Book &b1, Book &b2);
bool sortByPage(Book &b1, Book &b2);
bool sortByYear(Book &b1, Book &b2);

#endif //FELKESZITO3_LIBRARY_H
