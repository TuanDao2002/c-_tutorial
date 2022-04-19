#pragma once
#include<iostream>
#include<vector>
#include "Department.h"

class Department;
class Staff{
    private:
        std::string name;
        Department department;

    public:
        Staff();

        Staff(std::string name);

        void join(Department department);
        void leave();

        void showInfo();
};