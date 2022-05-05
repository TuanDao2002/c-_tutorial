#pragma once

#include <iostream>
using std::string;
//Class Prototype 
//(declare Department class to use this data type in Staff class)
class Department;

class Staff {
private:
    string name;
    string deptName;

public:
    //Constructors
    Staff(){}
    Staff(string name, string deptName){
        this->name = name;
        this->deptName = deptName;
    }

    //Methods: declare first, define later
    //(since the class Deparment is not fully defined above)
    void joinDept(Department &dept);    
    void leaveDept(Department &dept);

    friend class Department; //grant access
};
