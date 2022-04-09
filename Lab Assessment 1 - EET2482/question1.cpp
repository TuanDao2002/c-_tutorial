/*
    RMIT University Vietnam
    Course: EEET2482 Software Engineering Design
    Semester: 2022A
    Lab Assessment: 1
    Author: Dao Kha Tuan
    ID: s3877347
    Compiler used: gcc 8.1.0
    Created  date: 09/04/2022
    Acknowledgement: None
*/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[]){
    // question 1.1
    if (argc < 2) { // if there is no argument, print error
        std::cerr << "No arguments in the command line!" << std::endl;
        return -1;
    }

    if (strcmp(argv[1], "-w") != 0 && strcmp(argv[1], "-r") != 0) {
        if (argc != 4) { // if there is not enough 3 hexadecimal numbers, print error
            std::cerr << "There must be 3 hexadecimal numbers in the command line!" << std::endl;
            return -2;
        }

        int hexSum;
        for (int i = 1; i <= 3; i++) {
            // use stringstream to convert hexa string to int value and add to sum
            std::stringstream sstr;
            sstr << std::hex << argv[i];
            int tempVal;
            sstr >> tempVal;
            
            hexSum += tempVal;
        }

        std::cout << "Sum is: " << std::hex << std::showbase << hexSum << std::endl;
    }

    // question 1.2
    if (strcmp(argv[1], "-w") == 0) {
        std::fstream myFile;
        
        // clear old content with std::ios::trunc
        myFile.open("data.txt", std::ios::out | std::ios::trunc);
        if (!myFile) {
            std::cerr << "Cannot open file!!" << std::endl;
            return -3;
        }

        // write all arguments to file
        for (int i = 2; i < argc; i++) {
            myFile << argv[i] << std::endl;
        }
        
        myFile.close();

    }

    // question 1.3
    if (strcmp(argv[1], "-r") == 0) {
        std::fstream myFile;

        // read file
        myFile.open("data.txt", std::ios::in);
        if (!myFile) {
            std::cerr << "Cannot open file!!" << std::endl;
            return -3;
        }

        int maxLength = 0;
        std::string tempStr;
        std::string longestLine;
        while (std::getline(myFile, tempStr)) {
            if (tempStr.length() > maxLength) {
                // if the length of string is greater than max length, assign its length to max length, and itself to longest line
                maxLength = tempStr.length();
                longestLine = tempStr;
            }
        }

        std::cout << "Longest line: " << longestLine << std::endl;
        
        myFile.close();
    }

    return 0;
}