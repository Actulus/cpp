//
// Created by Pati on 10/1/2022.
//

#ifndef LAB2_UTIL_H
#define LAB2_UTIL_H

#include "Point.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cfloat>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
int compareX(const void* e1, const void* e2);
int compareY(const void* e1, const void* e2);
double smallestDist(Point points[], int nrPoints);
double min(double x, double y);
double stripClosest(Point strip[], int size, double d);
double closestUtil(Point pointsByX[], Point pointsByY[], int nrPoints);
double closest(Point points[], int nrPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
double farthestUtil(Point pointsByX[], Point pointsByY[], int nrPoints);
double biggestDist(Point points[], int nrPoints);
double max(double x, double y);
double stripFarthest(Point strip[], int size, double d);
double farthest(Point points[], int nrPoints);
bool sortX(Point e1, Point e2);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);

#endif //LAB2_UTIL_H
