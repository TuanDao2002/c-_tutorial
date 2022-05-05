#pragma once

#include <iostream>
#include <vector>

#include "Staff.h"

using std::vector;
using std::string;

class Department {
    private:
        string name;
        string location;
        vector<Staff*> staffs;
    public:
        Department(){};
        Department(string name, string location, vector<Staff*> staffs);    

        void showInfo();

        friend class Staff;
}; 