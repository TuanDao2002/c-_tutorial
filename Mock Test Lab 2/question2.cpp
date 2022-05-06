#include <iostream>

using std::string;

class Broker {
    private:
        string name;
        int buyPrice;
        int sellPrice;
        Broker* nextBuyer = NULL;
    public:
        Broker(){}
        Broker(string name, int buyPrice) {
            this->name = name;
            this->buyPrice = buyPrice;
        }

        void setNextBuyer(Broker* nextBuyer) {
            this->nextBuyer = nextBuyer;

            if (nextBuyer != NULL) {
                this->sellPrice = nextBuyer->buyPrice;
            } else {
                this->sellPrice = 0;
            }
        }

        void showInfo() {
            std::cout << "Broker name: " << name
                      << "\nBuy with price: " << buyPrice
                      << "\nSell with price: " << sellPrice << std::endl;  
        }

        friend void printTransactions(Broker* firstBroker);
        friend void printLowestAndHighestProfitBroker(Broker* firstBroker);
        friend void deleteTransacation(Broker*& firstBroker, Broker*& lastBroker, Broker* deleteBroker);
};

void printTransactions(Broker* firstBroker) {
    Broker* temp = firstBroker;
    std::cout << temp->name << ": initially bought the house for $" << temp->buyPrice << std::endl;
    
    while (temp->nextBuyer != NULL) {
        std::cout << temp->name << " --> " << temp->nextBuyer->name << " : price = $" << temp->sellPrice << std::endl;
        temp = temp->nextBuyer;
    }
}

void printLowestAndHighestProfitBroker(Broker* firstBroker) {
    Broker* highestProfitBroker = firstBroker;
    Broker* lowestProfitBroker = firstBroker;

    Broker* temp = firstBroker;
    while (temp->nextBuyer != NULL) {
        if (temp->sellPrice - temp->buyPrice > highestProfitBroker->sellPrice - highestProfitBroker->buyPrice) {
            highestProfitBroker = temp;
        }

        if (temp->sellPrice - temp->buyPrice < highestProfitBroker->sellPrice - highestProfitBroker->buyPrice) {
            lowestProfitBroker = temp;
        }

        temp = temp->nextBuyer;
    }

    std::cout << "\nBroker with highest profit: " << std::endl;
    highestProfitBroker->showInfo();

    std::cout << "\nBroker with lowest profit:" << std::endl;
    lowestProfitBroker->showInfo();
}

void deleteTransacation(Broker*& firstBroker, Broker*& lastBroker, Broker* deleteBroker) {
    if (firstBroker == deleteBroker) {
        firstBroker = deleteBroker->nextBuyer;
        return;
    }

    Broker* temp = firstBroker;
    while (temp != NULL) {
        if (temp->nextBuyer == deleteBroker) {
            temp->setNextBuyer(deleteBroker->nextBuyer);

            if (deleteBroker == lastBroker) {
                lastBroker = temp;
            }

            break;
        }

        temp = temp->nextBuyer;
    }
}

int main(){
    Broker david("David", 800), john("John", 1000), peter("Peter", 1200), luna("Luna", 1800), sophia("Sophia", 3500);

    Broker* firstBroker = &david;
    david.setNextBuyer(&john);
    john.setNextBuyer(&peter);
    peter.setNextBuyer(&luna);
    luna.setNextBuyer(&sophia);
    Broker* lastBroker = &sophia;

    printTransactions(firstBroker);

    printLowestAndHighestProfitBroker(firstBroker);

    deleteTransacation(firstBroker, lastBroker, &sophia);

    std::cout << "\nAfter deleting sophia" << std::endl;
    printTransactions(firstBroker);

    printLowestAndHighestProfitBroker(firstBroker);
    return 0;
}