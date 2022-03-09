#include<iostream>
#include<stdlib.h>
#define NUM_INT 5

bool is_integer(char* int_str) {
    int len = std::string(int_str).length();
    for (int i = 0; i < len; i++) {
        // continue if there is negative sign at the beginning
        if (i == 0 && int_str[i] == '-') {
            continue;
        }

        if (!isdigit(int_str[i])) {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    int int_arr[5];
    if (argc != NUM_INT + 1) {
        std::cerr << "There must be only 5 input arguments" << "\n";
        return -1;
    }

    for (int i = 1; i < argc; i++) {
        if (!is_integer(argv[i])) {
            std::cerr << "There is invalid integer" << "\n";
            return -2;
        }
        
        *(int_arr + i - 1) = atoi(argv[i]);
    }

    for (int j = 0; j < 5; j++) {
        std::cout << "Valid integer: " << *(int_arr + j) << "\n";
    }

    return  0;
}