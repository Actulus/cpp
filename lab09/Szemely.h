//
// Created by Pati on 11/17/2022.
//

#ifndef LAB9_SZEMELY_H
#define LAB9_SZEMELY_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Szemely {
protected:
	string vezetekNev;
	string keresztNev;
	int szuletesiEv;
public:
	Szemely(string vezetekNev, string kresztNev, int szuletesiEv);
	virtual void print(ostream &os);
};


#endif //LAB9_SZEMELY_H
