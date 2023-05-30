#include <iostream>
#include "EvesKiadas.h"

int main() {
//	std::cout << "Hello, World!" << std::endl;
	EvesKiadas *evesKiadas = new EvesKiadas("adatok.txt");

	evesKiadas->listazas();

	cout << "\nUj kiadas hozzaadasa\n";
	evesKiadas->ujKiadas("januar", "elofizetes", 30);
	cout << endl;

	evesKiadas->listazas();

	set<string> kiadasiKategoriak;
	kiadasiKategoriak = evesKiadas->kiadasiKategoriak();

	cout << "\nKiadasi Kategoriak\n";
	for (auto i : kiadasiKategoriak) {
		cout << i << endl;
	}
	cout << endl;

	cout << "\nJanuari atlag kiadas\n";
	cout << evesKiadas->honaponkentiAtlagKiadas("januar");
	cout << endl;

	cout << "\nLakber atlag kiadas\n";
	cout << evesKiadas->kategoriankentiAtlagKiadas("lakber");
	cout << endl;

	return 0;
}
