//
// Created by Pati on 6/2/2023.
//

#include "Library.h"

int Library::count() {
	return books.size();
}
void Library::import(string filename, string filter="") {
	ifstream fin(filename);
	if(!fin){
		cout<<"File not found";
		exit(-1);
	}

	string isbn, title, author, pagesString, yearString;
	unordered_set<string> authors;
	int pages, year;

	string line;
	while(getline(fin, line)){
		istringstream iss(line);
		string bookData;

		if(getline(iss, bookData, ';')){
			isbn = bookData;
		}

		if(getline(iss, bookData, ';')){
			istringstream authorStream(bookData);
			while(getline(authorStream, author, ':')){
				authors.insert(author);
			}
		}

		if(getline(iss, bookData, ';')){
			title = bookData;
		}

		if(getline(iss, bookData, ';')){
			yearString = bookData;
			year = stoi(yearString);
		}

		if(getline(iss, bookData, ';')){
			pagesString = bookData;
			pages = stoi(pagesString);
		}

		if(title.find(filter) != string::npos) {
			Book book = *new Book(isbn, title, authors, pages, year);
			insert(book);
		}
	}

	/*while (!fin.eof()){
		getline(fin, isbn, ';') && getline(fin, author, ';') && getline(fin, title, ';') && getline(fin, yearString, ';') && getline(fin, pagesString, ';'); //az osszeg stringkent van beolvasva a getline miatt

		year = stoi(yearString);
		pages = stoi(pagesString);
		authors.insert(author);

		if(title.find(filter) != string::npos){
			Book book = *new Book(isbn, title, authors, pages, year);
			insert(book);
		}
	}*/

	fin.close();
}
void Library::insert(Book book) {
	try {
		books.insert(make_pair(book.getIsbn(), book));
	} catch (error_code e){
		cerr << e.value();
	}
}
void Library::remove(string isbn) {
	try {
		books.erase(isbn);
	} catch (error_code e){
		cerr << e.value();
	}
}
vector<Book> Library::sorted(SortBy mode) {
	vector<Book> sortedBooks;
	for(auto& i : books){
		sortedBooks.push_back(i.second);
	}

	if(mode == SortBy::Title){ // mode - mi alapjan sortolunk; enum eseten elemek elerese ::-al
		sort(sortedBooks.begin(), sortedBooks.end(), [](const Book& b1, const Book& b2) {
			return b1.getTitle() < b2.getTitle();
		});
	} else if(mode == SortBy::Page){
		sort(sortedBooks.begin(), sortedBooks.end(), [](const Book& b1, const Book& b2){
			return b1.getPages() < b2.getPages();
		});
	} else if(mode == SortBy::Year){
		sort(sortedBooks.begin(), sortedBooks.end(), sortByYear);
	} else {
		cerr << "No mode like this"; // cout+error -> cerr - beepitett fuggveny hibakod eseten
	}

	return sortedBooks;
}
unordered_set<string> Library::authors() {
	unordered_set<string> authors;
	for(auto i : books){
		for(auto author: i.second.getAuthors()){
			authors.insert(author);
		}
	}
	return authors;
}
vector<Book> Library::authorBooks(string author) {
	vector<Book> authorsBooks;
	for(auto i: books){
		for(auto j: i.second.getAuthors()){
			if(j == author){
				authorsBooks.push_back(i.second);
			}
		}
	}
	return authorsBooks;
}

ostream &operator<<(ostream &os, const Library &library) {
	for(auto i : library.books){
		os << i.second;
	}
	return os;
}

bool sortByTitle(Book &b1, Book &b2) {
	return b1.getTitle() < b2.getTitle();
}
bool sortByPage(Book &b1, Book &b2) {
	return b1.getPages() < b2.getPages();
}
bool sortByYear(Book &b1, Book &b2) {
	return b1.getYear() < b2.getYear();
}
