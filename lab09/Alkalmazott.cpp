//
// Created by Pati on 11/17/2022.
//

#include "Alkalmazott.h"

int Alkalmazott::counter{0};

Alkalmazott::Alkalmazott(const string &vezetekNev, const string &kresztNev, int szuletesiEv,
                         const string &munkakor) : Szemely(vezetekNev, kresztNev, szuletesiEv), munkakor(munkakor) {
	/*this->vezetekNev = vezetekNev;
	this->keresztNev = keresztNev;
	this->szuletesiEv = szuletesiEv;
	this->munkakor = munkakor;*/
	this->id = counter;
	++counter;
}
void Alkalmazott::print(ostream &os) {
	os << "ID: " << this->getID() << " ";
	Szemely::print(os);
	os << " munkakore: " << this->getMunkakor();
	os << endl;
}
int Alkalmazott::getID() {
	return this->id;
}
string Alkalmazott::getMunkakor() {
	return this->munkakor;
}
