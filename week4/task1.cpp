#include <iostream>
#include <math.h>

class ComplNum {
    private: 
        double real;
        double img;

    public: 
        ComplNum(){} // default constructor
        ComplNum(double real, double img) { // constructor 
            this->real = real;
            this->img = img;
        }

        // object - object
        // cannot use arrow for temp and obj as they do not have "this" pointer
        ComplNum operator - (ComplNum num) {
            ComplNum temp;
            temp.real = this->real - num.real;
            temp.img = this->img - num.img;

            return temp;
        }

        // object - double
        ComplNum operator - (double val) {
            ComplNum temp;
            temp.real = this->real - val;
            temp.img = this->img - 0;

            return temp;
        }

        // double - object
        friend ComplNum operator - (double val, ComplNum num);

        // object-- 
        ComplNum operator -- (int) { // always int as the argument
            ComplNum temp = *this;
            this->real--;

            // return the previous value
            return temp;
        }

        // --object
        ComplNum operator -- () {
            --this->real;

            // return the value after decreasing
            return *this;
        }

        // method to get absolute value of complex number
        friend double absolute(ComplNum num);

        void display() {
            std::cout << std::noshowpos << this->real;
            std::cout << std::showpos << " " << this->img << "i";  
        }
};

// define for double - obj
ComplNum operator - (double val, ComplNum num) {
    ComplNum temp;
    temp.real = val - num.real;
    temp.img = 0 - num.img;

    return temp;
};

// define for absolute
double absolute(ComplNum num) {
    return sqrt(pow(num.real, 2) + pow(num.img, 2));
}

int main() {
    ComplNum c1(-1, 2), c2(3, 4);

    std::cout << "c1: ";
    c1.display();
    std::cout << "\n\n";

    std::cout << "c2: ";
    c2.display();
    std::cout << "\n\n";

    // test obj - obj
    ComplNum res = c1 - c2;
    std::cout << "c1 - c2: ";
    res.display();
    std::cout << "\n\n";

    // test obj - double
    res = c2 - 2.5;
    std::cout << "c2 - 2.5: ";
    res.display();
    std::cout << "\n\n";

    // test double - obj
    res = 3.5 - c1;
    std::cout << "3.5 - c1: ";
    res.display();
    std::cout << "\n\n";

    // test obj--
    res = c1--;
    std::cout << "c1--: ";
    res.display();
    std::cout << "\n\n";

    std::cout << "c1: ";
    c1.display();
    std::cout << "\n\n";

    // test --obj
    res = --c2;
    std::cout << "--c2: ";
    res.display();
    std::cout << "\n\n";

    std::cout << "Absolute of c2: " << absolute(c2) << "\n";

    return 0;
}

