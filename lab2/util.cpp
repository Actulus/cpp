//
// Created by Pati on 10/1/2022.
//

#include "util.h"


//4
double distance(const Point& a, const Point& b){
	double d = sqrt(pow((b.getX() - a.getX()), 2) + pow((b.getY() - a.getY()), 2));
	return d;
}

//5
bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
	if(distance(a,b) != distance(c,d)) return false;
	if(distance(a,c) != distance(b,d)) return false;
	if(distance(a,d) != distance(a,b)) return false;
	if(distance(a,b) == 0) return false;
	return true;
}

//6
void testIsSquare(const char * filename){
	std::ifstream fin(filename);
	if(fin.fail()){
		std::cout << "file does not exist";
		return;
	}

	Point *a, *b, *c, *d;
	int nr1, nr2, nr3, nr4, nr5, nr6, nr7, nr8;

	while (!fin.eof()){
		fin >> nr1 >> nr2 >> nr3 >> nr4 >> nr5 >> nr6 >> nr7 >> nr8;
		//std::cout << nr1 << " " << nr2 << " " << nr3 << " "  << nr4 << " " << nr5 << " " << nr6 << " " << nr7 << " " << nr8 << std::endl;
		a = new Point(nr1, nr2);
		b = new Point(nr3, nr4);
		c = new Point(nr5, nr6);
		d = new Point(nr7, nr8);

		a->print();
		cout << ", ";
		b->print();
		cout << ", ";
		c->print();
		cout << ", ";
		d->print();
		cout << " -> ";
		if(isSquare(*a,*b,*c,*d)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	delete(a);
	delete(b);
	delete(c);
	delete(d);
}

//7
Point* createArray(int numPoints){
	Point * points = new Point[numPoints];

	int xi, yi, min = 0, max = 2000;
	for (int i = 0; i < numPoints; ++i) {
		xi = min + (rand() % (max - min) + 1);
		yi = min + (rand() % (max - min) + 1);
		points[i] = {xi, yi};
	}

	return points;
}

//8
void printArray(Point* points, int numPoints){
	cout<<"\nThe array's elements:"<<endl;
	for (int i = 0; i < numPoints; ++i) {
		points[i].print();
		cout<<endl;
	}
}

//9
pair<Point, Point> closestPoints(Point* points, int numPoints){
	pair<Point, Point> closestPair;

	double min_dist = closest(points, numPoints);

	for (int i = 0; i < numPoints; ++i) {
		for (int j = i+1; j < numPoints; ++j) {
			if(distance(points[i], points[j]) == min_dist){
				closestPair.first = points[i];
				closestPair.second = points[j];
			}
		}
	}

	return closestPair;
}

int compareX(const void* e1, const void* e2){
	Point *p1 = (Point*) e1, *p2 = (Point*)e2;
	return (p1->getX() != p2->getX()) ? (p1->getX() - p2->getX()) : (p1->getY() - p2->getY());
}

int compareY(const void* e1, const void* e2){
	Point *p1 = (Point*) e1, *p2 = (Point*)e2;
	return (p1->getY() != p2->getY()) ? (p1->getY() - p2->getY()) : (p1->getX() - p2->getX());
}

double smallestDist(Point points[], int nrPoints){
	double min = DBL_MAX;
	for (int i = 0; i < nrPoints; ++i) {
		for (int j = i+1; j < nrPoints; ++j) {
			if(distance(points[i], points[j]) < min){
				min = distance(points[i], points[j]);
			}
		}
	}
	return min;
}

//returns the smaller
double min(double x, double y){
	return (x < y) ? x : y;
}

//distance between the closest points of strip of a given size
double stripClosest(Point strip[], int size, double d){
	double min = d;

	for (int i = 0; i < size; ++i) {
		for (int j = i+1; j < size && (strip[j].getY() - strip[i].getY()) < min; ++j) {
			if(distance(strip[i], strip[j]) < min){
				min = distance(strip[i], strip[j]);
			}
		}
	}

	return min;
}

double closestUtil(Point pointsByX[], Point pointsByY[], int nrPoints){
	if(nrPoints <= 3){
		return smallestDist(pointsByX, nrPoints);
	}

	int mid = nrPoints/2;
	Point midPoint = pointsByX[mid];

	// Divide points in y sorted array around the vertical line.
	Point pY1[mid]; // y sorted points on left of vertical line
	Point pYR[nrPoints-mid]; // y sorted points on right of vertical line
	int li = 0, ri = 0;
	for (int i = 0; i < nrPoints; ++i) {
		if((pointsByY[i].getX() < midPoint.getX() || (pointsByY[i].getX() == midPoint.getX() && pointsByY[i].getY() < midPoint.getY())) && li < mid){
			pY1[li++] = pointsByY[i];
		} else {
			pYR[ri++] = pointsByY[i];
		}
	}

	//smallest distance on left and right side, vertical line passing through middle point
	double dl = closestUtil(pointsByX, pY1, mid);
	double dr = closestUtil(pointsByX + mid, pYR, nrPoints - mid);

	double d = min(dl, dr);

	//strip[] contains points close to the line passing through the middle point
	Point strip[nrPoints];
	int j = 0;
	for (int i = 0; i < nrPoints; ++i) {
		if(abs(pointsByY[i].getX() - midPoint.getX()) < d){
			strip[j] = pointsByY[i];
			++j;
		}
	}

	//closest distance in strip and minimum of d
	return stripClosest(strip, j, d);
}

//main function that finds the smallest distance
double closest(Point points[], int nrPoints){
	Point pointsByX[nrPoints];
	Point pointsByY[nrPoints];

	for (int i = 0; i < nrPoints; ++i) {
		pointsByX[i] = points[i];
		pointsByY[i] = points[i];
	}

	qsort(pointsByX, nrPoints, sizeof(Point), compareX);
	qsort(pointsByY, nrPoints, sizeof(Point), compareY);

	return closestUtil(pointsByX, pointsByY, nrPoints);
}

//10
pair<Point, Point> farthestPoints(Point* points, int numPoints){
	pair<Point, Point> farthestPair;

	double max_dist = farthest(points, numPoints);

	for (int i = 0; i < numPoints; ++i) {
		for (int j = i+1; j < numPoints; ++j) {
			if(distance(points[i], points[j]) == max_dist){
				farthestPair.first = points[i];
				farthestPair.second = points[j];
			}
		}
	}
	return farthestPair;
}

double farthest(Point points[], int nrPoints){
	Point pointsByX[nrPoints];
	Point pointsByY[nrPoints];

	for (int i = 0; i < nrPoints; ++i) {
		pointsByX[i] = points[i];
		pointsByY[i] = points[i];
	}

	qsort(pointsByX, nrPoints, sizeof(Point), compareX);
	qsort(pointsByY, nrPoints, sizeof(Point), compareY);

	return farthestUtil(pointsByX, pointsByY, nrPoints);
}

double farthestUtil(Point pointsByX[], Point pointsByY[], int nrPoints){
	if(nrPoints <= 3){
		return biggestDist(pointsByX, nrPoints);
	}

	int mid = nrPoints/2;
	Point midPoint = pointsByX[mid];

	// Divide points in y sorted array around the vertical line.
	Point pY1[mid]; // y sorted points on left of vertical line
	Point pYR[nrPoints-mid]; // y sorted points on right of vertical line
	int li = 0, ri = 0;
	for (int i = 0; i < nrPoints; ++i) {
		if((pointsByY[i].getX() < midPoint.getX() || (pointsByY[i].getX() == midPoint.getX() && pointsByY[i].getY() < midPoint.getY())) && li < mid){
			pY1[li++] = pointsByY[i];
		} else {
			pYR[ri++] = pointsByY[i];
		}
	}

	//biggest distance on left and right side, vertical line passing through middle point
	double dl = farthestUtil(pointsByX, pY1, mid);
	double dr = farthestUtil(pointsByX + mid, pYR, nrPoints - mid);

	double d = max(dl, dr);

	//strip[] contains points close to the line passing through the middle point
	Point strip[nrPoints];
	int j = 0;
	for (int i = 0; i < nrPoints; ++i) {
		if(abs(pointsByY[i].getX() - midPoint.getX()) > d){
			strip[j] = pointsByY[i];
			++j;
		}
	}

	//closest distance in strip and minimum of d
	return stripFarthest(strip, j, d);
}

double biggestDist(Point points[], int nrPoints){
	double max = DBL_MIN;
	for (int i = 0; i < nrPoints; ++i) {
		for (int j = i+1; j < nrPoints; ++j) {
			if(distance(points[i], points[j]) > max){
				max = distance(points[i], points[j]);
			}
		}
	}
	return max;
}

double max(double x, double y){
	return (x > y) ? x : y;
}

double stripFarthest(Point strip[], int size, double d){
	double max = d;

	for (int i = 0; i < size; ++i) {
		for (int j = i+1; j < size && (strip[j].getY() - strip[i].getY()) > max; ++j) {
			if(distance(strip[i], strip[j]) > max){
				max = distance(strip[i], strip[j]);
			}
		}
	}

	return max;
}

//11
bool sortX(Point e1, Point e2){
	return e1.getX() < e2.getX();
}

void sortPoints(Point* points, int numPoints){
	sort(points, points + numPoints, sortX);
	cout << "\nThe sorted array (by X): \n";
	for (int i = 0; i < numPoints; ++i) {
		points[i].print();
		cout<<endl;
	}
}

//12
Point* farthestPointsFromOrigin(Point* points, int numPoints){
	int k = 11;
	auto* pFarthest = new Point[k];
	map <int, int> mp;
	for (int i = 0; i < numPoints; i++) {
		int x = points[i].getX(), y = points[i].getY();
		mp.insert({(x * x) + (y * y), i});
	}

	map <int,int>::reverse_iterator it;
	int index = 0;

	for(it = mp.rbegin(); it != mp.rend() && k > 0; it++, k--){
		pFarthest[index] = {points[it->second].getX(), points[it->second].getY()};
		index++;
	}

	return pFarthest;
}

//13
void deletePoints(Point* points){
	delete[] points;
}
