#include <iostream>

using std::string;

class Acc {
    protected:
        string name;
        double bill;

    public:
        Acc(){};
        Acc(string name, double bill) {
            this->name = name;
            this->bill = bill;
        }

        virtual void buyProduct(int price) {
            bill += price;
        }

        virtual void displayInfo() {
            std::cout << "Name: " << name << "\nBill: " << bill << std::endl;
        }
};

class GoldAcc : public Acc {
    private:
        double discRate;
    public:
        GoldAcc(){};
        GoldAcc(string name, double bill, double discRate) : Acc(name, bill) {
            this->discRate = discRate;
        }

        void buyProduct(int price) {
            bill += price * (1 - discRate);
        }

        void displayInfo() {
            Acc::displayInfo();
            std::cout << "Discount rate: " << discRate << std::endl;
        }
};

int main(){
    Acc acc("tuan", 20);
    GoldAcc goldAcc("khatun", 100, 0.15);

    acc.buyProduct(100);
    goldAcc.buyProduct(100);

    acc.displayInfo();
    std::cout << std::endl;
    goldAcc.displayInfo();
    return 0;
}