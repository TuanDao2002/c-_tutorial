#include <iostream>
#include <math.h>

class ComplNum {
    private: 
        double real;
        double img;

    public: 
        ComplNum(){}
        ComplNum(double real, double img) {
            this->real = real;
            this->img = img;
        }

        // object - object
        // cannot use arrow for temp and obj as they do not have "this" pointer
        ComplNum operator - (ComplNum &obj) { // pass by referece
            ComplNum temp;
            temp.real = this->real - obj.real;
            temp.img = this->img - obj.img;

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
        friend ComplNum operator - (double val, ComplNum &obj);

        // object--
        ComplNum operator -- (int) {
            ComplNum temp = *this;
            this->real--;

            // return the previous value
            return temp;
        }

        // --object
        ComplNum operator -- () {
            real--;

            // return the value after decreasing
            return *this;
        }

        // method to get absolute value of complex number
        friend double absolute(ComplNum &obj);

        void display() {
            std::string real_val = std::to_string(this->real);
            if (this->real < 0) {
                real_val = "(" + std::to_string(this->real) + ")";
            }

            std::string img_val = std::to_string(this->img);
            if (this->img < 0) {
                img_val = "(" + std::to_string(this->img) + ")";
            }

            std::cout << real_val << " + " << img_val << "i";
        }
};

// define for double - obj
ComplNum operator - (double val, ComplNum &obj) {
    ComplNum temp;
    temp.real = val - obj.real;
    temp.img = 0 - obj.img;

    return temp;
};

// define for absolute
double absolute(ComplNum &obj) {
    return sqrt(pow(obj.real, 2) + pow(obj.img, 2));
}

int main() {
    ComplNum c1(1, 2), c2(3, 4);

    std::cout << "c1: ";
    c1.display();
    std::cout << "\n";

    std::cout << "c2: ";
    c2.display();
    std::cout << "\n";

    // test obj - obj
    ComplNum res = c1 - c2;
    std::cout << "c1 - c2: ";
    res.display();
    std::cout << "\n";

    // test obj - double
    res = c2 - 2.5;
    std::cout << "c2 - 2.5: ";
    res.display();
    std::cout << "\n";

    // test double - obj
    res = 3.5 - c1;
    std::cout << "3.5 - c1: ";
    res.display();
    std::cout << "\n";

    // test obj--
    res = c1--;
    std::cout << "c1--: ";
    res.display();
    std::cout << "\n";

    // test --obj
    res = --c2;
    std::cout << "--c2: ";
    res.display();
    std::cout << "\n";

    std::cout << "Absolute of c2: " << absolute(c2) << "\n";

    return 0;
}

