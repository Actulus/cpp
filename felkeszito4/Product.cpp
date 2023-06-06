//
// Created by Pati on 6/6/2023.
//

#include "Product.h"

Product::Product(string filename) {
	ifstream fin(filename);
	if(!fin){
		cout<<"File not found";
		exit(-1);
	}

	string name, description;
	double price;

	string line;
	vector<pair<double, string>> temp;
	while(getline(fin, line)) {
		istringstream iss(line); // beletesszuk a sort, hogy szet tudjuk valasztani az adatokat

		string data;

		if(getline(iss, data, ' ')){
			name = data;
		}

		if(getline(iss, data, ' ')){
			price = stod(data);
		}

		if(getline(iss, data, '\n')){
			description = data;
		}

		products.insert(make_pair(name, temp));
		products[name].emplace_back(price, description);
	}

	fin.close();
}

void Product::sortByPrice() {
	std::vector<std::pair<std::string, std::vector<std::pair<double, std::string>>>> sortedProducts(
			products.begin(), products.end()
	);

	// Sort the vector of pairs based on the double value (price)
	std::sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& p1, const auto& p2) {
		return p1.second.front().first < p2.second.front().first;  // Compare based on the first (double) value (price)
	});

	// Print the sorted map
	for (const auto& pair : sortedProducts) {
		const auto& product = pair.first;
		const auto& pairs = pair.second;

		std::cout << product << ":" << std::endl;
		for (const auto& p : pairs) {
			std::cout << "  " << p.first << " - " << p.second << std::endl;
		}
	}
}
void Product::sortByDescription() {
	std::vector<std::pair<std::string, std::vector<std::pair<double, std::string>>>> sortedProducts(
			products.begin(), products.end()
	);

	// Sort the vector of pairs based on the double value (price)
	std::sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& p1, const auto& p2) {
		return p1.second.front().second < p2.second.front().second;  // Compare based on the first (double) value (price)
	});

	// Print the sorted map
	for (const auto& pair : sortedProducts) {
		const auto& product = pair.first;
		const auto& pairs = pair.second;

		std::cout << product << ":" << std::endl;
		for (const auto& p : pairs) {
			std::cout << "  " << p.first << " - " << p.second << std::endl;
		}
	}

	string c = "3";
	vector<string> v{"alma", "korte", "banan"};
	for_each(v.begin(), v.end(), [&c](const auto&elem){ // [&c] - kulso valtozok; (const auto&elem) - collection elemei
		cout << c << elem << endl; // a konkret feladat
	});

	int szam = 5, sum = 0;
	vector<int> szamok{1,2,3,4,5};
	std::for_each(szamok.begin(), szamok.end(), [&szam, &sum](const int& sz){
		cout << szam << " + " << sz << " = " << sz + szam << endl;
		sum += szam + sz;
	});

	cout << sum << endl;

	/*for(auto elem : v){
		cout << c << elem;
	}*/

	/*for (int i = 0; i < v.size(); ++i) {

	}*/
}

void Product::sortByNameDesc() {
	map<string, vector<pair<double, string>>, greater<>> productsDesc;

	vector<pair<double, string>> temp;

	for(auto i : products){
		productsDesc.insert({i.first, temp});
		for(auto j : i.second){
			productsDesc[i.first].emplace_back(j.first, j.second);
		}
	}

	for(auto i : productsDesc){
		cout << "\nNev: " << i.first << endl;
		for(auto j : i.second){
			cout << "\tAr: " << j.first << endl;
			cout << "\tLeiras: " << j.second << endl;
		}
		cout << endl;
	}

}

void Product::printMap() {
	for(auto i : products){
		cout << "\nNev: " << i.first << endl;
		for(auto j : i.second){
			cout << "\tAr: " << j.first << endl;
			cout << "\tLeiras: " << j.second << endl;
		}
		cout << endl;
	}
}
