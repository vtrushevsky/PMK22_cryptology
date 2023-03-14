#include <iostream>
#include <fstream>

using namespace std;

class Talon
{
private:
	string predmet;
	int score;
	string teacher;

public:
	Talon() :predmet(" "), score(0), teacher(" ") {}
	Talon(string p, int sc, string t) : predmet(p), score(sc), teacher(t) {}

	string GetPredmet() const { return predmet; }
	string GetTeacher() const { return teacher; }
	int GetScore() const { return score; }

	friend istream& operator >> (istream& is, Talon t)
	{
		is >> t.predmet;
		is >> t.score;
		is >> t.teacher;

		return is;
	}

	friend ostream& operator << (ostream& out, const Talon t)
	{
		out << t.predmet;
		out << t.score;
		out << t.teacher;

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
	
	Student() : talons(nullptr) {}
	Student(string f, string g, unsigned int a, Talon t) : fullname(f), group(g), amount(a), talon(t) 
	{
		talons = new Talon[amount];
	}
	~Student()
	{
		delete[] talons;
	}

	int GetScore() const { return talon.GetScore(); }
	string GetFullname() const { return fullname; }
	string GetTeacher() const { return talon.GetTeacher(); }
	Talon* GetTalons() const
	{
		return talons;
	}

	friend istream& operator >> (istream& is, Student s)
	{
		is >> s.fullname;
		is >> s.group;
		is >> s.amount;
		is >> s.talon;

		return is;
	}

	friend ostream& operator << (ostream& out, const Student s)
	{
		out << s.fullname;
		out << s.group;
		out << s.amount;
		out << s.talon;

		return out;
	}
};

struct Counder
{
	string nameofteacher;
	size_t count = 0;
};

int main()
{
	int n;

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

	ofstream out("File1.txt");
	for (int i = 0; i < n; i++)
	{
		if (array[i].GetScore() > 0 && array[i].GetScore() < 10)
			out << array[i].GetFullname();
	}
	out.close();

	ofstream out2("File2.txt");

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (array[j].GetTeacher() > array[j + 1].GetTeacher())
			{
				string temp = 0;
				temp = array[j].GetTeacher();
				array[j].GetTeacher() = array[j + 1].GetTeacher();
				array[j + 1].GetTeacher() = temp;	
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (array[i].GetTeacher() != array[i - 1].GetTeacher())
			out2 << array[i].GetTeacher();
	}
	out2.close();



	return 0;
}