#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) : value(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }


    void sort() {
        for (Node<T>* i = head; i != nullptr; i = i->next) {
            for (Node<T>* j = i->next; j != nullptr; j = j->next) {
                if (i->value > j->value) {
                    swap(i->value, j->value);
                }
            }
        }
    }

    int getSize() const {
        return size;
    }

    DoublyLinkedList<T> filter(T min, T max) const {
        DoublyLinkedList<T> filteredList;

        for (Node<T>* i = head; i != nullptr; i = i->next) {
            if (i->value >= min && i->value <= max) {
                filteredList.insert(i->value);
            }
        }

        return filteredList;
    }



    int getSize() const {
        return size;
    }

    void printToFile(const string& filename) const {
        ofstream output(filename);

        for (Node<T>* i = head; i != nullptr; i = i->next) {
            output << i->value << endl;
        }

        output.close();
    }

    ~DoublyLinkedList() {
        Node<T>* current = head;

        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

struct Triangle {
    double a, b, c;

    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double getArea() const {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double getPerimeter() const {
        return a + b + c;
    }
};

int main() {
    DoublyLinkedList<Triangle> triangles;
    ifstream input("triangle.txt");

    double a, b, c;
    while (input >> a >> b >> c) {
        triangles.insert(Triangle(a, b, c));
    }

    triangles.sort();

    DoublyLinkedList<Triangle> filteredList = triangles.filter(10.0, 20.0);

    filteredList.printToFile("filtered_triangles.txt");

    input.close();

    return 0;
}

TEST(TriangleTest, GetPerimeter) {
    Triangle t1(3, 4, 5);
    Triangle t2(5, 12, 13);
    Triangle t3(8, 15, 17);

    EXPECT_EQ(t1.getPerimeter(), 12);
    EXPECT_EQ(t2.getPerimeter(), 30);
    EXPECT_EQ(t3.getPerimeter(), 40);
}

TEST(DoublyLinkedListTest, AddAndSize) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.getSize(), 0);

    list.insert(1);
    EXPECT_EQ(list.getSize(), 1);

    list.insert(2);
    EXPECT_EQ(list.getSize(), 2);
}


