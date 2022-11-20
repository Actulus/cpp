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
	os << this->getVezetekNev() << " " << this->getKeresztNev() << "szuletesi eve: " << this->getSzuletesiEv();
}
string Szemely::getVezetekNev() {
	return this->vezetekNev;
}
string Szemely::getKeresztNev() {
	return this->keresztNev;
}
int Szemely::getSzuletesiEv() {
	return this->szuletesiEv;
}
