//
// Created by Pati on 11/17/2022.
//

#include "Szemely.h"

Szemely::Szemely(string vezetekNev, string kresztNev, int szuletesiEv) {
	this->vezetekNev = vezetekNev;
	this->keresztNev = keresztNev;
	this->szuletesiEv = szuletesiEv;
}
void Szemely::print(ostream &os) {
	os << endl << vezetekNev << " " << keresztNev << " szuletesi eve: " << szuletesiEv;
}
