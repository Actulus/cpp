//
// Created by Pati on 10/20/2022.
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) {
	this->mCols = mCols;
	this->mRows = mRows;

	mElements = new double *[mRows];
	for (int i = 0; i < mRows; ++i) {
		mElements[i] = new double[mCols];
	}
}

Matrix::Matrix(const Matrix &what) {
	mCols = what.mCols;
	mRows = what.mRows;

	mElements = new double *[mRows];
	for (int i = 0; i < mRows; ++i) {
		mElements[i] = new double[mCols];
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = what.mElements[i][j];
		}
	}
}

Matrix::Matrix(Matrix &&what) {
	mCols = what.mCols;
	mRows = what.mRows;

	mElements = what.mElements;

	what.mElements = nullptr;
	what.mRows = 0;
	what.mCols = 0;
}

Matrix::~Matrix() {
	for (int i = 0; i < mRows; ++i) {
		delete[] mElements[i];
	}
	delete[] mElements;
	mRows = 0;
	mCols = 0;
}

void Matrix::fillMatrix(double value) {
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = value;
		}
	}
}

void Matrix::randomMatrix(int a, int b) {
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = a + (rand() % (b - a));
		}
	}
}

void Matrix::printMatrix(ostream &os) const {
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			os << mElements[i][j] << " ";
		}
		os << endl;
	}
}

bool Matrix::isSquare() const {
	return (mRows == mCols);
}

Matrix operator+(const Matrix &x, const Matrix &y) {
	Matrix temp(x.mRows, x.mCols);
	if (x.mRows == y.mRows && x.mCols == y.mCols) {
		for (int i = 0; i < x.mRows; ++i) {
			for (int j = 0; j < x.mCols; ++j) {
				temp.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
			}
		}
	} else {
		throw out_of_range("Different dimensions!");
	}
	return temp;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
	Matrix temp(x.mRows, y.mCols);
	if (x.mCols == y.mRows) {
		for (int i = 0; i < x.mRows; ++i) {
			for (int j = 0; j < y.mCols; ++j) {
				temp.mElements[i][j] = 0;
				for (int k = 0; k < y.mRows; ++k) {
					temp.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
				}
			}
		}
	} else {
		throw out_of_range("Not compatible!");
	}
	return temp;
}

istream &operator>>(istream &is, Matrix &mat) {
	for (int i = 0; i < mat.mRows; ++i) {
		for (int j = 0; j < mat.mCols; ++j) {
			is >> mat.mElements[i][j];
		}
	}

	return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
	for (int i = 0; i < mat.mRows; ++i) {
		for (int j = 0; j < mat.mCols; ++j) {
			os << mat.mElements[i][j] << " ";
		}
		os << endl;
	}

	return os;
	//or use printMatrix
	//mat.printMatrix(os);
}

double *Matrix::operator[](int index) {
	return mElements[index];
}

double *Matrix::operator[](int index) const {
	return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
	if (mat.mRows == this->mRows && mat.mCols == this->mCols) {
		for (int i = 0; i < this->mRows; ++i) {
			for (int j = 0; j < this->mCols; ++j) {
				this->mElements[i][j] = mat.mElements[i][j];
			}
		}
	} else {
		throw out_of_range("Different dimensions!");
	}
	return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
	//sajat mElements felszabaditas
	for (int i = 0; i < mRows; ++i) {
		delete[] mElements[i];
	}
	delete[] mElements;
	mRows = 0;
	mCols = 0;

	//mElements feluliras
	mCols = mat.mCols;
	mRows = mat.mRows;

	mElements = mat.mElements;

	mat.mElements = nullptr;
	mat.mRows = 0;
	mat.mCols = 0;

	return *this;
}
