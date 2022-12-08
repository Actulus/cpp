//
// Created by Pati on 12/8/2022.
//

#ifndef LAB12_SETTLEMENT_H
#define LAB12_SETTLEMENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Settlement {
private:
	string name = "";
	string county = "";
	int population = 0;
// constructor, getters, setters, inserter operator
public:
	Settlement(string name, string country, int population);
	const string &getName() const;
	const string &getCounty() const;
	int getPopulation() const;
	void setName(const string &name);
	void setCounty(const string &county);
	void setPopulation(int population);
	friend ostream &operator<<(ostream &os, const Settlement &settlement);
};


#endif //LAB12_SETTLEMENT_H
