//
// Created by Pati on 12/8/2022.
//

#include "Settlement.h"

Settlement::Settlement(string name, string county, int population) {
	this->name = name;
	this->county = county;
	this->population = population;
}
const string &Settlement::getName() const {
	return name;
}
const string &Settlement::getCounty() const {
	return county;
}
int Settlement::getPopulation() const {
	return population;
}
void Settlement::setName(const string &name) {
	this->name.clear();
	this->name = name;
}
void Settlement::setCounty(const string &county) {
	this->county.clear();
	this->county = county;
}
void Settlement::setPopulation(int population) {
	this->population = 0;
	this->population = population;
}

ostream &operator<<(ostream &os, const Settlement &settlement) {
	os << settlement.name << " " << settlement.county << " " << settlement.population << endl;
	return os;
}
