#include <iostream>
#include <fstream>
#include <cstring>
#define MAXSIZE 100

 
int main () {
    std::fstream myfile;
    char password[MAXSIZE];

    std::cout <<    "Password management program: \n" 
                    "1. Save your password \n"
                    "2. Read your password \n"
                    "Your choice: ";
    int choice;                
    std::cin >> choice;

    if (choice == 1) { /* Save your password */
        myfile.open("pwd.dat", std::ios::out); 

        if (!myfile) { 
            std::cerr << "Fail to create/open file \n";
            return -1;
        }

        //Get the password from console
        std::cout << "Enter the password: ";
        //Keep reading (to ingore newline characters from previous input)
        do {
            std::cin.getline(password, sizeof(password));
        } while (strlen(password) == 0);

        //Save to the file
        myfile << password;
        myfile.close();
        std::cout << "Saved to the file! \n";
    } else { /* Read your password */
        myfile.open("pwd.dat", std::ios::in);
        if (!myfile) { 
            std::cerr << "Fail to create/open file \n";
            return -1;
        }

        myfile.getline(password, sizeof(password)); //read from the file
        myfile.close();
        std::cout   << "Read your password from the file: " 
                    << password << "\n";
    }

   return 0;
}