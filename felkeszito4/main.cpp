#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include "Product.h"

using namespace std;

struct Interval {
	int start, end; // lehetne nr1, nr2
};

void sortingVector();
void printVector(vector<int> v);
bool compareInterval(Interval i1, Interval i2);

int main() {
//	std::cout << "Hello, World!" << std::endl;
	sortingVector();

	Product *product = new Product("adatok.txt");
//	product->printMap();

//	cout << "\nAr szerint novekvo\n";
//	product->sortByPrice();

//	product->sortByNameDesc();

product->sortByDescription();

	return 0;
}

void sortingVector(){
	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	printVector(v);

	sort(v.begin(), v.end()); // rendezes novekvo sorrendben, ha nincs comparalo fuggveny
	printVector(v);

	sort(v.begin(), v.end(), greater<int>()); // csokkento sorrendben teriti vissza
	printVector(v);

	sort(v.begin(), v.end(), [](const auto &nr1, const auto &nr2){ // lambda functionkent
		return nr1 < nr2;
	});
	printVector(v);

	vector<Interval> v2 { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };

	// sort the intervals in increasing order of
	// start time
	sort(v2.begin(), v2.end(), compareInterval);

	cout << "Intervals sorted by start time : \n";
	for (auto x : v2)
		cout << "[" << x.start << ", " << x.end << "] ";
}

void printVector(vector<int> v){
	for(auto i : v){
		cout << i << " ";
	}
	cout << endl;
}

// Compares two intervals according to starting times.
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start); // vagy akar .end szerint is lehet
}
