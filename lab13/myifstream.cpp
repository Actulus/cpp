//
// Created by Pati on 12/15/2022.
//

#include "myifstream.h"

myifstream::myifstream(const string &file) {
	ifstream fin(file);
	char c;
	int counter = 0;
	while (fin >> noskipws >> c) {
		//cout << c;
		counter++;
		this->text.push_back(c);
	}

	//cout << counter;
	//cout << this->text << endl;
	this->size = counter;

	fin.close();
}
int myifstream::filesize() {
	return this->size;
}
char &myifstream::operator[](int index) {
	if (index > this->size) {
		throw out_of_range("index is either bigger or smaller than the file's size");
	}

	return this->text.at(index);
}
