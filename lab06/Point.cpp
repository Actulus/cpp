//
// Created by Pati on 10/27/2022.
//

#include "Point.h"

int Point::counter{0};

Point::Point(int x, int y) {
	if (x >= 0 && x <= M && y >= 0 && y <= M) {
		this->x = x;
		this->y = y;
	} else {
		this->x = 0;
		this->y = 0;
	}
	this->counter++;
}

Point::Point(const Point &point) {
	if ((point.x >= 0 && point.x <= M) && (point.y >= 0 && point.y <= M)) {
		this->x = point.x;
		this->y = point.y;
	} else {
		this->x = 0;
		this->y = 0;
	}
	this->counter++;
}

Point::~Point() {
	this->x = 0;
	this->y = 0;
	counter--;
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

int Point::getCounter() {
	return Point::counter;
}

double Point::distanceTo(const Point &point) const {
	return sqrt(pow((this->x - point.x), 2) + pow((this->y - point.y), 2));
}

void Point::print() const {
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}
