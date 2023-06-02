//
// Created by Pati on 6/2/2023.
//

#ifndef FELKESZITO3_BOOK_H
#define FELKESZITO3_BOOK_H

#include <string>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

class Book {

private:
	string isbn;
	string title;
	unordered_set<string> authors;
	int pages;
	int year;

public:
	Book(const string &isbn, const string &title, const unordered_set<string> &authors, int pages, int year);
	const string &getIsbn() const;
	const string &getTitle() const;
	const unordered_set<string> &getAuthors() const;
	int getPages() const;
	int getYear() const;
	friend ostream& operator << (ostream& os, const Book& book);
};


#endif //FELKESZITO3_BOOK_H
