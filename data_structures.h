// data_structures.h
//
// author: Jason Dominguez
// data: 2022-05-12
//
// header file for data structure
// class definitions

#include <iostream>
#include <utility>
#include <memory>

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

        T operator[](int i) const { return elements[i]; }
        T& operator[](int i) { return elements[i]; }
        std::pair<bool, int> find_first(T val) const;

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
        std::shared_ptr<Node<T>> next;

    public:
        Node(T value, std::shared_ptr<Node<T>> successor): key{value}, next{successor} {}

        T get() { return key; }
        std::shared_ptr<Node<T>> get_next() { return next; }
        void set_next(std::shared_ptr<Node<T>> new_next_node) { next = new_next_node; }

        template<class U> friend std::ostream& operator<<(
            std::ostream& os,
            const Node<U>& node
        );

    };

    template <typename T>
    class LinkedList
    {
    private:
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> current;

    public:
        LinkedList(T init_val);
        LinkedList(T init_vals[], int size);

        void add_start(T val);
        void add_end(T val);
        void set_current(std::shared_ptr<Node<T>> node);
        T get_current();
        std::shared_ptr<Node<T>> get_current_node();
        bool iter_next();
        void reset();

        template<class U> friend std::ostream& operator<<(
            std::ostream& os,
            const LinkedList<U>& list
        );

    };


    // Stack class definition
    

}

#endif // DATA-STRUCTURES_H_