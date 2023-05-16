#include "DoubleList.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

template<typename T>
DoubleList<T>::Iterator::Iterator(Node* node) : current(node) {}

template<typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr) {}

template<typename T>
DoubleList<T>::DoubleList(DoubleList&& other) noexcept : head(nullptr), tail(nullptr) { moveList(move(other));}


template<typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& other) noexcept {
    if (this != &other) {
        clear();
        moveList(std::move(other));
    }
    return *this;
}

template<typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other) {
    if (this != &other) {
        clear();
        copyList(other);
    }
    return *this;
}


template<typename T>
void DoubleList<T>::PushBack(const T& value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}


//template<typename T>
//void DoubleList<T>::remove(const Iterator& iterator) {
//    Node* node = iterator.getNode();  
//    if (node == nullptr)
//        throw std::runtime_error("Error: Iterator is invalid.");
//
//    if (node->prev != nullptr)
//        node->prev->next = node->next;
//    else
//        head = node->next;
//
//    if (node->next != nullptr)
//        node->next->prev = node->prev;
//    else
//        tail = node->prev;
//
//    delete node;  
//}

template<typename T>
void DoubleList<T>::Insert(Node* node, const T& value) {
    Node* newNode = new Node(value); 
    newNode->prev = node->prev;
    newNode->next = node;
    if (node->prev != nullptr)
        node->prev->next = newNode;
    else
        head = newNode;
    node->prev = newNode;
}

template<typename T>
void DoubleList<T>::Sort() {
    if (head == nullptr || head == tail)
        return;

    DoubleList<T> sortedList;  
    for (const T& value : *this) {
        bool inserted = false;
        for (const auto& sortedValue : sortedList) {
            if (value.getArea() < sortedValue.getArea()) {
                typename DoubleList<T>::Node* node = sortedList.findNode(sortedValue);
                sortedList.insertBefore(value, node);
                inserted = true;
                break;
            }
        }
        if (!inserted)
            sortedList.pushBack(value);
    }

    head = sortedList.head;
    tail = sortedList.tail;
    sortedList.head = nullptr;
    sortedList.tail = nullptr;

    for (const T& value : *this) {
        std::cout << "Triangle: A = " << value.getSideA() << ", B = " << value.getSideB() << ", C = " << value.getSideC() << "; area = " << value.getArea() << ", perimeter = " << value.getPerimeter() << "." << std::endl;
    }
}

template<typename T>
typename DoubleList<T>::Node* DoubleList<T>::FindNode(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value)
            return current;
        current = current->next;
    }
    return nullptr;
}

template<typename T>
void DoubleList<T>::CopyList(const DoubleList& other) {
    for (const T& value : other)
        pushBack(value);
}

template<typename T>
void DoubleList<T>::MoveList(DoubleList&& other) noexcept {
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

template<typename T>
void DoubleList<T>::Clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;  
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}


template<typename T>
DoubleList<T> filterTriangles(const DoubleList<Triangle>& inputList, double minPerimeter, double maxPerimeter) {
    DoubleList<Triangle> outputList; 
    for (const Triangle& triangle : inputList) {
        double perimeter = triangle.getPerimeter();

        if (perimeter >= minPerimeter && perimeter <= maxPerimeter)
            outputList.pushBack(triangle);  
    }
    return outputList;  
}

