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
            myfile.open("pwd.dat", std::ios::out);
            
            if (!myfile) {
                std::cout << "Cannot open file" << "\n";
                return -1;
            }

            std::cout << "Enter the password: ";
            std::cin.ignore(1, '\n'); // ignore previous '\n' character
            std::getline(std::cin, password); // use getline not cin.getline

            myfile << password << "\n";
            std::cout << "Saved to the file!" << "\n";

            myfile.close();
            break;
        
        case 2:
            myfile.open("pwd.dat", std::ios::in);

            if (!myfile) {
                std::cout << "Cannot open file!" << "\n";
                return -1;
            }

            std::getline(myfile, password); // read the whole line from "pwd.dat" with getline => replace std::cin with fstream
            std::cout << "Your password is: " << password << "\n";
            myfile.close();

            break;
        
        default:
            std::cout << "Invalid option!" << "\n";
    } 
    return 0;
}