#include "util.h"
using namespace std;

int main(int argc, char** argv) {
	srand((unsigned) time(NULL));
	Point p1(2,3);
	cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
	Point p2(100, 200);
	cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
	Point * pp1 = new Point(300, 400);
	Point * pp2 = new Point(500, 1000);
	cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
	cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
	delete pp1;
	delete pp2;

	p1.print();
	cout << "\nDistance between p1" ;
	p1.print();
	cout << " and p2";
	p2.print();
	cout << ": " << distance(p1, p2) << endl;

	//cout << "Is a square? " << boolalpha << isSquare(p1, p2, p1, p2) << endl;
	testIsSquare("points.txt");

	int N = 15;
	Point *points = createArray(N);
	printArray(points, N);

	cout << "\nThe smallest distance is " << closest(points, N) << " between: ";
	closestPoints(points, N).first.print();
	cout << " and ";
	closestPoints(points, N).second.print();

	cout << "\nThe biggest distance is " << farthest(points, N) << " between: ";
	farthestPoints(points, N).first.print();
	cout << " and ";
	farthestPoints(points, N).second.print();

	sortPoints(points, N);

	cout << "\n10 farthest point from Origin:";
	Point *fPFO = farthestPointsFromOrigin(points, N);
	printArray(fPFO, 10);

	deletePoints(points);
	deletePoints(fPFO);
	return 0;
}
