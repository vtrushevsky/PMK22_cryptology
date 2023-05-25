#pragma once
#include <stdexcept>
#include <iostream>
#include <stdexcept>

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "triangle.h"

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        explicit Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        // Node constructor: Initializes the data member with the provided value and sets prev and next pointers to nullptr.
    };

public:
    class Iterator {
    public:
        explicit Iterator(Node* node);

        Iterator& operator++();
        Iterator operator++(int);
        T& operator*() const;
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

        Node* getNode() const; // New getNode() method to obtain a pointer to the node.

    private:
        Node* current;
    };

    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList(DoublyLinkedList&& other) noexcept;
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;
    ~DoublyLinkedList();

    void pushBack(const T& value);
    Iterator begin() const;
    Iterator end() const;
    void remove(const Iterator& iterator);
    void insertBefore(const T& value, Node* node);
    void sort();
    Node* findNode(const T& value) const;


private:
    Node* head;
    Node* tail;

    void copyList(const DoublyLinkedList& other);
    void moveList(DoublyLinkedList&& other) noexcept;
    void clear();
};

#endif // DOUBLYLINKEDLIST_H
