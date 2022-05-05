#include "Department.h"

Department::Department(string name, string location, vector<Staff*> staffs) {
    this->name = name;
    this->location = location;
    this->staffs = staffs;
}

void Department::showInfo() {
    std::cout   << "\nDept Name = " << name
                << "\n> Location = " << location
                << "\n> Current staffs: \n";

    for (auto eachStaff: staffs){
        std::cout << "\t" << eachStaff->name << "\n";
    }
}