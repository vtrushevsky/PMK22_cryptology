#include <gtest/gtest.h>
#include "doublylinkedlist.h"

// Test fixture class
class DoublyLinkedListTest : public ::testing::Test {
protected:
    // Helper method to convert linked list to vector
    template<typename T>
    std::vector<T> convertLinkedListToVector(const DoublyLinkedList<T>& list) {
        std::vector<T> vec;
        for (const T& item : list) {
            vec.push_back(item);
        }
        return vec;
    }
};

// Test case for pushBack function
TEST_F(DoublyLinkedListTest, PushBack) {
    // Create a linked list and push back elements
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    // Convert the linked list to vector
    std::vector<int> result = convertLinkedListToVector(list);

    // Define the expected vector
    std::vector<int> expected = { 1, 2, 3 };

    // Check if the result matches the expected vector
    EXPECT_EQ(result, expected);
}

// Test case for remove function
TEST_F(DoublyLinkedListTest, Remove) {
    // Create a linked list and push back elements
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    // Remove the second element
    DoublyLinkedList<int>::Iterator it = list.begin();
    ++it;
    list.remove(it);

    // Convert the linked list to vector
    std::vector<int> result = convertLinkedListToVector(list);

    // Define the expected vector
    std::vector<int> expected = { 1, 3 };

    // Check if the result matches the expected vector
    EXPECT_EQ(result, expected);
}

// Test case for findNode function
TEST_F(DoublyLinkedListTest, FindNode) {
    // Create a linked list and push back elements
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    // Find the node with value 2
    DoublyLinkedList<int>::Node* node = list.findNode(2);

    // Check if the node is found
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 2);
}

// Test case for sort function
TEST_F(DoublyLinkedListTest, Sort) {
    // Create a linked list and push back elements in unsorted order
    DoublyLinkedList<int> list;
    list.pushBack(3);
    list.pushBack(1);
    list.pushBack(2);

    // Sort the linked list
    list.sort();

    // Convert the linked list to vector
    std::vector<int> result = convertLinkedListToVector(list);

    // Define the expected vector
    std::vector<int> expected = { 1, 2, 3 };

    // Check if the result matches the expected vector
    EXPECT_EQ(result, expected);
}
