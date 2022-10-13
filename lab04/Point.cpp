//
// Created by Pati on 10/13/2022.
//

#include "Point.h"

Point::Point(int x, int y) {
	if (x >= 0 && x <= M && y >= 0 && y <= M){
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

double Point::distanceTo(const Point &point) const {
	return sqrt(pow((this->x - point.x), 2)+pow((this->y - point.y),2));
}

void Point::print() const {
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}

