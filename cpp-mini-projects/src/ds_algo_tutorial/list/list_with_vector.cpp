#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr);
void appendToArray(std::vector<int>& arr, int data);
void insertInArray(std::vector<int>& arr, int data, int pos);
void removeFromArray(std::vector<int>& arr, int pos);

int main() {
  // Declare a vector with initial capacity
  std::vector<int> arr(10);

  // Append elements to the vector
  appendToArray(arr, 4);
  appendToArray(arr, 4);
  appendToArray(arr, 4);

  // Insert element at position 2
  insertInArray(arr, 6, 2);

  // Remove element at position 1
  removeFromArray(arr, 1);

  // Print the contents of the vector
  printArray(arr);

  return 0;
}

// Function to append data to the vector
void appendToArray(std::vector<int>& arr, int data) {
  arr.push_back(data); // Use vector's push_back for efficient appending
}

// Function to insert data at a specific position
void insertInArray(std::vector<int>& arr, int data, int pos) {
  // Check if insertion position is valid
  if (pos < 0 || pos > arr.size()) {
    std::cerr << "Invalid insertion position\n";
    return;
  }

  // Use vector's insert iterator to insert at position
  arr.insert(arr.begin() + pos, data);
}

// Function to remove element at a specific position
void removeFromArray(std::vector<int>& arr, int pos) {
  // Check if array is empty or position is invalid
  if (arr.empty()) {
    std::cerr << "Array is empty\n";
    return;
  } else if (pos < 0 || pos >= arr.size()) {
    std::cerr << "Invalid position\n";
    return;
  }

  // Use vector's erase iterator to remove element
  arr.erase(arr.begin() + pos);
}

// Function to print the vector elements
void printArray(const std::vector<int>& arr) {
  std::cout << "[";
  for (int num : arr) {
    std::cout << num << ", ";
  }
  
  if (!arr.empty()) {
    std::cout << "\b\b]"; // Backspace twice to remove ", "
  } else {
    std::cout << "]";
  }
  std::cout << std::endl;
}
