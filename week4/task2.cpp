#include <iostream>
#include <string.h>

// using string c++
#if 1
int main() {
    std::string str1, str2;

    std::cout << "Enter str1: ";
    std::getline(std::cin, str1); // get a whole line with spaces for string c++ with getline

    int str1_len = str1.length(); // strlen can only apply to const char array => convert string to const char array with c_str()
    for (int i = 0; i < str1_len / 2; i++) {
        char temp = str1[i];
        str1[i] = str1[str1_len - i - 1];
        str1[str1_len - i - 1] = temp;
    }

    std::cout << "String str1 after reverse: " << str1 << std::endl;

    std::cout << "Enter str2: ";
    std::getline(std::cin, str2);

    int str2_len = str2.length();
    for (int i = 0; i < str2_len; i++) {
        if (isupper(str2[i])) {
            str2[i] = tolower(str2[i]);
        } else if (islower(str2[i])) {
            str2[i] = toupper(str2[i]);
        }
    }

    std::cout << "String str2 after modification: " << str2 << std::endl;
    return 0;
}
#endif

// using char array
#if 0
int main() {
    char str1[100];
    char str2[100];

    std::cout << "Enter str1: ";
    std::cin.getline(str1, 99); // get a whole line with spaces for char array using cin.getline

    int str1_len = strlen(str1); // do not need to convert to char array using c_str()
    for (int i = 0; i < str1_len / 2; i++) {
        char temp = str1[i];
        str1[i] = str1[str1_len - i - 1];
        str1[str1_len - i - 1] = temp;
    }

    std::cout << "String str1 after reverse: " << str1 << std::endl;

    std::cout << "Enter str2: ";
    std::cin.getline(str2, 99);

    int str2_len = strlen(str2);
    for (int i = 0; i < str2_len; i++) {
        if (isupper(str2[i])) {
            str2[i] = tolower(str2[i]);
        } else if (islower(str2[i])) {
            str2[i] = toupper(str2[i]);
        }
    }

    std::cout << "String str2 after modification: " << str2 << std::endl;
    return 0;
}
#endif
