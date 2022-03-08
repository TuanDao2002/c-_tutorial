#include<iostream>

int maxOfElement(int arr[], int size) {
    int max = arr[0]; // assign max to the first element in array
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) { // if there is an element in array greater than max, assign max to that element
            max = arr[i];
        }
    }

    return max;
}

int main(){
    int size;
    std::cout << "Enter size of the array: ";
    std::cin >> size;

    int arr[size];
    std::cout << "Enter values for the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i]; 
    }

    std::cout << "The max element is: " <<  maxOfElement(arr, size);

    return 0;
}