//
// Created by Pati on 11/17/2022.
//

#ifndef LAB9_SZEMELY_H
#define LAB9_SZEMELY_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Szemely {
protected:
	string vezetekNev;
	string keresztNev;
	int szuletesiEv;
public:
	Szemely(string vezetekNev, string kresztNev, int szuletesiEv);
	virtual void print(ostream &os) /*override - ha elmarad a virtual, akkor jelzi, ososztalynal is szol masmirol, nem kotelezo odairni*/;
	string getVezetekNev();
	string getKeresztNev();
	int getSzuletesiEv();
};


#endif //LAB9_SZEMELY_H
