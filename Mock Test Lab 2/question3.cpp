#include <iostream>
#include <vector>

using std::string;
using std::vector;

#define ACC_CHARGE 0.1
#define GOLD_CHARGE 0.05

class Product;

class Shop {
    private:
        string name;
        vector<Product*> productList = {};
    public:
        Shop(){};
        Shop(string name, vector<Product*> productList) {
            this->name = name;
            this->productList = productList;
        }

        void addProduct(Product* product) {
            this->productList.push_back(product);
        }

        friend class Acc;
        friend class GoldAcc;
};

class Product {
    private:
        string name;
        double price;
    public:
        Product(){};
        Product(string name, double price) {
            this->name = name;
            this->price = price;
        }

        void displayInfo() {
            std::cout << "Name: " << name
                      << ", Price: " << price << std::endl;  
        }

        friend class Acc;
        friend class GoldAcc;
};

class Acc {
    protected:
        string name;
        double bill;
        vector<Product*> boughtProducts = {};

    public:
        Acc(){};
        Acc(string name, double bill) {
            this->name = name;
            this->bill = bill;
        }

        virtual void buyProduct(Product* buyProduct, Shop* shop) {
            for (int j = 0; j < this->boughtProducts.size(); j++) {
                if (this->boughtProducts[j] == buyProduct) {
                    std::cout << name << " bought product: " << buyProduct->name << " already!!!"<< std::endl;
                    return;
                }
            }

            for (int i = 0; i < shop->productList.size(); i++) {
                if (shop->productList[i] == buyProduct) {
                    this->boughtProducts.push_back(buyProduct);
                    bill += buyProduct->price;

                    std::cout << name << " has bought product: " << buyProduct->name << " from shop: " << shop->name << std::endl;
                    return;
                }
            }

            std::cout << "Product: " << buyProduct->name << " is not in shop: " << shop->name << std::endl;
        }

        virtual void returnProduct(Product* returnedProduct, Shop* shop) {
            bool containsProduct = false;
            for (int i = 0; i < shop->productList.size(); i++) {
                if (shop->productList[i] == returnedProduct) {
                    containsProduct = true;
                    break;
                }
            }

            if (!containsProduct) {
                std::cout << "Shop: " << shop->name << " does not have product: " << returnedProduct->name << std::endl;
            }

            for (int j = 0; j < this->boughtProducts.size(); j++) {
                if (this->boughtProducts[j] == returnedProduct) {
                    this->boughtProducts.erase(this->boughtProducts.begin() + j);
                    bill -= returnedProduct->price * (1 - ACC_CHARGE);
                    std::cout << name << " has returned product: " << returnedProduct->name << " to shop: " << shop->name << std::endl;
                }
            }
        }


        virtual void displayInfo() {
            std::cout << "Name: " << name << "\nBill: " << bill << std::endl;

            std::cout << "List of bought products:" << std::endl;
            for (Product* boughtProd : boughtProducts) {
                std::cout << ">> ";
                boughtProd->displayInfo();
            }
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

        void buyProduct(Product* buyProduct, Shop* shop) {
            for (int j = 0; j < this->boughtProducts.size(); j++) {
                if (this->boughtProducts[j] == buyProduct) {
                    std::cout << name << " bought product: " << buyProduct->name << " already!!!"<< std::endl;
                    return;
                }
            }

            for (int i = 0; i < shop->productList.size(); i++) {
                if (shop->productList[i] == buyProduct) {
                    this->boughtProducts.push_back(buyProduct);
                    bill += buyProduct->price * (1 - discRate);

                    std::cout << name << " has bought product: " << buyProduct->name << " from shop: " << shop->name << std::endl;
                    return;
                }
            }

            std::cout << "Product: " << buyProduct->name << " is not in shop: " << shop->name << std::endl;
        }

        void returnProduct(Product* returnedProduct, Shop* shop) {
            bool containsProduct = false;
            for (int i = 0; i < shop->productList.size(); i++) {
                if (shop->productList[i] == returnedProduct) {
                    containsProduct = true;
                    break;
                }
            }

            if (!containsProduct) {
                std::cout << "Shop: " << shop->name << " does not have product: " << returnedProduct->name << std::endl;
                return;
            }

            for (int j = 0; j < this->boughtProducts.size(); j++) {
                if (this->boughtProducts[j] == returnedProduct) {
                    this->boughtProducts.erase(this->boughtProducts.begin() + j);
                    bill -= returnedProduct->price * (1 - discRate) * (1 - GOLD_CHARGE);
                    std::cout << name << " has returned product: " << returnedProduct->name << " to shop: " << shop->name << std::endl;
                    return;
                }
            }

            std::cout << name << " did not buy product: " << returnedProduct->name << std::endl;
        }

        void displayInfo() {
            Acc::displayInfo();
            std::cout << "Discount rate: " << discRate << std::endl;
        }
};

int main(){
    Product apple("apple", 100);
    Product orange("orange", 200);
    Product grape("grape", 300);

    Shop shop1("shop 1", vector<Product*>());
    shop1.addProduct(&apple);
    shop1.addProduct(&orange);

    Shop shop2("shop 2", vector<Product*>());
    shop2.addProduct(&grape);

    Acc acc("tuan", 0);
    GoldAcc goldAcc("khatun", 0, 0.15);

    acc.buyProduct(&apple, &shop1);
    acc.buyProduct(&orange, &shop1);
    acc.displayInfo();

    std::cout << std::endl;
    acc.returnProduct(&apple, &shop1);
    acc.displayInfo();

    std::cout << std::endl;
    goldAcc.buyProduct(&grape, &shop2);
    goldAcc.displayInfo();

    std::cout << std::endl;
    goldAcc.returnProduct(&grape, &shop1);
    goldAcc.buyProduct(&orange, &shop2);
    goldAcc.returnProduct(&grape, &shop2);
    goldAcc.returnProduct(&grape, &shop2);
    goldAcc.displayInfo();
    return 0;
}