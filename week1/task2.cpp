#include<iostream>

int main(){
    using namespace std;
    int integer;
    int digit;
    cout << "Enter an integer: ";
    cin >> integer;

    int result;

    while(integer > 0) {
        // get the last digit of the integer
        digit = integer % 10;

        // remove the last digit of the integer
        integer /= 10;

        // put the last digit at the beggining of the result
        result = result * 10 + digit;
    }

    cout << "Result: " << result << endl;
    return 0;
}