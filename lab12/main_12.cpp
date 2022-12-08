#include <iostream>
#include "GraduationDao.h"
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"
#include "SettlementStatisticsImpl.h"

string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

void admin();
void test();
void ex2();

int main() {
	//region ex1
	//admin();
	//test();
	//endregion

	//region ex2
	ex2();
	//endregion
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

void ex2() {
	SettlementStatisticsImpl *set = new SettlementStatisticsImpl("telepulesek.csv");
	cout << "Number of settlementsByCounty is " << set->numSettlements() << endl;
	cout << "Number of counties is " << set->numCounties() << endl;
	string county = "AR";
	cout << "Number of settlementsByCounty in " << county << " is " << set->numSettlementsByCounty(county) << endl;
	cout << "These settlementsByCounty are: " << endl;
	vector<Settlement> settlementsByCounty = set->findSettlementsByCounty(county);
	for (auto i: settlementsByCounty) {
		cout << i;
	}
	cout << endl;
	string name = "Nou";
	vector<Settlement> settlementsByName = set->findSettlementsByName(name);
	cout << "Settlements with the name " << name << " in their name are: " << endl;
	for (auto i: settlementsByName) {
		cout << i;
	}
	cout << endl;
	cout << "Settlement with the county " << county << " and name " << name << " is "
	     << set->findSettlementsByNameAndCounty(name, county) << endl;;
	cout << "The settlement with the max population is " << set->maxPopulationDensity();
	cout << "The settlement with the min population is " << set->minPopulationDensity();

}