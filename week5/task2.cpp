#include <iostream>

int main() {
    double a, b;
    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    try {
        if (b == 0) throw 1;
    } catch (int error_code) {
        std::cerr << "b is 0. Enter b again: ";
        std::cin >> b;
    } 

    int count = 0;
    while (1) {
        try {
            char *char_arr = new char[1024]; // 1GB
            count++;

            if (count == 100) { // throw custom error
                throw -1;
            }
        } catch (int errorcode) {
            std::cerr << "Fail to allocate memory\n";
            std::cout << "Allocated " << count << "GB" << "\n";
            break;
        }

        std::cout << "Hello world\n";
    }

    return 0;
}