//
// Created by Pati on 12/8/2022.
//

#include "GraduationServiceImpl.h"

GraduationServiceImpl::GraduationServiceImpl(GraduationDao *newdao) : dao(newdao) {}

Student GraduationServiceImpl::findById(int id) const {
	return this->dao->findById(id);
}
double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const {
	return this->dao->findById(id).getGrade(subject);
}
