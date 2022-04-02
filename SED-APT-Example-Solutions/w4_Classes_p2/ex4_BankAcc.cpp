#include <iostream>
#include <fstream>
#include <sstream>

class BankAcc {
public:
    std::string name = "";
    float amount = 0;

    //Constructor
    BankAcc(std::string name_val, float amount_val) {
        name = name_val;
        amount = amount_val;
    }

    //To get the information as a string
    std::string toString() {
        std::stringstream info;
        info << "Name: " << name <<", Amount: " << amount;
        return info.str();
    }

    //Withdraw function
    void withdraw(float num) {
        if (amount < num) {
            std::cerr << "Not enough money in the account. Fail to withdraw !\n";
        } else {
            amount -= num;
            std::cout << "Withdrawn successfully\n";
        }
    }
};


int main(int argc, char* argv[]) {

    // Qa
    // Init 3 bank accounts
    BankAcc acc1 ("TCB", 1000);
    BankAcc acc2 ("XYZ", 1000);
    BankAcc acc3 ("ACB", 3000);

    // Print all info
    std::cout << "All information of 3 accounts:\n";
    std::cout << acc1.toString() << "\n";
    std::cout << acc2.toString() << "\n";
    std::cout << acc3.toString() << "\n";

    // Qb
    std::cout << "\nTest withdraw function on acc1: \n";
    std::cout << "Withdraw 500: "; acc1.withdraw(500);
    std::cout << "Withdraw 700: "; acc1.withdraw(700);

    // Qc
    if (argc != 2) {
        return 0;
    }

    /* Save to file */   
    
    //Create/open file
    std::fstream myfile;
    myfile.open(argv[1], std::ios::out);

    if (!myfile) {
        std::cerr << "Failt to create/ open file " << argv[1] << "\n";
    }

    //Save data
    myfile << acc1.toString() << "\n";
    myfile << acc2.toString() << "\n";
    myfile << acc3.toString() << "\n";
    myfile.close();
    

    return 0;
}