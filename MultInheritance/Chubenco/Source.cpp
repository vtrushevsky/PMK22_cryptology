#include <iostream>
using namespace std;

struct Figure
{
protected:
	int Ribs;
    int Heights;
public:
	Figure() {
		Ribs = 0;
		Heights = 0;
	}
};
struct Flat_figure : protected Figure
{
protected:
	double Square;
public:
	Flat_figure() {
		Square = 0;
	}
};
struct Volumetric_figure : protected Figure
{
protected:
	double Heigh;
	double Square;
	double Volume;
public:
	Volumetric_figure() {
		Square = 0;
		Volume = 0;
		Heigh = 0;
	}
};
struct Polygon : protected Flat_figure
{
private:
	double Side_length;
	double Apothem;
public:
	Polygon() {
		Side_length = 0;
		Apothem = 0;
	}
	void setData(int Ribs, double Side_length, double Apothem) {
		this->Ribs = Ribs;
		this->Heights = Ribs;
		this->Apothem = Apothem;
		this->Side_length = Side_length;
		Square = 0.5 * Apothem * Ribs * Side_length;
	}
	double GetSquare() {
		return Square;
	}
	void Print() {
		cout << "Polygon" << endl;
		cout << "Ribs: " << Ribs << endl;
		cout << "Heights: " << Heights << endl;
		cout << "Side length: " << Side_length << endl;
		cout << "Square: " << Square << endl;
		cout << "___________________" << endl;
	}
};
struct Circle : protected Flat_figure
{
private:
	double Radius;
public:
	Circle() {
		Radius = 0;
	}
	void setData(double Radius) {
		this->Radius = Radius;
		Square = 3.14 * this->Radius * this->Radius;
	}
	double GetSquare() {
		return Square;
	}
	void Print() {
		cout << "Circle" << endl;
		cout << "Ribs: " << Ribs << endl;
		cout << "Heights: " << Heights << endl;
		cout << "Radius: " << Radius << endl;
		cout << "Square: " << Square << endl;
		cout << "___________________" << endl;
	}
};
struct Parallelepiped : protected Volumetric_figure
{
private:
	double Length;
	double Width;
public:
	Parallelepiped(){
		Ribs = 12;
		Heights = 8;
		Length = 0;
		Width = 0;
	}
	void setData(double Length, double Widht, double High) {
		this->Length = Length;
		this->Width = Widht;
		this->Heigh = High;
		Square = (High * Widht * 2) + (High * Length * 2) + (Length * Widht * 2);
		Volume = High * Widht * Length;
	}
	double getHigh() {
		return Heigh;
	}
	void Print() {
		cout << "Parallelepiped" << endl;
		cout << "Ribs: " << Ribs << endl;
		cout << "Heights: " << Heights << endl;
		cout << "Length: " << Length << endl;
		cout << "Height: " << Heigh << endl;
		cout << "Width: " << Width << endl;
		cout << "Square: " << Square << endl;
		cout << "Volume: " << Volume << endl;
		cout << "___________________" << endl;
	}
};
struct Cone : protected Volumetric_figure
{
private:
	double Radius;
public:
	Cone() {
		Ribs = 0;
		Heights = 1;
		Radius = 0;
	}
	void setData(double Heigh, double Radius) {
		this->Heigh = Heigh;
		this->Radius = Radius;
		Square = 3.14 * Radius * (pow((Heigh * Heigh) + (Radius * Radius), 0.5)) + 3.14 * Radius * Radius;
		Volume = (0.3333333) * Heigh * 3.14 * Radius * Radius;
	}
	double getHigh() {
		return Heigh;
	}
	void Print() {
		cout << "Cone" << endl;
		cout << "Ribs: " << Ribs << endl;
		cout << "Heights: " << Heights << endl;
		cout << "Height: " << Heigh << endl;
		cout << "Radius: " << Radius << endl;
		cout << "Square: " << Square << endl;
		cout << "Volume: " << Volume << endl;
		cout << "___________________" << endl;
	}
};
void bubbleSort(double arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	Polygon a1;
	a1.setData(5, 6, 5);
	Polygon a2;
	a2.setData(7, 8, 6);
	Circle b1;
	b1.setData(6);
	Circle b2;
	b2.setData(7);
	Circle b3;
	b3.setData(8);
	Parallelepiped d1;
	d1.setData(5, 5, 10);
	Parallelepiped d2;
	d2.setData(6, 6, 5);
	Cone c1;
	c1.setData(7, 5);
	Cone c2;
	c2.setData(6, 6);
	Cone c3;
	c3.setData(9, 7);
	double arr_Flat_figure[5] = { a1.GetSquare(), a2.GetSquare(), b1.GetSquare(), b2.GetSquare(), b3.GetSquare() };
	double arr_Volumetric_figure[5] = { c1.getHigh(), c2.getHigh(), c3.getHigh(), d1.getHigh(), d2.getHigh() };
	bubbleSort(arr_Flat_figure, 5);
	for (int i = 0; i < 5; i++) {
		if (arr_Flat_figure[i] == a1.GetSquare()) {a1.Print();}
		else if (arr_Flat_figure[i] == a2.GetSquare()) {a2.Print();}
		else if (arr_Flat_figure[i] == b1.GetSquare()) {b1.Print();}
		else if (arr_Flat_figure[i] == b2.GetSquare()) {b2.Print();}
		else if (arr_Flat_figure[i] == b3.GetSquare()) {b3.Print();}
	}
	cout  << endl;
	cout << "///////////////////////////////"<< endl;
	cout  << endl;
	bubbleSort(arr_Volumetric_figure, 5);
	for (int i = 0; i < 5; i++) {
		if (arr_Volumetric_figure[i] == c1.getHigh()) { c1.Print(); }
		else if (arr_Volumetric_figure[i] == c2.getHigh()) { c2.Print(); }
		else if (arr_Volumetric_figure[i] == c3.getHigh()) { c3.Print(); }
		else if (arr_Volumetric_figure[i] == d1.getHigh()) { d1.Print(); }
		else if (arr_Volumetric_figure[i] == d2.getHigh()) { d2.Print(); }
	}
}