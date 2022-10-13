//
// Created by Pati on 10/13/2022.
//

#ifndef LAB4_POINTSET_H
#define LAB4_POINTSET_H

#include "Point.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;

class PointSet {
//különböző pontok
	vector<Point> points;

//különböző pontok száma
	int n;

//pontok kozotti tavolsagok
	vector<double> distances;

//segédfüggvény, amely feltölti a distances tömböt
	void computeDistances();

public:
//konstruktor: előállítja a points tömböt
//kiszámítja a pontok közötti távolságokat (tavolsagok tömb),
	PointSet(int n = 100);

//maximum kiválasztás a tavolsag tömbből
	double maxDistance() const;

//minimum kiválasztás a tavolsag tömbből
	double minDistance() const;

//összesen hány távolság értelmezhető n
//különböző pont között
	int numDistances() const;

//a pontok tároló kiíratása
	void printPoints() const;

//a tavolsagok tároló kiíratása
	void printDistances() const;

//növekvő sorrendbe rendezi a pontokat x koordináta szerint
	void sortPointsX();

//u. a. y koordináta szerint
	void sortPointsY();

//a tavolsagok tároló rendezése
	void sortDistances();

//hány darab különböző távolságot tartalmaz a tavolsagok tömb
	int numDistinctDistances();

};

//X koordinata szerinti rendezes
bool sortX(Point p1, Point p2);

//X koordinata szerinti rendezes
bool sortY(Point p1, Point p2);

#endif //LAB4_POINTSET_H
