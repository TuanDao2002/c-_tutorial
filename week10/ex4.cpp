#include <iostream>

template<int N> 
class factorial {
    public:
        int value = 1;
        factorial() {
            for (int i = 1; i <= N; i++) {
                value *= i;
            }
        }

        void display() {
            std::cout << "Factorial of " << N << " is: " << value << std::endl;
        }
};

template<>
class factorial<0> {
    public:
        int value = 1;
        void display() {
            std::cout << "Factorial of 0 is: " << value << std::endl;
        }
};

int main(){
    factorial<5> f5;
    f5.display();

    factorial<10> f10;
    f10.display();

    factorial<0> f0;
    f0.display();
    return 0;
}