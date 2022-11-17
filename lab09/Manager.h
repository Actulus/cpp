//
// Created by Pati on 11/17/2022.
//

#ifndef LAB9_MANAGER_H
#define LAB9_MANAGER_H

#include "Alkalmazott.h"

class Manager: public Alkalmazott{
	Alkalmazott *beosztottak;
public:
	Manager(string vezetekNev, string kresztNev, int szuletesiEv, string munkakor);
	void addAlkalmazott(Alkalmazott*alkalmazott);
	void deleteAlkalmazott(Alkalmazott*alkalmazott);
	int beosztottakSzama();
	void print(ostream&os) override;
};


#endif //LAB9_MANAGER_H
