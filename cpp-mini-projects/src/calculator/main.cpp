#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Calculator.h"

std::vector<int> extractNumbers(std::string numbersString);
void printVector(std::vector<int> myVector);



int main(int argc, const char *argv[])
{
  // Interface to select operations
  // sin, cos, tan

  Calculator calc = Calculator();
  bool calculatorRunning = true;


  while(calculatorRunning){
    std::cout << "-----------------------------------" << std::endl;
    std::cout<< "What do you want to do with the calculator" << std::endl;
    std::cout<< "A - Addition" << std::endl;
    std::cout<< "S - Subtraction" << std::endl;
    std::cout<< "M - Multiplication" << std::endl;
    std::cout<< "D - Division" << std::endl;
    std::cout<< "SQ - Square" << std::endl;
    std::cout<< "SQR - Square Root" << std::endl;
    std::cout<< "Enter 'X' to close the game" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    std::string userOption, values;
    std::cin >> userOption;
    std::cin.ignore();
 
    transform(userOption.begin(), userOption.end(), userOption.begin(), ::toupper);

    if(userOption == "A"){
      std::cout << "Enter the numbers seperated with a space" << std::endl;

      std::getline(std::cin, values);
      std::vector<int> numberList = extractNumbers(values);
      int result = calc.add(numberList);

      std::cout << "====================================" << std::endl;
      std::cout << "   The result is => " << result << std::endl;
      std::cout << "====================================" << std::endl;
      std::cout << "\n" << std::endl;
      std::cin.clear();
    }
    else if(userOption == "S"){
      std::cout << "Enter the numbers seperated with a space" << std::endl;

      std::getline(std::cin, values);
      std::vector<int> numberList = extractNumbers(values);
      int result = calc.subtract(numberList);

      std::cout << "====================================" << std::endl;
      std::cout << "   The result is => " << result << std::endl;
      std::cout << "====================================" << std::endl;
      std::cout << "\n" << std::endl;
    }
    else if(userOption == "M"){
      std::cout << "Enter the numbers seperated with a space" << std::endl;

      std::getline(std::cin, values);
      std::vector<int> numberList = extractNumbers(values);
      int result = calc.multiply(numberList);

      std::cout << "====================================" << std::endl;
      std::cout << "   The result is => " << result << std::endl;
      std::cout << "====================================" << std::endl;
      std::cout << "\n" << std::endl;
    }
    else if(userOption == "D"){
      std::cout << "Enter the numbers seperated with a space" << std::endl;

      std::getline(std::cin, values);
      std::vector<int> numberList = extractNumbers(values);
      int result = calc.divide(numberList[0], numberList[1]);

      std::cout << "====================================" << std::endl;
      std::cout << "   The result is => " << result << std::endl;
      std::cout << "====================================" << std::endl;
      std::cout << "\n" << std::endl;
    }
    else if(userOption == "SQ"){
      std::cout << "Enter the numbers seperated with a space" << std::endl;

      std::getline(std::cin, values);
      std::vector<int> numberList = extractNumbers(values);
      int result = calc.square(numberList[0]);

      std::cout << "====================================" << std::endl;
      std::cout << "   The result is => " << result << std::endl;
      std::cout << "====================================" << std::endl;
      std::cout << "\n" << std::endl;
    }
    else if(userOption == "SQR"){
      std::cout << "Enter the numbers seperated with a space" << std::endl;

      std::getline(std::cin, values);
      std::vector<int> numberList = extractNumbers(values);
      int result = calc.squareRoot(numberList[0]);

      std::cout << "====================================" << std::endl;
      std::cout << "   The result is => " << result << std::endl;
      std::cout << "====================================" << std::endl;
      std::cout << "\n" << std::endl;
    }

    if(userOption == "X"){
      std::cout << "" << std::endl;
      std::cout << "See you later!" << std::endl;
      std::cout << "" << std::endl;
      calculatorRunning = false;
      continue;
    }
  }

  return 0;
}

std::vector<int> extractNumbers(std::string numbersString){
  std::vector<int> numberList;
  std::string curr = "";
  for (int i = 0; i <= numbersString.size(); i++){
    if(i == numbersString.size()){
      numberList.push_back(std::stoi(curr));
      curr = "";
    }
    if(std::isspace(numbersString[i])){
      numberList.push_back(std::stoi(curr));
      curr = "";
    }
    else {
      curr += numbersString[i];
    }
  }

  return numberList;
}

void printVector(std::vector<int> myVector){
  for (const auto& element : myVector) {
    std::cout << element << " ";
  }
  std::cout << "\n";
}