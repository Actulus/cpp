//
// Created by Pati on 6/6/2023.
//

#ifndef FELKESZITO4_PRODUCT_H
#define FELKESZITO4_PRODUCT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

//typedef struct ProductType {
//	string name;
//	double price;
//	string description;
//} ProductType;

//struct ComparePairs {
//	bool operator()(const std::pair<double, std::string>& p1, const std::pair<double, std::string>& p2) const {
//		return p1.first < p2.first;  // Compare based on the first (double) value
//	}
//};

class Product {
private:
	map<string, vector<pair<double, string>>> products; // string - name, double - price, string - description
//	map<string, vector<ProductType>> products2;

public:
	explicit Product(string filename);
	void sortByPrice();
	void sortByDescription();
	void sortByNameDesc();
	void printMap();

};

//multimap<int, string> invert(map<string, int> & mymap)
//{
//	multimap<int, string> multiMap;
//
//	map<string, int> :: iterator it;
//	for (it=mymap.begin(); it!=mymap.end(); it++)
//	{
//		multiMap.insert(make_pair(it->second, it->first));
//	}
//
//	return multiMap;
//}


#endif //FELKESZITO4_PRODUCT_H
