#include "EvesKiadas.h"

int main() {
	EvesKiadas *evesKiadas = new EvesKiadas("adatok.txt");
	evesKiadas->ujKiadas("aprilis", "szamlak", 1500);
	evesKiadas->listazas();
	evesKiadas->ujKiadas("aprilis", "kozlekedes", 100);
	evesKiadas->listazas();
	evesKiadas->ujKiadas("aprilis", "ruhazat", 10);
	evesKiadas->listazas();
	set<string> kategoriak = evesKiadas->kiadasiKategoriak();
	/*std::for_each(kategoriak.begin(), kategoriak.end(), [](const auto &i){
		cout << i << endl;
	});*/
	double avgEves = evesKiadas->honaponkentiAtlagKiadas("");
	cout << "Az eves kiadas: " << avgEves << endl;
	double avgMajus = evesKiadas->honaponkentiAtlagKiadas("majus");
	cout << "A majusi kiadas: " << avgMajus << endl;
	evesKiadas->kategoriankentiAtlagKiadas();
	return 0;
}