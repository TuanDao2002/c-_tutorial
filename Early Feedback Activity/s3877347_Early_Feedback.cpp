/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Dao Kha Tuan
  ID: s3877347
  Compiler used: 8.1.0
  Created  date: 18/03/2022
  Acknowledgement: None.
*/

#include <iostream>
#include <fstream>
class Bankacc {
    public: 
        std::string name;
        float amount;

        // constructor for 2 attributes name and amount
        Bankacc(std::string name_val, float amount_val) {
            name = name_val;
            amount = amount_val;
        }

        // a method to withdraw money in the bank account
        int withdraw(float num) {
            // if the amount is greater than num, subtract amount by num and return 1, which is the success code
            if (amount >= num) {
                amount -= num;
                return 1;
            } else { // otherwise, print out error message and return -1, which is the error code
                std::cerr << "Cannot withdraw " << num << "\n";
                return -1;
            }
        }
};

int main(int argc, char* argv[]) {

    // create 3 bank account objects
    Bankacc acc1("vietcombank", 2222);
    Bankacc acc2("agribank", 9999);
    Bankacc acc3("techcombank", 2324);

    // display all information of all of them
    std::cout << "Display 3 bank account objects: \n";
    std::cout << "Bank name: " << acc1.name << " " << "Amount: " << acc1.amount << "\n";
    std::cout << "Bank name: " << acc2.name << " " << "Amount: " << acc2.amount << "\n";
    std::cout << "Bank name: " << acc3.name << " " << "Amount: " << acc3.amount << "\n\n";

    // test withdraw method
    std::cout << "Test withdraw method:\n";
    if (acc1.withdraw(3000) != -1) {
        std::cout << "Withdraw successfully\n";
    }

    if (acc2.withdraw(3000) != -1) {
        std::cout << "Withdraw successfully\n";
    }

    std::cout << "Bank name: " << acc1.name << " " << "Amount: " << acc1.amount << "\n"; // the amount of acc1 is not changed
    std::cout << "Bank name: " << acc2.name << " " << "Amount: " << acc2.amount << "\n\n"; // the amount of acc2 deducted by 3000

    if (argc != 2) { // if there is no only one command line argument, the data is not saved
        std::cout << "The data is not save!\n";
    } else { // otherwise, use fstream to save the data into a file

        // create fstream object
        std::fstream myfile;

        // open the file whose name is in the command line argument
        myfile.open(argv[1], std::ios::out);

        // print error message and return error code if the file cannot be opened
        if (!myfile) {
            std::cout << "Cannot open file" << "\n";
            return -2;
        }
        
        // save all data (one line for each account) into the file
        myfile << "Bank name: " << acc1.name << " " << "Amount: " << acc1.amount << "\n";
        myfile << "Bank name: " << acc2.name << " " << "Amount: " << acc2.amount << "\n";
        myfile << "Bank name: " << acc3.name << " " << "Amount: " << acc3.amount << "\n";

        // print out message that the data is saved into the file
        std::cout << "Data is saved!" << "\n"; 

        // close file
        myfile.close();
    }

    return 0;
}

