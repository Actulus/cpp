//
// Created by Pati on 5/30/2023.
//

#include "EvesKiadas.h"

EvesKiadas::EvesKiadas(const string &filename) {
	ifstream fin(filename);
	if(!fin){
		cout<<"File not found";
		exit(-1);
	}

	string honap, kiadas;
	int osszeg;

	while (!fin.eof()){
		fin >> honap >> kiadas >> osszeg; // mivel tabbal/space-szel vannak elvalasztva

		pair<string,int> pair1 = make_pair(kiadas,osszeg);

		kiadasok[honap].push_back(pair1);
	}

	fin.close();
}
void EvesKiadas::listazas() const {
	// {i, j} - mapen beluli par; j = i.second
	// {j.first, j.second} - vectoron beluli par
	cout << "\nEves kiadasok" << endl;
	for(auto i : kiadasok){
		cout << i.first << ":\n"; // i.first = kulcs
		for(auto j : i.second){ // i.second = value = vector({string, int})
			cout << "\t- " << j.first << ": " << j.second << endl; // j.first = kiadasi kategoria, j.second = osszeg
		}
		cout << endl;
	}
	cout << endl;
}
void EvesKiadas::ujKiadas(const string &honap, const string &kiadas, int osszeg) {
	kiadasok[honap].push_back(make_pair(kiadas, osszeg));
}
set<string> EvesKiadas::kiadasiKategoriak() const {
	set<string> kiadasiKategoriak;
	for(auto i : kiadasok){
		for(auto j : i.second){
			kiadasiKategoriak.insert(j.first); // valuet/erteket teszunk bele, csak az ertek van benne
		}
	}

//	for (auto i: kiadasiKategoriak){
//		cout << i << "\n";
//	}

	// Elso elem kivetele set-bol
	/*auto elsoElemIterator = kiadasiKategoriak.begin(); // pointer az elso elemre
	cout << *elsoElemIterator;
	string elsoElem = *elsoElemIterator;*/


//set legelso elemenek kiiratasa
//	for(auto i = kiadasiKategoriak.begin(); i != kiadasiKategoriak.end(); i++){
//		cout << *i << "\n";
//	}

	return kiadasiKategoriak;
}
double EvesKiadas::honaponkentiAtlagKiadas(const string &honap) const {
	double avg = 0.0;
	int sum = 0, n = 0;

	if(honap.empty()){
		for(auto i : kiadasok){
			for(auto j : i.second) {
				sum += j.second;
			}
		}

		n = kiadasok.size();

		avg = (double) sum / n;
	} else {

		for (auto i: kiadasok.at(honap)) { // honap kulcsu vectoron megyunk vegig
			sum += i.second; // kivesszuk az osszegeket
		}

		n = kiadasok.at(honap).size(); // hany darab ertek/elem van a honap kulcsnal
		//	cout << "Osszeg: " << sum << "\n";
		//	cout << "Darabszam: " << n << "\n";

		avg = (double) sum / n; // vagy a sum double tipusu

		//	cout << "Atlag: " << avg << "\n";
	}

	return avg;
}
double EvesKiadas::kategoriankentiAtlagKiadas(const string& kategoria) const {
	map<string, pair<double, int>> kategoriankentiKiadas; // string - kategoria, double - osszeget kategoriankent, int - hanyszor szerepel
	// pl. ruhazat szerepel 3-szor -> int resz = 3

	for(auto i : kiadasok){
		for (auto j : i.second) {
			kategoriankentiKiadas.insert(make_pair(j.first, make_pair(0, 0)));
			kategoriankentiKiadas[j.first].first += j.second; // osszeg
			kategoriankentiKiadas[j.first].second++; // darabszam
		}
	}

//	for (auto i : kategoriankentiKiadas){
//		cout << "Kategoria: " << i.first << ", osszeg: " << i.second.first << ", darabszam " << i.second.second << "\n";
//	}

	double sum = 0.0;
	double avg = 0.0;
	int osszdarabszam = 0;

	if (kategoria.empty()){
		double osszeg;
		int darabszam;
		for(auto i : kategoriankentiKiadas){
			osszeg = i.second.first;
			darabszam = i.second.second;

			sum += osszeg;
			osszdarabszam += darabszam;
		}

		avg = sum / osszdarabszam;
	} else {
		sum = kategoriankentiKiadas[kategoria].first;
		osszdarabszam = kategoriankentiKiadas[kategoria].second;

		avg = sum / osszdarabszam;
	}

	return avg;
}
void EvesKiadas::fajlBeolvTab() {
	map<string, vector<pair<string, int>>> kiadasokTab;
	ifstream fin("adatTab.txt");
	if(!fin){
		cout<<"File not found";
		exit(-1);
	}

	string honap, kiadas;
	int osszeg;

	while (!fin.eof()){
		fin >> honap >> kiadas >> osszeg;

		pair<string,int> pair1 = make_pair(kiadas,osszeg);

		kiadasokTab[honap].push_back(make_pair(kiadas, osszeg));
	}

	fin.close();

	for(auto i : kiadasokTab){
		cout << i.first << ":\n";
		for(auto j : i.second){
			cout << "\t" << j.first << " " << j.second << endl;
		}
		cout << endl;
	}
}
void EvesKiadas::fajlBeolvVesszo() {
	map<string, vector<pair<string, int>>> kiadasokTab;
	ifstream fin("adatVesszo.txt");
	if(!fin){
		cout<<"File not found";
		exit(-1);
	}

	string honap, kiadas, osszegS;
	int osszeg;

	while (!fin.eof()){
		getline(fin, honap, ',') && getline(fin, kiadas, ',') && getline(fin, osszegS, '\n'); //az osszeg stringkent van beolvasva a getline miatt
		 osszeg = stoi(osszegS);

		pair<string,int> pair1 = make_pair(kiadas,osszeg);

		kiadasokTab[honap].push_back(pair1);
	}

	fin.close();

	for(auto i : kiadasokTab){
		cout << i.first << ":\n";
		for(auto j : i.second){
			cout << "\t" << j.first << " " << j.second << endl;
		}
		cout << endl;
	}
}
void EvesKiadas::fajlBeolvSpace() {
	map<string, vector<pair<string, int>>> kiadasokTab;
	ifstream fin("adatSpace.txt");
	if(!fin){
		cout<<"File not found";
		exit(-1);
	}

	string honap, kiadas;
	int osszeg;

	while (!fin.eof()){
		fin >> honap >> kiadas >> osszeg;

		pair<string,int> pair1 = make_pair(kiadas,osszeg);

		kiadasokTab[honap].push_back(make_pair(kiadas, osszeg));
	}

	fin.close();

	for(auto i : kiadasokTab){
		cout << i.first << ":\n";
		for(auto j : i.second){
			cout << "\t" << j.first << " " << j.second << endl;
		}
		cout << endl;
	}
}
