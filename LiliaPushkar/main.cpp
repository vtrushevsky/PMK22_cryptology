#include <iostream>
#include <fstream>

using namespace std;

class Phone
{
protected:
	string name, firm;
	unsigned int price;

public:
	Phone():name(" "), firm(" "), price(0){}
	Phone(string n, string f, unsigned int p) : name(n), firm(f),  price(p){}
	virtual ~Phone() {}

	virtual void Virtual(){}
	virtual string GetName() { return name; }
	virtual string GetFirm() { return firm; }
	virtual unsigned int GetPrice() { return price; }

	friend istream& operator >> (istream& is, Phone p)
	{
		is >> p.name;
		is >> p.firm;
		is >> p.price;

		return is;
	}

	friend ostream& operator << (ostream& out, const Phone p)
	{
		out << p.name;
		out << p.firm;
		out << p.price;

		return out;
	}
};

class Mobile : public Phone
{
	string color;
	unsigned int storage;

public:
	Mobile(): color(" "), storage(0){}
	Mobile(string c, unsigned int s): color(c), storage(s){}

	string GetName() override { return name; }
	string GetFirm() override { return firm; }
	unsigned int GetPrice() override { return price; }
	string GetColor() { return color; }
	unsigned int GetStorage() { return storage; }

	friend istream& operator >> (istream& is, Mobile m)
	{
		is >> m.color;
		is >> m.storage;

		return is;
	}

	friend ostream& operator << (ostream& out, const Mobile m)
	{
		out << m.color;
		out << m.storage;

		return out;
	}
};

class Radio : public Phone
{
	unsigned int radius;
	bool autovid;

public:
	Radio() :radius(0), autovid(""){}
	Radio(unsigned int r, bool a): radius(r), autovid(a){}

	string GetName() override { return name; }
	string GetFirm() override { return firm; }
	unsigned int GetPrice() override { return price; }
	bool GetAutovid() { return autovid; }
	unsigned int GetRadius() { return radius; }

	friend istream& operator >> (istream& is, Radio r)
	{
		is >> r.radius;
		is >> r.autovid;

		return is;
	}

	friend ostream& operator << (ostream& out, const Radio r)
	{
		out << r.radius;
		out << r.autovid;

		return out;
	}
};

void BubbleSort(Phone arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j - 1 - i; j++)
		{
			if (arr[j].GetPrice() > arr[j + 1].GetPrice())
			{
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

unsigned int AllPrice(Phone arr[], int n)
{
	unsigned int price = 0;

	for (int i = 0; i < n; i++)
	{
		price += arr[i].GetPrice();
	}

	return price;
}

int main()
{
	int n, m, all;         

	ifstream f1("Firm1.txt");
	f1 >> n;

	ifstream f2("Firm2.txt");
	f2 >> m;

	all = n + m;

	Phone* arr = new Phone[all];
	Radio* r = new Radio[m];

	size_t i = 0;
	while (f1.eof() && i < n)
	{
		f1 >> arr[i];
		i++;
	}
	f1.close();

	while (f2.eof() && n < all)
	{
		f2 >> arr[i];
		n++;
	}
	f2.close();

	i = 0;
	while (f2.eof() && i < m)
	{
		f2 >> r[i];
		i++;
	}
	f2.close();

	ofstream out("outAll.txt");

	BubbleSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		out << arr[i];
	}
	out << AllPrice(arr, n);

	out.close();

	ofstream out1("outRadio.txt");
	for (int i = 0; i < n; i++)
	{
		if (r[i].GetAutovid() == true)
			out << r[i];		
	}
	out1.close();

	return 0;
}