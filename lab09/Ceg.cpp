//
// Created by Pati on 11/17/2022.
//

#include "Ceg.h"

void Ceg::addNewAlkalmazott(Alkalmazott *alkalmazott) {
	if(std::find(alkalmazottak.begin(), alkalmazottak.end(), alkalmazott) != alkalmazottak.end()){
		cout << "\nA szemely mar a ceg alkalmazottja!";
	} else {
		alkalmazottak.push_back(alkalmazott);
		//cout << "\nFelvettuk " << alkalmazott->getVezetekNev() << "!\n";
	}
}
void Ceg::fireAlkalmazott(int id) {
	auto it = remove_if(alkalmazottak.begin(), alkalmazottak.end(), [&id](Alkalmazott *alkalmazott){
		return alkalmazott->getID() == id;
	});
	alkalmazottak.erase(it, alkalmazottak.end());
}
void Ceg::addAlkalmazottToManager(Alkalmazott *alkalmazott, Manager *manager) {
	vector<Alkalmazott*> beosztottak = manager->getBeosztottak();
	if(! (std::find(beosztottak.begin(), beosztottak.end(), alkalmazott) != alkalmazottak.end())){
		Manager *temp = nullptr;
		temp = dynamic_cast<Manager*>(alkalmazott);
		if(temp != nullptr){
			cout << "\n" << temp->getID() << " manager.";
			return;
		}
	} else {
		manager->addAlkalmazott(alkalmazott);
		//cout << "\nFelvettuk!\n";
	}
}
void Ceg::cutAlkalmazottFromManager(Alkalmazott *alkalmazott, Manager *manager) {
	vector<Alkalmazott*> beosztottak = manager->getBeosztottak();
	if(std::find(beosztottak.begin(), beosztottak.end(), alkalmazott) != alkalmazottak.end()){
		manager->deleteAlkalmazott(alkalmazott);
		//cout << "\nAz alkalmazottat levalasztottuk a managertol.";
	} else {
		cout << "\nAz alkalmazott nem dolgozik ennel a managernel.";
	}
}
void Ceg::listAlkalmazottak(ostream &os) {
	auto print = [&os](Alkalmazott *alkalmazott) {
		Manager *mtemp = nullptr;
		mtemp = dynamic_cast<Manager*>(alkalmazott);
		if(mtemp != nullptr){
			Alkalmazott atemp = (Alkalmazott) (*mtemp);
			atemp.print(os);
		} else {
			alkalmazott->print(os);
		}
	};
	std::for_each(alkalmazottak.begin(), alkalmazottak.end(), print);

}
void Ceg::listManagers(ostream &os) {
	std::for_each(alkalmazottak.begin(), alkalmazottak.end(), [&os](Alkalmazott *alkalmazott){
		Manager *temp = nullptr;
		temp = dynamic_cast<Manager*>(alkalmazott);
		if(temp != nullptr){
			temp->print(os);
		}
	});
}

vector<Manager*> Ceg::getManagers(){
	vector<Manager*> managers;
	std::for_each(alkalmazottak.begin(), alkalmazottak.end(), [&managers](Alkalmazott *alkalmazott){
		Manager *temp = nullptr;
		temp = dynamic_cast<Manager*>(alkalmazott);
		if(temp != nullptr){
			managers.push_back(temp);
		}
	});
	return managers;
}