#include<iostream>
#include<string>
int main(int argc, char* argv[]){
    int value[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    std::string symbol[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    int input;
    if (argc > 2) {
        std::cerr << "There must be only 1 user input" << "\n";
        return -1;
    } else if (argc == 2) {
        input = atoi(argv[1]);
    } else {
        std::cout << "Input an integer: ";
        std::cin >> input;
    }

    std::string roman;
    int max_index = 12;
    while (input > 0) {
        if (input >= value[max_index]) {
            input -= value[max_index];
            roman += symbol[max_index];
        } else {
            max_index--;
        }
    }

    std::cout << "Converted Roman number: " << roman << "\n";
    return 0;
}