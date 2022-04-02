#include <iostream>
#define MAXSIZE 100

int main() {
    
    std::string str1, str2;
    char temp[MAXSIZE];

    //we need to use getline with C-type string. Using it with string object may crash !
    std::cout << "Enter the first string: ";
    std::cin.getline(temp, MAXSIZE);  
    str1 = temp;

    std::cout << "Enter the second string: ";
    std::cin.getline(temp, MAXSIZE);  
    str2 = temp;

    //Qa: revert string 1
    //swap first characters with the last characters until the middle
    for (int i = 0; i < str1.length() / 2; i++) { 
        char ch = str1[i];
        str1[i] = str1[str1.length() - i - 1];
        str1[str1.length() - i - 1] = ch;
    }
    
    std::cout << "Str1 after being reverted: " << str1 << "\n";

    //Qb: convert from lowercase to uppercase and vice versa
    for (int i = 0; i < str2.length(); i++) { 
        if ( isupper(str2[i]) ) {
            str2[i] = tolower(str2[i]);
        } else {
            str2[i] = toupper(str2[i]);
        }
    }
    std::cout << "Str2 after being converted: " << str2 << "\n";


    /* To use with C-type string: 
    Just change .length function become strlen() function. 
    Must include <cstring> library to use it*/


    return 0;
}