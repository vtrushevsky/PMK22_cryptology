#include "doublylinkedlist.h"

template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node* node) : current(node) {}
// Iterator constructor: Initializes the iterator with the provided node pointer.

template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}
// Pre-increment operator: Moves the iterator to the next node in the list and returns the updated iterator.

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}
// Post-increment operator: Creates a temporary iterator pointing to the current node, moves the current iterator to the next node, and returns the temporary iterator.

template<typename T>
T& DoublyLinkedList<T>::Iterator::operator*() const {
    return current->data;
}
// Dereference operator: Returns a reference to the data stored in the current node.

template<typename T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}
// Equality operator: Compares two iterators for equality based on their current node pointers.

template<typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}
// Inequality operator: Compares two iterators for inequality based on their current node pointers.

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}
// Default constructor: Initializes the head and tail pointers to nullptr.

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) {
    copyList(other);
}
// Copy constructor: Creates a new doubly linked list and copies the contents of the other list into it.

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList&& other) noexcept : head(nullptr), tail(nullptr) {
    moveList(std::move(other));
}
// Move constructor: Moves the contents of the other list to a new doubly linked list.

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& other) noexcept {
    if (this != &other) {
        clear();
        moveList(std::move(other));
    }
    return *this;
}
// Move assignment operator: Moves the contents of the other list to the current list.

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
    if (this != &other) {
        clear();
        copyList(other);
    }
    return *this;
}
// Copy assignment operator: Copies the contents of the other list to the current list.

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}
// Destructor: Deallocates memory and clears the doubly linked list.

template<typename T>
void DoublyLinkedList<T>::pushBack(const T& value) {
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
// Inserts a new node with the provided value at the end of the list.

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() const {
    return Iterator(head);
}
// Returns an iterator pointing to the first node in the list.

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() const {
    return Iterator(nullptr);  // Constructor call for Iterator class
}

template<typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::Iterator::getNode() const {
    return current;  // Returns the current node pointer
}

template<typename T>
void DoublyLinkedList<T>::remove(const Iterator& iterator) {
    Node* node = iterator.getNode();  // Accessing the public method getNode() of the Iterator class
    if (node == nullptr)
        throw std::runtime_error("Error: Iterator is invalid.");

    if (node->prev != nullptr)
        node->prev->next = node->next;
    else
        head = node->next;

    if (node->next != nullptr)
        node->next->prev = node->prev;
    else
        tail = node->prev;

    delete node;  // Deleting the node
}

template<typename T>
void DoublyLinkedList<T>::insertBefore(const T& value, Node* node) {
    Node* newNode = new Node(value);  // Constructor call for Node class
    newNode->prev = node->prev;
    newNode->next = node;
    if (node->prev != nullptr)
        node->prev->next = newNode;
    else
        head = newNode;
    node->prev = newNode;
}

template<typename T>
void DoublyLinkedList<T>::sort() {
    if (head == nullptr || head == tail)
        return;

    DoublyLinkedList<T> sortedList;  // Constructor call for DoublyLinkedList class
    for (const T& value : *this) {
        bool inserted = false;
        for (const auto& sortedValue : sortedList) {
            if (value.getArea() < sortedValue.getArea()) {
                typename DoublyLinkedList<T>::Node* node = sortedList.findNode(sortedValue);
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
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::findNode(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value)
            return current;
        current = current->next;
    }
    return nullptr;
}

template<typename T>
void DoublyLinkedList<T>::copyList(const DoublyLinkedList& other) {
    for (const T& value : other)
        pushBack(value);
}

template<typename T>
void DoublyLinkedList<T>::moveList(DoublyLinkedList&& other) noexcept {
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;  // Deleting the current node
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}


template<typename T>
DoublyLinkedList<T> filterTriangles(const DoublyLinkedList<Triangle>& inputList, double minPerimeter, double maxPerimeter) {
    DoublyLinkedList<Triangle> outputList;  // Constructor call for DoublyLinkedList class
    for (const Triangle& triangle : inputList) {
        double perimeter = triangle.getPerimeter();

        if (perimeter >= minPerimeter && perimeter <= maxPerimeter)
            outputList.pushBack(triangle);  // Calls pushBack() method to add the triangle to the outputList
    }
    return outputList;  // Returns the outputList
}


// Explicit template instantiation
template class DoublyLinkedList<Triangle>;