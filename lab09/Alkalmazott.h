//
// Created by Pati on 11/17/2022.
//

#ifndef LAB9_ALKALMAZOTT_H
#define LAB9_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott: public Szemely{
protected:
	string munkakor;
public:
	Alkalmazott(string vezetekNev, string kresztNev, int szuletesiEv,
	            string munkakor);
	void print(ostream &os) override;
};


#endif //LAB9_ALKALMAZOTT_H
