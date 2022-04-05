/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Dao Kha Tuan
  ID: s3877347
  Compiler used: gcc 8.1.0
  Created  date: 4/4/2002
  Acknowledgement: None
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#define ARG_NUM 1

// fuction to check if a string is integer
bool is_integer(const char* int_str) {
    int len = std::string(int_str).length();
    for (int i = 0; i < len; i++) {
        if (!isdigit(int_str[i])) {
            return false;
        }
    }

    return true;
}

// funtion to check if a string is double 
bool is_double(const char* float_str) {
    int len = std::string(float_str).length();
    bool dot_flag = false;
    for (int i = 0; i < len; i++) {
        if (!dot_flag && i != 0 && i != len - 1 && float_str[i] == '.') {
            dot_flag = true;
            continue;
        }

        if (!isdigit(float_str[i])) {
            return false;
        }
    }

    return dot_flag;
}

// doubleVal version that takes integer version
int doubleVal(int integer) {
    return integer * 2;
}


// doubleVal version that takes double version
double doubleVal(double double_num) {
    return double_num * 2;
}

// doubleVal version that takes hexadecimal string version
int doubleVal(std::string hex_num) {
    std::stringstream ss;
    int value;

    ss << std::hex << hex_num;
    ss >> value;

    value *= 2;
    return value;
}



int main(int argc, const char* argv[]){
    // print out warning if the number of arguments is not 1
    if (argc != ARG_NUM + 1) {
        std::cerr << "There must be only 1 argument in the command line" << std::endl;
        return -1;
    }

    if (is_integer(argv[1])) { // if the string is integer, use the first version of doubleVal
        std::cout << doubleVal(atoi(argv[1])) << std::endl;
    } else if (is_double(argv[1])){ // if the string is double, use the second version of doubleVal
        std::cout << std::fixed << std::setprecision(2) << doubleVal(atof(argv[1])) << std::endl;
    } else { // otherwise, use the third version of doubleVal
        std::cout << std::hex << std::showbase << int(doubleVal(argv[1])) << std::endl;
    }

    return 0;
}
