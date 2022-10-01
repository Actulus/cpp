//
// Created by Pati on 9/29/2022.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <iostream>
#include <cstdio>

class Point {
private:
	int x, y;
public:
	Point( int x=0, int y=0);
	int getX() const;
	int getY() const;
	void print() const;
};


#endif //LAB2_POINT_H
