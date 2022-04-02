#include <iostream>

class Juice
{
private:
    std::string name;
    int *price;

public:
    // Default contructor
    Juice()
    {
        this->price = new int(0);
    }

    Juice(std::string name, int price)
    {
        this->name = name;
        this->price = new int(price);
    }

    // copy constructor
    Juice(const Juice& juice) {
        this->name = juice.name;
        int old_price = *juice.price;
        this->price = new int(old_price);
    }

    // Display method
    void display()
    {
        std::cout << "Juice name: " << name << std::endl;
        std::cout << "Price: " << *price << std::endl;
        std::cout << std::endl;
    }

    // Overload operators --
    Juice operator--(int)
    {
        Juice temp = *this;
        (*(this->price))--;
        return temp;
    }

    // Overload operators juice + juice
    Juice operator+(Juice juice)
    {
        Juice temp = *this;
        if (this->name != juice.name)
        {
            temp.name = "NA";
            *(temp.price) = 0;
        }
        else
        {
            *(temp.price) += *(juice.price);
        }
        return temp;
    }

    // Destructor
    ~Juice()
    {
				// std::cout << name << " " << price << std::endl;
				// if (price != NULL) {
				// 	delete price;
				// }

			delete price;
    }

    // Overload operators n - juice
    friend Juice operator-(int n, Juice juice);
};

Juice operator-(int n, Juice juice)
{
    Juice result = juice;
    *(result.price) = *(juice.price) * ((100 - n) / 100.0);
    return result;
}

int main(int argc, char *argv[])
{
    // Question A
    const int SIZE = 3;
    Juice *arr = new Juice [SIZE] {Juice("Apple", 50), Juice("Watermelon", 22), Juice("Orange", 33)};

    for (int i = 0; i < SIZE; i++)
    {
        arr[i].display();
    }

    // Question B
    Juice juice1("Kiwi", 100);
    Juice juice2("Kiwi", 50);
    Juice juice_temp = juice1--;
    juice_temp.display();

    Juice juice3 = juice1 + juice2;
    juice3.display();

    Juice juice4 = 50 - juice2;
    juice4.display();

    delete[] arr;

    return 0;
}