//
// Created by Pati on 12/8/2022.
//

#ifndef LAB12_GRADUATIONSERVICEIMPL_H
#define LAB12_GRADUATIONSERVICEIMPL_H

#include "GraduationService.h"
#include "GraduationDao.h"

class GraduationServiceImpl : public GraduationService {
private:
	GraduationDao *dao;

public:
	GraduationServiceImpl(GraduationDao *newdao);
	Student findById(int id) const override;
	double getResultByIdAndSubject(int id, const string &subject) const override;
};


#endif //LAB12_GRADUATIONSERVICEIMPL_H
