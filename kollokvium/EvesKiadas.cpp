//
// Created by Pati on 1/5/2023.
//

#include "EvesKiadas.h"

EvesKiadas::EvesKiadas(const string &filename) {
	ifstream fin(filename);
	if(!fin.is_open()){
		throw runtime_error("Cannot open file.");
	}

	string honap, kiadas;
	int osszeg;
	while(fin.good()){
		fin >> honap >> kiadas >> osszeg;
		//cout << honap << " " << kiadas << " " << osszeg << endl;
		vector<pair<string, int>> pairs;
		kiadasok.insert(make_pair(honap, pairs));
		kiadasok.at(honap).emplace_back(kiadas, osszeg);
	}

	/*for(auto i : kiadasok){
		cout << i.first << " ";
		for(auto j : i.second){
			cout << j.first << " " << j.second << endl;
		}
		cout << endl;
	}*/

	fin.close();
}
void EvesKiadas::ujKiadas(const string &honap, const string &kiadas, int osszeg) {
	auto it = std::find_if(kiadasok.at(honap).begin(), kiadasok.at(honap).end(), [&kiadas](const auto&pair){
		return pair.first == kiadas;
	});
	//tartalmazza
	if(it != kiadasok.at(honap).end()){
		//nem irja felul az eredetit
		for(auto i : kiadasok.at(honap)){
			//cout << i.first << " " << i.second << endl;
			if(i.first == kiadas){
				i.second = osszeg;
				//cout << i.second;
			}
		}
	} else {
		kiadasok.at(honap).emplace_back(kiadas, osszeg);
	}
}

void EvesKiadas::listazas() const {
	cout << "\n-----------------------------------\n";
	for(auto i : kiadasok){
		cout << i.first << "\n\t";
		for(auto j : i.second){
			cout << "- " << j.first << " : " << j.second << "\n\t";
		}
		cout << endl;
	}
	cout << "\n-----------------------------------\n";
}
set<string> EvesKiadas::kiadasiKategoriak() const {
	set<string> kategoriak;
	for(auto i : kiadasok){
		for(auto j : i.second){
			kategoriak.insert(j.first);
		}
	}
	return kategoriak;
}
double EvesKiadas::honaponkentiAtlagKiadas(const string &honap) const {
	double avg = 0;
	int sum = 0, c = 0;

	if(honap.empty()){
		for(auto i : kiadasok){
			for(auto j : i.second){
				//cout << j.second << " ";
				sum += j.second;
				c++;
			}
		}
		/*avg = (double)sum / c;
		cout << avg;*/
	} else {
		for(auto i : kiadasok.at(honap)){
			//cout << i.second << " ";
			sum += i.second;
			c++;
		}
		/*avg = (double)sum / c;
		cout << avg;*/
	}
	avg = (double)sum / c;
	return avg;
}
void EvesKiadas::kategoriankentiAtlagKiadas() const {
	set<string> kategoriak = kiadasiKategoriak();
	/*map<string, int> kategelof;
	map<string, int> kategosszeg;*/ //ennek hasznalataval is megoldhato, ellenben hosszabb kodot kapunk
	map<string, pair<int,int>> kategElofOsszeg; //{kategoria, {elofordulas_szama, osszeg}}
	for(auto i : kategoriak){
		/*kategelof.insert({i, 0});
		kategosszeg.insert({i, 0});*/
		kategElofOsszeg.insert({i, {0, 0}});
	}
	for(auto i : kiadasok){
		//cout << i.first << endl;
		for(auto j : i.second){
			for(auto k : kategoriak){
				if(j.first == k){
					//cout << "\t" << k << " " << j.second << endl;
					/*kategelof.at(k)++;
					kategosszeg.at(k) += j.second;*/
					kategElofOsszeg.at(k).first++;
					kategElofOsszeg.at(k).second += j.second;
				}
			}
		}
	}

	/*for(auto i : kategelof){
		cout << i.first << " " << i.second << endl;
	}*/

	/*for(auto i : kategosszeg){
		cout << i.first << " " << i.second << endl;
	}*/

	//cout << endl << "Kategoriankenti atlag kiadas" << endl;
	/*for(auto i : kategosszeg){
		cout << "\t-" << i.first << " : ";
		for (auto j : kategelof) {
			if(i.first == j.first) {
				//cout << i.second << " " << j.second << " hanyados: " <<  i.second / j.second << endl;
				cout << (double) i.second / j.second << endl;
			}
		}
	}*/

	//cout << "\n-----------------------------------\n";
	cout << endl << "Kategoriankenti atlag kiadas" << endl;
	for(auto i : kategElofOsszeg){
		cout << "-" << i.first << ": " << (double) i.second.second / i.second.first << endl;
	}
}
