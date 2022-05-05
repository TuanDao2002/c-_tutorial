#include <iostream>
#include "Staff.h"
#include "Department.h"
#include "NonAcaDept.h"
#include "AcaDept.h"

int main(){
    Staff staff1("staff 1", "");
    Staff staff2("staff 2", "");
    Staff staff3("staff 3", "");

    NonAcaDept dept1("SSET", "Building 2", vector<Staff*>{}, 2);
    AcaDept dept2("ITS",  "Building 1", vector<Staff*>{}, 10);

    staff1.joinDept(dept1);
    staff2.joinDept(dept2);
    staff3.joinDept(dept1);
    dept1.showInfo();
    dept2.showInfo();
    return 0;
}