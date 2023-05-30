//
// Created by Pati on 5/30/2023.
//

#ifndef FELKESZITO2_EVESKIADAS_H
#define FELKESZITO2_EVESKIADAS_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

class EvesKiadas {
private:
	map<string, vector<pair<string, int>>> kiadasok;
public:
	EvesKiadas(const string & filename);
	void listazas() const;
	void ujKiadas(const string& honap, const string& kiadas, int osszeg);
	set<string> kiadasiKategoriak() const;
	double honaponkentiAtlagKiadas(const string& honap) const;
	double kategoriankentiAtlagKiadas(const string& kategoria) const;
	void fajlBeolvTab();
	void fajlBeolvVesszo();
	void fajlBeolvSpace();
};

#endif //FELKESZITO2_EVESKIADAS_H
