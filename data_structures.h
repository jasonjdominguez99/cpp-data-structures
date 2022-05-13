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

    // Array class definition
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


    // LinkedList class defintion
    template <typename T>
    class Node
    {
    private:
        T key;
        Node* next;

    public:
        Node(T value, Node* successor): key{value}, next{successor} {}

        T get() { return key; }
        Node* get_next() { return next; }
        void set_next(Node* new_next_node) { next = new_next_node; }

    };

    template <typename T>
    class LinkedList
    {
    private:
        Node<T>* head;
        Node<T>* current;

    public:
        LinkedList(T init_val);
        LinkedList(T init_vals[], int size);

        ~LinkedList();

        void add_start(T val);
        void add_end(T val);
        T get_current();
        bool iter_next();
        void reset();

        template<class U> friend std::ostream& operator<<(
            std::ostream& os,
            const LinkedList<U>& list
        );

    };

}

#endif // DATA-STRUCTURES_H_