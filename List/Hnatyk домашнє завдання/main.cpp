#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <exception>
#include <string>
#include <cmath>

// Клас, що представляє трикутник
class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3)
        : side1(s1), side2(s2), side3(s3) {}

    // Метод, що повертає площу трикутника
    double getArea() const {
        double p = getPerimeter() / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

    // Метод, що повертає периметр трикутника
    double getPerimeter() const {
        return side1 + side2 + side3;
    }
};

// Шаблонний клас двозв'язного списку
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        
        Node(const T& value, Node* p = nullptr, Node* n = nullptr)
        : data(value), prev(p), next(n) {}
    };
    
    Node* head;
    Node* tail;
    size_t size;
    
public:
    // Конструктор за замовчуванням
    LinkedList()
    : head(nullptr), tail(nullptr), size(0) {}
    
    // Конструктор копіювання
    LinkedList(const LinkedList& other)
    : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            addBack(current->data);
            current = current->next;
        }
    }
    
    // Оператор присвоєння
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                addBack(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    // Конструктор переміщення
    LinkedList(LinkedList&& other) noexcept
    : head(other.head), tail(other.tail), size(other.size) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    
    // Оператор переміщення
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            head = other.head;
            tail = other.tail;
            size = other.size;
            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }
    
    // Деструктор
    ~LinkedList() {
        clear();
    }
    class Iterator {
            friend class LinkedList<T>;
        private:
            Node* current;

            Iterator(Node* node) : current(node) {}

        public:
        bool operator==(const Iterator& other) const {
                   return current == other.current;
               }

               // Перевантаження оператора нерівності (!=) для ітераторів
               bool operator!=(const Iterator& other) const {
                   return !(*this == other);
               }
        Iterator& operator++() {
                    if (current) {
                        current = current->next;
                    }
                    return *this;
                }
        T& operator*() const {
                    return current->data;
                }
        };
    Iterator begin() const {
           return Iterator(head);
       }
    Iterator end() const {
            return Iterator(nullptr);
        }
    // Додати елемент в кінець списку
    void addBack(const T& value) {
        Node* newNode = new Node(value, tail, nullptr);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }
    
    // Додати елемент впереді списку
    void addFront(const T& value) {
        Node* newNode = new Node(value, nullptr, head);
        if (head) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        size++;
    }
    
    // Видалити елемент з кінця списку
    void removeBack() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            size--;
        }
    }
    
    // Видалити елемент з початку списку
    void removeFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            size--;
        }
    }
    
    // Очистити вміст списку
    void clear() {
        while (head) {
            removeFront();
        }
    }
    
    // Перевірити, чи список порожній
    bool isEmpty() const {
        return size == 0;
    }
    
    // Отримати кількість елементів у списку
    size_t getSize() const {
        return size;
    }
    
    // Перевірити, чи елемент знаходиться у списку
    bool contains(const T& value) const {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // Знайти елемент по ітератору
    Node* findNode(const Iterator& iter) const {
        Node* current = head;
        while (current) {
            if (current == iter.current) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    // Видалити елемент за ітератором
    void remove(const Iterator& iter) {
        Node* nodeToRemove = findNode(iter);
        if (nodeToRemove) {
            if (nodeToRemove->prev) {
                nodeToRemove->prev->next = nodeToRemove->next;
            } else {
                head = nodeToRemove->next;
            }
            if (nodeToRemove->next) {
                nodeToRemove->next->prev = nodeToRemove->prev;
            } else {
                tail = nodeToRemove->prev;
            }
            delete nodeToRemove;
            size--;
        }
    }
    
    // Відсортувати список за зростанням площ трикутників
    void sort() {
        if (size > 1) {
            Node* current = head;
            while (current->next) {
                Node* nextNode = current->next;
                while (nextNode) {
                    if (current->data.getArea() > nextNode->data.getArea()) {
                        std::swap(current->data, nextNode->data);
                    }
                    nextNode = nextNode->next;
                }
                current = current->next;
            }
        }
    }
    
    // Функція для фільтрування трикутників за периметром і створення нового списку
    LinkedList<T> filterByPerimeter(double minPerimeter, double maxPerimeter) const {
        LinkedList<T> newList;
        Node* current = head;
        while (current) {
            double perimeter = current->data.getPerimeter();
            if (perimeter >= minPerimeter && perimeter <= maxPerimeter) {
                newList.addBack(current->data);
            }
            current = current->next;
        }
        return newList;
    }
};
// Клас винятку для обробки помилок
class CustomException : public std::exception {
private:
    std::string message;
    
public:
    CustomException(const std::string& msg) : message(msg) {}
    // Перевизначення функції what() для отримання повідомлення про помилку
    const char* what() const noexcept override {
        return message.c_str();
    }
    
};
// Функція для зчитування трикутників з файлу та створення списку
LinkedList<Triangle> readTrianglesFromFile(const std::string& filename) {
LinkedList<Triangle> triangleList;
std::ifstream file(filename);
if (!file.is_open()) {
throw CustomException("Failed to open file.");
}
double s1, s2, s3;
while (file >> s1 >> s2 >> s3) {
triangleList.addBack(Triangle(s1, s2, s3));
}
file.close();
return triangleList;
}
// Функція для запису списку трикутників в файл
void writeTrianglesToFile(const LinkedList<Triangle>& triangleList, const std::string& filename) {
std::ofstream file(filename);
if (!file.is_open()) {
throw CustomException("Failed to open file.");
}
for (const auto& triangle : triangleList) {
file << triangle.getPerimeter() << " " << triangle.getArea() << std::endl;
}
file.close();
}

int main() {
    try {
        // Зчитування трикутників з файлу та створення списку
        LinkedList<Triangle> triangleList = readTrianglesFromFile("/Users/solomia/Desktop/25балів дз/25балів дз/triangles.txt");
        
        // Сортування списку за зростанням площ трикутників
        triangleList.sort();
        
        // Фільтрування трикутників за периметром та створення нового списку
        double minPerimeter = 10.0;
        double maxPerimeter = 20.0;
        LinkedList<Triangle> filteredList = triangleList.filterByPerimeter(minPerimeter, maxPerimeter);
        
        // Запис списків трикутників у новий файл
        // Запис відсортованого списку трикутників у файл
        writeTrianglesToFile(triangleList, "/Users/solomia/Desktop/25балів дз/25балів дз/sorted_triangles.txt");
        writeTrianglesToFile(filteredList, "/Users/solomia/Desktop/25балів дз/25балів дз/filtered_triangles.txt");
        
        // Виведення списку трикутників за допомогою Range-based циклу
        std::cout << "Sorted Triangles:" << std::endl;
        for (const auto& triangle : triangleList) {
            std::cout << "Perimeter: " << triangle.getPerimeter() << ", Area: " << triangle.getArea() << std::endl;
        }
        std::cout << "Filtered Triangles:" << std::endl;
        for (const auto& triangle : filteredList) {
            std::cout << "Perimeter: " << triangle.getPerimeter() << ", Area: " << triangle.getArea() << std::endl;
        }
    } catch (const CustomException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}



