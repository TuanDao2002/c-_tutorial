#include<iostream>
#include<string>
int main(int argc, char* argv[]){
    if (argc != 2) { // check if users insert 1 input only
        std::cerr << "There must be only 1 input arguments" << "\n";
        return -1;
    }

    char* input = argv[1];

    int len = std::string(input).length();

    if (len < 3 || len > 4) { // check if the hexadecimal values have the length between 3 and 4
        std::cerr << "The hexadecimal value must be between 0x00 and 0xFF" << "\n";
        return -1;
    } 
    if (input[0] != '0') { // check if the first character is '0'
        std::cerr << "Hexadecimal must start with 0" << "\n";
        return -1;
    } 

    if (tolower(input[1]) != 'x') { // check if the second character is 'x' lowercase or uppercase
        std::cerr << "Hexadecimal must have character 'x' uppercase of lowercase at second character" << "\n";
        return -1;
    }

    for (int i = 2; i < len; i++) {
        if (!isxdigit(input[i])) { // check if the digit is valid in hexadecimal
            std::cerr << "Invalid hexadecimal value" << "\n";
            return -1;
        }

        if  (!isdigit(input[i]) && !isupper(input[i])) { // check if hexadecimal digits except integers are uppercase only
            std::cerr << "Hexadecimal digits can only contain uppercase characters" << "\n";
            return -1;
        }
    }

    std::cerr << "Got valid hexadecimal: " << input << "\n";

    return 0;
}