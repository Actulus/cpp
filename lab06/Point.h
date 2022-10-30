//
// Created by Pati on 10/27/2022.
//

#ifndef LAB6_POINT_H
#define LAB6_POINT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define M 2000

using namespace std;

class Point {
private:
	int x, y;
	static int counter;
public:
	Point(int x = 0, int y = 0);
	Point(const Point &);
	~Point();
	int getX() const;
	int getY() const;
	static int getCounter();
	double distanceTo(const Point &point) const;
	void print() const;
};


#endif //LAB6_POINT_H
