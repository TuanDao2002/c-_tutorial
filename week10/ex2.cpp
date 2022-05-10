#include <iostream>

template<typename type>
type min3(type num1, type num2, type num3) {
    type min = num1;

    if (num2 < min) {
        min = num2;
    }

    if (num3 < min) {
        min = num3;
    }

    return min;
}

int main(){
    std::cout << "The min of 1, 0, 2 is " << min3<int>(1, 0, 2) << std::endl;
    std::cout << "The min of 1.5, 0.5, 3.0 is " << min3<double>(1.5, 0.5, 3.0) << std::endl;
    std::cout << "The min of Hello, Hi, Morning is " << min3<std::string>("Hello", "Hi", "Morning") << std::endl;
    return 0;
}