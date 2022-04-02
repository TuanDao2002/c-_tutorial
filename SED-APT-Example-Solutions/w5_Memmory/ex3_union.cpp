#include <iostream>
#include <cstring>

#define STRSIZE 100
#define STUSIZE 3

union Student {
    char firstName[STRSIZE];
    char fullName[STRSIZE];
};


int main() {
    
    //Qa
    Student std_arr[STUSIZE];

    for (int i = 0; i < STUSIZE; i++) {
        std::cout << "Enter full name for student " << i + 1 << ": ";
        do {
            std::cin.getline(std_arr[i].fullName, sizeof(std_arr[i].fullName));
        } while (strlen(std_arr[i].fullName) == 0);
    }

    //Qb 
    std::cout << "\nAll full names: \n";
    for (Student stu: std_arr) { //Range-based for loop (access by values)
        std::cout << stu.fullName << "\n";
    }

    //Qc
    for (Student &stu: std_arr) { //acccess by reference to modify values
        strcpy(stu.firstName, "NA");
    }

    std::cout << "\nFirst name after changed: \n";
    for (Student stu: std_arr) {
        std::cout << stu.firstName << "\n";
    }

    std::cout << "\nFull name after changing first names: \n";
    //full names were also changed (because they shared the same location with firstnames)
    for (Student stu: std_arr) {
        std::cout << stu.fullName << "\n";
    }


    return 0;
}