#include <iostream>
#include <iomanip>

int main() {
    // a)	Print 200 with and without a positive + sign.
    std::cout << std::showpos << 20 << " ";
    std::cout << std::noshowpos << 20 << "\n\n";

    // b)	Print 10 and 200 left justified with 5-character width.
    std::cout << std::left  << std::setw(5) << 10 
                            << std::setw(5) << 200 << "*\n\n"; //* is used just to mark the spaces

    // c)	Read a hexadecimal value (preceded by 0x) into variable hex, then print out its decimal value.
    // Input: 0x10
    // Output: 16
    int num;
    std::cin >> std::hex >> num;
    std::cout << num << "\n\n";

    // d)	Print 100 in hexadecimal form preceded by 0x.
    std::cout << std::hex << std::showbase << 100 <<"\n\n";

    // e)	Print 1.234 with 9-character width, padded by zeros.
    std::cout << std::setw(9) << std::setfill('0') << 1.234 <<"\n\n";

    // f)	Print 1.234 with precision is 2 digits of fractional part (after decimal point).
    std::cout << std::setprecision(2) << std::fixed << 1.234 <<"\n\n";

    // g)	Read a string from the console input, store the string in character array str. Then print out its all characters, separated by a space.
    char str[100];
    std::cin >> str;

    /* this way will allow you to read in a string with spaces */
    // std::cin.ignore(1,'\n'); //Ignore previous "\n" character   
    // std::cin.getline(str, sizeof(str));   

    for (int i = 0; str[i] != '\0'; i++) {
        std::cout << str[i] << " ";
    }


    return 0;
}