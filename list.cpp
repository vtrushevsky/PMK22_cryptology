#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
using namespace std;

class my_exception: public exception
{
public:
    my_exception(const char* msg) : exception(msg) {};


    const char* what() {
        return "my exception class";
    }
};
template<typename T>    
class Linked_List
{  
public:
    struct Node
    {
        Node(const T& _data, Node* _next, Node* _previous) : data(_data), next(_next), previous(_previous) {};
        T data;
        Node* next;
        Node* previous;
    };
    Linked_List();
    ~Linked_List();
    void insertFront(const T& value);
    void insertBack(const T& value);
    void insertAfter(Node* prevNode, const T& value);
    void deleteNode(Node* deleteNode);
    T find(Node* value);
    Node* getHead() const { return this->head; }
    int getSize() {return this->size;}
private:
    Node* head;
    Node* tail;
    size_t size;
};
template <typename T>
Linked_List<T>::Linked_List() : head(nullptr), tail(nullptr), size(0) {}
template <typename T>
void Linked_List<T>::insertFront(const T& value)
{
    Node* newNode = new Node(value, head, nullptr);
    if (head != nullptr)
    {
        head->previous = newNode;
    }
    else
    {
        tail = newNode;
    }
    head = newNode;
    size++;
}
template <typename T>
Linked_List<T>::~Linked_List()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
template <typename T>
void Linked_List<T>::insertBack(const T& value)
{
    Node* newNode = new Node(value, tail, nullptr);
    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    else
    {
        head = newNode;
    }
    tail = newNode;
    size++;
}
template <typename T>
void Linked_List<T>::insertAfter(Node* prevNode, const T& value)
{
    if (prevNode == nullptr)
    {
        return;
    }
    Node* newNode = new Node(value, prevNode->next, prevNode);
    prevNode->next = newNode;
    if (newNode->next != nullptr)
    {
        newNode->next->previous = newNode;
    }
    else
    {
        tail = newNode;
    }
    size++;
}
template <typename T>
void Linked_List<T>::deleteNode(Node* deleteNode)
{
    if (deleteNode == nullptr)
    {
        return;
    }
    if (deleteNode == head)
    {
        head = deleteNode->next;
    }
    if (deleteNode == tail)
    {
        tail = deleteNode->previous;
    }
    if (deleteNode->previous != nullptr)
    {
        deleteNode->previous->next = deleteNode->next;
    }
    if (deleteNode->next != nullptr)
    {
        deleteNode->next->previous = deleteNode->previous;
    }
    delete deleteNode;
    size--;
}
template <typename T>
T Linked_List<T>::find(Node* value)
{
    Node* cur = head;
    while (cur != nullptr)
    {
        if (cur == value)
            return cur->data;
        else
            cur = cur->next;
        throw invalid_argument("Value not found in list..");
    }
}
class Triangle
{
    size_t sides[3];
    string name;
    double area;
    int perimeter;
public:
    Triangle() : sides(), name(""), area(0), perimeter(0) {};
    const int getPerimeter() const{ return this->perimeter; }
    double calc_area()
    {
        area = 0.5 * sides[0] * sides[1]; 
        return area;
    }
    int calc_perim()
    {
        perimeter = this->sides[0] + this->sides[1] + this->sides[2];
        return perimeter;
    }
     friend istream& operator>>(istream& input, Triangle& triangle)
     {
         input >> triangle.name;
         input >> triangle.sides[0] >> triangle.sides[1] >> triangle.sides[2];
         return input;
     }
     friend ostream& operator<<(ostream& output, const Triangle& triangle)
     {
         output << "Triangle name: " << triangle.name << endl;
         output << "Triangle area: " << triangle.area << endl;
         output << "Triangle perimeter: " << triangle.perimeter << endl;
         return output;
     }
};

void sortList(Linked_List<Triangle>& _triangles, const string& filename)
{
    
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cerr << "Unable to open file " << filename << " for writing" << endl;
        return;
    }

    typename Linked_List<Triangle>::Node* current = _triangles.getHead();
    while (current != nullptr)
    {
        typename Linked_List<Triangle>::Node* minNode = current;
        double minArea = minNode->data.calc_area();

        typename Linked_List<Triangle>::Node* iter = current->next;
        while (iter != nullptr)
        {
            double area = iter->data.calc_area();
            if (area < minArea)
            {
                minNode = iter;
                minArea = area;
            }
            iter = iter->next;
        }

        if (minNode != current)
        {
            Triangle temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }
        outFile << current->data << endl;

        current = current->next;
    }

    outFile.close();
}
void sortByPerim(Linked_List<Triangle>& _triangles, int minPerim, int maxPerim, const string& filename)
{
    try 
    {
        fstream outFile(filename);
        if (!outFile)
        {
            throw my_exception("Failed to open file.");
        }
    }
    catch(my_exception)
    {
        cout << "Update a file name. It was wrong.." << endl;
    }
    fstream outFile(filename);

    typename Linked_List<Triangle>::Node* current = _triangles.getHead();
    while (current != nullptr)
    {
        typename Linked_List<Triangle>::Node* minNode = current;
        double minPerim = current->data.getPerimeter();

        typename Linked_List<Triangle>::Node* searchNode = current->next;
        while (searchNode != nullptr)
        {
            double searchPerim = searchNode->data.getPerimeter();
            if (searchPerim < minPerim && searchPerim >= minPerim && searchPerim <= maxPerim)
            {
                minNode = searchNode;
                minPerim = searchPerim;
            }
            searchNode = searchNode->next;
        }

        if (minNode != current)
        {
            _triangles.insertAfter(current->previous, minNode->data);
            _triangles.deleteNode(minNode);
        }
        else
        {
            current = current->next;
        }
    }

    typename Linked_List<Triangle>::Node* node = _triangles.getHead();
    while (node != nullptr)
    {
        if (node->data.getPerimeter() >= minPerim && node->data.getPerimeter() <= maxPerim)
        {
            outFile << node->data << endl;
        }
        node = node->next;
    }

    outFile.close();
}

int main(){}