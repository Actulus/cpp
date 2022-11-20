//
// Created by Pati on 11/17/2022.
//

#ifndef LAB9_ALKALMAZOTT_H
#define LAB9_ALKALMAZOTT_H

#include "Szemely.h"

//publikus szarmaztatas a legnagyobb, mindent orokol, a private mindent privatete tesz, a protected pedig protectedde
//a privatetokat nem eri el a szarmaztatott osztaly, a protectedeket igen
class Alkalmazott: public Szemely{
protected:
	string munkakor;
	int id;
	static int counter;
public:
	Alkalmazott(const string &vezetekNev, const string &kresztNev, int szuletesiEv,
	            const string &munkakor);
	virtual void print(ostream &os);
	int getID();
	string getMunkakor();
};


#endif //LAB9_ALKALMAZOTT_H
