//
// Created by Pati on 10/27/2022.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
	this->capacity = degree + 1;
	this->coefficients = new double[this->capacity];
	for (int i = 0; i < this->capacity; ++i) {
		this->coefficients[i] = coefficients[i];
	}
}
Polynomial::Polynomial(const Polynomial &that) {
	this->capacity = that.capacity;
	this->coefficients = new double[this->capacity];
	for (int i = 0; i < this->capacity; ++i) {
		this->coefficients[i] = that.coefficients[i];
	}
}
Polynomial::Polynomial(Polynomial &&that) noexcept {
	this->capacity = 0;
	delete[] this->coefficients;

	this->capacity = that.capacity;
	this->coefficients = that.coefficients;

	that.capacity = 0;
	that.coefficients = nullptr;
}
Polynomial::~Polynomial() {
	this->capacity = 0;
	try {
		delete[] this->coefficients;
	} catch (exception e) {
		cout << e.what();
	}
	this->coefficients = nullptr;
}
int Polynomial::degree() const {
	return this->capacity - 1;
}
double Polynomial::evaluate(double x) const {
	double result = this->coefficients[0];
	//cout << result << " ";
	for (int i = 1; i < this->capacity; ++i) {
		result = result * x + this->coefficients[i];
		//cout << result << " ";
	}
	return result;
}
Polynomial Polynomial::derivative() const {
	int tempCap = this->capacity - 1;
	int derCap = this->capacity - 1;
	auto *derCoeffs = new double[derCap];

	for (int i = 0; i < this->capacity - 1; ++i) {
		//cout << coefficients[i] << " ;" << tempCap << " ->";
		derCoeffs[i] = this->coefficients[i] * tempCap;
		--tempCap;
		//cout << derCoeffs[i] << "\n";
	}

	/*for (int i = 0; i < derCap; ++i) {
		cout << derCoeffs[i] << " ";
	}*/
	Polynomial derPoly(derCap - 1, derCoeffs);
	return derPoly;
}
double Polynomial::operator[](int index) const {
	return coefficients[index];
}
Polynomial operator-(const Polynomial &a) {
	auto *neg = new double[a.capacity];
	for (int i = 0; i < a.capacity; ++i) {
		neg[i] = a.coefficients[i] * (-1);
	}

	return Polynomial(a.capacity - 1, neg);
}
Polynomial operator+(const Polynomial &a, const Polynomial &b) {
	int tempCap = max(a.capacity, b.capacity);
	auto *sum = new double[tempCap];
	int j = tempCap - 1;
	for (int i = a.capacity - 1; i >= 0; --i) {
		sum[j] = a.coefficients[i];
		--j;
	}
	j = tempCap - 1;
	for (int i = b.capacity - 1; i >= 0; --i) {
		sum[j] += b.coefficients[i];
		--j;
	}

	return Polynomial(tempCap - 1, sum);
}
Polynomial operator-(const Polynomial &a, const Polynomial &b) {
	int tempCap = max(a.capacity, b.capacity);
	auto *diff = new double[tempCap];

	int j = tempCap - 1;
	for (int i = a.capacity - 1; i >= 0; --i) {
		diff[j] = a.coefficients[i];
		--j;
	}
	j = tempCap - 1;
	for (int i = b.capacity - 1; i >= 0; --i) {
		diff[j] -= b.coefficients[i];
		--j;
	}

	return Polynomial(tempCap - 1, diff);
}
Polynomial operator*(const Polynomial &a, const Polynomial &b) {
	int tempCap = a.capacity + b.capacity - 1;
	auto *product = new double[tempCap];


	for (int i = 0; i < a.capacity; ++i) {
		for (int j = 0; j < b.capacity; ++j) {
			product[i + j] += a.coefficients[i] * b.coefficients[j];
		}
	}

	return Polynomial(tempCap - 1, product);
}
ostream &operator<<(ostream &out, const Polynomial &what) {
	for (int i = 0; i < what.capacity; ++i) {
		out << what.coefficients[i];
		if (i != what.capacity - 1) {
			out << "x^" << what.degree() - i;
		}
		if (i != what.capacity - 1) {
			out << " + ";
		}
	}
	return out;
}
