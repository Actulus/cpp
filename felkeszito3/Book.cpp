//
// Created by Pati on 6/2/2023.
//

#include "Book.h"

Book::Book(const string &isbn, const string &title, const unordered_set<string> &authors, int pages, int year) : isbn(
		isbn), title(title), authors(authors), pages(pages), year(year) {
//	this->isbn = isbn;
//	this->title = title;
//	this->authors = authors;
//	this->pages = pages;
//	this->year = year;
}

const string &Book::getIsbn() const {
	return isbn;
}
const string &Book::getTitle() const {
	return title;
}
const unordered_set<string> &Book::getAuthors() const {
	return authors;
}
int Book::getPages() const {
	return pages;
}
int Book::getYear() const {
	return year;
}
ostream &operator<<(ostream &os, const Book &book) {
	os << "\tisbn: " << book.getIsbn() << " title: " << book.getTitle() << " authors: " << book.getAuthors().size() << " pages: " << book.getPages() << " year: " << book.getYear() << endl;
	return os;
}
