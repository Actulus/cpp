//
// Created by Pati on 11/17/2022.
//

#ifndef LAB9_MANAGER_H
#define LAB9_MANAGER_H

#include "Alkalmazott.h"

class Manager: public Alkalmazott{
	vector<Alkalmazott*> beosztottak;
public:
	static const string MANAGER_MUNKAKOR;
	Manager(const string &vezetekNev, const string &kresztNev, int szuletesiEv, const string &munkakor);
	void addAlkalmazott(Alkalmazott*alkalmazott);
	void deleteAlkalmazott(Alkalmazott*alkalmazott);
	int const beosztottakSzama(); //constos fg. csak mas standard szerint mukodott {query} = const
	virtual void print(ostream&os) /*override*/; //a virtualt nem muszaj odairni de boviteshez jo
	vector<Alkalmazott*> getBeosztottak();
};


#endif //LAB9_MANAGER_H
