//
// Created by Pati on 11/17/2022.
//

#ifndef LAB9_CEG_H
#define LAB9_CEG_H

#include "Manager.h"

class Ceg {
	string cegNev;
	vector<Alkalmazott*> alkalmazottak;
public:
	Ceg(string cNev) {
		this->cegNev = cNev;
	}
	void addNewAlkalmazott(Alkalmazott *alkalmazott);
	void fireAlkalmazott(int id);
	void addAlkalmazottToManager(Alkalmazott*alkalmazott, Manager *manager);
	void cutAlkalmazottFromManager(Alkalmazott*alkalmazott, Manager *manager);
	void listAlkalmazottak(ostream &os);
	void listManagers(ostream&os);
	vector<Manager*> getManagers();
};


#endif //LAB9_CEG_H
