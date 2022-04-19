#include <iostream>
#include <vector>
#include "Staff.h"
#include "Department.h"


// implementation for Staff
Staff::Staff(){}

Staff::Staff(std::string name) {
    this->name = name;
}

void Staff::join(Department department) {
    this->department = department;
}

void Staff::leave() {
    if (department.getName() != "NA" && department.getLocation() != "NA") {
        Department none;
        this->department = none;
    } else {
        std::cerr << "No department to leave" << std::endl;
    }
}

void Staff::showInfo(){
    std::cout << "Name: " << name << std::endl;
}

// implementation for Department
Department::Department(){
    this->name = "NA";
    this->location = "NA";
};

std::string Department::getName() {
    return name;
}

std::string Department::getLocation() {
    return location;
}

Department::Department(std::string name, std::string location, Staff staff) {
    this->name = name;
    this->location = location;
    this->staffList.push_back(staff);
    staff.join(*this);
}


// implementation for AcademicDepartment
AcademicDepartment::AcademicDepartment(std::string name, std::string location, Staff staff) : Department(name, location, staff){}

void AcademicDepartment::addCourse(Course course) {
    courseList.push_back(course);
}

int AcademicDepartment::courseNum() {
    return courseList.size();
}

// implementation for NonAcaDepartment
NonAcaDepartment::NonAcaDepartment(std::string name, std::string location, Staff staff) : Department(name, location, staff){}

void NonAcaDepartment::addService(Service service) {
    serviceList.push_back(service);
}

int NonAcaDepartment::serviceNum() {
    return serviceList.size();
}

// implementation for Course
Course::Course(std::string name, int credit) {
    this->name = name;
    this->credit = credit;
}

// implementation for Service
Service::Service(std::string name) {
    this->name = name;
}

int main(){
    Staff s1("tuan");
    s1.showInfo();

    Department dep("rmit", "hcm city", s1);
    
    Staff s2("khatun");
    Course c1("sed", 12);
    AcademicDepartment aca1("rmit", "district 7", s2);
    aca1.addCourse(c1);
    std::cout << "Number of courses: " << aca1.courseNum() << std::endl;

    Staff s3("tuan dao");
    Service ser1("studying");
    NonAcaDepartment non1("lhp", "disctrict 5", s3);
    non1.addService(ser1);
    std::cout << "Number of services: " << non1.serviceNum() << std::endl;
    return 0;
}