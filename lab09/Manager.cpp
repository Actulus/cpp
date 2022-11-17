//
// Created by Pati on 11/17/2022.
//

#include "Manager.h"

Manager::Manager(string vezetekNev, string kresztNev, int szuletesiEv, string munkakor) : Alkalmazott(vezetekNev, kresztNev, szuletesiEv, munkakor) {
	this->vezetekNev = vezetekNev;
	this->keresztNev = keresztNev;
	this->szuletesiEv = szuletesiEv;
	this->munkakor = munkakor;
}
void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {

}
void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {

}
void Manager::print(ostream &os) {
	Alkalmazott::print(os);
}
