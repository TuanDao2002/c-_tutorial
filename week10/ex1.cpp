#include <iostream>

template<typename type>
void swap(type &num1, type &num2) {
    type temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){
    int num1 = 2, num2 = 3;
    swap<int>(num1, num2);

    std::cout << "Num1: " << num1 << ", Num2: " << num2 << std::endl;
    return 0;
}