#include <iostream>

int max_element(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  int size;
  std::cout << "Enter size for the array: ";
  std::cin >> size;

  int arr[size];
  std::cout << "Enter values for the array: ";
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }

  std::cout << ">> Maximum value is: " << max_element(arr, size) << "\n";

  return 0;
}