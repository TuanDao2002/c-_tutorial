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
#include <vector>

using std::string;
using std::vector;

class Shop;

class Product {
    private:
        string name;
        string ID;
        double price;       
        Shop *shop;
    public:
        Product(){}
        Product(string name, string ID, double price) {
            this->name = name;
            this->ID = ID;
            this->price = price;
        }

        string getID() {
            return ID;
        }

        void displayInfo() {
            std::cout << ">> Product name: " << name
                      << ", ID: " << ID 
                      << ", price: " << price << std::endl;  
        }

        friend class Shop;
        friend class Customer;
        friend class Bill;
};

class Customer;

class Shop {
    private:
        string name;
        vector<Product*> productList = {};
        double totalRevenue = 0;
    public:
        Shop(){}
        Shop(string name) {
            this->name = name;
        }

        // function to add a product to the shop
        void addProduct(Product *product) {
            productList.push_back(product);
            product->shop = this;
        }

        void calculateBillForCustomer(Customer *customer, vector<string> productIDList);

        void displayInfo() {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Total revenue: " << totalRevenue << std::endl;

            std::cout << "List of products in the shop: " << std::endl;
            for (Product *prod : productList) {
                prod->displayInfo();
            }

            std::cout << std::endl;
        };
};

class Bill {
    private:
        vector<Product*> productList = {};
        vector<int> quantityRecord = {};
        double totalValue = 0;
    public:
        Bill(){}

        // function to return the list of product IDs from list of products in the bill
        vector<string> getProductIDList() {
            vector<string> productIDList = {};
            for (Product* prod : productList) {
                productIDList.push_back(prod->getID());
            }

            return productIDList;
        }

        void showInfo() {
            for (int i = 0; i < productList.size(); i++) {
                productList[i]->displayInfo();
                std::cout << ">> Quantity: " << quantityRecord[i] << std::endl;
                std::cout << ">> Total price: " << productList[i]->price * quantityRecord[i] << "\n\n";
            }

            std::cout << "Total value of bill: " << totalValue << std::endl;
        }

        friend class Customer;
        friend class Shop;
};

class Customer {
    private:
        string name;
        string ID;
        Bill bill;
        double totalSpend = 0;
    public:
        Customer(){}
        Customer(string name, string ID) {
            this->name = name;
            this->ID = ID;
            this->bill = Bill();
        }

        Bill &getBill() {
            return bill;
        }

        // function to buy the product
        void buyProduct(Product* product) {
            for (int i = 0; i < bill.productList.size(); i++) {
                if (bill.productList[i] == product) { // if the product is already in the bill, add the quantity of that product by 1
                    bill.quantityRecord[i] += 1; 
                    bill.totalValue += product->price;
                    return;   
                }
            }

            // otherwise, add the new product and assign its quantity to 1
            bill.productList.push_back(product);
            bill.quantityRecord.push_back(1);

            // increase the total value of the bill
            bill.totalValue += product->price;
        }

        void showInfo() {
            std::cout << "Name: " << name
                      << ", ID: " << ID 
                      << ", Total spend: " << totalSpend << "\n\n";

            std::cout << "Current bill:" << std::endl;
            bill.showInfo();
        }

        friend class Shop;
};

// function for the shop to calculate bill for customer
void Shop::calculateBillForCustomer(Customer *customer, vector<string> productIDList) {
    if (customer->bill.productList.empty() && customer->bill.quantityRecord.empty()) {
        std::cout << "The customer has no bill to calculate!!!" << std::endl;
        return;
    }

    for (Product *prod : productList) {
        for (int i = 0; i < productIDList.size(); i++) {
            if (prod->ID == productIDList[i]) { // if the product ID of the product is matched in the product ID list of the customer
                totalRevenue += prod->price * customer->bill.quantityRecord[i]; // total revenue of the shop is increased
                customer->totalSpend += prod->price * customer->bill.quantityRecord[i]; // total spend of the customer is increased
            }
        }
    }
}

int main(){
    Product apple("apple", "1", 100);
    Product orange("orange", "2", 200);
    Product lemon("lemon", "4", 300);

    Shop shop("circle K");
    shop.addProduct(&apple);
    shop.addProduct(&orange);
    shop.addProduct(&lemon);

    std::cout << "The info of the shop:" << std::endl;
    shop.displayInfo();

    Customer customer("khatun", "1");
    std::cout << "\nThe info of the customer: " << std::endl;
    customer.showInfo();

    shop.calculateBillForCustomer(&customer, customer.getBill().getProductIDList());

    // customer buys 2 apples, an orange and a lemon
    customer.buyProduct(&apple);
    customer.buyProduct(&orange);
    customer.buyProduct(&lemon);
    customer.buyProduct(&apple);

    // calculate bil for customer
    shop.calculateBillForCustomer(&customer, customer.getBill().getProductIDList());

    std::cout << "\nThe info of the shop after calculating the bill for customer:" << std::endl;
    shop.displayInfo();

    std::cout << "\nThe info of the customer after the bill is calculated:" << std::endl;
    customer.showInfo();
    return 0;
}