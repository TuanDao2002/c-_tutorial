#include "NonAcaDept.h"

NonAcaDept::NonAcaDept(string name, string location, vector<Staff*> staffs, int numOfServices) : Department(name, location, staffs) {
    this->numOfServices = numOfServices;
}

void NonAcaDept::showInfo() {
    Department::showInfo();
    std::cout << "> Num of servies: " << numOfServices  << std::endl;
}