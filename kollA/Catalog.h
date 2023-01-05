//
// Created by Pati on 1/4/2023.
//

#ifndef KOLLA_CATALOG_H
#define KOLLA_CATALOG_H

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Subject {
	Subject(string basicString);
	string name;
	vector<int> grades;
};

class Catalog {
//	int id;
//	string subject;
//	double grade;
	//static int counter;
	map<int, set<pair<string, vector<int>>>> grades;
public:
	bool subject_compare(const Subject &s1, const Subject &s2) {
		return s1.name < s2.name;
	}
	void readGrades(const string &filename);
	set<int> getIds() const;
	int getNumStudtents() const;
	set<string> getStudentSubjects(int id) const;
	double getStudentSubjectAverage(int id, const string &subject) const;
	map<string, double> getStudentSubjectsAverages(int id) const;
	double getStudentGeneralAverage(int id) const;
};

#endif //KOLLA_CATALOG_H
