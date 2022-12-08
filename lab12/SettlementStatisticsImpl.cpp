//
// Created by Pati on 12/8/2022.
//

#include <sstream>
#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const char *file) {
	ifstream fin;
	fin.open(file);
	if (fin.fail()) {
		throw runtime_error("Cannot open file");
	}

	vector<string> row;
	string line, temp, word, name, code;
	int population;
	multimap<string, Settlement>::iterator it;

	int counter = 0;
	while (fin.good() && getline(fin, line)) {
		stringstream ss(line);
		vector<string> words;
		while (getline(ss, word, ',')) {
			words.push_back(word);
		}
		if (words.size() != 3) { // hibas sor
			continue;
		}

		name = words[0];
		code = words[1];
		population = stoi(words[2]);

		//cout << name << ", " << code << ", " << population << endl;
		data.insert(make_pair(code, new Settlement(name, code, population)));
	}

	/*for (auto i: data) {
		cout << i.first << " " << i.second->getCounty() << " " << i.second->getName() << " "
		     << i.second->getPopulation() << endl;
	}*/

	fin.close();
}
int SettlementStatisticsImpl::numSettlements() const {
	return data.size();
}
int SettlementStatisticsImpl::numCounties() const {
	int counter = 0;
	for (auto it = data.begin(), end = data.end();
	     it != end; it = data.upper_bound(it->first)) {
		counter++;
	}
	return counter;
}
int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
	int counter = 0;
	for (auto i = data.begin(); i != data.end(); ++i) {
		if (i->first == county) {
			counter++;
		}
	}
	return counter;
}
vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
	vector<Settlement> settlements;
	for (auto i = data.begin(); i != data.end(); ++i) {
		if (i->first == county) {
			settlements.push_back(*i->second);
		}
	}
	return settlements;
}
vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
	vector<Settlement> settlements;
	for (auto &i: data) {
		if (i.second->getName().find(name) != string::npos) {
			settlements.push_back(*i.second);
		}
	}

	return settlements;
}
Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
	for (const auto &i: data) {
		if ((i.first == county) && (i.second->getName().find(name) != string::npos)) {
			return *i.second;
		}
	}

	//or you can get the settlements by county using the function above
	//then search through the result vector to find the name
}
Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
	auto item = max_element(
			begin(data), end(data),
			[](const pair<string, Settlement *> i1, const pair<string, Settlement *> i2) {
				return i1.second->getPopulation() < i2.second->getPopulation();
			}
	);
	return *item->second;
}
Settlement SettlementStatisticsImpl::minPopulationDensity() const {
	auto item = min_element(
			begin(data), end(data),
			[](const pair<string, Settlement *> i1, const pair<string, Settlement *> i2) {
				return i1.second->getPopulation() < i2.second->getPopulation();
			}
	);
	return *item->second;
}
