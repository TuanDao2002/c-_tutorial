#include <iostream>
#include <string.h>

#define STRSIZE 100

// cannot use std::string as it is an object inside union
union Students {
    char firstName[STRSIZE];
    char fullName[STRSIZE];
};

int main() {
    const int SIZE = 3;

    // question a
    union Students student_arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        // // use strcpy to copy the string to char array
        // strcpy(student_arr[i].fullName, "dao kha ");

        // // use strcat to concat the string to char array
        // // convert int to const char* so it can be concated
        // // using std::to_string(number: int).c_str()
        // strcat(student_arr[i].fullName, std::to_string(i + 1).c_str());

        std::cout << "Enter full name for student " << i + 1 << ": ";
        do {
            std::cin.getline(student_arr[i].fullName, sizeof(student_arr[i].fullName));
        } while (strlen(student_arr[i].fullName) == 0);
    }
    // question b
    for (auto s : student_arr) {
        std::cout << s.firstName << " and " << s.fullName << "\n";
    }

    // question c
    // change first name will also change full name
    for (int i = 0; i < SIZE; i++) {
        strcpy(student_arr[i].firstName, "kha tuan ");
        strcat(student_arr[i].firstName, std::to_string(i + 1).c_str());
    }

    for (auto s : student_arr) {
        std::cout << s.firstName << " and " << s.fullName << "\n";
    }
    return 0;
}