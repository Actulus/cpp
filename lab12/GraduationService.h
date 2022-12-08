//
// Created by Pati on 12/8/2022.
//

#ifndef LAB12_GRADUATIONSERVICE_H
#define LAB12_GRADUATIONSERVICE_H

#include "Student.h"

class GraduationService {
public:
	virtual Student findById(int id) const = 0;
	virtual double getResultByIdAndSubject(int id,
	                                       const string &subject) const = 0;
};


#endif //LAB12_GRADUATIONSERVICE_H
