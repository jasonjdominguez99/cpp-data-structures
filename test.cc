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
    //-----Array class tests-----
    std::cout << "-----Array class tests-----" << std::endl;

    int numbers[5]{1, 2, 3, 4, 5};
    Array<int, 5> intArr(numbers);
    std::cout << intArr << std::endl;

    int index{1};
    std::cout << "Element " << index << " is " 
              << intArr[index] << std::endl;

    std::string words[3]{"hi", "jason", "cool"};
    Array<std::string, 3> strArr(words);
    std::cout << strArr << std::endl;

    index = 2;
    std::cout << "Element " << index << " is " 
              << strArr[index] << std::endl;
    
    strArr[index] = "new";
    std::cout << strArr << std::endl;
    std::cout << "Element " << index << " is " 
              << strArr[index] << std::endl;

    std::cout << std::endl << std::endl;

    //-----LinkedList class tests-----
    std::cout << "-----LinkedList class tests-----" << std::endl;

    LinkedList<int> intList(numbers, 5);
    std::cout << intList << std::endl;

    intList.iter_next();
    std::cout << "Next number is " << intList.get_current() << std::endl;

    intList.reset();
    std::cout << "Starting number is " << intList.get_current() << std::endl;

    LinkedList<std::string> strList(words, 3);
    std::cout << strList << std::endl;

    std::string new_start_word{"start"};
    std::cout << "Adding " << new_start_word << " to the start of the list:" << std::endl;
    strList.add_start(new_start_word);
    std::cout << strList << std::endl;

    std::string new_end_word{"end"};
    std::cout << "Adding " << new_end_word << " to the end of the list:" << std::endl;
    strList.add_end(new_end_word);
    std::cout << strList << std::endl;

    std::cout << std::endl << std::endl;


    return 0;

}