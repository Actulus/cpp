//
// Created by Pati on 1/4/2023.
//

#include "Catalog.h"

//int Catalog::counter = {1};

void Catalog::readGrades(const string &filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		throw runtime_error("Cannot open file");
	}

	int id, grade;
	string subject;
	set<pair<string, vector<int>>> temp;
	vector<int> temp2;
	while (fin.good()) {
		fin >> id >> subject >> grade;
		//cout << id << subject << grade << endl;
		grades.insert({id, temp});
		grades.at(id).insert({{subject, {grade}}});
	}

	for (auto i: grades) {
		cout << i.first << ". Student";
		for (auto j: i.second) {
			cout << "\n\t" << j.first << " ";;
			for (auto g: j.second) {
				cout << g << " ";
			}
		}
		cout << endl;
	}

	fin.close();
}
Subject::Subject(string basicString) {
	this->name = basicString;
	vector<int> temp;
	this->grades = temp;
}
