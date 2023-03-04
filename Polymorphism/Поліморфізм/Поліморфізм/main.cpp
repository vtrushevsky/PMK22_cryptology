#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

//3. Поліморфізм: Визначити абстрактний тип «телефон»(назва, фірма, ціна).
//Визначити 2 похідні від нього типи : «мобільний телефон»(колір, об’єм пам’яті)
//, «радіотелефон»(радіус дії, наявність автовідповідача).
//У двох текстових файлах задано дані про телефони двох різних фірм.Зчитати ці 
//дані в один масив  і вивести у текстовий файл : 1) всі телефони, посортовані 
//за ціною із зазначенням загальної суми; 2) радіотелефони з автовідповідачем

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
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int size = 0;
	
	string randLine;

	fstream in("МобільніТелефони.txt");
	getline(in, randLine); 

	in >> size;
	
	getline(in, randLine);
	getline(in, randLine);
	
	MobilePhone* array = new MobilePhone[size];

	for (int i = 0; i < size; i++)
	{
		in >> array[i];
	}
	in.close(); 




	fstream in_2("РадіоТелефони.txt");
    
	getline(in_2, randLine);
	int size2 = 0;
	in_2 >> size2;
	
	getline(in_2, randLine);
	getline(in_2, randLine);

	RadioPhone* array_2 = new RadioPhone[size2];


	for (int i = 0; i < size2; i++)
	{
		in_2 >> array_2[i];
	}
	in_2.close();
	int finalSize = size + size2; 

	Phone** finalArray = new Phone * [finalSize];

	for (int i = 0; i < size; i++)
	{
		finalArray[i] = &array[i];
	}
	for (int j = 0; j < size2; j++)
	{
		finalArray[j + size] = &array_2[j];
	}
	
	fstream finalOut("Телефони.txt");
	int sumPrice = 0; 

	sortByPrice(finalArray, finalSize);
	for (int i = 0; i < finalSize; i++)
	{
		if (finalArray[i]->getAutoResponse() == true)
		{
			finalOut << finalArray[i]->printPhone() << endl;
		}
		else
		{
			finalArray[i]->setFiltered();
		}
	}
	
	for (int i = 0; i < finalSize; i++)
	{
		if (finalArray[i]->getFiltered() == false)
			sumPrice += finalArray[i]->getPrice();
		else 
		{
			i++;
		}
	}
	
	finalOut << "Price for all phones -> " << sumPrice << ";";
	
	return 0; 
}