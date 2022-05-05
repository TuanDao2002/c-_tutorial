#include <iostream>
#include "Department.h"

class NonAcaDept : public Department {
    private:    
        int numOfServices;      
    public:
        NonAcaDept(){}
        NonAcaDept(string name, string location, vector<Staff*> staffs, int numOfServices);

        void showInfo();
};