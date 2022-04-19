#pragma once
#include<iostream>
#include<vector>
#include "Staff.h"
#include "Course.h"
#include "Service.h"

class Staff;
class Department{
    private:
        std::string name;
        std::string location;
        std::vector<Staff> staffList;

    public:
        Department();

        std::string getName();

        std::string getLocation();

        Department(std::string name, std::string location, Staff staff);
};

class AcademicDepartment : public Department{
    private:
        std::vector<Course> courseList;

    public:
        AcademicDepartment(std::string name, std::string location, Staff staff);
        
        void addCourse(Course course);

        int courseNum();
};

class NonAcaDepartment : public Department{
    private:
        std::vector<Service> serviceList;

    public:
        NonAcaDepartment(std::string name, std::string location, Staff staff);
        
        void addService(Service service);

        int serviceNum();
};