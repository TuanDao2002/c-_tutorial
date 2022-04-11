#include <iostream>
#include <vector>

#define VECTOR_SIZE 10

void display(std::vector<int> v) {  
    for (auto e : v) {
        std::cout << e << " ";
    }

    std::cout << std::endl;
}

int main(){
    std::vector<int> vectorInt(VECTOR_SIZE);
    for (int i = 0; i < vectorInt.size(); i++) {
        vectorInt.at(i) = i;
    }

    vectorInt.push_back(100);

    display(vectorInt);

    std::cout << "Last element of vector: " << vectorInt.back() << std::endl;
    std::cout << "First element of vector: " << vectorInt.front() << std::endl;
    
    int index, num, val;

    do {
        std::cout << "Enter the index to insert: " << std::endl;
        std::cin >> index;
    } while(index < 0);

    do {
        std::cout << "Enter the number of elements to insert: " << std::endl;
        std::cin >> num;
    } while (num < 1 || num > 5); // too large number of elements can lead to core dump

    std::cout << "Enter the value to insert: " << std::endl;
    std::cin >> val;

    std::vector<int>::iterator it = vectorInt.begin();
    it += index;
    vectorInt.insert(it, num, val);

    std::cout << "After inserting " << num << " elements of value " << val << " at index " << index << std::endl;
    display(vectorInt);

    std::vector<int> anotherVector (2, 400);

    // add the whole new vector to the current vector at the current iterator
    // end iterator points after the last element in the vector
    // insert all element in range [begin, end) (end is not included)
    vectorInt.insert(it, anotherVector.begin(), anotherVector.end());

    int arr[3] = {3,2,1};
    // add the whole new array to new vector at the current iterator 
    // all elements from index 0 to index 2 (index 3 is not included)
    vectorInt.insert(it, arr, arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "Vector after update: " << std::endl;
    display(vectorInt);

    int deleteIndex;

    do {
        std::cout << "Enter the index to delete: " << std::endl;
        std::cin >> deleteIndex;
    } while(deleteIndex < 0 || deleteIndex > 10);

    it = vectorInt.begin();
    vectorInt.erase(it + deleteIndex - 1);

    std::cout << "After delete element at index: " << deleteIndex << std::endl;
    display(vectorInt);

    vectorInt.clear();
    std::cout << "After clearing all elements: " << std::endl;
    display(vectorInt);
    if (vectorInt.empty()) {
        std::cout << "The vector is clear" << std::endl;
    }
    return 0;
}