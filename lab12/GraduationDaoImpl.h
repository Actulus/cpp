//
// Created by Pati on 12/8/2022.
//

#ifndef LAB12_GRADUATIONDAOIMPL_H
#define LAB12_GRADUATIONDAOIMPL_H


#include "Student.h"
#include "GraduationDao.h"

class GraduationDaoImpl : public GraduationDao {
	int year{2022};
	map<int, Student> students;
public:
	void enrollStudents(const string &filename) override;

	void saveGradesForSubject(const string &subject, const string &filename) override;

	void computeAverage() override;

	int numEnrolled() const override {
		return students.size();
	}

	int numPassed() const override;

	Student findById(int id) const override {
		return students.at(id);
	}

	double getAverageBySubject(const string &subject) const override;
};


#endif //LAB12_GRADUATIONDAOIMPL_H