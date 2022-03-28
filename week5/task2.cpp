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

    return 0;
}