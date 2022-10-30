//
// Created by Pati on 10/27/2022.
//

#include "functions.h"

int fel1_point() {
	Point p1(1, 2), p2;
	cout << Point::getCounter() << endl;// Eredmény: 2
	Point p3 = p1;
	Point p4(p2);
	cout << Point::getCounter() << endl;// Eredmény: 4
	Point *p5 = new Point(3, 3);
	cout << Point::getCounter() << endl;// Eredmény: 5
	delete p5;
	cout << Point::getCounter() << endl;// Eredmény: 4
	return 0;
}

Matrix createSquareMatrix(int size) {
	Matrix m(size, size);
	m.fillMatrix(1);
	return m;
}

int fel2_matrix() {
	srand(time_t(NULL));
	cout << "******************************************************************" << endl;
	cout << "Constructor " << endl;
	cout << "******************************************************************" << endl;
	Matrix m1(2, 3);
	m1.fillMatrix(5);
	cout << "m1: " << endl;
	m1.printMatrix();
	cout << endl;
	cout << "******************************************************************" << endl;
	cout << "+ operator - equal sizes " << endl;
	cout << "******************************************************************" << endl;
	Matrix m2(2, 3);
	m2.fillMatrix(2);
	cout << "m2: " << endl << m2 << endl;
	try {
		cout << "Matrix m3 = m1 + m2: " << endl;
		Matrix m3 = (m1 + m2);
		cout << "m3: " << endl << m3 << endl;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	cout << "******************************************************************" << endl;
	cout << "+ operator - different sizes " << endl;
	cout << "******************************************************************" << endl;
	Matrix m3(5, 5);
	m3.fillMatrix(1);
	cout << "m3: " << endl << m3 << endl;
	try {
		cout << "m1+m3:" << endl;
		cout << "m1+m3: " << endl << m1 + m3 << endl;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	cout << "******************************************************************" << endl;
	cout << "copy assignment - different sizes " << endl;
	cout << "******************************************************************" << endl;
	try {
//copy assignment
		cout << "m3 = m1" << endl;
		m3 = m1;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	cout << "m3: " << endl;
	cout << m3 << endl;
	cout << "******************************************************************" << endl;
	cout << "Extractor operator " << endl;
	cout << "******************************************************************" << endl;
	Matrix m4(1, 2);
	cout << "Please type in two real numbers for m4[0][0] and m4[0][1]: " << endl;
//Extractor operator
	cin >> m4;
//Inserter operator
	cout << "m4: " << endl << m4 << endl;
	cout << "******************************************************************" << endl;
	cout << "Index operator " << endl;
	cout << "******************************************************************" << endl;
//Index operator
	cout << endl << "m4[0][0]: " << m4[0][0] << endl;
	cout << "******************************************************************" << endl;
	cout << "* operator " << endl;
	cout << "******************************************************************" << endl;
	Matrix m5(2, 1);
	m5.fillMatrix(1);
	cout << "M4: " << endl << m4 << endl;
	cout << "M5: " << endl << m5 << endl;
	cout << "Multiplication: ";
	try {
		cout << "M4 x M5: " << endl << m4 * m5 << endl;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	cout << "******************************************************************" << endl;
	cout << " = operator -- copy assignment " << endl;
	cout << "******************************************************************" << endl;
	Matrix m6(m4);
	cout << "m6 created as a copy of m4 using copy constructor: " << endl << m6 << endl;
	try {
		cout << "m1 = m6 = m6" << endl;
		m1 = m6 = m6;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	cout << "******************************************************************" << endl;
	cout << "MOVE constructor " << endl;
	cout << "******************************************************************" << endl;
	Matrix mx(3, 2), my(2, 3);
	mx.fillMatrix(1);
	my.fillMatrix(2);
	cout << "mx: " << endl << mx << endl;
	cout << "my: " << endl << my << endl;
//Move constructor
	cout << "Matrix mz1 = std::move(mx * my);\n";
	Matrix mz1 = std::move(mx * my);
	mz1.printMatrix(cout);
	Matrix mz2 = std::move(createSquareMatrix(3));
	cout << "Matrix mz2 = std::move(createSquareMatrix(3))\n";
	mz2.printMatrix(cout);
	cout << "******************************************************************" << endl;
	cout << "MOVE assignment " << endl;
	cout << "******************************************************************" << endl;
	try {
		cout << "mx: " << mx.getRows() << " x " << mx.getCols() << endl;
		cout << mx << endl;
		cout << "my: " << my.getRows() << " x " << my.getCols() << endl;
		cout << my << endl;
		cout << "m6 = mx * my: " << endl;
		m6 = mx * my;
		cout << "m6: " << m6.getRows() << " x " << m6.getCols() << endl;
		cout << m6 << endl;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	return 0;
}
int fel3_polinom() {
	cout << "\nPolynomial class\n";
	double d[]{3, 4, 2, 5};
	Polynomial poly(3, d);

	cout << "\nEvaluate\n";
	cout << "P[x] = " << d[0] << "x^3 + " << d[1] << "x^2 + " << d[2] << "x + " << d[3] << endl;
	cout << "P[3] = ";
	cout << poly.evaluate(3);
	cout << endl;

	cout << "\nDerivation\n";
	Polynomial pDer = poly.derivative();
	cout << "P'[x] = " << pDer[0] << "x^2 + " << pDer[1] << "x + " << d[2] << endl;
	cout << "P'[3] = ";
	cout << pDer.evaluate(3);
	cout << endl;

	cout << "\nIndex operator []\n";
	cout << "First coefficient of P, poly[0]: " << poly[0] << endl;

	cout << "\nOutput stream operator <<\n";
	cout << "P[x] = " << poly << endl;

	cout << "\nNegation -\n";
	cout << "-poly[0] = " << -poly[0] << endl;

	cout << "\nAddition +\n";
	double d1[]{2, 4, 6, 8};
	double d2[]{3, 5, 7};
	Polynomial p1(3, d1);
	Polynomial p2(2, d2);

	cout << "P1 + P2 = \n";
	cout << p1 << " + \n";
	cout << p2 << " = \n";
	cout << p1 + p2;
	cout << "\n\n";

	cout << "P2 + P1 = \n";
	cout << p2 << "\n" << " + \n";
	cout << p1 << "\n" << " = \n";
	cout << p2 + p1;
	cout << "\n\n";

	cout << "\nSubtraction -\n";
	double d3[]{2, 4, 6, 8};
	double d4[]{3, 5, 7};
	Polynomial p3(3, d3);
	Polynomial p4(2, d4);

	cout << "P3 - P4 = \n";
	cout << p3 << "\n" << " - \n";
	cout << p4 << "\n" << " = \n";
	cout << p3 - p4;
	cout << "\n\n";

	cout << "P4 - P3 = \n";
	cout << p4 << "\n" << " - \n";
	cout << p3 << "\n" << " = \n";
	cout << p4 - p3;
	cout << "\n\n";

	cout << "\nMultiplication\n";
	double d5[]{1, -1};
	double d6[]{1, 1};
	Polynomial p5(1, d5);
	Polynomial p6(1, d6);

	cout << "P5 * P6 = \n";
	cout << p5 << "\n" << " * \n";
	cout << p6 << "\n" << " = \n";
	cout << p5 * p6;
	cout << "\n\n";

	cout << "P6 * P5 = \n";
	cout << p6 << "\n" << " * \n";
	cout << p5 << "\n" << " = \n";
	cout << p6 * p5;
	cout << "\n\n";

	return 0;
}

