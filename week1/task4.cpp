#include<iostream>

int main(int argc, char* argv[]){
    using namespace std;

    if (argc != 2) { // check if users insert 1 input only
        cout << "There must be only 1 input" << endl;
        return -1;
    }

    char* input = argv[1];

    int len = string(input).length();

    if (len < 3 || len > 4) { // check if the hexadecimal values have the length between 3 and 4
        cout << "The hexadecimal value must be between 0x00 and 0xFF" << endl;
        return -1;
    } 
    if (input[0] != '0') { // check if the first character is '0'
        cout << "Hexadecimal must start with 0" << endl;
        return -1;
    } 

    if (tolower(input[1]) != 'x') { // check if the second character is 'x' lowercase or uppercase
        cout << "Hexadecimal must have character 'x' uppercase of lowercase at second character" << endl;
        return -1;
    }

    for (int i = 2; i < len; i++) {
        if (!isxdigit(input[i])) { // check if the digit is valid in hexadecimal
            cout << "Invalid hexadecimal value" << endl;
            return -1;
        }

        if  (!isdigit(input[i]) && !isupper(input[i])) { // check if hexadecimal digits except integers are uppercase only
            cout << "Hexadecimal digits can only contain uppercase characters" << endl;
            return -1;
        }
    }

    cout << "Valid hexadecimal: " << input << endl;

    return 0;
}