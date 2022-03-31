#include <iostream>
#include <math.h>
int main() {
    using namespace std;
    float a, b, c;
    cout << "Enter a, b, c for ax2 + bx + c: ";
    cin >> a >> b >> c;

    // calculate the delta of the equation
    float delta = pow(b, 2) - 4 * a * c;
    if (delta < 0) {// if delta < 0, the equation has no root
        cout << "There is no root" << endl;
    } else if (delta == 0) {// if delta == 0, the equation has only one root
        cout << "There is only one root x1 = x2 = " << (-b) / (2 * a) << endl;
    } else if (delta > 0) {// if delta > 0, the equation has 2 roots
        float first_root = (-b + sqrt(delta)) / (2 * a);
        float second_root = (-b - sqrt(delta)) / (2 * a);
        cout << "First root x1: " << first_root << endl;
        cout << "Second root x2: " << second_root << endl;
    }
    return 0;
}