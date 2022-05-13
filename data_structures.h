// data_structures.h
//
// author: Jason Dominguez
// data: 2022-05-12
//
// header file for data structure
// class definitions

#include <iostream>

#ifndef DATA_STRUCTURES_H_
#define DATA_STRUCTURES_H_

namespace cpp_data_structures {

    // array
    template <typename T, int size>
    class Array
    {
    private:
        T elements[size];

    public:
        Array(T array_elements[]);

        T get(int index);
        void set(T value, int index);

        template<class U, int s> friend std::ostream& operator<<(
            std::ostream& os,
            const Array<U, s>& arr
        );

    };

}

#endif // DATA-STRUCTURES_H_