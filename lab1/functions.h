//
// Created by Pati on 9/22/2022.
//

#ifndef LAB1_FUNCTIONS_H
#define LAB1_FUNCTIONS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cmath>
#include <limits>
#include <utility>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream> // stringstream, istringstream, ostringstream

using namespace std;

void fuggvenyek();
void fel1();
int countBits(int number);
void bitsFrom1To127();
void fel2(int, int);
bool setBit(int &number, int order);
double mean(double array[], int numElements);
double fel3();
double fel4();
double stddev(double array[], int numElements);
void fel5();
void makeArray(double *a, int n);
void printArray(double *a, int n);
pair<double, double> max2(double array[], int numElements);
int cmp(const void *a, const void *b);

void karakterlancok();
void stringSum(const string &s);
int countWords(const string &text);
string code(const string &text);
string decode(const string &text);
string capitalizeWords(string text);

void extra(char **);

#endif //LAB1_FUNCTIONS_H
