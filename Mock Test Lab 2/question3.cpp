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
        Shop(string name) {
            this->name = name;
        }

        void addProduct(Product* product);

        friend class Acc;
        friend class GoldAcc;
        friend class Product;
};

class Product {
    private:
        string name;
        double price;
        Shop *shop;
    public:
        Product(){};
        Product(string name, double price) {
            this->name = name;
            this->price = price;
        }

        void displayInfo() {
            std::cout << "Name: " << name
                      << ", Price: " << price 
                      << ", Shop: " << shop->name << std::endl;  
        }

        friend class Acc;
        friend class GoldAcc;
        friend class Shop;
};

void Shop::addProduct(Product* product) {
    this->productList.push_back(product);
    product->shop = this;
}

void removeProduct(vector<Product*> &products, Product* removeProduct) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i] == removeProduct) {
            products.erase(products.begin() + i);
        }
    }
}

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

        virtual void buyProduct(Product* buyProduct) {
            this->boughtProducts.push_back(buyProduct);
            removeProduct(buyProduct->shop->productList, buyProduct);
            bill += buyProduct->price;
            std::cout << name << " has bought product: " << buyProduct->name << " from shop: " << buyProduct->shop->name << std::endl;
        }

        virtual void returnProduct(Product* returnedProduct) {
            removeProduct(this->boughtProducts, returnedProduct);
            returnedProduct->shop->productList.push_back(returnedProduct);
            bill -= returnedProduct->price * (1 - ACC_CHARGE);
            std::cout << name << " has returned product: " << returnedProduct->name << " to shop: " << returnedProduct->shop->name << std::endl;
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

        virtual void buyProduct(Product* buyProduct) {
            this->boughtProducts.push_back(buyProduct);
            removeProduct(buyProduct->shop->productList, buyProduct);
            bill += buyProduct->price * (1 - discRate);
            std::cout << name << " has bought product: " << buyProduct->name << " from shop: " << buyProduct->shop->name << std::endl;
        }

        virtual void returnProduct(Product* returnedProduct) {
            removeProduct(this->boughtProducts, returnedProduct);
            returnedProduct->shop->productList.push_back(returnedProduct);
            bill -= returnedProduct->price * (1 - discRate) * (1 - GOLD_CHARGE);
            std::cout << name << " has returned product: " << returnedProduct->name << " to shop: " << returnedProduct->shop->name << std::endl;
        }

        void displayInfo() {
            Acc::displayInfo();
            std::cout << "Discount rate: " << discRate << std::endl;
        }
};

int main(){
    //Create some shops and add products
    Shop shop1("Shop1");
    Product pd1("Shoe", 1000);
    shop1.addProduct(&pd1); 

    Shop shop2("Shop2");
    Product pd2("Car", 20000);
    shop2.addProduct(&pd2); 

    //Create two customers
    Acc acc1("Peter", 0);
    GoldAcc goldAcc1("John", 0, 0.2);

    //Test buying/ returning
    acc1.buyProduct(&pd1);
    acc1.buyProduct(&pd2);
    acc1.returnProduct(&pd1);
    acc1.displayInfo();

    goldAcc1.buyProduct(&pd1);
    goldAcc1.returnProduct(&pd1);
    goldAcc1.displayInfo();
    return 0;
}