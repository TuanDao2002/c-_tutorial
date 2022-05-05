#include <iostream>
#include "Department.h"

class AcaDept : public Department {
    private:
        int numOfCourses;
    public:
        AcaDept(){}
        AcaDept(string name, string location, vector<Staff*> staffs, int numOfCourses);

        void showInfo();
};