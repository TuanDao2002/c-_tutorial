#include "AcaDept.h"

AcaDept::AcaDept(string name, string location, vector<Staff*> staffs, int numOfCourses) : Department(name, location, staffs) {
    this->numOfCourses = numOfCourses;
}

void AcaDept::showInfo() {
    Department::showInfo();
    std::cout << "> Num of courses: " << numOfCourses << std::endl;
}
