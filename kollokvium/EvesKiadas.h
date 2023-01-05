//
// Created by Pati on 1/5/2023.
//

#ifndef KOLLOKVIUM_EVESKIADAS_H
#define KOLLOKVIUM_EVESKIADAS_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class EvesKiadas {
	map<string, vector<pair<string, int>>> kiadasok;
public:
	EvesKiadas(const string &filename);
	void listazas() const;
	void ujKiadas(const string& honap, const string& kiadas, int osszeg);
	set<string> kiadasiKategoriak() const;
	double honaponkentiAtlagKiadas(const string& honap) const;
	void kategoriankentiAtlagKiadas() const;
};


#endif //KOLLOKVIUM_EVESKIADAS_H
