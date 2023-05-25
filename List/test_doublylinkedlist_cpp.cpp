#include "doublylinkedlist.h"
#include <iostream>
#include <cassert>

// Test case for the pushBack() function
void testPushBack() {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    DoublyLinkedList<int>::Iterator it = list.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
    ++it;
    assert(it == list.end());
}

// Test case for the remove() function
void testRemove() {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    DoublyLinkedList<int>::Iterator it = list.begin();
    list.remove(it);
    assert(*it == 2);  // Iterator should still point to the same node
    ++it;
    assert(*it == 3);
    ++it;
    assert(it == list.end());
}

// Test case for the copy constructor and assignment operator
void testCopy() {
    DoublyLinkedList<int> list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);

    DoublyLinkedList<int> list2 = list1;  // Copy constructor
    assert(list2.begin().getNode() != list1.begin().getNode());  // Nodes should be different

    DoublyLinkedList<int> list3;
    list3.pushBack(4);
    list3.pushBack(5);
    list3 = list1;  // Assignment operator
    assert(list3.begin().getNode() != list1.begin().getNode());  // Nodes should be different
}

// Test case for the move constructor and assignment operator
void testMove() {
    DoublyLinkedList<int> list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);

    DoublyLinkedList<int> list2 = std::move(list1);  // Move constructor
    assert(list1.begin().getNode() == nullptr);  // Original list should be empty
    assert(*list2.begin() == 1);  // Move should preserve the content

    DoublyLinkedList<int> list3;
    list3.pushBack(4);
    list3.pushBack(5);
    list3 = std::move(list2);  // Move assignment operator
    assert(list2.begin().getNode() == nullptr);  // Original list should be empty
    assert(*list3.begin() == 1);  // Move should preserve the content
}

// Test case for insertBefore() function
void testInsertBefore() {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(3);
    DoublyLinkedList<int>::Node* node = list.begin().getNode();
    list.insertBefore(2, node);

    DoublyLinkedList<int>::Iterator it = list.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
    ++it;
    assert(it == list.end());
}

// Test case for sort() function
void testSort() {
    DoublyLinkedList<Triangle> list;
    Triangle t1(3, 4, 5);
    Triangle t2(5, 12, 13);
    Triangle t3(8, 15, 17);
    list.pushBack(t2);
    list.pushBack(t1);
    list.pushBack(t3);
    list.sort();

    DoublyLinkedList<Triangle>::Iterator it = list.begin();
    assert(*it == t1);
    ++it;
    assert(*it == t2);
    ++it;
    assert(*it == t3);
    ++it;
    assert(it == list.end());
}

// Test case for findNode() function
void testFindNode() {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    DoublyLinkedList<int>::Node* node = list.findNode(2);

    assert(node != nullptr);
    assert(node->data == 2);
}

// Test case for copyList() function
void testCopyList() {
    DoublyLinkedList<int> list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);
    DoublyLinkedList<int> list2;
    list2.copyList(list1);

    DoublyLinkedList<int>::Iterator it1 = list1.begin();
    DoublyLinkedList<int>::Iterator it2 = list2.begin();

    while (it1 != list1.end()) {
        assert(*it1 == *it2);
        ++it1;
        ++it2;
    }
}

// Test case for moveList() function
void testMoveList() {
    DoublyLinkedList<int> list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);
    DoublyLinkedList<int> list2;
    list2.moveList(std::move(list1));

    assert(list1.begin().getNode() == nullptr);  // Original list should be empty

    DoublyLinkedList<int>::Iterator it = list2.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
    ++it;
    assert(it == list2.end());
}

// Test case for clear() function
void testClear() {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.clear();

    assert(list.begin().getNode() == nullptr);  // List should be empty
}

// Test case for filterTriangles() function
void testFilterTriangles() {
    DoublyLinkedList<Triangle> inputList;
    Triangle t1(3, 4, 5);
    Triangle t2(5, 12, 13);
    Triangle t3(8, 15, 17);
    inputList.pushBack(t1);
    inputList.pushBack(t2);
    inputList.pushBack(t3);
    DoublyLinkedList<Triangle> outputList = filterTriangles(inputList, 10, 20);
    DoublyLinkedList<Triangle>::Iterator it = outputList.begin();
    assert(*it == t2);
    ++it;
    assert(*it == t3);
    ++it;
    assert(it == outputList.end());
}