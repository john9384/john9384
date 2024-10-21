#include <cmath>
#include <vector>

class Calculator{
  public:
    int add(std::vector<int> numbers){
      int result = 0;
      std::cout << sizeof(numbers[0]);
      int arrSize = sizeof(&numbers) / sizeof(numbers[0]);
      for (int i = 0; i <= arrSize; i++){
        result += numbers[i];
      }

      return result;
    }

    int subtract(std::vector<int> numbers){
      int result = 0;
      std::cout << sizeof(numbers[0]);
      int arrSize = sizeof(&numbers) / sizeof(numbers[0]);
      for (int i = 0; i <= arrSize; i++){
        result -= numbers[i];
      }

      return result;
    }

    int multiply(std::vector<int> numbers){
      int result = 0;
      std::cout << sizeof(numbers[0]);
      int arrSize = sizeof(&numbers) / sizeof(numbers[0]);
      for (int i = 0; i <= arrSize; i++){
        result *= numbers[i];
      }

      return result;
    }

    float divide(float numerator, float denominator){
      if(denominator == 0){
        std::cout << "Cannot divide by zero" << std::endl;
        return 0;
      }

      else {
        float division = numerator / denominator;
        return division;
      }
    }

    int square(int number){
      return number * number;
    }

    float squareRoot(int number){
      return std::sqrt(number);
    }
};

// compilation command
// g++ main.cpp -o calculator