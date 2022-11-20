//
// Created by Pati on 11/17/2022.
//

#include "Manager.h"

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const string &vezetekNev, const string &kresztNev, int szuletesiEv, const string &munkakor) : Alkalmazott(vezetekNev, kresztNev, szuletesiEv, munkakor) {
	/*this->vezetekNev = vezetekNev;
	this->keresztNev = keresztNev;
	this->szuletesiEv = szuletesiEv;
	this->munkakor = munkakor;*/
}
void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
	beosztottak.push_back(alkalmazott);
}
void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
	Alkalmazott alkalmazott1 = *alkalmazott;
	//remove_if moves the found element to the end
	auto new_end = std::remove_if(beosztottak.begin(), beosztottak.end(), [&alkalmazott1](Alkalmazott *alk){
		return alk->getID() == alkalmazott1.getID();
	});
	//erase deletes it from the end
	beosztottak.erase(new_end, beosztottak.end());
}
void Manager::print(ostream &os) {
	os << endl;
	Alkalmazott::print(os);
	if(!beosztottak.empty()){
		os << "Beosztottak:";
		for (auto beosztott: beosztottak) {
			os << "\n\t";
			beosztott->print(os);
		}
	}
}
int const Manager::beosztottakSzama() {
	return beosztottak.size();
}
vector<Alkalmazott*> Manager::getBeosztottak() {
	return this->beosztottak;
}

