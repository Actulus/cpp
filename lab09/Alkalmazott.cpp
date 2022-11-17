//
// Created by Pati on 11/17/2022.
//

#include "Alkalmazott.h"

Alkalmazott::Alkalmazott(string vezetekNev, string kresztNev, int szuletesiEv,
                         string munkakor) : Szemely(vezetekNev, kresztNev, szuletesiEv) {
	this->vezetekNev = vezetekNev;
	this->keresztNev = keresztNev;
	this->szuletesiEv = szuletesiEv;
	this->munkakor = munkakor;
}
void Alkalmazott::print(ostream &os) {
	Szemely::print(os);
	os << munkakor;
}
