//
// Created by Pati on 10/20/2022.
//

#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class Matrix {
public:
//Methods
// Default constructor
	Matrix( int mRows = 10, int mCols =10);
// Copy constructor
	Matrix(const Matrix& what);
// Move constructor
	Matrix( Matrix&& what );
// Destructor
	~Matrix();

//fills the matrix with identical elements
	void fillMatrix(double value);
//fills the matrix with random real numbers in the range [a, b)
	void randomMatrix(int a, int b); //fills
//prints the matrix
	void printMatrix(ostream& os = cout) const;

//checks whether this matrix is a square one
	bool isSquare() const;
	int getRows() const { return this->mRows;}
	int getCols() const { return this->mCols;}

// operation is permitted on matrices having the same dimensions
// otherwise throws an out_of_range exception!!
	friend Matrix operator+(const Matrix& x, const Matrix& y);
// operation is permitted on matrices having proper dimensions
// otherwise throws an out_of_range exception!!
	friend Matrix operator*(const Matrix& x, const Matrix& y);

// extractor operator
	friend istream & operator>>(istream& is, Matrix& mat);
// inserter operator
	friend ostream & operator<<(ostream& os, const Matrix& mat);

// index operator
	double* operator[] (int index);
// index operator that works on constant matrices!
	double* operator[] (int index) const;

// Copy assignment
// operation is permitted between matrices having the same dimensions
// otherwise throws an exception (out_of_range)
	Matrix & operator=(const Matrix& mat);
// Move assignment
	Matrix & operator=(Matrix&& mat);

private:
//Data
	double ** mElements;
	int mRows; //number of rows
	int mCols; //number of columns
};


#endif //LAB5_MATRIX_H
