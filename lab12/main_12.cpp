#include <iostream>
#include "GraduationDao.h"
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"

string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

void admin();
void test();

int main() {
	admin();
	test();
	return 0;
}

void admin() {
	// region ADMIN
	GraduationDao *dao = new GraduationDaoImpl();
	dao->enrollStudents("names.txt");
	cout << "Number of enrolled students: " << dao->numEnrolled() << endl;

	for (int i = 0; i < numSubjects; ++i) {
		dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
	}
	dao->computeAverage();

	cout << "Subject's averages: " << endl;
	try {
		for (int i = 0; i < numSubjects; ++i) {
			cout << "\taverage(" << subjects[i] << "): " << dao->getAverageBySubject(subjects[i]) << endl;
		}
	} catch (domain_error &e) {
		cerr << e.what() << endl;
	}
	cout << "Individual results: " << endl;
	int id = 0;
	while (id != -1) {
		cout << "Enter ID (-1 for EXIT): ";
		cin >> id;
		if (id == -1) {
			break;
		}
		cout << "Student id=" << id << " results: " << endl;
		try {
			auto results = dao->findById(id);
			for_each(results.getGrades().begin(), results.getGrades().end(), [](const pair<string, double> &e) {
				cout << "\t" << e.first << " : " << e.second << endl;
			});
		} catch (out_of_range &e) {
			cerr << e.what() << endl;
		}
	}

	delete dao;
	//endregion
}

void test() {
	//region TEST
	GraduationDao *dao = new GraduationDaoImpl();
	dao->enrollStudents("names.txt");
	for (int i = 0; i < numSubjects; ++i) {
		dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
	}
	dao->computeAverage();
	GraduationService *service = new GraduationServiceImpl(dao);
	// tesztelés
	int id = 7;
	string subject = subjects[0];
	cout << "Student's data with id =  " << id << endl;
	cout << service->findById(7) << endl;
	cout << "Student's id = " << id << " their grade in " << subject << " is ";
	cout << service->getResultByIdAndSubject(id, subject) << endl;

	delete dao;
	delete service;
	//endregion
}