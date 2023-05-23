#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Phone {
protected:
    string name;
    string brand; 
    float price; 
public:
    Phone(string n, string b, float p) : name(n), brand(b), price(p) {}
    virtual ~Phone() {}
    virtual void print() = 0; 
    float getPrice() { return price; }
};
class MobilePhone : public Phone {
private:
    string color; 
    int memory; 
public:
    MobilePhone(string n, string b, float p, string c, int m) : Phone(n, b, p), color(c), memory(m) {}
    void print() { cout << name << " (" << brand << "), color: " << color << ", memory: " << memory << " GB, price: " << price << " UAH" << endl; }
};

class RadioPhone : public Phone {
private:
    float range; 
    bool answeringMachine;
public:
    RadioPhone(string n, string b, float p, float r, bool am) : Phone(n, b, p), range(r), answeringMachine(am) {}
    void print() { cout << name << " (" << brand << "), range: " << range << " km, answering machine: " << (answeringMachine ? "yes" : "no") << ", price: " << price << " UAH" << endl; }
    bool hasAnsweringMachine() { return answeringMachine; }
};

int main() {
    vector<Phone*> phones;

   
    ifstream fin1("phones1.txt");
    string name, brand, color;
    float price;
    int memory;
    while (fin1 >> name >> brand >> price >> color >> memory) {
        phones.push_back(new MobilePhone(name, brand, price, color, memory));
    }
    fin1.close();

    
    ifstream fin2("phones2.txt");
    float range;
    bool answeringMachine;
    while (fin2 >> name >> brand >> price >> range >> answeringMachine) {
        phones.push_back(new RadioPhone(name, brand, price, range, answeringMachine));
    }
    fin2.close();

   
    sort(phones.begin(), phones.end(), [](Phone* a, Phone* b) { return a->getPrice() < b->getPrice(); });

   
    ofstream fout1("phones_sorted.txt");
    float sum = 0;
    return 0;
}