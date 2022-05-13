// data_structures.cc
//
// author: Jason Dominguez
// data: 2022-05-12
//
// source code file for data structure
// class implementations

#include <iostream>
#include <exception>
#include "data_structures.h"

namespace cpp_data_structures {

    // Array class method definitions
    template <class T, int size>
    Array<T, size>::Array(T array_elements[]) {
        // this is vulnerbable to segmentation faults
        // if array_elements is differnt size from
        // size
        for (int i=0; i < size; i++) {
            this->elements[i] = array_elements[i];
        }
    }

    template <class T, int size>
    T Array<T, size>::get(int index) {
        if (index >= size) {
            throw std::out_of_range(
                "Attempted to access element at index outside of the size of the array"
            );
        } else {
            return this->elements[index];
        }
    }

    template <class T, int size>
    void Array<T, size>::set(T value, int index) {
        if (index >= size) {
            throw std::out_of_range(
                "Attempted to access element at index outside of the size of the array"
            );
        } else {
            this->elements[index] = value;
        }
    }

    template <class U, int s>
    std::ostream& operator<<(std::ostream& os, const Array<U, s>& arr) {
        os << "[ ";
        for (int i=0; i < s; i++) {
            os << arr.elements[i] << " ";
        }
        os << "]";

        return os;
    }

}