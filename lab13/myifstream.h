//
// Created by Pati on 12/15/2022.
//

#ifndef LAB13_MYIFSTREAM_H
#define LAB13_MYIFSTREAM_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

class myifstream {
	int size;
	string text;
public:
	myifstream(const string &file);
	int filesize();
	char &operator[](int index);
};


#endif //LAB13_MYIFSTREAM_H
