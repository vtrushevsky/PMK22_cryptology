#include "pch.h"
#include "../DoubleLinkList_Triangle/main.cpp"
#include <gtest/gtest.h>

TEST(LinkedListTest, TestInsertFront)
{
    Linked_List<int> list;
    list.insertFront(1);
    ASSERT_EQ(list.getHead()->data, 1);
    ASSERT_EQ(list.getSize(), 1);

    list.insertFront(2);
    ASSERT_EQ(list.getHead()->data, 2);
    ASSERT_EQ(list.getHead()->next->data, 1);
    ASSERT_EQ(list.getSize(), 2);
}

TEST(LinkedListTest, TestInsertBack)
{
    Linked_List<int> list;
    list.insertBack(1);
    ASSERT_EQ(list.getHead()->data, 1);
    ASSERT_EQ(list.getSize(), 1);

    list.insertBack(2);
    ASSERT_EQ(list.getHead()->data, 1);
    ASSERT_EQ(list.getHead()->next->data, 2);
    ASSERT_EQ(list.getSize(), 2);
}

TEST(LinkedListTest, TestInsertAfter)
{
    Linked_List<int> list;
    list.insertFront(1);
    list.insertBack(3);

    Linked_List<int>::Node* prevNode = list.getHead();
    list.insertAfter(prevNode, 2);

    ASSERT_EQ(prevNode->next->data, 2);
    ASSERT_EQ(prevNode->next->next->data, 3);
    ASSERT_EQ(list.getSize(), 3);
}

TEST(LinkedListTest, TestDeleteNode)
{
    Linked_List<int> list;
    list.insertFront(1);
    list.insertBack(2);
    Linked_List<int>::Node* nodeToDelete = list.getHead()->next;

    list.deleteNode(nodeToDelete);

    ASSERT_EQ(list.getHead()->data, 1);
    ASSERT_EQ(list.getHead()->next, nullptr);
    ASSERT_EQ(list.getSize(), 1);
}

TEST(LinkedListTest, TestFind)
{
    Linked_List<int> list;
    list.insertFront(1);
    list.insertBack(2);
    Linked_List<int>::Node* nodeToFind = list.getHead()->next;

    int foundValue = list.find(nodeToFind);

    ASSERT_EQ(foundValue, 2);
}

//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
