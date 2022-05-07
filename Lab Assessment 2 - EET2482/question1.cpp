/*
    RMIT University Vietnam
    Course: EEET2482 Software Engineering Design
    Semester: 2022A
    Lab Assessment: 1
    Author: Dao Kha tuan
    ID: s3877347
    Compiler used: gcc 8.1.0
    Created  date: 07/05/2022
    Acknowledgement: None
*/

#include <iostream>

using std::string;

#define REWARD_PERCENT 0.05

class RegularAcc {
    private:
        string name;
        double balance; 
    public:
        RegularAcc(){}
        RegularAcc(string name, double balance) {
            this->name = name;
            this->balance = balance;
        }

        // function for the account to pay with an amount
        virtual bool pay(double amount) {

            // if the amount is greater than the balance, return false
            if (amount > balance) {
                return false;
            }

            // otherwise, deduct the balance by the amount and return true
            balance -= amount;
            return true;
        }

        virtual void showInfo() {
            std::cout << "Name: " << name
                      << ", Balance: " << balance << std::endl;  
        }
};

class GoldAcc : public RegularAcc {
    private:
        double bonusCoin = 0;
    public:
        GoldAcc(){}
        GoldAcc(string name, double balance, double bonusCoin) : RegularAcc(name, balance) {
            this->bonusCoin = bonusCoin;
        }

        bool pay(double amount) {

            if (RegularAcc::pay(amount)) { // if it is possible to pay this amount, the golden account will have bonus coin added
                bonusCoin += amount * REWARD_PERCENT; // bonus coin added by the reward percent of 5% of the amount
                return true;
            }

            // otherwise return false
            return false;

        }

        void showInfo() {
            RegularAcc::showInfo();
            std::cout << "Bonus coin: " << bonusCoin << std::endl;
        }
};

int main(){
    RegularAcc reg("kha tuan", 1000);
    GoldAcc gold("khatun", 1000, 0);

    // regular account pays 1000
    reg.pay(1000);
    std::cout << "Info of regular account after paying 1000: " << std::endl;
    reg.showInfo();

    // golden account pays 1000
    gold.pay(1000);
    std::cout << "\nInfo of golden account after paying 1000: " << std::endl;
    gold.showInfo();
    return 0;
}