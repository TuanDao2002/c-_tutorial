#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    int val = 0;
    while (num != 0) {
        int digit = num % 10;
        val = val*10 + digit;
        num /= 10;
    }

    std::cout << "Reversed number: " << val << "\n";

    return 0;
}