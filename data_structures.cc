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

    // Array class method implementations
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


    // LinkedList class method implementations
    template<class T>
    LinkedList<T>::LinkedList(T init_val) {
        head, current = &Node<T>(init_val, nullptr);
    }

    template<class T>
    LinkedList<T>::LinkedList(T init_vals[], int size) {
        head = new Node<T>(init_vals[0], nullptr);

        Node<T>* current_node = head;
        for (int i=1; i < size; i++) {
            Node<T>* next_node = new Node<T>(init_vals[i], nullptr);
            current_node->set_next(next_node);
            current_node = next_node;
        }

        current = head;
    }

    template<class T>
    LinkedList<T>::~LinkedList() {
        this->reset();
        while (current->get_next() != nullptr) {
            Node<T>* prev_node = current;
            current = current->get_next();
            delete prev_node;
        }

        delete current;
    }

    template<class T>
    void LinkedList<T>::add_start(T val) {
        head = Node<T>(val, &head);
    }

    template<class T>
    void LinkedList<T>::add_end(T val) {
        Node<T> new_node = Node<T>(val, nullptr);

        Node<T>* current_node = current;
        while (current_node->get_next() != nullptr) {
            current_node = current_node->get_next();
        }

        current_node->set_next(&new_node);
    }

    template<class T>
    T LinkedList<T>::get_current() {
        return *current;
    }

    template<class T>
    bool LinkedList<T>::iter_next() {
        if (this->current.get_next() != nullptr) {
            this->current = current.get_next();
            return true;
        } else {
            return false;
        }
    }

    template<class T>
    void LinkedList<T>::reset() {
        current = head;
    }

    template <class U>
    std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list) {
        os << "[ ";

        Node<U>* current_node = list.head;
        while (current_node->get_next() != nullptr) {
            os << current_node->get() << " ";
            current_node = current_node->get_next();
        }

        os << current_node->get() << " ]";

        return os;
    }


}