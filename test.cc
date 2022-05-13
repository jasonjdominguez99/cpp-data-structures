// test.cc
//
// author: Jason Dominguez
// data: 2022-05-12
//
// source code file for testing data structure
// implementations

#include <iostream>
#include <string>
#include "data_structures.cc"

using namespace cpp_data_structures;

int main() {
    // Array class tests
    int numbers[5]{1, 2, 3, 4, 5};
    Array<int, 5> intArr(numbers);

    std::cout << intArr << std::endl;
    int index{1};
    std::cout << "Element " << index << " = " 
              << intArr.get(index) << std::endl;

    std::string words[3]{"hi", "jason", "cool"};
    Array<std::string, 3> strArr(words);

    std::cout << strArr << std::endl;
    index = 2;
    std::cout << "Element " << index << " is " 
              << strArr.get(index) << std::endl;
    
    strArr.set("new", index);
    std::cout << strArr << std::endl;
    std::cout << "Element " << index << " is " 
              << strArr.get(index) << std::endl;

    return 0;
}