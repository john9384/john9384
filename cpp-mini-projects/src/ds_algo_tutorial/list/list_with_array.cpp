#include <iostream>
#include <iomanip>
#include <vector>

void printArray(const int *arr, int arrSize);
void appendToArray(int *arr, int &arrSize, int maxSize, int data);
void insertInArray(int *arr, int &arrSize, int maxSize, int data, int pos);
void removeFromArray(int *arr, int &arrSize, int maxSize, int pos);

int main()
{
  int maxSize = 10;
  int arr[maxSize];
  int arrSize = 0;

  appendToArray(arr, arrSize, maxSize, 4);
  appendToArray(arr, arrSize, maxSize, 4);
  appendToArray(arr, arrSize, maxSize, 4);
  insertInArray(arr, arrSize, maxSize, 6, 2);
  removeFromArray(arr, arrSize, maxSize, 1);

  printArray(arr, arrSize);

  return 0;
}

void appendToArray(int* arr, int& arrSize, int maxSize, int data) {
  if (arrSize == maxSize) {
    int* newArr = new int[maxSize * 2];  // Allocate memory for new array
    std::copy(arr, arr + arrSize, newArr);

    delete[] arr; // Delete the old array (important to avoid memory leak)

    arr = newArr;
    arrSize = maxSize * 2;  // Update size of the array
  }

  arr[arrSize] = data;
  arrSize++;
}

void insertInArray(int* arr, int& arrSize, int maxSize, int data, int pos) {
  if (arrSize == maxSize) {
    int* newArr = new int[maxSize * 2];  // Allocate memory for new array
    std::copy(arr, arr + arrSize, newArr); // Copy existing data to the new array

    delete[] arr;// Delete the old array (important to avoid memory leak)

    arr = newArr;
    arrSize = maxSize * 2;
  }
  if (pos < 0 || pos > arrSize) {
    std::cerr << "Invalid insertion position\n";
    return;
  }

  for (int i = arrSize - 1; i >= pos; i--) {
    arr[i + 1] = arr[i];
  }

  arr[pos] = data;
  arrSize++;
}

void removeFromArray(int* arr, int& arrSize, int maxSize, int pos) {
  if (arrSize == 0) {
    std::cerr << "Array is empty\n";
    return;
  } else if (pos < 0 || pos >= arrSize) {
    std::cerr << "Invalid position\n";
    return;
  } else if (arrSize == 1) {
    arrSize = 0;
  } else {
    for (int i = pos; i < arrSize - 1; i++) {
      arr[i] = arr[i + 1];
    }
    arrSize--;
  }
}

void printArray(const int* arr, int arrSize) {
  std::cout << "[";
  for (int i = 0; i < arrSize; i++)
  {
    if(i == arrSize - 1){
      std::cout << arr[i] << "]";
    }else{
      std::cout  <<  arr[i] << ", ";
    }
  }

  std::cout << std::endl;
}


// Notes
// Time complexity of accessing an element is O(1)
// Time complexity of inserting an element at the end of the list is O(1)
// If the array is full, the time complexity will be O(n) (the copyin of array)
// Time complexity of inserting an element at a position will be O(n)
// Time complexity of removing an element at the end of the list is O(1)
// Time complexity of removing an element at a position will be O(n)