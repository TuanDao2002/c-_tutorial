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
#include <sstream>
#include <fstream>

#define STRSIZE 100

class EWallet{
    private:
        std::string id;
        double balance;
    public:
        // constructor for EWallet
        EWallet(){};

        EWallet(std::string id, double balance) {
            this->id = id;
            this->balance = balance;
        }

        // getters
        std::string getID(){
            return id;
        }

        double getBalance(){
            return balance;
        }

        // deposit method to add amount of money to balance
        void deposit(double num) {
            this->balance += num;
            std::cout << id <<  " deposit: " << num << std::endl;
        }

        // withdraw method to deduct amount of money to balance
        bool withdraw(double num) {
            if (this->balance < num) { // print error if the balance less than amount of money
                std::cerr << id <<  " cannot withdraw: " << num << std::endl;
                return false;
            }

            this->balance -= num;
            std::cout << id << " witdraw: " << num << std::endl;
            return true;
        }
};

class Customer{
    private:
        std::string name;
        std::string pwd;
        EWallet ew;
    
    public:
        // constructor for Customer
        Customer(){};

        Customer(std::string name, std::string pwd, EWallet ew){
            this->name = name;
            this->pwd = pwd;
            this->ew = ew;
        };

        EWallet getWallet() {
            return ew;
        }

        void setWallet(EWallet ew) {
            this->ew = ew;
        }

        // function to verify the password
        bool verifyPass() {
            std::cout << "Enter a password for " << name << " :" << std::endl;
            char tempStr[STRSIZE];

            do {
                std::cin.getline(tempStr, sizeof(tempStr));
            } while (strlen(tempStr) == 0);

            if (tempStr != pwd) {
                return false;
            }

            return true;
        }

        // function to deposit money of customer
        bool doDeposit() {
            if (!verifyPass()) {
                std::cout << "Wrong password!" << std::endl;
                return false;
            }

            std::cout << "Enter the amount of money to deposit: " << std::endl;
            double depositAmount;
            std::cin >> depositAmount;

            ew.deposit(depositAmount);
            std::cout << name << " deposits successfully!!" << std::endl;
            return true;
        }
        // function to deposit money of customer
        bool doWithdraw() {
            if (!verifyPass()) {
                std::cout << "Wrong password!" << std::endl;
                return false;
            }

            std::cout << "Enter the amount of money to withdraw: " << std::endl;
            double withdrawAmount;
            std::cin >> withdrawAmount;

            if (!ew.withdraw(withdrawAmount)) {
                std::cout << name << " does not withdraw successfully!!" << std::endl;
                return false;
            }

            std::cout << name << " withdraw successfully!!" << std::endl;
            return true;
        }

        void operator >> (Customer &c) {
            double thisBalance = this->ew.getBalance();
            this->ew.withdraw(thisBalance);
            EWallet newEW = c.getWallet();
            newEW.deposit(thisBalance);

            c.setWallet(newEW);
            std::cout << c.toString() << std::endl;
        }

        Customer operator++ (int) {
            Customer temp = *this;
            ew.deposit(1000);
            return temp;
        }

        std::string toString() {
            std::stringstream sstr;
            sstr << "Name: " << name
                 << ", Password: " << pwd 
                 << ", Wallet ID: " << ew.getID() 
                 << ", Balance: " << ew.getBalance() << std::endl;
            return sstr.str();
        }
};

int main(){
    // question a
    std::cout << "Question a\n";
    // initialize a EWallet object using dynamic allocation
    EWallet *e = new EWallet("123", 1000);

    // deposit 100 from wallet e
    e->deposit(100);

    // withdraw 1000 from wallet e
    e->withdraw(1000);

    // withdraw 200 from wallet e
    e->withdraw(200);

    delete e; 


    // question b
    std::cout << "\nQuestion b\n";
    // initialize and create 4 Customer objects along with 4 EWallet objects
    EWallet e1 = EWallet("234", 100);
    Customer c1("tuan", "123", e1);

    EWallet e2 = EWallet("235", 200);
    Customer c2("dao", "122", e2);

    EWallet e3 = EWallet("236", 310);
    Customer c3("kha", "124", e3);

    EWallet e4 = EWallet("237", 280);
    Customer c4("khatun", "125", e4);

    // deposit balance for Customer c1
    std::cout << "Deposit balance for Customer c1: " << std::endl;
    c1.doDeposit();

    // withdraw balance for Customer c2
    std::cout << "\nWithdraw balance for Customer c2:" << std::endl;
    c2.doWithdraw();

    // Move balance of c1 to c2
    std::cout << "\nMove balance of c1 to c2: " << std::endl;
    c1 >> c2;
    std::cout << "Account of Customer c2: " << c2.getWallet().getBalance() << std::endl;
    std::cout << "Account of Customer c1: " << c1.getWallet().getBalance() << std::endl;

    // test ++ postfix on c4
    Customer tempCustomer = c4++;
    std::cout << "Info of Customer c4++: " << std::endl;
    std::cout << tempCustomer.toString() << std::endl;
    std::cout << "Info of Customer c4:" << std::endl;
    std::cout << c4.toString() << std::endl;

    // a dynamic array of 4 customers
    Customer *customerArr = new Customer[4]{c1, c2, c3, c4};

    // open file with std::ios::trunct to delete old content and write new one
    std::fstream infile;
    infile.open("customer.txt", std::ios::out | std::ios::trunc);

    if (!infile) {
        std::cerr << "Cannot open file!!!" << std::endl;
        return -1;
    }

    Customer largestBalanceCustomer = c1;
    Customer secondLargestBalanceCustomer = c1;

    std::cout << "\nInfo of all 4 customers: " << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << customerArr[i].toString() << std::endl;
        infile << customerArr[i].toString();

        // if balance of customer is larger than one with largest balance
        if (customerArr[i].getWallet().getBalance() >= largestBalanceCustomer.getWallet().getBalance()) {
            secondLargestBalanceCustomer = largestBalanceCustomer; // swap the second largest and largest before
            largestBalanceCustomer = customerArr[i]; // assign the customer to one with largest balance
        } else if (customerArr[i].getWallet().getBalance() > secondLargestBalanceCustomer.getWallet().getBalance()) {
            // assign the customer to one with second largest balance
            secondLargestBalanceCustomer = customerArr[i];
        } 
    
    }

    std::cout << "Info of customer with the second largest balance in the wallet: " << std::endl;
    std::cout << secondLargestBalanceCustomer.toString() << std::endl;

    infile.close();

    delete[] customerArr;
    return 0;
}