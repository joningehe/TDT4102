//
//  Course_catalog.hpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 19/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#include "std_lib_facilities.h"
class Course_catalog {
    std::map<std::string, std::string> emne_liste;
public:
    void addCourse();
    void removeCourse();
    std::string getCourse();
    friend ostream& operator << (ostream& output, const Course_catalog& emner);
    void read();
    void write();
    void read_and_write();
};

