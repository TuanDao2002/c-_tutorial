#include "Staff.h"
// include "Department.h" so class Department in Staff.h can be fully implemented
// Note: cannot include "Department.h" in "Staff.h" as it will cause circular dependency error
#include "Department.h" 

//Define join and leave methods of Staff class
void Staff::joinDept(Department &dept){
    //insert current staff in to the list
    dept.staffs.push_back(this);

    //update the department name of the staff
    deptName = dept.name;
}

void Staff::leaveDept(Department &dept){
    //find and remove current staff from the list
    for (int i = 0; i < dept.staffs.size(); i++) {
        if (dept.staffs[i] == this) {
            dept.staffs.erase(dept.staffs.begin() + i);
        }
    }

    //remove the department name of the staff
    deptName = ""; //assign it by an empty string
}