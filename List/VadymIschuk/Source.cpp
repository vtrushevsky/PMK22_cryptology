
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include "Test.h"


using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& d, Node* p = nullptr, Node* n = nullptr)
            : data(d), prev(p), next(n) {}
    };
    void quicksort(Node* left, Node* right, bool (*compare)(const T&, const T&)) {
        if (left == nullptr || right == nullptr || left == right) {
            return;
        }

        Node* pivot = partition(left, right, compare);
        if (pivot != nullptr && pivot != left) {
            quicksort(left, pivot->prev, compare);
        }
        if (pivot != nullptr && pivot != right) {
            quicksort(pivot->next, right, compare);
        }
    }

    Node* partition(Node* left, Node* right, bool (*compare)(const T&, const T&)) {
        T pivotValue = right->data;
        Node* i = left->prev;

        for (Node* j = left; j != right; j = j->next) {
            if (compare(j->data, pivotValue)) {
                i = (i == nullptr) ? left : i->next;
                swap(i->data, j->data);
            }
        }

        i = (i == nullptr) ? left : i->next;
        swap(i->data, right->data);
        return i;
    }

public:
    void sort(bool (*compare)(const T&, const T&)) {
        quicksort(head, tail, compare);
    }

    class Iterator {
    public:
        Iterator(Node* n = nullptr) : node(n) {}
       

        T& operator*() { return node->data; }
        const T& operator*() const { return node->data; }

        Iterator& operator++() {
            node = node->next;
            return *this;
        }
        Iterator operator++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        Iterator& operator--() {
            node = node->prev;
            return *this;
        }
        Iterator operator--(int) {
            Iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const Iterator& rhs) const {
            return node == rhs.node;
        }
        bool operator!=(const Iterator& rhs) const {
            return node != rhs.node;
        }
        friend ostream& operator<<(ostream& out, const Iterator& it) {
            out << it.node->data;
            return out;
        }
        Iterator find(const T& value) const {
            for (Iterator it = *this; it != end(); ++it) {
                if (*it == value) {
                    return it;
                }
            }
            return end();
        }
        void erase() {
            Node* curr = node;

            // Якщо вузол - голова
            if (curr == list->head) {
                list->head = curr->next;
            }

            // Якщо вузол - хвіст
            if (curr == list->tail) {
                list->tail = curr->prev;
            }

            // Зміна покажчиків
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            }

            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }

            // Перехід до наступного елемента
            node = curr->next;

            // Видалення вузла
            delete curr;
            // Зменшення лічильника
            --list->count;
        }
    private:
        Node* node;
        DoublyLinkedList* list;
       
    };

    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~DoublyLinkedList() { clear(); }

    void push_front(const T& data) {
        Node* newNode = new Node(data, nullptr, head);
        if (head == nullptr) {
            tail = newNode;
        }
        else {
            head->prev = newNode;
        }
        head = newNode;
        ++count;
    }

    void push_back(const T& data) {
        Node* newNode = new Node(data, tail, nullptr);
        if (tail == nullptr) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }
        tail = newNode;
        ++count;
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    Iterator rbegin() { return Iterator(tail); }
    Iterator rend() { return Iterator(nullptr); }

    int size() const { return count; }
    bool empty() const { return count == 0; }

private:
    Node* head;
    Node* tail;
    int count;
};

struct Triangle {
    double a, b, c;
    double area() const {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

bool compare_triangles(const Triangle& t1, const Triangle& t2) {
    return t1.area() < t2.area();
}

int main() {
    DoublyLinkedList<Triangle> triangles;
    ifstream infile("triangles.txt");

    while (infile) {
        Triangle t;
        infile >> t.a >> t.b >> t.c;
        if (infile) {
            triangles.push_back(t);
        }
    }

    triangles.sort(compare_triangles);

    double min_perimeter, max_perimeter;
        cout << "Мінімальний периметр: ";
    cin >> min_perimeter;

    cout << "Максимальний периметр: ";
    cin >> max_perimeter;

    DoublyLinkedList<Triangle> filtered_triangles;
    for (const Triangle& t : triangles) {
        double perimeter = t.a + t.b + t.c;
        if (perimeter >= min_perimeter && perimeter <= max_perimeter) {
            filtered_triangles.push_back(t);
        }
    }

    // Записуємо список відфільтрованих трикутників в файл
    ofstream outfile("filtered_triangles.txt");
    for (const Triangle& t : filtered_triangles) {
        outfile << t.a << " " << t.b << " " << t.c << endl;
    }

    return 0;
}