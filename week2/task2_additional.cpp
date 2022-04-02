#include<iostream>
#include<string>

bool is_float(char* float_str) {
    int len = std::string(float_str).length();
    bool dot_flag = false;
    for (int i = 0; i < len; i++) {
        // continue if there is negative sign at the beginning
        if (i == 0 && (float_str[i] == '-' || float_str[i] == '+')) {
            continue;
        }

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

int main(int argc, char* argv[]) {
    float float_arr[10];
    if (argc != 11) {
        std::cerr << "There must be only 10 float numbers" << "\n";
        return -1;
    }


    for (int i = 1; i < argc; i++) {
        if (!is_float(argv[i])) {
            std::cerr << "There is invalid float" << "\n";
            return -1;
        }
        
        *(float_arr + i - 1) = atof(argv[i]);
    }

    for (int j = 1; j < argc; j++) {
        std::cout << "Valid float: " << *(float_arr + j - 1) << "\n";
    }

    return  0;
}