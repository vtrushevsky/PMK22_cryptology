#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    Node* next;
    struct Triangle {
        double a;
        double b;
        double c;
        double area;
    } data;
};

class List {
private:
    Node* head;
public:
    List() {
        head = NULL;
    }

    void add(Node::Triangle val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void remove(Node::Triangle val) {
        if (head == NULL) {
            return;
        }
        if (head->data.a == val.a && head->data.b == val.b && head->data.c == val.c) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != NULL && (current->next->data.a != val.a || current->next->data.b != val.b || current->next->data.c != val.c)) {
            current = current->next;
        }
        if (current->next == NULL) {
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data.a << " " << current->data.b << " " << current->data.c << " " << current->data.area << endl;
            current = current->next;
        }
    }

    Node* search(Node::Triangle val) {
        Node* current = head;
        while (current != NULL && (current->data.a != val.a || current->data.b != val.b || current->data.c != val.c)) {
            current = current->next;
        }
        return current;
    }

    Node* getHead() {
        return head;
    }
};


bool compareTriangles(const Node::Triangle& t1, const Node::Triangle& t2) {
    return t1.area < t2.area;
}

int main() {
    ifstream infile("triangles.txt");
    vector<Node::Triangle> triangles;

    double a, b, c;
    while (infile >> a >> b >> c) {
        Node::Triangle t = { a, b, c, 0.0 };
        double s = (a + b + c) / 2.0;
        t.area = sqrt(s * (s - a) * (s - b) * (s - c));
        triangles.push_back(t);
    }

    sort(triangles.begin(), triangles.end(), compareTriangles);

    List triangleList;
    List perimeterList;

    for (const auto& t : triangles) {
        triangleList.add(t);
        if (t.a + t.b + t.c >= 10 && t.a + t.b + t.c <= 1000) {
            perimeterList.add(t);
        }
    }

    ofstream outfile("output.txt");
    outfile << "Triangles sorted by area:" << endl;
    Node* current = triangleList.getHead();
    while (current != NULL) {
        outfile << current->data.a << " " << current->data.b << " " << current->data.c << " " << current->data.area << endl;
        current = current->next;
    }
    outfile << endl;

    outfile << "Triangles with perimeter between 10 and 1000:" << endl;  current = perimeterList.getHead();
    while (current != NULL) {
        outfile << current->data.a << " " << current->data.b << " " << current->data.c << " " << current->data.area << endl;
        current = current->next;
    }

    system("pause");
    return 0;
}