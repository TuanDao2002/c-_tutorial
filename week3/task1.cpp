#include <iostream>
#include <fstream>

int main(){
    std::cout << "Password management program:" << "\n";
    std::cout << "1. Save your password" << "\n";
    std::cout << "2. Read your password" << "\n";

    int choice;
    std::cout << "Your choice: ";
    std::cin >> choice;

    std::string password;
    std::fstream myfile;
    switch (choice) {
        case 1: 
            std::cout << "Input a password: ";
            std::cin >> password;

            myfile.open("pwd.dat", std::ios::out);
            break;
        
        case 2:
            break;
    } 
    return 0;
}