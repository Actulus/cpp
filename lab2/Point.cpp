//
// Created by Pati on 9/29/2022.
//

#include "Point.h"

//1-2
Point::Point(int x, int y){
	if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
		this->x = x;
		this->y = y;
	}
	else{
		this->x = 0;
		this->y = 0;
	}
}

int Point::getX() const {
	return x;
}
int Point::getY() const {
	return y;
}

//3
void Point::print() const {
	std::cout << "(" << x << ", " << y << ")";
}
