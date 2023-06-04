#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

class Talon
{
private:
	string subject;
	int score;
	string teacher;

public:
	Talon() :subject(" "), score(0), teacher(" ") {}
	Talon(string p, int sc, string t) : subject(p), score(sc), teacher(t) {}

	string Getsubject() { return subject; }
	string GetTeacher() { return teacher; }
	int GetScore() { return score; }
	string clearName()
	{
		return this->teacher = ""; 
	}
	friend istream& operator >> (istream& is, Talon& t)
	{
		is >> t.subject;
		is >> t.score;
		is >> t.teacher;
		return is;
	}


	friend ostream& operator << (ostream& out, const Talon& t)
	{
		out << t.subject << " ";
		out << t.score << " ";
		out << t.teacher << " ";
		return out;
	}	
};

class Student
{
private:
	string fullname;
	string group;
	unsigned int amount;
	Talon talon;
	Talon* talons;

public:

	Student() : talons(nullptr), amount(0) {}
	Student(string f, string g, unsigned int a, Talon t) : fullname(f), group(g), amount(a), talon(t)
	{
		talons = new Talon[amount];
	}

	int GetScore() { return talon.GetScore(); }
	string GetFullname() { return fullname; }
	string GetTeacher() { return talon.GetTeacher();}
	Talon* GetTalons()
	{
		return talons;
	}
	string clearTeachersName()
	{
		return talon.clearName(); 
	}
	friend istream& operator >> (istream& is, Student& s)
	{
		is >> s.fullname;
		is >> s.group;
		is >> s.amount;
		is >> s.talon;
		return is;
	}

	friend ostream& operator << (ostream& out, const Student& s)
	{
		out << s.fullname << " ";
		out << s.group << " ";
		out << s.amount << " ";
		out << s.talon << " ";
		return out;
	}
	~Student()
	{
		delete[] talons;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 1;

	ifstream f("Student.txt");
	f >> n;
	Student* array = new Student[n];

	int i = 0;
	while (!f.eof() && i < n)
	{
		f >> array[i];
		i++;
	}
	f.close();

	ofstream out("Студенти.txt");
	for (int i = 0; i < n; i++)
	{
		if (array[i].GetScore() > 0 && array[i].GetScore() < 10)
			out << "Ім'я студента:" << array[i].GetFullname() << endl;
		out << "Кількість балів:" << array[i].GetScore() << endl; 
	}
	out.close();

	ofstream out2("Викладачі.txt");

	
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (array[j].GetTeacher().compare(array[j + 1].GetTeacher()) > 0) 
			{
				// Переставити вчителів місцями
				swap(array[j], array[j + 1]);
			}
		}
	}
	string lastTeacherName = "";
	for (int i = 0; i < n; i++) 
	{
		if (array[i].GetTeacher() != lastTeacherName) 
		{
			out2 << array[i].GetTeacher() << endl;
			lastTeacherName = array[i].GetTeacher();
		}
	}

	return 0; 
}
	 