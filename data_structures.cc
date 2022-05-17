// data_structures.cc
//
// author: Jason Dominguez
// data: 2022-05-12
//
// source code file for data structure
// class implementations

#include <iostream>
#include <memory>
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

    // template <class T, int size>
    // int Array<T, size>::find(T val) const {
    //     for (int i=0; i < size; i++) {
    //         if (elements[i] == val) {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }

    // template <class T, int size>
    // T Array<T, size>::get(int index) {
    //     if (index >= size) {
    //         throw std::out_of_range(
    //             "Attempted to access element at index outside of the size of the array"
    //         );
    //     } else {
    //         return this->elements[index];
    //     }
    // }

    // template <class T, int size>
    // void Array<T, size>::set(T value, int index) {
    //     if (index >= size) {
    //         throw std::out_of_range(
    //             "Attempted to access element at index outside of the size of the array"
    //         );
    //     } else {
    //         this->elements[index] = value;
    //     }
    // }

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
    template <class U>
    std::ostream& operator<<(std::ostream& os, const Node<U>& node) {
        os << node.key;
        return os;
    }

    template<class T>
    LinkedList<T>::LinkedList(T init_val) {
        head, current = std::shared_ptr<Node<T>>(init_val, nullptr);
    }

    template<class T>
    LinkedList<T>::LinkedList(T init_vals[], int size) {
        head = std::make_shared<Node<T>>(init_vals[0], nullptr);

        std::shared_ptr<Node<T>> current_node = head;
        for (int i=1; i < size; i++) {
            std::shared_ptr<Node<T>> next_node{new Node<T>(init_vals[i], nullptr)};
            current_node->set_next(next_node);
            current_node = next_node;
        }

        current = head;
    }

    // template<class T>
    // LinkedList<T>::~LinkedList() {
    //     this->reset();
    //     while (current->get_next() != nullptr) {
    //         std::shared_ptr<Node<T>> prev_node = current;
    //         current = current->get_next();
    //     }
    // }

    template<class T>
    void LinkedList<T>::add_start(T val) {
        head = std::make_shared<Node<T>>(val, head);
    }

    template<class T>
    void LinkedList<T>::add_end(T val) {
        std::shared_ptr<Node<T>> current_node = current;
        while (current_node->get_next() != nullptr) {
            current_node = current_node->get_next();
        }

        current_node->set_next(std::make_shared<Node<T>>(val, nullptr));
    }

    template<class T>
    void LinkedList<T>::set_current(std::shared_ptr<Node<T>> node) {
        current = node;
    }

    template<class T>
    T LinkedList<T>::get_current() {
        return current->get();
    }

    template<class T>
    std::shared_ptr<Node<T>> LinkedList<T>::get_current_node() {
        return current;
    }

    template<class T>
    bool LinkedList<T>::iter_next() {
        if (this->current->get_next() != nullptr) {
            this->current = current->get_next();
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
    std::ostream& operator<<(std::ostream& os, LinkedList<U>& list) {
        os << "[ ";

        std::shared_ptr<Node<U>> current_node{list.get_current_node()};
        list.reset();
        while (list.get_current_node()->get_next() != nullptr) {
            os << list.get_current_node()->get() << " "; // something about this line cause last value in list to be messed up
            list.iter_next();
        }

        os << list.get_current_node()->get() << "]" << std::endl;

        list.set_current(current_node);

        return os;
    }


}