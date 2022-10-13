//
// Created by Pati on 10/13/2022.
//

#ifndef LAB4_POINT_H
#define LAB4_POINT_H

#define M 2000


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

class Point {
private:
	int x, y;

public:
	Point( int x=0, int y=0);
	int getX() const;
	int getY() const;
	double distanceTo(const Point& point)const ;
	void print() const;
};


#endif //LAB4_POINT_H
