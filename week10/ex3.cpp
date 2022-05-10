#include <iostream>
#include <vector>

using std::vector;

template<typename type>
class MyClass {
    private:
        vector<type> vector = {};
    public:
        MyClass() {}

        bool find(type element) {
            for (auto &e : vector) {
                if (e == element) {
                    return true;
                }
            }

            return false;
        }

        void insert(type element) {
            vector.push_back(element);
        }

        bool remove(type element) {
            for (int i = 0; i < vector.size(); i++) {
                if (vector[i] == element) {
                    vector.erase(vector.begin() + i);
                    return true;
                    break;
                }
            }

            return false;
        }

        void display() {
            for (auto e : vector) {
                std::cout << e << " ";
            }

            std::cout << std::endl;
        }
};

int main(){
    MyClass<int> intVector;
    intVector.insert(2);
    intVector.insert(3);
    intVector.insert(5);
    if (!intVector.find(4)) {
        std::cout << "4 is not in int vector" << std::endl;
    }

    intVector.remove(5);
    intVector.display();

    MyClass<double> doubleVector;
    doubleVector.insert(2.2);
    doubleVector.insert(3.2);
    doubleVector.display();
    return 0;
}