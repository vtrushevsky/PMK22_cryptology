#include <iostream>
using namespace std;
class Figure {
public:
    virtual ~Figure() {}
};

class Figure2D : public Figure {
protected:
    double area;
public:
    Figure2D() : area(0) {}
    Figure2D(double _area) : area(_area) {}
    virtual ~Figure2D() {}
    const double getArea() const 
    { 
        return this->area; 
    }
    virtual void print(ostream& os) const 
    { 
        os << this->area << endl; 
    }
    
    bool operator<(const Figure2D& other) const { return this->area>other.area;}
};

class Figure3D : public Figure {
protected:
    double volume;
public:
    Figure3D() : volume(0) {}
    Figure3D(double _volume) : volume(_volume) {}
   
    virtual void print(ostream& os) const 
    { 
        os << this->volume << endl; 
    }
    
    const double getVolume() const { return this->volume; }
    bool operator>(const Figure3D& other) const 
    { 
        return this->volume < other.volume; 
    }

    virtual ~Figure3D() {}
};

class Circle :virtual public Figure2D
{
public:
    Circle() : Figure2D(0) {}
    Circle(double _area) : Figure2D(_area) {}
    void print(ostream& out) const override
    {
        out << "Circle`s Area : " << this->area << ";" << endl;
    }
    ~Circle() {}
};

class Parallelepiped : public Figure3D
{
public:
    Parallelepiped() : Figure3D(0) {}
    Parallelepiped(double _volume) : Figure3D(_volume) {}
    ~Parallelepiped() {}
    
};

class Cone : public Figure3D {
public:
    Cone() : Figure3D(0) {}
    Cone(double _volume) : Figure3D(_volume) {}
    ~Cone() {}
   
};
class Triangle : public Figure2D
{
private: 
   
public: 
    Triangle(): Figure2D() {}
    Triangle(double _area ): Figure2D(_area) {}
    void print(ostream& out) const override
    {
        out << "Triangle`s Area : " << this->area << ";" << endl;
    }
    ~Triangle() {}
}; 
class Square : public Figure2D
{
private: 

public: 
    Square(): Figure2D() {}
    Square(double _area): Figure2D(_area) {}

    void print(ostream& out) const override
    {
        out << "Square`s Area : " << this->area << ";" << endl;
    }
}; 
void bubbleSort(Figure2D** arr, int n) {
    bool swapped = true;
    int j = 0;
    Figure2D* tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (*(arr[i]) < *(arr[i + 1])) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}
void bubbleSort3D(Figure3D** arr, int n) {
    bool swapped = true;
    int j = 0;
    Figure3D* tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (*(arr[i]) > *(arr[i + 1])) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}

int main() {
    const size_t size = 3; 
    Figure2D** A = new Figure2D * [size];
    Figure3D** B = new Figure3D * [size];
    Circle a(23.4);
    Triangle b(13.2);
    Square c(9.5);

    Cone q(22.3);
    Parallelepiped w(12.4); 
    Parallelepiped w2(16.4);
    A[0] = &a;
    A[1] = &b;
    A[2] = &c;
    B[0] = &q;
    B[1] = &w;
    B[2] = &w2;
    
    int choice = 0;
    while (true) {
        system("cls");
        cout <<
            " 0 - for printing all 2D Figures \n\n" <<
            " 1 - for printing all 3D figures \n\n" <<
            " 2 - for finding figure with geometrical values \n\n" << "Enter the command:";
        cin >> choice;
        if (choice == 0)
        {
            system("cls");
            bubbleSort(A, size);
            for (int i = 0; i < size; i++) {

                A[i]->print(cout);
            }
            system("pause"); 
        }
        else if (choice == 1)
        {
            system("cls");
            bubbleSort3D(B, size);
            for (int i = 0; i < size; i++)
            {
                B[i]->print(cout);
            }
            system("pause");
        }
        else if (choice == 2)
        {
            system("cls");
            cout << "Enter a float value :";
            double res = 0;
            cin >> res;
            for (int i = 0; i < size; i++)
            {
                if (res == A[i]->getArea())
                {
                    cout << "The 2D object with same value is : ";
                    A[i]->print(cout);
                    continue;

                }
                else if (res == B[i]->getVolume())
                {
                    cout << "The 3D object with same value is : ";
                    B[i]->print(cout);
                }
            }
            system("pause");
        }
    }
}

