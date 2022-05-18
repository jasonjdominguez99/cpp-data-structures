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
    template <typename T, unsigned int size>
    class Array
    {
    private:
        T elements[size];

    public:
        Array(T array_elements[]);

        T operator[](int i) const { return elements[i]; }
        T& operator[](int i) { return elements[i]; }
        std::pair<bool, int> find_first(T val) const;

        template<class U, unsigned int s> friend std::ostream& operator<<(
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


    // AbstractStaticArray class definition
    template<typename T, unsigned int size>
    class AbstractStaticArray
    {
    protected:
        std::unique_ptr<T> elements[size];

    public:
        AbstractStaticArray();
        virtual ~AbstractStaticArray() {}

        virtual std::pair<bool, unsigned int> add(T val)=0;
        virtual T remove()=0;

        unsigned int num_filled() const;
        bool is_empty() const;
        bool is_full() const;

        T operator[](int i) const { return elements[i]; }

        template<class U, unsigned int s>
        friend std::ostream& operator<<(
            std::ostream& os,
            const AbstractStaticArray<U, s>& arr
        );

    }

    // Stack class definition
    template<typename T, unsigned int size>
    class Stack : public AbstractStaticArray
    {
    public:
        Stack() : AbstractStaticArray() {}
        virtual ~Stack() {}

        std::pair<bool, unsigned int> add(T val);
        T remove();

        std::pair<T, unsigned int> peek() const;

    };


    // Queue class defintion
    template<typename T, unsigned int size>
    class Queue
    {
    private:
        std::unique_ptr<T> elements[size];

    public:
        Queue() : AbstractStaticArray() {}
        virtual ~Queue() {}

        std::pair<bool, unsigned int> add(T val);
        T remove();

    };

}

#endif // DATA-STRUCTURES_H_