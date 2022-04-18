#if 1
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
    std::vector<int> vectorInt;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vectorInt.push_back(i);
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
    } while (num < 1);

    std::cout << "Enter the value to insert: " << std::endl;
    std::cin >> val;
	
	// vectorInt.resize(index + 1);
    std::vector<int>::iterator it = vectorInt.begin();
    it = vectorInt.insert(it + index, num, val);

    std::cout << "After inserting " << num << " elements of value " << val << " at index " << index << std::endl;
    display(vectorInt);

	// add the whole new vector to the current vector at the current iterator
    // end iterator points after the last element in the vector
    // insert all element in range [begin, end) (end is not included)
    std::vector<int> anotherVector (2, 400);
	// vectorInt.resize(vectorInt.size() + 2);
	it = vectorInt.begin();
    vectorInt.insert(it, anotherVector.begin(), anotherVector.end());
	std::cout << "Add new vector to current vector:\n";
    display(vectorInt);

	// add the whole new array to new vector at the current iterator 
    // all elements from index 0 to index 2 (index 3 is not included)
    int arr[3] = {3,2,1};
	// vectorInt.resize(vectorInt.size() + 3);
    std::cout << "Add new array to current vector: " << std::endl;
	vectorInt.insert(it, arr, arr + 3);
    display(vectorInt);

    int deleteIndex;

    do {
        std::cout << "Enter the index to delete: " << std::endl;
        std::cin >> deleteIndex;
    } while(deleteIndex < 0);

    it = vectorInt.begin();
    vectorInt.erase(it + deleteIndex - 1);

    std::cout << "After delete element at index: " << deleteIndex << std::endl;
    display(vectorInt);
    return 0;
}

#endif