#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

class Phone
{
protected: 
	string name; 
	string producerName;
	int price;
	bool isFiltered; 
public:
	Phone(): name(), producerName(""), price(0), isFiltered(false)  {}
	Phone(string n, string prodN, int p,bool isFilt): name(n), producerName(prodN), price(p), isFiltered(isFilt) {}
	
	virtual string getPhoneType() = 0;

	friend istream& operator >> (istream& in, Phone& s)
	{
		in >> s.name;
		in >> s.producerName;
		in >> s.price;
		return in;
	}
		 
	friend ostream& operator << (ostream& out, Phone& s)
	{
		out << s.name << " ";
		out << s.producerName << " ";
		out << s.price << " ";
		return out;
	}

	virtual string printPhone()
	{
		string phoneDetails = this->producerName + " " + this->name + " " + to_string(this->price) + " ";
		return phoneDetails;
	}
	int getPrice() { return this->price;}
	string getName() {return this->name;}

	virtual bool getAutoResponse()
	{
		return TRUE;
	}
	virtual bool setFiltered()
	{
		isFiltered = true;
		return isFiltered; 
	}
	virtual bool getFiltered()
	{
		return isFiltered;
	}
};
class MobilePhone : public Phone
{
private:
	string color;
	int storageVolume; 
public:
	MobilePhone(): color("White"), storageVolume(0) {}
	MobilePhone(string c, int storageV) : color(c), storageVolume(storageV) {}

	virtual string getPhoneType()
	{
		return "Mobile Phone";
	}

	friend istream& operator >> (istream& in, MobilePhone& s)
	{
		Phone& b = s;
		in >> b;
		in >> s.color; 
		in >> s.storageVolume; 
		return in; 
	}
	friend ostream& operator << (ostream& out, MobilePhone& s)
	{
		Phone& b = s; 
		out << b;
		out << s.color;
		out << s.storageVolume; 
		return out;
	}
	virtual string printPhone()
	{
		string phoneDetails = this->producerName + " " + this->name + " " + to_string(this->price) + " " + this->color + " " + to_string(this->storageVolume);
		return phoneDetails;
	}
};

class RadioPhone : public Phone
{
private:
	int workRadius;
	bool autoResponse; 
public: 
	RadioPhone():workRadius(0),autoResponse(FALSE) {}
	RadioPhone(int workR, bool response) :workRadius(workR), autoResponse(response) {}
	
	virtual string getPhoneType()
	{
		return "Radio Phone";
	}
	friend istream& operator >> (istream& in, RadioPhone& s)
	{
		Phone& b = s;
		in >> b;
		in >> s.workRadius; 
		in >> s.autoResponse; 
		return in;
	
	}
	friend ostream& operator << (ostream& out, RadioPhone& s)
	{
		Phone& b = s;
		out << b;
		out << s.workRadius << " ";
		out << s.autoResponse << " ";
		return out;
	}

	virtual string printPhone()
	{
		string phoneDetails = this->producerName + " " + this->name + " " + to_string(this->price)+ " " + to_string(this->workRadius) + " " + to_string(this->autoResponse);
		return phoneDetails;
	}
	bool getAutoResponse() { return this->autoResponse;}
};
void sortByPrice(Phone** array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j]->getPrice() > array[j + 1]->getPrice()) {
				Phone* temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
int main(){}