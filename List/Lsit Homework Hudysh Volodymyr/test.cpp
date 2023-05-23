#include "pch.h"
#include <gtest/gtest.h>

TEST(TestDoubleLinkedList, TestGetSize) {

    DoubleLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty(), true);

    list.PushBack(10);
    EXPECT_FALSE(list.isEmpty(), false);
    
}
TEST(TestDoubleLinkedList, TestPushBack) {

    DoubleLinkedList<int> list;
   
    list.PushBack(5);
    list.PushBack(8);
    list.PushBack(3);
    

  EXPECT_EQ(list.getSize(), 3);
}
TEST(TestDoubleLinkedList, TestBackAndFront) {

    DoubleLinkedList<int> list;

    list.PushBack(10);
    list.PushBack(18);
    list.PushBack(8);
    list.PushBack(7);

    EXPECT_EQ(list.Back(), 7);
    EXPECT_EQ(list.Front(), 10);
}
TEST(TestDoubleLinkedList, TestPushFront) {

    DoubleLinkedList<int> list;

    list.PushFront(7);
    list.PushFront(4);
    list.PushFront(2);
   EXPECT_EQ(list.getSize(), 3);
   EXPECT_EQ(list.Front(), 2);
}
TEST(TestDoubleLinkedList, TestCopy) {

    DoubleLinkedList<int> list;

    list.PushFront(3);
    list.PushFront(6);
    list.PushFront(8);

    DoubleLinkedList<int> list2(list);
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list2.getSize(), 3);

}
TEST(TestDoubleLinkedList, TestClear) {

    DoubleLinkedList<int> list;

    list.PushFront(9);
    list.PushBack(12);
    list.PushFront(5);
    list.PushBack(3);
    list.Clear();
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty(), true);
   
}
TEST(TestDoubleLinkedList, TestMove) {

    DoubleLinkedList<int> list;

    list.PushFront(6);
    list.PushBack(15);
    list.PushFront(4);
    list.PushBack(8);
    DoubleLinkedList<int> list2(move(list));
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty(), true);
    EXPECT_EQ(list2.getSize(), 4);

}

