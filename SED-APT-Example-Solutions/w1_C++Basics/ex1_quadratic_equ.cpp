#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cout << "Enter a, b, c for equation ax^2 + bx + c = 0 \n";
    std::cin >> a >> b >> c;

    if (a == 0) {
    /* Become linear equation */
        if (b == 0) { //Now it become equation c = 0
            if (c != 0) {
                std::cout << "There are no roots \n";
            } else {
                std::cout << "There are infinite solution (for any value of x) \n";
            }
        } else { //Now it become equation bx + c = 0
            std::cout << "There is one root: x = " << -c / b << "\n";
        }
    } else { 
    /* Valid quadratic equation ax^2 + bx + c = 0 */
        double delta = b*b - 4*a*c;

        if (delta < 0) {
            std::cout << "There are no roots \n";
        } else if (delta > 0) {
            std::cout   << "There are two roots: "
                        << "x1 = "  << (-b + sqrt(delta)) / (2*a)
                        << " x2 = "  << (-b - sqrt(delta)) / (2*a);
        } else { //detal == 0
            std::cout   << "There are one root: "
                        << "x1 = x2 = "  << (-b) / (2*a);
        }
    }

    return 0; 
}