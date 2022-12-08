cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 23)
project(lab12)
add_executable(lab12 main_12.cpp GraduationDao.h GraduationDaoImpl.cpp GraduationDaoImpl.h Student.cpp Student.h)