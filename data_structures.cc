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
    template<class T, unsigned int size>
    Array<T, size>::Array(T array_elements[]) {
        // this is vulnerbable to segmentation faults
        // if array_elements is differnt size from
        // size
        for (int i=0; i < size; i++) {
            this->elements[i] = array_elements[i];
        }
    }

    template<class T, unsigned int size>
    std::pair<bool, int> Array<T, size>::find_first(T val) const {
        for (int i=0; i < size; i++) {
            if (elements[i] == val) {
                return std::make_pair(true, i);
            }
        }

        return std::make_pair<bool, int>(false, 0);
    }

    template <class U, unsigned int s>
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

        os << list.get_current_node()->get() << "]";

        list.set_current(current_node);

        return os;
    }


    // AbstractStaticArray class method implementations
    template<class T, unsigned int size>
    AbstractStaticArray<T, size>::AbstractStaticArray() {
        for (int i=0; i < size; i++) {
            elements[i] = std::unique_ptr<T>{nullptr};
        }
    }

    template<class T, unsigned int size>
    std::pair<bool, unsigned int> AbstractStaticArray<T, size>::add(T val) {
        if (this->is_full()) {
            return std::pair<bool, unsigned int>(false, 0);
        }

        unsigned int last_element_idx{this->num_filled()};
        elements[last_element_idx] = std::make_unique<T>(val);

        return std::pair<bool, unsigned int>(
            true, last_element_idx
        );
    }

    template<class T, unsigned int size>
    unsigned int AbstractStaticArray<T, size>::num_filled() const {
        for (int i=0; i < size; i++) {
            if (elements[i] == nullptr) {
                return i;
            }
        }
        return size;
    }

    template<class T, unsigned int size>
    bool AbstractStaticArray<T, size>::is_empty() const {
        return elements[0] == nullptr;
    }

    template<class T, unsigned int size>
    bool AbstractStaticArray<T, size>::is_full() const {
        return elements[size - 1] != nullptr;
    }

    template<class U, unsigned int s>
    std::ostream& operator<<(
        std::ostream& os,
        const AbstractStaticArray<U, s>& arr) {
        
        os << "[ ";

        for (int i=0; i < s; i++) {
            if (arr.elements[i] != nullptr) {
                os << *arr.elements[i] << " ";
            } else {
                os << "- ";
            }
        }

        os << "]";

        return os;
    }


    // Stack class method implementations
    template<class T, unsigned int size>
    T Stack<T, size>::remove() {
        std::pair<T, unsigned int> top_of_stack{this->peek()};
        elements[top_of_stack.second] = std::unique_ptr<T>{nullptr};

        return top_of_stack.first;
    }

    template<class T, unsigned int size>
    std::pair<T, unsigned int> Stack<T, size>::peek() const {
        if (this->is_empty()) {
            throw std::out_of_range(
                "Attempted to access an empty stack"
            );
        }
        unsigned int top_of_stack{this->num_filled() - 1};

        return std::pair<T, unsigned int>(
            *elements[top_of_stack],
            top_of_stack
        );
    }


    // Queue class method implementations
    template<class T, unsigned int size>
    std::pair<bool, unsigned int> Queue<T, size>::add(T val) {
        
    }

    template<class T, unsigned int size>
    T Queue<T, size>::remove() {
        
    }


}