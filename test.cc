// test.cc
//
// author: Jason Dominguez
// data: 2022-05-12
//
// source code file for testing data structure
// implementations

#include <iostream>
#include <utility>
#include <string>
#include "data_structures.cc"

using namespace cpp_data_structures;

int main() {
    // //-----Array class tests-----
    // std::cout << "-----Array class tests-----" << std::endl;

    // // Testing int array constructor
    // int numbers[5]{1, 2, 3, 4, 5};
    // Array<int, 5> intArr(numbers);
    // std::cout << intArr << std::endl;

    // // Testing int array accessor
    // int index{1};
    // std::cout << "Element " << index << " is " 
    //           << intArr[index] << std::endl;

    // // Testing std::string array constructor
    // std::string words[3]{"hi", "jason", "cool"};
    // Array<std::string, 3> strArr(words);
    // std::cout << strArr << std::endl;

    // // Testing std::string array accessor
    // index = 2;
    // std::cout << "Element " << index << " is " 
    //           << strArr[index] << std::endl;
    
    // // Testing std::string array element reassignment
    // strArr[index] = "new";
    // std::cout << strArr << std::endl;
    // std::cout << "Element " << index << " is " 
    //           << strArr[index] << std::endl;

    // // Testing searching in std::string array
    // std::cout << strArr << std::endl;
    // std::string string_to_find{"new"};
    // std::pair<bool, int> search_result{strArr.find_first(string_to_find)};
    // std::cout << string_to_find << " is ";
    // if (search_result.first == true) {
    //     std::cout << "at index " << search_result.second << std::endl;
    // } else {
    //     std::cout << "not in the array!" << std::endl;
    // }

    // std::cout << std::endl << std::endl;
    // //---------------------------------


    // //-----LinkedList class tests-----
    // std::cout << "-----LinkedList class tests-----" << std::endl;

    // // Testing int linked list constructor
    // LinkedList<int> intList(numbers, 5);
    // std::cout << intList << std::endl;

    // // Testing int linked list iterator
    // intList.iter_next();
    // std::cout << "Next number is " << intList.get_current() << std::endl;

    // // Testing int linked list iterator reset method
    // intList.reset();
    // std::cout << "Starting number is " << intList.get_current() << std::endl;

    // // Testing std::string linked list constructor
    // LinkedList<std::string> strList(words, 3);
    // std::cout << strList << std::endl;

    // // Testing adding to the start of a linked list
    // std::string new_start_word{"start"};
    // std::cout << "Adding " << new_start_word << " to the start of the list:" << std::endl;
    // strList.add_start(new_start_word);
    // std::cout << strList << std::endl;

    // // Testing adding to the end of a linked list
    // std::string new_end_word{"end"};
    // std::cout << "Adding " << new_end_word << " to the end of the list:" << std::endl;
    // strList.add_end(new_end_word);
    // std::cout << strList << std::endl;

    // std::cout << std::endl << std::endl;
    // //---------------------------------

    //-----Stack class tests-----
    std::cout << "-----Stack class tests-----" << std::endl;

    // Testing int stack constructor
    const unsigned int stack_size{5};
    Stack<int, stack_size> intStack{};
    std::cout << intStack << std::endl;

    // Testing is_empty method
    std::string is_empty{};
    if (intStack.is_empty()) {
        is_empty = "is empty";
    } else {
        is_empty = "is not empty";
    }
    std::cout << "This stack " << is_empty << std::endl;

    // Testing adding to the stack
    int num_to_add{5};
    std::cout << "Adding " << num_to_add << " to"
              << std::endl << intStack << std::endl
              << "gives" << std::endl;
    intStack.add(num_to_add);
    std::cout << intStack << std::endl;
    
    // Testing is_full method
    for (int i=1; i < stack_size; i++) {
        intStack.add(2*i);
    }
    std::cout << intStack << std::endl;
    std::string is_full{};
    if (intStack.is_full()) {
        is_full = "is full";
    } else {
        is_full = "is not full";
    }
    std::cout << "This stack " << is_full << std::endl;

    // Testing peek method
    std::cout << "The value at the top of the stack is "
              << intStack.peek().first << std::endl;

    // Testing removing from the stack
    std::cout << "Removing " << intStack.remove() << " and " << intStack.remove()
              << " from the top leaves us with " << std::endl
              << intStack << std::endl;

    std::cout << std::endl << std::endl;
    //---------------------------------

    //--------Queue class tests--------

    // Testing std::string queue constructor
    const unsigned int queue_size{3};
    Queue<std::string, queue_size> strQueue{};
    std::cout << strQueue << std::endl;

    // Testing adding to the queue
    strQueue.add("Dave");
    strQueue.add("Jason");
    strQueue.add("Billy");
    std::cout << strQueue << std::endl;

    // Testing removing from the queue
    strQueue.remove();
    std::cout << strQueue << std::endl;

    //---------------------------------


    return 0;

}