#include <iostream>
#include <cstring>

int main(int argc, const char *argv[]) {
    //Check for number of arguments
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments ! ";
        return -1; //error code
    }

    //Check for valid hexadecimal number
    if (strncmp(argv[1], "0x", 2) == 0  || strncmp(argv[1], "0X", 2) == 0) {
        if (strlen(argv[1]) < 3) {
            std::cerr << "No hexa digit \n";
            return -2; //error code
        }
        
        for (int i = 2; argv[1][i] != '\0'; i++) {
            if ((argv[1][i] >= '0' && argv[1][i] <= '9') || 
                (argv[1][i] >= 'A' && argv[1][i] <= 'F')) {
                continue;
            } else {
                std::cerr << "At lease one digit is not valid ! ";
                return -3; //error code
            }
        }

        //All characters are valid in above loop
        std::cout << "Got valid hexadecimal number: " << argv[1];
    } else {
        std::cerr << "Incorrect prefix (should start with 0x or 0X) ! ";
        return -4; //error code
    }

    return 0;
}
