//
// Created by Pati on 10/13/2022.
//

#include "PointSet.h"

PointSet::PointSet(int n) {
	//points.assign(n, Point(0,0));
	this->n = n;
	random_device rd; // seed the random number generator named rd
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, M); // return a number in the given range
	for (int i = 0; i < n; ++i) {
		int x = dist(mt);
		int y = dist(mt);

		Point point(x,y);
		points.push_back(point);
	}

	computeDistances();
}

void PointSet::computeDistances() {
	for (int i = 0; i < this->n-1; ++i) {
		for (int j = i+1; j < this->n; ++j) {
			distances.push_back(points.at(i).distanceTo(points.at(j)));
		}
	}
}

double PointSet::maxDistance() const {
	double max = *max_element(distances.begin(), distances.end());
	return max;
}

double PointSet::minDistance() const {
	double min = *min_element(distances.begin(), distances.end());
	return min;
}

int PointSet::numDistances() const {
	return distances.size();
}

void PointSet::printPoints() const {
	for (auto point: points) {
		point.print();
		//cout << "(" << point.getX() << ", " << point.getY() << ")" << endl;
	}

}

void PointSet::printDistances() const {
	for (auto dist: distances) {
		cout << dist << " ";
	}
	cout << endl;
}

void PointSet::sortPointsX() {
	sort(points.begin(), points.end(), sortX);
}

void PointSet::sortPointsY() {
	sort(points.begin(), points.end(), sortY);
}

void PointSet::sortDistances() {
	std::sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
	sortDistances();
	double distinctCount = distance(distances.begin(), (unique(distances.begin(), distances.end())));
	return distinctCount;
}

bool sortX(Point p1, Point p2) {
	return p1.getX() < p2.getX();
}

bool sortY(Point p1, Point p2) {
	return p1.getY() < p2.getY();
}
