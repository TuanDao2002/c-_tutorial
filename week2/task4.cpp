#include<iostream>
#include<iomanip>
#include<math.h>

int main(){
    // a) print 200 with and without positive + sign
    std::cout << std::showpos << 200 << "\n";
    std::cout << std::noshowpos << 200 << "\n\n";

    // b) print 10 and 200 left justified with 5-character width
    std::cout << std::setfill('x') << std::setw(5) << std::left << 10
                                   << std::setw(5)<< 200 << "*\n\n"; // * is used to mark the spaces

    char hexachar[6] = {'A', 'B', 'C', 'E', 'F'};
    int hexavalue[6] = {10, 11, 12, 13, 14, 15};

    // c) convert hexadecimal to decimal
    /*
    std::string input;
    std::cout << "Input: ";
    std::cin >> input;

    int len = input.length();
    int decimal = 0;

    for (int i = 2; i < len; i++) {
        if (isdigit(input[i]) && input[i] != '0') {
            decimal += (input[i] - '0') * pow(16, len - 1 - i);
            continue;
        }

        for (int j = 0; j < 6; j++) {
            if (input[i] == hexachar[j]) {
                decimal += hexavalue[j] * pow(16, len - 1 - i);
                break;
            }
        }
    }

    std::cout << "Output: " << decimal << "\n\n";
    */
    int num;
    std::cout << "Enter hexadecimal number: ";
    std::cin >> std::hex >> num;
    std::cout << num << "\n\n";

    // d) convert 100 to hexadecimal form preceded by 0x
    /*
    int integer = 100;
    std::string hexa = "";
    int hexaval = 0;
    std::string hexadigit = "";
    while (integer > 0) {
        hexaval = integer % 16;
        hexadigit = std::to_string(hexaval);

        if (hexaval >= 10) { // value greater than 10
            for (int j = 0; j < 6; j++) {
                if (hexaval == hexavalue[j]) {
                    hexadigit = std::string(1, hexachar[j]); // convert char to string
                }
            }
        }

        hexa = hexadigit + hexa;
        integer /= 16;
    }

    hexa = "0x" + hexa;

    std::cout << "Hexadecimal of 100 is: " << hexa << "\n\n";
    */

    std::cout << std::hex << std::showbase << 100 << "\n\n";

    // e) Print 1.234 with 9-character width, padded by zeros
    std::cout << std::setw(9) << std::setfill('0') << 1.234 << "\n\n";

    // f) Print 1.234 with precision is 2 digits of fractional part (after decimal point)
    std::cout << std::fixed << std::setprecision(2) << 1.234 << "\n\n";


    // g) Read a string from the console input, store the string in character array str. Then print out its all characters, separated by a space
    char str[100];
    std::cout << "Enter a string: ";
    std::cin.ignore(1, '\n'); // ignore previous '\n' character
    std::cin.getline(str, sizeof(str));

    // for (char* p = str; *p != '\0'; p++) {
    //     std::cout << *p << " ";
    // }

    for (int i = 0; str[i] != '\0'; i++) {
        std::cout << str[i] << " ";
    }
    return 0;
}